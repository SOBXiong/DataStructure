#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * 编一个程序,输入一个长整型数x,输出小于等于这个数字的所有梅森素数。
 * 梅森数是指形如2^p - 1的一类数字,其中指数p是大于等于2的正整数,通常记为M(p).
 * 如果梅森数是素数,就称之为梅森素数. (40分)
 *
 * 例如: 输入100
 * 输出: M(2) = 3
 *       M(3) = 7
 *       M(5) = 31
 **/
#define TRUE 1
#define FALSE 0
int isPriNum(long data)
{
    long i;
    for (i = 2; i <= sqrt(data); i++)
    {
        if (data % i == 0)
            return FALSE;
    }
    return TRUE;
}
void printMerPriNum(long data)
{
    int i = 2;
    long cur;
    while (TRUE)
    {
        cur = (long)(pow(2, i)) - 1;
        if (cur > data)
            break;
        if (isPriNum(cur))
            printf("M(%d) = %ld\n", i, cur);
        i++;
    }
}
int main()
{
    long x;
    scanf("%ld", &x);
    printMerPriNum(x);
    return 0;
}
