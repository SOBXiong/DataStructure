#include <stdio.h>
#include <stdlib.h>
// 七个评委给选手打分,去掉最高分和最低分,输出平均分,保留一位小数
int floatCompare(const void *p1, const void *p2)
{
    const float *f1 = (float *)p1;
    const float *f2 = (float *)p2;
    return *f2 - *f1 > 0;
}
// 例:6.2 7.8 8.4 0 6.9 4.8 7.9
int main()
{
    float input[7], sum = 0;
    int i;
    for (i = 0; i < 7; i++)
        scanf("%f", &input[i]);
    qsort(input, 7, sizeof(float), floatCompare);
    for (i = 1; i < 6; i++)
        sum += input[i];
    printf("Average: %.1f\n", sum / 5.0f);
    return 0;
}
