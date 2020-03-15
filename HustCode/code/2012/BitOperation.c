#include <stdio.h>
#include <stdlib.h>
/**
 * (1)输入一个无符号长整数，将最高字节与最低字节互换，然后再输出。
 * (2)将这个长整数中间两个字节循环左移n位(n要输入)，然后再输出。
 * (3)将长整数按照二进制输出，每8位输出一个空格
 **/
void transformHighAndLow(unsigned long *data)
{
    unsigned high, low;
    // 得到高8bit
    high = *data >> 24;
    // 得到低8bit
    low = *data << 24;
    // printf("high -> %x , low -> %x\n",high,low);
    // 与0x00FFFF00中间24bit,或high、low高低8bit
    *data = *data & 0x00FFFF00 | high | low;
    printf("%lx\n", *data);
}
void leftMove(unsigned long *data, int bit)
{
    unsigned mid = *data & 0x00FFFF00;
    // 得到除去中间的部分
    *data = *data & 0xFF0000FF;
    mid = mid << bit;
    // 中间部分+移位后的部分
    *data = mid + *data;
    printf("%lx\n", *data);
}
void printBinary(unsigned long data)
{
    int bit[32], i;
    for (i = 0; i < 32; i++)
    {
        bit[i] = data % 2;
        data /= 2;
    }
    for (i = 31; i >= 0; i--)
    {
        printf("%d", bit[i]);
        if (i != 31 && (32 - i) % 8 == 0)
            printf(" ");
    }
}
int main()
{
    // 32bit
    unsigned long data;
    scanf("%lx", &data);
    transformHighAndLow(&data);
    int bit;
    scanf("%d", &bit);
    leftMove(&data, bit);
    printBinary(data);
    return 0;
}
