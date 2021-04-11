#pragma once
#include"classfile/classfile.h"

const u1 nop = (u1)0x00; //	什么都不做
const u1 aconst_null = (u1)0x01; //	将null推送至栈顶
const u1 iconst_m1 = (u1)0x02; //	将int型-1推送至栈顶
const u1 iconst_0 = (u1)0x03; //	将int型0推送至栈顶
const u1 iconst_1 = (u1)0x04; //	将int型1推送至栈顶
const u1 iconst_2 = (u1)0x05; //	将int型2推送至栈顶
const u1 iconst_3 = (u1)0x06; //	将int型3推送至栈顶
const u1 iconst_4 = (u1)0x07; //	将int型4推送至栈顶
const u1 iconst_5 = (u1)0x08; //	将int型5推送至栈顶
const u1 lconst_0 = (u1)0x09; //	将long型0推送至栈顶
const u1 lconst_1 = (u1)0x0a; //	将long型1推送至栈顶
const u1 fconst_0 = (u1)0x0b; //	将float型0推送至栈顶
const u1 fconst_1 = (u1)0x0c; //	将float型1推送至栈顶
const u1 fconst_2 = (u1)0x0d; //	将float型2推送至栈顶
const u1 dconst_0 = (u1)0x0e; //	将do le型0推送至栈顶
const u1 dconst_1 = (u1)0x0f; //	将do le型1推送至栈顶
const u1 bipush = (u1)0x10; //	将单字节的常量值(-128~127)推送至栈顶
const u1 sipush = (u1)0x11; //	将一个短整型常量值(-32768~32767)推送至栈顶
const u1 ldc = (u1)0x12; //	将int, float或String型常量值从常量池中推送至栈顶
const u1 ldc_w = (u1)0x13; //	将int, float或String型常量值从常量池中推送至栈顶（宽索引）
const u1 ldc2_w = (u1)0x14; //	将long或do le型常量值从常量池中推送至栈顶（宽索引）
const u1 iload = (u1)0x15; //	将指定的int型本地变量
const u1 lload = (u1)0x16; //	将指定的long型本地变量
const u1 fload = (u1)0x17; //	将指定的float型本地变量
const u1 dload = (u1)0x18; //	将指定的do le型本地变量
const u1 aload = (u1)0x19; //	将指定的引用类型本地变量
const u1 iload_0 = (u1)0x1a; //	将第一个int型本地变量
const u1 iload_1 = (u1)0x1b; //	将第二个int型本地变量
const u1 iload_2 = (u1)0x1c; //	将第三个int型本地变量
const u1 iload_3 = (u1)0x1d; //	将第四个int型本地变量
const u1 lload_0 = (u1)0x1e; //	将第一个long型本地变量
const u1 lload_1 = (u1)0x1f; //	将第二个long型本地变量
const u1 lload_2 = (u1)0x20; //	将第三个long型本地变量
const u1 lload_3 = (u1)0x21; //	将第四个long型本地变量
const u1 fload_0 = (u1)0x22; //	将第一个float型本地变量
const u1 fload_1 = (u1)0x23; //	将第二个float型本地变量
const u1 fload_2 = (u1)0x24; //	将第三个float型本地变量
const u1 fload_3 = (u1)0x25; //	将第四个float型本地变量
const u1 dload_0 = (u1)0x26; //	将第一个do le型本地变量
const u1 dload_1 = (u1)0x27; //	将第二个do le型本地变量
const u1 dload_2 = (u1)0x28; //	将第三个do le型本地变量
const u1 dload_3 = (u1)0x29; //	将第四个do le型本地变量
const u1 aload_0 = (u1)0x2a; //	将第一个引用类型本地变量
const u1 aload_1 = (u1)0x2b; //	将第二个引用类型本地变量
const u1 aload_2 = (u1)0x2c; //	将第三个引用类型本地变量
const u1 aload_3 = (u1)0x2d; //	将第四个引用类型本地变量
const u1 iaload = (u1)0x2e; //	将int型数组指定索引的值推送至栈顶
const u1 laload = (u1)0x2f; //	将long型数组指定索引的值推送至栈顶
const u1 faload = (u1)0x30; //	将float型数组指定索引的值推送至栈顶
const u1 daload = (u1)0x31; //	将do le型数组指定索引的值推送至栈顶
const u1 aaload = (u1)0x32; //	将引用型数组指定索引的值推送至栈顶
const u1 baload = (u1)0x33; //	将boolean或byte型数组指定索引的值推送至栈顶
const u1 caload = (u1)0x34; //	将char型数组指定索引的值推送至栈顶
const u1 saload = (u1)0x35; //	将short型数组指定索引的值推送至栈顶
const u1 istore = (u1)0x36; //	将栈顶int型数值存入指定本地变量
const u1 lstore = (u1)0x37; //	将栈顶long型数值存入指定本地变量
const u1 fstore = (u1)0x38; //	将栈顶float型数值存入指定本地变量
const u1 dstore = (u1)0x39; //	将栈顶do le型数值存入指定本地变量
const u1 astore = (u1)0x3a; //	将栈顶引用型数值存入指定本地变量
const u1 istore_0 = (u1)0x3b; //	将栈顶int型数值存入第一个本地变量
const u1 istore_1 = (u1)0x3c; //	将栈顶int型数值存入第二个本地变量
const u1 istore_2 = (u1)0x3d; //	将栈顶int型数值存入第三个本地变量
const u1 istore_3 = (u1)0x3e; //	将栈顶int型数值存入第四个本地变量
const u1 lstore_0 = (u1)0x3f; //	将栈顶long型数值存入第一个本地变量
const u1 lstore_1 = (u1)0x40; //	将栈顶long型数值存入第二个本地变量
const u1 lstore_2 = (u1)0x41; //	将栈顶long型数值存入第三个本地变量
const u1 lstore_3 = (u1)0x42; //	将栈顶long型数值存入第四个本地变量
const u1 fstore_0 = (u1)0x43; //	将栈顶float型数值存入第一个本地变量
const u1 fstore_1 = (u1)0x44; //	将栈顶float型数值存入第二个本地变量
const u1 fstore_2 = (u1)0x45; //	将栈顶float型数值存入第三个本地变量
const u1 fstore_3 = (u1)0x46; //	将栈顶float型数值存入第四个本地变量
const u1 dstore_0 = (u1)0x47; //	将栈顶do le型数值存入第一个本地变量
const u1 dstore_1 = (u1)0x48; //	将栈顶do le型数值存入第二个本地变量
const u1 dstore_2 = (u1)0x49; //	将栈顶do le型数值存入第三个本地变量
const u1 dstore_3 = (u1)0x4a; //	将栈顶do le型数值存入第四个本地变量
const u1 astore_0 = (u1)0x4b; //	将栈顶引用型数值存入第一个本地变量
const u1 astore_1 = (u1)0x4c; //	将栈顶引用型数值存入第二个本地变量
const u1 astore_2 = (u1)0x4d; //	将栈顶引用型数值存入第三个本地变量
const u1 astore_3 = (u1)0x4e; //	将栈顶引用型数值存入第四个本地变量
const u1 iastore = (u1)0x4f; //	将栈顶int型数值存入指定数组的指定索引位置
const u1 lastore = (u1)0x50; //	将栈顶long型数值存入指定数组的指定索引位置
const u1 fastore = (u1)0x51; //	将栈顶float型数值存入指定数组的指定索引位置
const u1 dastore = (u1)0x52; //	将栈顶do le型数值存入指定数组的指定索引位置
const u1 aastore = (u1)0x53; //	将栈顶引用型数值存入指定数组的指定索引位置
const u1 bastore = (u1)0x54; //	将栈顶boolean或byte型数值存入指定数组的指定索引位置
const u1 castore = (u1)0x55; //	将栈顶char型数值存入指定数组的指定索引位置
const u1 sastore = (u1)0x56; //	将栈顶short型数值存入指定数组的指定索引位置
const u1 pop = (u1)0x57; //	将栈顶数值弹出 (数值不能是long或do le类型的)
const u1 pop2 = (u1)0x58; //	将栈顶的一个（long或do le类型的)或两个数值弹出（其它）
const u1 dup_ = (u1)0x59; //	复制栈顶数值并将复制值压入栈顶
const u1 dup_x1 = (u1)0x5a; //	复制栈顶数值并将两个复制值压入栈顶
const u1 dup_x2 = (u1)0x5b; //	复制栈顶数值并将三个（或两个）复制值压入栈顶
const u1 dup2_ = (u1)0x5c; //	复制栈顶一个（long或do le类型的)或两个（其它）数值并将复制值压入栈顶
const u1 dup2_x1 = (u1)0x5d; //	dup_x1 指令的双倍版本
const u1 dup2_x2 = (u1)0x5e; //	dup_x2 指令的双倍版本
const u1 swap_ = (u1)0x5f; //	将栈最顶端的两个数值互换(数值不能是long或do le类型的)
const u1 iadd = (u1)0x60; //	将栈顶两int型数值相加并将结果压入栈顶
const u1 ladd = (u1)0x61; //	将栈顶两long型数值相加并将结果压入栈顶
const u1 fadd = (u1)0x62; //	将栈顶两float型数值相加并将结果压入栈顶
const u1 dadd = (u1)0x63; //	将栈顶两do le型数值相加并将结果压入栈顶
const u1 is = (u1)0x64; //	将栈顶两int型数值相减并将结果压入栈顶
const u1 ls = (u1)0x65; //	将栈顶两long型数值相减并将结果压入栈顶
const u1 fs = (u1)0x66; //	将栈顶两float型数值相减并将结果压入栈顶
const u1 ds = (u1)0x67; //	将栈顶两do le型数值相减并将结果压入栈顶
const u1 imul = (u1)0x68; //	将栈顶两int型数值相乘并将结果压入栈顶
const u1 lmul = (u1)0x69; //	将栈顶两long型数值相乘并将结果压入栈顶
const u1 fmul = (u1)0x6a; //	将栈顶两float型数值相乘并将结果压入栈顶
const u1 dmul = (u1)0x6b; //	将栈顶两do le型数值相乘并将结果压入栈顶
const u1 idiv = (u1)0x6c; //	将栈顶两int型数值相除并将结果压入栈顶
const u1 ldiv_ = (u1)0x6d; //	将栈顶两long型数值相除并将结果压入栈顶
const u1 fdiv = (u1)0x6e; //	将栈顶两float型数值相除并将结果压入栈顶
const u1 ddiv = (u1)0x6f; //	将栈顶两do le型数值相除并将结果压入栈顶
const u1 irem = (u1)0x70; //	将栈顶两int型数值作取模运算并将结果压入栈顶
const u1 lrem = (u1)0x71; //	将栈顶两long型数值作取模运算并将结果压入栈顶
const u1 frem = (u1)0x72; //	将栈顶两float型数值作取模运算并将结果压入栈顶
const u1 drem = (u1)0x73; //	将栈顶两do le型数值作取模运算并将结果压入栈顶
const u1 ineg = (u1)0x74; //	将栈顶int型数值取负并将结果压入栈顶
const u1 lneg = (u1)0x75; //	将栈顶long型数值取负并将结果压入栈顶
const u1 fneg = (u1)0x76; //	将栈顶float型数值取负并将结果压入栈顶
const u1 dneg = (u1)0x77; //	将栈顶do le型数值取负并将结果压入栈顶
const u1 ishl = (u1)0x78; //	将int型数值左移位指定位数并将结果压入栈顶
const u1 lshl = (u1)0x79; //	将long型数值左移位指定位数并将结果压入栈顶
const u1 ishr = (u1)0x7a; //	将int型数值右（符号）移位指定位数并将结果压入栈顶
const u1 lshr = (u1)0x7b; //	将long型数值右（符号）移位指定位数并将结果压入栈顶
const u1 iushr = (u1)0x7c; //	将int型数值右（无符号）移位指定位数并将结果压入栈顶
const u1 lushr = (u1)0x7d; //	将long型数值右（无符号）移位指定位数并将结果压入栈顶
const u1 iand = (u1)0x7e; //	将栈顶两int型数值作“按位与”并将结果压入栈顶
const u1 land = (u1)0x7f; //	将栈顶两long型数值作“按位与”并将结果压入栈顶
const u1 ior = (u1)0x80; //	将栈顶两int型数值作“按位或”并将结果压入栈顶
const u1 lor = (u1)0x81; //	将栈顶两long型数值作“按位或”并将结果压入栈顶
const u1 ixor = (u1)0x82; //	将栈顶两int型数值作“按位异或”并将结果压入栈顶
const u1 lxor = (u1)0x83; //	将栈顶两long型数值作“按位异或”并将结果压入栈顶
const u1 iinc = (u1)0x84; //	将指定int型变量增加指定值（i++, i–, i+=2）
const u1 i2l = (u1)0x85; //	将栈顶int型数值强制转换成long型数值并将结果压入栈顶
const u1 i2f = (u1)0x86; //	将栈顶int型数值强制转换成float型数值并将结果压入栈顶
const u1 i2d = (u1)0x87; //	将栈顶int型数值强制转换成doule型数值并将结果压入栈顶
const u1 l2i = (u1)0x88; //	将栈顶long型数值强制转换成int型数值并将结果压入栈顶
const u1 l2f = (u1)0x89; //	将栈顶long型数值强制转换成float型数值并将结果压入栈顶
const u1 l2d = (u1)0x8a; //	将栈顶long型数值强制转换成doule型数值并将结果压入栈顶
const u1 f2i = (u1)0x8b; //	将栈顶float型数值强制转换成int型数值并将结果压入栈顶
const u1 f2l = (u1)0x8c; //	将栈顶float型数值强制转换成long型数值并将结果压入栈顶
const u1 f2d = (u1)0x8d; //	将栈顶float型数值强制转换成doule型数值并将结果压入栈顶
const u1 d2i = (u1)0x8e; //	将栈顶do le型数值强制转换成int型数值并将结果压入栈顶
const u1 d2l = (u1)0x8f; //	将栈顶do le型数值强制转换成long型数值并将结果压入栈顶
const u1 d2f = (u1)0x90; //	将栈顶do le型数值强制转换成float型数值并将结果压入栈顶
const u1 i2b = (u1)0x91; //	将栈顶int型数值强制转换成byte型数值并将结果压入栈顶
const u1 i2c = (u1)0x92; //	将栈顶int型数值强制转换成char型数值并将结果压入栈顶
const u1 i2s = (u1)0x93; //	将栈顶int型数值强制转换成short型数值并将结果压入栈顶
const u1 lcmp = (u1)0x94; //	比较栈顶两long型数值大小，并将结果（1，0，-1）压入栈顶
const u1 fcmpl = (u1)0x95; //	比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶
const u1 fcmpg = (u1)0x96; //	比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶
const u1 dcmpl = (u1)0x97; //	比较栈顶两do le型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶
const u1 dcmpg = (u1)0x98; //	比较栈顶两do le型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶
const u1 ifeq = (u1)0x99; //	当栈顶int型数值等于0时跳转
const u1 ifne = (u1)0x9a; //	当栈顶int型数值不等于0时跳转
const u1 iflt = (u1)0x9b; //	当栈顶int型数值小于0时跳转
const u1 ifge = (u1)0x9c; //	当栈顶int型数值大于等于0时跳转
const u1 ifgt = (u1)0x9d; //	当栈顶int型数值大于0时跳转
const u1 ifle = (u1)0x9e; //	当栈顶int型数值小于等于0时跳转
const u1 if_icmpeq = (u1)0x9f; //	比较栈顶两int型数值大小，当结果等于0时跳转
const u1 if_icmpne = (u1)0xa0; //	比较栈顶两int型数值大小，当结果不等于0时跳转
const u1 if_icmplt = (u1)0xa1; //	比较栈顶两int型数值大小，当结果小于0时跳转
const u1 if_icmpge = (u1)0xa2; //	比较栈顶两int型数值大小，当结果大于等于0时跳转
const u1 if_icmpgt = (u1)0xa3; //	比较栈顶两int型数值大小，当结果大于0时跳转
const u1 if_icmple = (u1)0xa4; //	比较栈顶两int型数值大小，当结果小于等于0时跳转
const u1 if_acmpeq = (u1)0xa5; //	比较栈顶两引用型数值，当结果相等时跳转
const u1 if_acmpne = (u1)0xa6; //	比较栈顶两引用型数值，当结果不相等时跳转
const u1 goto_ = (u1)0xa7; //	无条件跳转
const u1 jsr = (u1)0xa8; //	跳转至指定16位offset位置，并将jsr下一条指令地址压入栈顶
const u1 ret = (u1)0xa9; //	返回至本地变量
const u1 tableswitch = (u1)0xaa; //	用于switch条件跳转，case值连续（可变长度指令）
const u1 lookupswitch = (u1)0xab; //	用于switch条件跳转，case值不连续（可变长度指令）
const u1 ireturn = (u1)0xac; //	从当前方法返回int
const u1 lreturn = (u1)0xad; //	从当前方法返回long
const u1 freturn = (u1)0xae; //	从当前方法返回float
const u1 dreturn = (u1)0xaf; //	从当前方法返回do le
const u1 areturn = (u1)0xb0; //	从当前方法返回对象引用
const u1 return_ = (u1)0xb1; //	从当前方法返回void
const u1 getstatic = (u1)0xb2; //	获取指定类的静态域，并将其值压入栈顶
const u1 putstatic = (u1)0xb3; //	为指定的类的静态域赋值
const u1 getfield = (u1)0xb4; //	获取指定类的实例域，并将其值压入栈顶
const u1 putfield = (u1)0xb5; //	为指定的类的实例域赋值
const u1 invokevirtual = (u1)0xb6; //	调用实例方法
const u1 invokespecial = (u1)0xb7; //	调用超类构造方法，实例初始化方法，私有方法
const u1 invokestatic = (u1)0xb8; //	调用静态方法
const u1 invokeinterface = (u1)0xb9; //	调用接口方法
const u1 invokedynamic = (u1)0xba; //	调用动态方法
const u1 new_ = (u1)0xbb; //	创建一个对象，并将其引用值压入栈顶
const u1 newarray = (u1)0xbc; //	创建一个指定原始类型（如int, float, char…）的数组，并将其引用值压入栈顶
const u1 anewarray = (u1)0xbd; //	创建一个引用型（如类，接口，数组）的数组，并将其引用值压入栈顶
const u1 arraylength = (u1)0xbe; //	获得数组的长度值并压入栈顶
const u1 athrow = (u1)0xbf; //	将栈顶的异常抛出
const u1 checkcast = (u1)0xc0; //	检验类型转换，检验未通过将抛出ClassCastException
const u1 instanceof = (u1)0xc1; //	检验对象是否是指定的类的实例，如果是将1压入栈顶，否则将0压入栈顶
const u1 monitorenter = (u1)0xc2; //	获得对象的锁，用于同步方法或同步块
const u1 monitorexit = (u1)0xc3; //	释放对象的锁，用于同步方法或同步块
const u1 wide = (u1)0xc4; //	<待补充>
const u1 multianewarray = (u1)0xc5; //	创建指定类型和指定维度的多维数组（执行该指令时，操作栈中必须包含各维度的长度值），并将其引用值压入栈顶
const u1 ifnull = (u1)0xc6; //	为null时跳转
const u1 ifnonnull = (u1)0xc7; //	不为null时跳转
const u1 goto_w = (u1)0xc8; //	无条件跳转（宽索引）
const u1 jsr_w = (u1)0xc9; //   跳转至指定32位offset位置，并将jsr_w下一条指令地址压入栈顶