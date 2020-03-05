#include <stdio.h>
#include <stdlib.h>

void count(char *str){
    int i;
    int hasWhite = 0;
    int currentCount = 0;
    for(i = 0;;i++){
        // 到结尾
        char c = str[i];
        if (c == '.' || c == '\0'){
            if(currentCount != 0){
                printf("%d ",currentCount);
            }
            break;
        }else if(c == ' '){ // 为空格
            // 之前没有空格,开始复原
            if (hasWhite == 0)
            {
                if(currentCount != 0){
                    printf("%d ",currentCount);
                }
                currentCount = 0;
                hasWhite = 1;
            }
            // 之间有空格,不做变化
        }else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){ // 是字符
            // 将空格置空
            hasWhite = 0;
            currentCount++;
        }else{ // 不然报错

        }
    }
}

int main(){
    char str[100];
    // gets()遇到回车结束,scanf()遇到空格或者回车才结束
    gets(str);
    str[99] = '\0';
    count(str);
    return 0;
}