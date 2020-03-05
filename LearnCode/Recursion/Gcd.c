#include <stdio.h>
#include <stdlib.h>
/**
 * gcd: greatest common divisor -> 最大公约数
 * 辗转相除法,又名欧几里德法
 **/
int gcd(int a, int b)
{
    // 如果余数为0,直接返回a
    if (b == 0)
    {
        return a;
    }
    else
    {
        // 得到余数
        int r = a % b;
        // 递归调用
        return gcd(b, r);
    }
}
int main()
{
    printf("%d",gcd(100, 45));
    return 0;
}