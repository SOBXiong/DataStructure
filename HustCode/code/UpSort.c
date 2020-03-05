#include <stdio.h>
#include <stdlib.h>
void sort(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, n);
    free(a);
    return 0;
}