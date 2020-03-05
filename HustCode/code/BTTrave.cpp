#include <stdio.h>
#include <stdlib.h>
#include <cstring>
int n = 0;
void post(char pre[],char in[],int start,int end){
    if(start > end) return;
    char root = pre[n];
    // 前序中的根后移
    n++;
    int i = start;
    // 找到根在中序中的位置,这样就可以把中序切成两半
    while (in[i] != root && i != end) i++;
    // 后序遍历左孩子
    post(pre,in,start,i - 1);
    // 后序遍历右孩子
    post(pre,in,i + 1,end);
    printf("%c",in[i]);
}
int main(){
    char preOrder[27];
    char inOrder[27];
    while(~scanf("%s\n%s",preOrder,inOrder)){
        if(strlen(preOrder) != strlen(inOrder)) break;
        post(preOrder,inOrder,0,strlen(preOrder) - 1);
        printf("\n");
    }
    return 0;
}