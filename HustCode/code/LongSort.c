#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *p1,const void *p2){
    // p1,p2均为字符串数组的首地址
    // 直接赋值为(char*)p是不行的
    char *pStr1 = *(char**)p1;
    char *pStr2 = *(char**)p2;
    int lStr1 = strlen(pStr1);
    int lStr2 = strlen(pStr2);
    // 长度不同,返回长的那段
    if(lStr1 != lStr2) return lStr1 - lStr2;
    // 根据ASCII码比大小
    return strcmp(pStr1,pStr2);
}
int main(){
    int i,n;
    while(~scanf("%d",&n)){
        char **datas = (char**)malloc(sizeof(char*)*n);
        for(i = 0;i < n;i++){
            datas[i] = (char*)malloc(sizeof(char)*1000);
            scanf("%s",datas[i]);
        }
        // 此处不能写sizeof(char) * 1000
        // 是因为字符串数组比较传递的是首地址,不是整个数组
        qsort(datas,n,sizeof(char*),compare);
        for(i = 0;i < n;i++)
            printf("%s\n",datas[i]);
        // 释放内存,不然多次进入,会泄漏大量
        for(i = n - 1;i >= 0;i--)
            free(datas[i]);
        free(datas);
    }
    return 0;
}
