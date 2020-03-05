#include <stdio.h>
#include <stdlib.h>

// 此题留有疑问
int main()
{
    int mat[4][5];
    while(1){
        int i,j;
        int flg=0;
        // input matrix
        for(i=0;i<4;i++){
            for(j=0;j<5;j++){
                if(scanf("%d", &mat[i][j])==EOF)
                    flg = 1;
            }
        }
        if(flg==1){
            break;
        }
        // sort
        for(i=0;i<5;++i){
            for(j=2;j<4;++j){
                if(mat[j][i] > mat[1][i]){
                    if(mat[1][i] > mat[0][i]){
                        mat[0][i] = mat[1][i];
                    }
                    mat[1][i] = mat[j][i];
                }
                else if(mat[j][i] > mat[0][i]){
                    if (mat[1][i] > mat[0][i]){
                        mat[0][i] = mat[1][i];
                    }
                    mat[1][i] = mat[j][i];
                }
            }
        }
        for(i=0;i<2;i++){
            for(j=0;j<5;j++){
                printf("%d", mat[i][j]);
                if(j==4)
                    printf("\n");
                else
                    printf(" ");
            }
        }
    }
    return 0;
}