#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0;i < n;i++){
        printf("\n");
        for(j = 0;j < n;j++){
            printf("%d ",a[j][i]);
        }
    }
    return 0;
}