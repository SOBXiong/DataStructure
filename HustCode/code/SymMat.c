#include <stdio.h>
#include <stdlib.h>
int judgeSymmetry(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // j > i,只检查右上角部分矩阵
        for (j = i + 1; j < n; j++)
        {
            if (a[i][j] != a[j][i])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n, i, j;
    while (~scanf("%d", &n))
    {
        // 部分编译器通不过这种二维数组的定义
        // int a[n][n] = {0};
        // 采用动态内存分配的方式
        int **a = (int **)malloc(sizeof(int *) * n);
        for (i = 0; i < n; i++)
        {
            a[i] = (int *)malloc(sizeof(int) * n);
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        /**
         *  将二维数组变为指向指针的指针
         *  不然编译通不过二维数组的传递
         *  指针的指针,和二维数组的差异:二维数组的地址是连续的,所有成员按顺序排序
         *  而指针的指针只要求指针地址连续,而不要求指针的指针地址连续
         **/
        /*int *p[n];
        for(i = 0;i < n;i++){
            p[i] = a[i];
        }*/
        printf("%s\n", judgeSymmetry(a, n) ? "Yes!" : "No!");

        // 回收内存,不然内存泄漏
        for (i = n - 1; i >= 0; i--)
            free(a[i]);
        free(a);
    }
    return 0;
}
