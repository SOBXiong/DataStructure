#include <stdio.h>
#include <stdlib.h>
// 后推法
// Way(n) = Way(n-1) + Way(n-2)
// Way(2) = 2
// way(1) = 1
// way(0) = 0

// 递归方式
int getWay(int n)
{
    if(n == 2)
        return 2;
    else if(n == 1)
        return 1;
    else if(n == 0)
        return 0;
    return getWay(n-1) + getWay(n-2);
}

// 非递归方式
int getWay2(int n)
{
    int *Way = (int*)malloc(sizeof(int) * (n+1));
    Way[0] = 0,Way[1] = 1,Way[2] = 2;
    int i;
    for(i = 3; i <= n; i++)
        Way[i] = Way[i-1] + Way[i-2];
    return Way[n];
    free(Way);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int way = getWay2(n);
        printf("%d\n",way);
    }
}
