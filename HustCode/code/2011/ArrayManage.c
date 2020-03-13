#include <stdio.h>
#include <stdlib.h>
/**
    编写一个C程序，完成下列任务:
    1.输入任意n个整数并将其无冗余的存放到数组中
    (n值不得事先指定，数组必须无冗余，否则0分),然后输出该数组中的n个整数。(20分)
    2.对该数组中的n个整数进行排序并输出结果。(10分)
**/
int compare(const void *p1, const void *p2)
{
    int *ip1 = (int *)p1;
    int *ip2 = (int *)p2;
    return *ip1 - *ip2;
}
// 3 34 4 12 5 2 18 64 3 8
int main()
{
    int i, data, count = 0;
    int *p = NULL;
    while (~scanf("%d", &data))
    {
        if (p == NULL)
        {
            p = (int *)malloc(sizeof(int));
            *p = data;
            count++;
        }
        else
        {
            p = (int *)realloc(p, sizeof(int) * (++count));
            p[count - 1] = data;
        }
    }
    for (i = 0; i < count; i++)
        printf("%2d\t", p[i]);
    printf("\n");
    qsort(p, count, sizeof(int), compare);
    for (i = 0; i < count; i++)
        printf("%2d\t", p[i]);
    printf("\n");
    free(p);
    return 0;
}
