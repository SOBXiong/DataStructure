#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * 孪生素数: 如果n和n+2都是素数，则称它们是孪生素数。
 * 输入m，输出2个均不超过m的最大孪生素数。5<=m<=1000。
 * 例如m = 20时候，答案为17、19。
 **/
#define TRUE 1
#define FALSE 0
// 判断data是否为素数
int judgePrime(int data)
{
    int i;
    for (i = 2; i < sqrt(data); i++)
    {
        if (data % i == 0)
            return FALSE;
    }
    return TRUE;
}
// 将data转为最近的奇数
int toOdd(int data)
{
    if (data % 2 == 0)
        return data - 1;
    return data;
}
int main()
{
    int m, i;
    scanf("%d", &m);
    for (i = toOdd(m); i >= 3; i -= 2)
    {
        if (judgePrime(i) && judgePrime(i - 2))
        {
            printf("twin prime number: %d %d\n", i, i - 2);
            break;
        }
    }
    return 0;
}
