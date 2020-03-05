#include <stdio.h>
#include <stdlib.h>
int main(){
    char str[20] = {'\0'};
    gets(str);
    int i;
    int current = -1;
    int count = 0;
    for(i = 0; ;i++){
        if(str[i] != '\0'){
            // 不是'.',那必为数字
            if(str[i] != '.'){
                // 未被标志过
                if(current == -1){
                    current = str[i] - '0';
                } 
                else{ // 标志过,那么累加位数
                    current = current * 10 + str[i] - '0';
                }
            }else{ // 为'.'
                // 直接遇到标志位
                if(current == -1) {
                    printf("No!\n");
                    break;
                }else{ 
                    // 如果数字不符合
                    if(current < 0 || current > 255){
                        printf("No!\n");
                        break;
                    }else{
                        count++;
                        // 重置位数
                        current = -1;
                    }
                }
            }
        } 
        else { // 走到最后
            // 如果数字不符合
            if(current < 0 || current > 255){
                printf("No!\n");
                break;
            }else{
                count++;
            }
            count == 4 ? printf("Yes!\n") : printf("No!\n");
            break;
        }
    }
    return 0;
}