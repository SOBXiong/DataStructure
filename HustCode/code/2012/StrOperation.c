#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * (1)输入n个字符串，字符串只能是纯字母或者纯数字，不能事先指定字符串个数，最后
 * 将输入字符串倒序输出
 * (2)将纯字母的字符串按照字典顺序排序，纯数字的字符串按照数值大小排序，最后在输出。
 **/
int getNum(char *data, int length)
{
    int sum = 0, i;
    for (i = 0; i < length; i++)
    {
        sum *= 10;
        sum += data[i] - '0';
    }
    return sum;
}
int letterCompare(const void *p1, const void *p2)
{
    char *str1 = (char *)p1;
    char *str2 = (char *)p2;
    return strcmp(str1, str2);
}
int numberCompare(const void *p1, const void *p2)
{
    char *str1 = (char *)p1;
    char *str2 = (char *)p2;
    int num1 = getNum(str1, strlen(str1));
    int num2 = getNum(str2, strlen(str2));
    return num1 - num2;
}
int isNumber(char c)
{
    return (c <= '9' && c >= '0') ? 1 : 0;
}
int isLetter(char c)
{
    return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) ? 1 : 0;
}
int main()
{
    char in[1024];
    char **data = NULL;
    int flag = -1, i, length, size;
    // 一行输入,以换行符结束
    while (~scanf("%s", in))
    {
        length = strlen(in);
        // 校验纯数字/字母
        for (i = 0; i < length; i++)
        {
            if (i == 0 && flag == -1)
            {
                if (isLetter(in[i]))
                    flag = 0;
                else if (isNumber(in[i]))
                    flag = 1;
                else
                {
                    printf("输入的字符既不为数字也不为字母!\n");
                    exit(-1);
                }
            }
            else
            {
                if (flag) // 是纯数字
                {
                    if (!isNumber(in[i]))
                    {
                        printf("输入的字符必须为纯数字!\n");
                        exit(-1);
                    }
                }
                else
                {
                    if (!isLetter(in[i]))
                    {
                        printf("输入的字符必须为纯字母!\n");
                        exit(-1);
                    }
                }
            }
        }
        if (data == NULL)
        {
            data = (char **)malloc(sizeof(char *));
            data[0] = (char *)malloc(sizeof(char) * length);
            strcpy(data[0], in);
            size = 1;
        }
        else
        {
            data = (char **)realloc(data, sizeof(char *) * (++size));
            data[size - 1] = (char *)malloc(sizeof(char) * length);
            strcpy(data[size - 1], in);
            // printf("in -> %s\n",in);
        }
    }
    printf("Original Output -> \n");
    for (i = 0; i < size; i++)
        printf("%s\n", data[i]);
    qsort(data, size, sizeof(char *), flag ? numberCompare : letterCompare);
    printf("Sorted Output -> \n");
    for (i = 0; i < size; i++)
        printf("%s\n", data[i]);
    for (i = size - 1; i >= 0; i--)
        free(data[i]);
    free(data);
    return 0;
}
