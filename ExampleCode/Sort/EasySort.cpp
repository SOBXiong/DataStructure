#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

typedef int ElemType;
int num;

void Traverse(int data[], int n, bool printFirst)
{
    printf(">>> Start: \n");
    int end = printFirst ? n : n + 1;
    for (int i = printFirst ? 0 : 1; i < end; i++)
        printf("%d  ", data[i]);
    printf("\n>>> End! \n\n");
}

// 直接插入排序(S[0]哨兵,不存储数据)
void InsertSort(ElemType S[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (S[i] < S[i - 1])
        {
            S[0] = S[i];
            for (j = i - 1; S[0] < S[j]; --j)
                S[j + 1] = S[j];
            S[j + 1] = S[0];
        }
    }
}

// 折半插入排序(S[0]哨兵,不存储数据)
void BinaryInsertSort(ElemType S[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++)
    {
        S[0] = S[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (S[mid] > S[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
            S[j + 1] = S[j];
        S[high + 1] = S[0];
    }
}

// 希尔排序(S[0]哨兵,不存储数据)
void ShellSort(ElemType S[], int n)
{
    for (int dk = n / 2; dk >= 1; dk /= 2)
    {
        for (int i = dk + 1; i <= n; ++i)
        {
            if (S[i] < S[i - dk])
            {
                S[0] = S[i];
                int j;
                for (j = i - dk; j > 0 && S[0] < S[j]; j -= dk)
                    S[j + dk] = S[j];
                S[j + dk] = S[0];
            }
        }
    }
}

// 冒泡排序
void BubbleSort(ElemType S[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (S[j - 1] > S[j])
            {
                int temp = S[j];
                S[j] = S[j - 1];
                S[j - 1] = temp;
                flag = 1;
            }
        }
        if (!flag)
            return;
    }
}

void BubbleSortInRecursion(ElemType S[], int L, int R)
{
    // 只剩一个元素 -> 递归出口
    if(L == R){
        return;
    }
    int i;
    for (i = L; i <= R - 1; i++)
    {
        // 最大的放到R位置
        if (S[i] > S[i + 1])
        {
            int temp = S[i];
            S[i] = S[i + 1];
            S[i + 1] = temp;
        }
    }
    // 对L ~ R-1排序
    BubbleSortInRecursion(S, L, R - 1);
}

// 枢轴划分
int Partition(ElemType S[], int low, int high)
{
    ElemType pivot = S[low];
    while (low < high)
    {
        while (low < high && S[high] >= pivot)
            --high;
        S[low] = S[high];
        while (low < high && S[low] <= pivot)
            ++low;
        S[high] = S[low];
    }
    S[low] = pivot;
    Traverse(S, num, false);
    return low;
}

// 快速排序
void QuickSort(ElemType S[], int low, int high)
{
    if (low < high)
    {
        int pivotPos = Partition(S, low, high);
        QuickSort(S, low, pivotPos - 1);
        QuickSort(S, pivotPos + 1, high);
    }
}

// 简单选择排序
void SelectSort(ElemType S[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (S[j] < S[min])
                min = j;
        }
        if (min != i)
        {
            int temp = S[i];
            S[i] = S[min];
            S[min] = temp;
        }
    }
}

// 示例: 10 98 36 -9 0 47 23 1 8 10 7
// 8 29 18 25 47 58 12 51 10
int main()
{
    int n;
    scanf("%d", &n);
    ElemType *data = (ElemType *)malloc((n + 1) * sizeof(ElemType));
    for (int i = 1; i <= n; i++)
        scanf("%d", &data[i]);
    // QkSort
    // InsertSort(data, n);
    // BinaryInsertSort(data,n);
    // ShellSort(data, n);
    Traverse(data, n, false);
    // num = n;
    // QuickSort(data, 1, n);
    // Traverse(data, n, false);
    return 0;
}