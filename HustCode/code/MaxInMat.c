#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,i,j;
    while(~scanf("%d %d",&m,&n)){
        int** a = (int **)malloc(sizeof(int*) * m);
        for(i = 0;i < m;i++){
            a[i] = (int *)malloc(sizeof(int) * n);
            int maxValue,maxIndex = -1,sum = 0;
            for(j = 0;j < n;j++){
                scanf("%d",&a[i][j]);
                if(maxIndex == -1){
                    maxIndex = j;
                    maxValue = a[i][j];
                }else{
                    if(a[i][j] > maxValue){
                        maxIndex = j;
                        maxValue = a[i][j];
                    }
                }
                sum += a[i][j];
            }
            a[i][maxIndex] = sum;
        }
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        for(i = m - 1;i >= 0;i--){
            free(a[i]);
        }
        free(a);
    }
    return 0;
}
