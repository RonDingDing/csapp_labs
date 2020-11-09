#include <stdio.h>
#include <limits.h>

int howManyBits(int x)
{
    int b16, b8, b4, b2, b1, b0;
    int sign = x >> 31;
    x = (sign & ~x) | (~sign & x); //如果x为负则不变，否则按位取反（原来是最高位为0的都变成最高位为1）
    printf("(sign & ~x) | (~sign & x) = %d\n", x);
    // 不断缩小范围
    b16 = !!(x >> 16) << 4; //高十六位是否有0
    x = x >> b16;           //如果有（至少需要16位），则将原数右移16位
    b8 = !!(x >> 8) << 3;   //剩余位高8位是否有0
    x = x >> b8;            //如果有（至少需要16+8=24位），则右移8位
    b4 = !!(x >> 4) << 2;   //同理
    x = x >> b4;
    b2 = !!(x >> 2) << 1;
    x = x >> b2;
    b1 = !!(x >> 1);
    x = x >> b1;
    b0 = x;
    return b16 + b8 + b4 + b2 + b1 + b0 + 1; //+1表示加上符号位
}

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

int main()
{
    unsigned uf = 0x007fffff;
    printf("f    : %d\n", floatFloat2Int(uf));
}