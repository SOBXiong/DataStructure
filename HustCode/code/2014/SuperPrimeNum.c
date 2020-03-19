#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * 要求: 编程找出所有的4位超级素数.
 *       每行输出6个数,两个数之间空格分隔.
 * 超级素数: 一个n位超级素数是指一个n位正整数,
 *           它的前1位,前2位,...,前n位数均为素数.
 *           例如,2333是个4位超级素数,因为2,23,233,
 *           2333均为素数.
 **/
#define TRUE 1
#define FALSE 0
int isPrimeNum(int data)
{
    int i;
    for (i = 2; i <= sqrt(data); i++)
    {
        if (data % i == 0)
            return FALSE;
    }
    return TRUE;
}
int isSuperPrimeNum(int data)
{
    int i;
    for (i = data; i > 0; i /= 10)
    {
        if (!isPrimeNum(i))
            return FALSE;
    }
    return TRUE;
}
int main()
{
    int i, count = 0;
    for (i = 1000; i < 10000; i++)
    {
        if (isSuperPrimeNum(i))
        {
            printf("%d ", i);
            count++;
            if (count % 6 == 0)
                printf("\n");
        }
    }
    return 0;
}
