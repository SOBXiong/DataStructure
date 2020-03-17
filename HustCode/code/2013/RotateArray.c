#include <stdio.h>
#include <stdlib.h>
/**
 * 顺转数组(30分):
 *     输入一个数字n,输出一个n阶顺转数组
 *     如输入: 5
 *     输出:
 *     1  2  3  4  5
 *     16 17 18 19 6
 *     15 24 25 20 7
 *     14 23 22 21 8
 *     13 12 11 10 9
 **/
// 递归设置矩阵边界
void recursionSetBorder(int **a, int start, int end, int startData)
{
    // 两个递归出口
    if (start > end)
        return;
    if (start == end)
    {
        a[start][start] = startData;
        return;
    }

    int i;
    // 填充右
    for (i = start; i <= end; i++)
    {
        a[start][i] = startData;
        startData++;
    }
    // 填充下
    for (i = start + 1; i <= end; i++)
    {
        a[i][end] = startData;
        startData++;
    }
    // 填充左
    for (i = end - 1; i >= start; i--)
    {
        a[end][i] = startData;
        startData++;
    }
    // 填充上
    for (i = end - 1; i > start; i--)
    {
        a[i][start] = startData;
        startData++;
    }
    recursionSetBorder(a, start + 1, end - 1, startData);
}
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int **a = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        a[i] = (int *)malloc(sizeof(int) * n);
    recursionSetBorder(a, 0, n - 1, 1);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%2d ", a[i][j]);
        printf("\n");
    }
    for (i = n - 1; i >= 0; i--)
        free(a[i]);
    free(a);
    return 0;
}
