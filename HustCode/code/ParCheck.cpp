#include <stdio.h>
#include <stdlib.h>
#include <cstring>
void calculate(char c){
    int out[8];
    // 得到ASCII码
    int sum = c;
    // 1的个数
    int count = 0;
    int i,remain;
    for (i = 7; i > 0; i--)
    {
        remain = sum % 2;
        if(remain == 1) count++;
        out[i] = remain;
        sum /= 2;
    }
    if(count % 2 == 0) out[0] = 1;
    else out[0] = 0;
    for (i = 0; i < 8; i++) printf("%d",out[i]);
    printf("\n");
}
int main(){
    char input[1001];
    while (~scanf("%s",input))
    {
        int i;
        for (i = 0; i < strlen(input); i++)
        {
            calculate(input[i]);
        }
    }
    return 0;
}