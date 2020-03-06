#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int turnStrToInt(char *in){
    int length = strlen(in);
    int i,base = 1,count = 0,sum = 0;
    for(i = length - 1;i >= 0;i--){
        if(in[i] == ',') continue;
        else if(in[i] >= '0' && in[i] <= '9'){
            int num = in[i] - '0';
            sum += num * base;
            base *= 10;
            count++;
        }else if(in[i] == '-'){
            sum *= -1;
        }else{
            exit(0);
        }
    }
    return sum;
}
int main(){
    char a[20],b[20];
    while(~(scanf("%s %s",a,b))){
        printf("%d\n",turnStrToInt(a) + turnStrToInt(b));
    }
    return 0;
}
