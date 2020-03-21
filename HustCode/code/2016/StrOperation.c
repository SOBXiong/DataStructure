#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 输入字符串
 * 1.去除前面的空格;
 * 2.中间多个空格只保留一个空格;
 * 3.数字字母中间加上_
 **/
#define TRUE 1
#define FALSE 0
int isNum(char c)
{
    return (c >= '0' && c <= '9') ? TRUE : FALSE;
}
int isLetter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? TRUE : FALSE;
}
// 例子:     ni15smd8  dme9 s
int main()
{
    char input[1024], *str1 = NULL, *str2 = NULL;
    gets(input);
    int i, length = strlen(input), count = 0, isFirst = 1;
    for (i = 0; i < length; i++)
    {
        if (input[i] == ' ' && isFirst)
        {
            continue;
        }
        else
        {
            isFirst = 0;
            if (count == 0)
                str1 = (char *)malloc(sizeof(char));
            else
                str1 = (char *)realloc(str1, sizeof(char) * (count + 1));
            str1[count++] = input[i];
        }
    }
    str1 = (char *)realloc(str1, sizeof(char) * (count + 1));
    str1[count] = '\0';
    length = count;
    count = 0;
    printf("First step: %s\n", str1);
    for (i = 0; i < length; i++)
    {
        // 如果第一次碰到空格或者不是空格,加入str2
        if ((isFirst && str1[i] == ' ') || str1[i] != ' ')
        {
            // 如果第一次,将第一次标志置否
            if (isFirst)
                isFirst = 0;
            else // 否则,将第一次标志置是
                isFirst = 1;
            if (count == 0)
                str2 = (char *)malloc(sizeof(char));
            else
                str2 = (char *)realloc(str2, sizeof(char) * (count + 1));
            str2[count++] = str1[i];
        }
    }
    str2 = (char *)realloc(str2, sizeof(char) * (count + 1));
    str2[count] = '\0';
    length = count;
    printf("Second step: %s\n", str2);
    printf("Third step: ");
    isFirst = 2;
    for (i = 0; i < length; i++)
    {
        // 如果是数字,第一次碰到才置为1
        if (isNum(str2[i]))
            isFirst = 1;
        else if (isLetter(str2[i])) // 如果是字符
        {
            // 如果上一个字符是数字
            if (isFirst == 1)
            {
                isFirst = 0;
                printf("%c", '_');
            }
        }
        // 其他情况直接输出
        printf("%c", str2[i]);
    }
    printf("\n");
    free(str2);
    free(str1);
    return 0;
}
