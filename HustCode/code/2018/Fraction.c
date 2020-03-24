#include <stdio.h>
#include <stdlib.h>
/**
 * 编写程序,接收3个以N/D形式输入的分数,其中N(0<=N<=65535)为分子,
 * D(0<=N<=65535)为分母,输出它们的小数形式.
 * 如果小数形式存在循环节,则用括号括起来.如1/3=.3333...表示为.(3) (30分)
 * 例如,输入: 8/5 1/3 11/13
 * 则输出为: 8/5 = 1.6
 *          1/3 = .(3)
 *          11/13 = .(846153)
 * 
 * 其他例子: 3/7 = .(428571)
 *
 * @method: 分析: 模拟长除法的计算过程
 *          1. mod = a % b;
 *          2. 小数 = mod * 10 / b;
 *          3. mod = mod * 10 % b;
 *          循环2~3步,当出现重复的余数/余数为0的时候,也就是循环节出现/能够整除的时候
 *
 * @link: https://blog.csdn.net/qq742762377/article/details/80572811
 **/
#define TRUE 1
#define FALSE 0
int isInArray(int *array, int count, int data)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (array[i] == data)
            return TRUE;
    }
    return FALSE;
}
void printFraction(int n, int d)
{
    int i, result, mod, *results = NULL, *mods = NULL, rCount = 0, mCount = 0, zeroFlag = FALSE;
    if (n / d > 0)
    {
        result = n / d;
        mod = n % d;
        printf("%d.", result);
    }
    else
    {
        mod = n;
        printf(".");
    }
    mods = (int *)malloc(sizeof(int));
    mods[mCount++] = mod;
    while (TRUE)
    {
        result = mod * 10 / d;
        mod = mod * 10 % d;
        // 出口
        if (isInArray(mods, mCount, mod) || mod == 0)
        {
            // 设置标志位
            if (mod == 0)
                zeroFlag = TRUE;

            // 记录循环节的最后一位/整除的最后一位(结果位)
            mods = (int *)realloc(mods, sizeof(int) * (mCount + 1));
            mods[mCount++] = mod;
            if (results == NULL)
                results = (int *)malloc(sizeof(int));
            else
                results = (int *)realloc(results, sizeof(int) * (rCount + 1));
            results[rCount++] = result;
            break;
        }
        else
        {
            // 记录中间结果位
            mods = (int *)realloc(mods, sizeof(int) * (mCount + 1));
            mods[mCount++] = mod;
            if (results == NULL)
                results = (int *)malloc(sizeof(int));
            else
                results = (int *)realloc(results, sizeof(int) * (rCount + 1));
            results[rCount++] = result;
        }
    }
    // 如果整除
    if (zeroFlag)
    {
        for (i = 0; i < rCount; i++)
            printf("%d", results[i]);
        printf("\n");
    }
    else // 有循环节
    {
        printf("(");
        for (i = 0; i < rCount; i++)
            printf("%d", results[i]);
        printf(")\n");
    }
    // 释放内存
    free(results);
    free(mods);
}
int main()
{
    int N[3], D[3];
    int i;
    for (i = 0; i < 3; i++)
        scanf("%d/%d", &N[i], &D[i]);
    for (i = 0; i < 3; i++)
        printFraction(N[i], D[i]);
    return 0;
}
