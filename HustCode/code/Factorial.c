#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
{
    if(n == 1)
        return 1;
    else
        return n * factorial(n-1);
}
int factorialSum(int n)
{
    int i,sum = 0;
    for(i = n; i >= 1; i-=2)
        sum += factorial(i);
    return sum;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n % 2 == 0)
            printf("%d %d\n",factorialSum(n-1),factorialSum(n));
        else
            printf("%d %d\n",factorialSum(n),factorialSum(n-1));
    }
    return 0;
}
