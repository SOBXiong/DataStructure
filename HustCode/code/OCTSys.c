#include <stdio.h>
#include <stdlib.h>
void fromDecimalToOctal(int decimal)
{
    int num[20] = {0};
    int count = 0,remain,i;
    while(1)
    {
        remain = decimal % 8;
        num[count++] = remain;
        decimal /= 8;
        if(decimal == 0)
            break;
    }
    for(i = count-1; i >= 0; i--)
        printf("%d",num[i]);
    printf("\n");
}
int main()
{
    int n;
    while(~scanf("%d",&n))
        fromDecimalToOctal(n);
    return 0;
}
