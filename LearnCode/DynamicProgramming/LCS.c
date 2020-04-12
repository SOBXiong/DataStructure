#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @description: Longest Common Subsequence最长公共子序列问题
 *               子序列:
 *                  设序列X,Z,X=<x1,x2,...,xm> Z=<z1,z2,...,zk>
 *                  若存在X的元素构成的严格递增序列使得
 *                  zj=x[ij],j=1,2,...,k
 *                  则称Z是X的子序列
 *               最长公告子序列问题:
 *                  给定序列X=<x1,x2,...,xm> Y=<y1,y2,...,yn>
 *                  求X和Y的最长公共子序列(可能多个,只需要求出一个即可)
 * 
 * @method: 子问题间的依赖关系:
 *          设X=<x1,x2,...,xm> Y=<y1,y2,...,yn>
 *          Z=<z1,z2,...,zk>为X和Y的LCS,那么
 *          (1)若xm=yn => zk=xm=yn,且
 *              z[k-1]是X[m-1]与Y[n-1]的LCS;
 *          (2)若xm!=yn,zk!=xm => 
 *              Z是X[m-1]与Y的LCS;
 *          (3)若xm!=yn,zk!=yn => 
 *              Z是X与Y[n-1]的LCS.
 *          满足优化原则和子问题重叠性
 * 
 *          递推方程: 
 *              令X与Y的子序列Xi=<x1,x2,...,xi> Yj=<y1,y2,...,yj>
 *              C[i,j]: Xi与Yj的LCS的长度
 *              当i=0或j=0时,C[i,j]=0
 *              当i,j>0,xi = yj时,C[i,j]=C[i-1,j-1]+1
 *              当i,j>0,xi != yj时,C[i,j]=max{C[i,j-1], C[i-1,j]}
 * 
 *          标记函数:
 *              B[i,j],值为↖、←、↑
 *              C[i,j]=C[i-1,j-1]+1 对应 ↖
 *              C[i,j]=C[i,j-1] 对应 ←
 *              C[i,j]=C[i-1,j] 对应 ↑
 *          
 *          时间复杂度: Θ(mn)
 *          空间复杂度: Θ(mn)
 * 
 * @pseudocode: 算法LCS(X,Y,m,n)
 *              for i <- 1 to m do C[i,0] <- 0
 *              for i <- 1 to n do C[0,i] <- 0
 *              for i <- 1 to m do
 *                  for j <- 1 to n do
 *                      if X[i]=Y[j]
 *                      then C[i,j] <- C[i-1,j-1]+1
 *                           B[i,j] <- '↖'
 *                      else if C[i-1,j] >= C[i,j-1]
 *                           then C[i,j] <- C[i-1,j]
 *                                B[i,j] <- '↑'
 *                           else C[i,j] <- C[i,j-1]
 *                                B[i,j] <- '←'
 * 
 *              追踪解算法 Structure Sequence(B,i,j)
 *              输入:B[i,j]
 *              输出:X与Y的最长公共子序列
 *              if i=0 or j=0 then return //序列为空
 *              if B[i,j] = '↖'
 *              then 输出X[i]
 *                   Structure Sequence(B,i-1,j-1)
 *              else if B[i,j] = '↑'
 *                   then Structure Sequence(B,i-1,j)
 *                   else Structure Sequence(B,i,j-1)
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=42
 **/
#define TRUE 1
void SearchTrace(char *s1, char **c, int l1, int l2, int length)
{
    int curX = l1, curY = l2, i = 1;
    char *result = (char *)malloc(sizeof(char) * length);
    while (TRUE)
    {
        switch (c[curX][curY])
        {
        case '1':
            result[length - i] = s1[curX - 1];
            i++;
            curX--;
            curY--;
            break;
        case '2':
            curX--;
            break;
        case '3':
            curY--;
            break;
        case '\0':
            for (i = 0; i < length; i++)
                printf("%c ", result[i]);
            printf("\n");
            free(result);
            return;
        }
    }
}
void LCS(char *s1, char *s2, int l1, int l2)
{
    int **a = (int **)malloc(sizeof(int *) * (l1 + 1)), i, j;
    char **c = (char **)malloc(sizeof(char *) * (l1 + 1));
    for (i = 0; i <= l1; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * (l2 + 1));
        c[i] = (char *)malloc(sizeof(char) * (l2 + 1));
        for (j = 0; j <= l2; j++)
            c[i][j] = '\0';
        a[i][0] = 0;
    }
    for (i = 1; i <= l2; i++)
        a[0][i] = 0;
    for (i = 1; i <= l1; i++)
    {
        for (j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            { // 相同,找左上
                // printf("same: %c\n", s1[i - 1]);
                a[i][j] = a[i - 1][j - 1] + 1;
                c[i][j] = '1';
            }
            else
            { // 不相同,找长的
                if (a[i - 1][j] >= a[i][j - 1])
                { // 上边长
                    a[i][j] = a[i - 1][j];
                    c[i][j] = '2';
                }
                else
                { // 左边长
                    a[i][j] = a[i][j - 1];
                    c[i][j] = '3';
                }
            }
        }
    }
    int length = a[l1][l2];
    printf("Length: %d , LSC: ", length);
    SearchTrace(s1, c, l1, l2, length);
    /*
    for (i = 0; i <= l1; i++)
    {
        for (j = 0; j <= l2; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i <= l1; i++)
    {
        for (j = 0; j <= l2; j++)
        {
            printf("%c ", c[i][j]);
        }
        printf("\n");
    }
    */
    for (i = l1; i >= 0; i--)
    {
        free(c[i]);
        free(a[i]);
    }
    free(c);
    free(a);
}
/* 
Sample: 
ABCBDAB 
BDCABA
*/
int main()
{
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    LCS(str1, str2, strlen(str1), strlen(str2));
    return 0;
}