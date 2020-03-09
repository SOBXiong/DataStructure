#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPaStr(char data[]){
    int strLen = strlen(data);
    // 偶数长度
    if(strLen % 2 == 0){
        int i,mid = strLen / 2;
        for(i = 0;i <= mid;i++){
            if(data[mid-i-1] != data[mid+i]) return 0;
        }
    }else{ // 奇数长度
        int i,mid = strLen / 2;
        for(i = 1;i < mid;i++){
            if(data[mid-i] != data[mid+i]) return 0;
        }
    }
    return 1;
}
int main(){
    char data[1000];
    while(~scanf("%s",data)){
        printf("%s\n",isPaStr(data) ? "Yes!" : "No!");
    }
    return 0;
}
