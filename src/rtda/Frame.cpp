#include "Frame.h"

Frame::Frame(ClassFile *classfile, std::string class_name, std::string method_name, std::string method_descriptor)
{
    this->classfile = classfile;
    this->class_name = class_name;
    this->method_name = method_name;
    this->method_descriptor = method_descriptor;
    Code_attribute *code = classfile->getMethodByNameAndType(method_name, method_descriptor);
    localVars = new LocalVars(code->max_locals);
    operandStack = new OperandStack(code->max_stack);
    this->code_length = code->code_length;
    this->codes = code->codes;
    // lower = NULL;
}

ClassFile *Frame::getClassFile()
{
    return classfile;
}

static u4 opcode_length[] = JVM_OPCODE_LENGTH_INITIALIZER; //每个指令的长度

void Frame::printFrame()
{
    std::cout << "class_name: " << class_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "method_descriptor: " << method_descriptor << std::endl;
    std::cout << "code_length:" << code_length << std::endl;
    // std::cout << std::hex; //打印16进制数
    // for (u4 i = 0; i < code_length; i++)
    //     std::cout << codes[i] << std::endl;
    // std::cout << std::dec;
    // for (u4 i = 0; i < code_length;)
    // {
    //     u4 j = i;
    //     for (j; j < i+opcode_length[codes[i]]; j++)
    //         printf("%02hhx\t", codes[j]);
    //     printf("\n");
    //     i = j+1;
    // }
    for(u4 i = 0;i<code_length;i++)
        printf("%02hhx\n",codes[i]);
    operandStack->printOperandStack();
    localVars->printLocalVars();
}

u1 Frame::get_code(u4 pc) //todo暂时将此作为程序退出的条件
{
    
    if (pc >= code_length)
    {
        exit_with_massage("pc out of code length");
        // std::cout << "jvm end" << std::endl;
        // exit(0);
    }

    return (u1)codes[pc];
}

u1 Frame::get_u1(u4 pc)
{
    return (u1)codes[pc + 1];
}

u2 Frame::get_u2(u4 pc)
{
    union
    {
        u1 _u1[2];
        u2 _u2;
    } a;
    a._u1[1] = codes[pc + 1];
    a._u1[0] = codes[pc + 2];
    return a._u2;
}

u4 Frame::get_u4(u4 pc)
{
    union
    {
        u1 _u1[4];
        u4 _u4;
    } a;
    a._u1[3] = codes[pc + 1];
    a._u1[2] = codes[pc + 2];
    a._u1[1] = codes[pc + 3];
    a._u1[0] = codes[pc + 4];

    return a._u4;
}

void Frame::push_byte32(byte_32 a)
{
    operandStack->push(a._u4);
}

void Frame::push_byte64(byte_64 a)
{
    operandStack->push(a._u4[0]);
    operandStack->push(a._u4[1]);
}

void Frame::push_jbyte(jbyte a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jbyte = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}

void Frame::push_jint(jint a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jint = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}
void Frame::push_jchar(jchar a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jchar = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}

void Frame::push_jboolean(jboolean a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jboolean = a;
    operandStack->push(byte32._u4);
}

void Frame::push_jshort(jshort a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jshort = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}
void Frame::push_jlong(jlong a)
{
    byte_64 byte64;
    byte64._jlong = a;
    //下面2句的顺序决定了内部数据的存储是大端还是小端
    //要与pop的顺序保持一致
    operandStack->push(byte64._u4[0]);
    operandStack->push(byte64._u4[1]);
}
void Frame::push_jfloat(jfloat a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jfloat = a;
    operandStack->push(byte32._u4); //存储纯粹数据
}
void Frame::push_jdouble(jdouble a)
{
    byte_64 byte64;
    byte64._jdouble = a;
    //下面2句的顺序决定了内部数据的存储是大端还是小端
    //要与pop的顺序保持一致
    operandStack->push(byte64._u4[0]);
    operandStack->push(byte64._u4[1]);
}
void Frame::push_jobject(jobject a)
{
    byte_32 byte32;
    byte32._u4 = 0;
    byte32._jobject = a;
    operandStack->push(byte32._u4);
}

void Frame::pop()
{
    operandStack->pop();
}

void Frame::pop2()
{
    operandStack->pop();
    operandStack->pop();
}

void Frame::dup()
{
    u4 a = operandStack->getTop();
    operandStack->push(a);
}

void Frame::dup_x1()
{
    u4 a = operandStack->getTop();
    operandStack->push(a);
    operandStack->push(a);
}

void Frame::dup_x2()
{
    u4 a = operandStack->getTop();
    operandStack->push(a);
    operandStack->push(a);
    operandStack->push(a);
}

void Frame::dup2()
{
    u4 a = operandStack->getTop();
    operandStack->pop();
    u4 b = operandStack->getTop();

    operandStack->push(a);
    operandStack->push(b);
    operandStack->push(a);
}

void Frame::dup2_x1()
{
    u4 a = operandStack->getTop();
    operandStack->pop();
    u4 b = operandStack->getTop();

    operandStack->push(a);
    operandStack->push(b);
    operandStack->push(a);
    operandStack->push(b);
    operandStack->push(a);
}

void Frame::dup2_x2()
{
    u4 a = operandStack->getTop();
    operandStack->pop();
    u4 b = operandStack->getTop();

    operandStack->push(a);
    operandStack->push(b);
    operandStack->push(a);
    operandStack->push(b);
    operandStack->push(a);
    operandStack->push(b);
    operandStack->push(a);
}

void Frame::swap()
{
    u4 a = operandStack->getTop();
    operandStack->pop();
    u4 b = operandStack->getTop();
    operandStack->pop();

    operandStack->push(a);
    operandStack->push(b);
}

jint Frame::pop_jint()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jint;
}
jbyte Frame::pop_jbyte()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jbyte;
}
jboolean Frame::pop_jboolean()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jboolean;
}
jchar Frame::pop_jchar()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jchar;
}
jshort Frame::pop_jshort()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jshort;
}
jlong Frame::pop_jlong()
{
    byte_64 byte64;
    byte64._u4[1] = operandStack->getTop();
    operandStack->pop();
    byte64._u4[0] = operandStack->getTop();
    operandStack->pop();
    return byte64._jlong;
}
jfloat Frame::pop_jfloat()
{
    byte_32 byte32;
    byte32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte32._jfloat;
}
jdouble Frame::pop_jdouble()
{
    byte_64 byte64;
    byte64._u4[1] = operandStack->getTop();
    operandStack->pop();
    byte64._u4[0] = operandStack->getTop();
    operandStack->pop();
    return byte64._jdouble;
}
jobject Frame::pop_jobject()
{
    byte_32 byte_32;
    byte_32._u4 = operandStack->getTop();
    operandStack->pop();
    return byte_32._jobject;
}

jint Frame::load_jint(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jint;
}
jbyte Frame::load_jbyte(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jbyte;
}
jboolean Frame::load_jboolean(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jboolean;
}
jchar Frame::load_jchar(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jchar;
}
jshort Frame::load_jshort(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jshort;
}
jfloat Frame::load_jfloat(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jfloat;
}

jlong Frame::load_jlong(u2 shift)
{
    byte_64 byte64;
    byte64._u4[0] = localVars->load(shift);
    byte64._u4[1] = localVars->load(shift + 1);
    return byte64._jlong;
}

jdouble Frame::load_jdouble(u2 shift)
{
    byte_64 byte64;
    byte64._u4[0] = localVars->load(shift);
    byte64._u4[1] = localVars->load(shift + 1);
    return byte64._jdouble;
}
jobject Frame::load_jobject(u2 shift)
{
    byte_32 byte32;
    byte32._u4 = localVars->load(shift);
    return byte32._jobject;
}

void Frame::store_jint(u2 shift, jint a)
{
    byte_32 byte32;
    byte32._jint = a;
    localVars->store(shift, byte32._u4);
}
void Frame::store_jbyte(u2 shift, jbyte a)
{
    byte_32 byte32;
    byte32._jbyte = a;
    localVars->store(shift, byte32._u4);
}
void Frame::store_jboolean(u2 shift, jboolean a)
{
    byte_32 byte32;
    byte32._jboolean = a;
    localVars->store(shift, byte32._u4);
}
void Frame::store_jchar(u2 shift, jchar a)
{
    byte_32 byte32;
    byte32._jchar = a;
    localVars->store(shift, byte32._u4);
}
void Frame::store_jshort(u2 shift, jshort a)
{
    byte_32 byte32;
    byte32._jshort = a;
    localVars->store(shift, byte32._u4);
}
void Frame::store_jfloat(u2 shift, jfloat a)
{
    byte_32 byte32;
    byte32._jfloat = a;
    localVars->store(shift, byte32._u4);
}
void Frame::store_jlong(u2 shift, jlong a)
{
    byte_64 byte64;
    byte64._jlong = a;
    localVars->store(shift, byte64._u4[0]);
    localVars->store(shift + 1, byte64._u4[1]);
}
void Frame::store_jdouble(u2 shift, jdouble a)
{
    byte_64 byte64;
    byte64._jdouble = a;
    localVars->store(shift, byte64._u4[0]);
    localVars->store(shift + 1, byte64._u4[1]);
}
void Frame::store_jobject(u2 shift, jobject a)
{
    byte_32 byte_32;
    byte_32._jobject = a;
    localVars->store(shift, byte_32._u4);
}

Frame::~Frame()
{
    free(localVars);
    free(operandStack);
}