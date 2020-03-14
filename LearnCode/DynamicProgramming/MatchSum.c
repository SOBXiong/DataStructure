#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 要求要一系列数字中,选择其中几个数,它们的和是否为
 *               指定的数S(假定arr[]和S的类型都是int)
 * 
 * @method: 递推式: 
 *              选择: SubSet(arr[i],S) = SubSet(arr[i-1],S-arr[i])
 *              不选择: SubSet(arr[i],S) = SubSet(arr[i-1],S)
 *          递归出口: 
 *              ①、SubSet(arr[i],0); ②、SubSet(arr[0],?)
 *          特殊情况: 
 *              arr[i] > s : return SubSet(arr[i-1],S)
 * 
 * @link: https://www.bilibili.com/video/av18512769
 **/

int recursiveSubSet(int arr[], int i, int s)
{
    if (s == 0)
        return 1;
    else if (i == 0)
        return arr[0] == s;
    else if (arr[i] > s)
        return recursiveSubSet(arr, i - 1, s);
    else
    {
        int selRes = recursiveSubSet(arr, i - 1, s - arr[i]);
        int unselRes = recursiveSubSet(arr, i - 1, s);
        // 妙啊
        return selRes || unselRes;
    }
}

/**
 * @todo: 有点问题,需要再做修改 
 **/ 
int nonRecursiveSubSet(int arr[], int n, int s)
{
    int **subSet = (int **)malloc((sizeof(int *) * n));
    int i, j;
    for (i = 0; i < n; i++)
    {
        subSet[i] = (int *)malloc(sizeof(int) * (s + 1));
        // 第一列全是True
        subSet[i][0] = 1;
        if (i == 0)
        {
            // 第一行都是False
            for (j = 1; j < s + 1; j++)
                subSet[i][j] = 0;
            // 刚好符合s = arr[0]
            if (arr[0] <= s)
                subSet[i][arr[0]] = 1;
        }
    }
    // 表从(1,1)开始填
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < s + 1; j++)
        {
            if (arr[i] > s)
                subSet[i][j] = subSet[i - 1][s];
            else
            { // arr[i] <= s
                int selRes = subSet[i - 1][s - arr[i]];
                int unselRes = subSet[i - 1][s];
                // 妙啊*2
                subSet[i][j] = selRes || unselRes;
            }
        }
    }
    int result = subSet[n - 1][s];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < s + 1; j++)
            printf("%d ", subSet[i][j]);
        printf("\n");
    }
    for (i = n - 1; i >= 0; i--)
        free(subSet[i]);
    free(subSet);
    return result;
}
int main()
{
    int arr[6] = {3, 34, 4, 12, 5, 2};
    /**
    int result = recursiveSubSet(arr, 5, 8);
    printf("8 => %s\n", result == 0 ? "False!" : "True!");
    result = recursiveSubSet(arr, 5, 9);
    printf("9 => %s\n", result == 0 ? "False!" : "True!");
    result = recursiveSubSet(arr, 5, 10);
    printf("10 => %s\n", result == 0 ? "False!" : "True!");
    result = recursiveSubSet(arr, 5, 11);
    printf("11 => %s\n", result == 0 ? "False!" : "True!");
    result = recursiveSubSet(arr, 5, 12);
    printf("12 => %s\n", result == 0 ? "False!" : "True!");
    
    **/
    // int result = recursiveSubSet(arr, 5, 13);
    // printf("Recursive: 13 => %s\n", result == 0 ? "False!" : "True!");
    int result = nonRecursiveSubSet(arr, 6, 13);
    printf("NonRecursive: 13 => %s\n", result == 0 ? "False!" : "True!");
    result = nonRecursiveSubSet(arr, 6, 12);
    printf("NonRecursive: 12 => %s\n", result == 0 ? "False!" : "True!");
    result = nonRecursiveSubSet(arr, 6, 11);
    printf("NonRecursive: 11 => %s\n", result == 0 ? "False!" : "True!");
    result = nonRecursiveSubSet(arr, 6, 10);
    printf("NonRecursive: 10 => %s\n", result == 0 ? "False!" : "True!");
    result = nonRecursiveSubSet(arr, 6, 9);
    printf("NonRecursive: 9 => %s\n", result == 0 ? "False!" : "True!");
    result = nonRecursiveSubSet(arr, 6, 8);
    printf("NonRecursive: 8 => %s\n", result == 0 ? "False!" : "True!");
    return 0;
}