#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left;
    int rightSize = right - mid + 1;
    int leftArr[leftSize];
    int rightArr[rightSize];
    int i,j,k;
    // 得到左右两边的小数组
    for (i = left; i < mid; i++)
        leftArr[i - left] = arr[i];
    for (i = mid; i <= right; i++)
        rightArr[i - mid] = arr[i];

    // arr数组从left变化到right
    i = j =0,k = left;
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid + 1, right);
}

int main()
{
    int arr[8] = {29, 18, 25, 47, 58, 12, 51, 10};
    mergeSort(arr, 0, 7);
    int i;
    for (i = 0; i < 8; i++)
        printf("%d\t", arr[i]);
}