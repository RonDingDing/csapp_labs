/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    return (~(x & y)) & (~((~x) & (~y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    // 因为题目默认32位，所以左移 31 位
    return 0x1 << 31;
} //2
/*
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    // 0x 7f 是 0b 0111 1111，因为题目默认 32 位，所以左移 32 - 8 位得到 0111 1111 ……，然后若 z ^ y = 0，z = y，取逻辑 ! 值得到 1 。
    return !(x ^ 0x7fffffff);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    // 奇数位都是1，最右一位为第0位，单看最后四位，得 x & 1010 == 1010，然后若 z ^ y = 0，z = y，取逻辑 ! 值得到 1 。
    return !(0xAAAAAAAA ^ (x & 0xAAAAAAAA));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
    // 0x30到0x39的数x满足，x-0x30的符号位为0，0x39-x的符号位为0
    int sign = 1 << 31;
    int lower = !((x + ~0x30 + 1) & sign);
    int upper = !((0x39 + ~x + 1) & sign);
    return lower & upper;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    // 若 x == 0，mask =  0；即 0000 0000 ……，相反数 dusk 为 1111 1111 ……， (y & mask) | (z & task) = (y & -1) | (z & 0) = y;
    // 若 x != 0，mask = -1；即 1111 1111 ……，相反数 dusk 为 0000 0000 ……， (y & mask) | (z & task) = (y & 0) | (z & -1) = z;
    int mask = ~(!!x) + 1;
    int dusk = ~mask;
    return (y & mask) | (z & dusk);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    int x_sign = (x & (1 << 31)) >> 31;
    int y_sign = (y & (1 << 31)) >> 31;
    int diff_sign = !!(x_sign ^ y_sign);
    int same_sign = !(x_sign ^ y_sign);
    int y_minus_x = y + ~x + 1;
    int y_minus_x_greater_0 = !(y_minus_x >> 31);
    int x_equals_y = !(x ^ y);
    // 不同符号时，x 为负；同符号时，y - x 为正或 x ^ y == 0
    return (diff_sign & x_sign & 1) | (same_sign & (y_minus_x_greater_0 | x_equals_y));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x)
{
    // 非零值 | 自身的相反数，会得到全 1 的结果，+ 1 会得 0；零值 | 自身的相反数，会得 0， + 1 得 1；
    int minus = ~x + 1;
    int have = x | minus;
    return (have >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    int sign = x >> 31;
    x = (sign & ~x) | (~sign & x); //如果x为负则不变，否则按位取反（原来是最高位为0的都变成最高位为1）
    // 不断缩小范围
    int b16 = !!(x >> 16) << 4; //高十六位是否有0
    x = x >> b16;               //如果有（至少需要16位），则将原数右移16位
    int b8 = !!(x >> 8) << 3;   //剩余位高8位是否有0
    x = x >> b8;                //如果有（至少需要16+8=24位），则右移8位
    int b4 = !!(x >> 4) << 2;   //同理
    x = x >> b4;
    int b2 = !!(x >> 2) << 1;
    x = x >> b2;
    int b1 = !!(x >> 1);
    x = x >> b1;
    int b0 = x;
    return b16 + b8 + b4 + b2 + b1 + b0 + 1; //+1表示加上符号位
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
    int sign_inplace = uf & (1 << 31); // 符号位
    int exp = (uf & 0x7f800000) >> 23; // 0b 0111 1111 1000 0000 0000 0000 0000 0000 根据IEEE浮点数定义获得 exp 八位
    if (exp == 0)
    {
        return uf << 1 | sign_inplace; // 无穷小（非规格化），左移保留符号即可。
    }
    if (exp == 0xff)
    {
        return uf;
    }                      // 无穷大或 Nan，返回本身
    int new_exp = exp + 1; // 规格化，exp + 1 代表 * 2
    if (new_exp == 0xff)
    {
        return 0x7f800000 | sign_inplace; // 若此时 new_exp 全为 1，返回带符号的无穷大
    }

    return (uf & 0x807fffff) | (new_exp << 23); // 0b 1000 0000 0111 1111 1111 1111 1111 1111 挖空原来的 exp，填入 new_exp
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    // 这题只需考虑规格化即可，非规格化都小于 1。
    int sign = uf & (1 << 31);
    int E = ((uf & 0x7f800000) >> 23) - 127; // 取 E = e - bias，bias 为 127
    // 越界
    if (E > 31)
        return 0x80000000;
    if (E < 0)
        return 0;
    int M = (uf & 0x007fffff) | 0x00800000; // M = 1 + f
    int f = (E > 23) ? (M << (E - 23)) : (M >> (23 - E));
    return sign ? -f : f;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    // 非规格化 E = 1 - bias = 1 - 127 = -126 小于这个数不行
    // 规格化 E 最大值为 255 否则就是无穷了
    int exp = x + 127;
    if (exp <= 0)
    {
        return 0;
    }
    else if (exp >= 255)
    {
        return 0x7f800000; // INF
    }
    return exp << 23;
}
