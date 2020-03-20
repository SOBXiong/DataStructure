#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 无冗余的输入两个字符串,并对其进行拼接.
 * 1.输出拼接后的字符串.
 *      例如:,输入: string buff
 *            输出: stringbuff
 * 2.对于拼接后的字符串,输出奇数下标组成的子串和偶数下标组成的子串.
 *      例如: srnbf tiguf
 * 3.对于奇数下标组成的子串以及偶数下标组成的子串进行排序.
 *      例如 bfnrs fgitu
 **/
int compare(const void *p1, const void *p2)
{
    char *c1 = (char *)p1;
    char *c2 = (char *)p2;
    return strcmp(c1, c2);
}
int main()
{
    char in;
    char *str1, *str2;
    str1 = str2 = NULL;
    int count = 0, curStr = 0;
    while ((in = getchar()) != '\n')
    {
        if (in == ' ')
        {
            str1 = (char *)realloc(str1, sizeof(char) * (count + 1));
            str1[count] = '\0';
            curStr = 1;
            count = 0;
            continue;
        }
        if (curStr == 0)
        {
            if (count == 0)
                str1 = (char *)malloc(sizeof(char));
            else
                str1 = (char *)realloc(str1, sizeof(char) * (count + 1));
            str1[count++] = in;
        }
        else
        {
            if (count == 0)
                str2 = (char *)malloc(sizeof(char));
            else
                str2 = (char *)realloc(str2, sizeof(char) * (count + 1));
            str2[count++] = in;
        }
    }
    str2 = (char *)realloc(str2, sizeof(char) * (count + 1));
    str2[count] = '\0';
    strcat(str1, str2);
    printf("%s\n", str1);
    int i, oddCount = 0, evenCount = 0, length = strlen(str1);
    char *odd = (char *)malloc(sizeof(char) * ((length + 1) / 2));
    char *even = (char *)malloc(sizeof(char) * (length / 2));
    for (i = 0; i < length; i++)
    {
        if ((i + 1) % 2 == 0)
            even[evenCount++] = str1[i];
        else
            odd[oddCount++] = str1[i];
    }
    even[evenCount] = '\0';
    odd[oddCount] = '\0';
    printf("%s %s\n", odd, even);
    qsort(odd, evenCount, sizeof(char), compare);
    qsort(even, evenCount, sizeof(char), compare);
    printf("%s %s\n", odd, even);
    free(even);
    free(odd);
    free(str2);
    free(str1);
    return 0;
}
