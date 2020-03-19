#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 编写一个程序,判断给定的字符串是否是合法的C整形常量
 * 是,输出YES,不是,输出NO.C整形常量的语法如下图所示(图中0是数字零)
 * 要求程序能循环接收用户的输入,每行输入1个字符串,给出判定结果.
 * 再输入1个字符串,再给出判定结果,...,直至输入Ctrl+Z结束.
 * 例如:
 *      123
 *      Yes
 *      078
 *      No
 *      100h
 *      No
 *      ^Z
 **/
#define TRUE 1
#define FALSE 0
#define TEN 0
#define EIGHT 1
#define SIXTEEN 2
int isNum(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}
int isCInteger(char *data)
{
    int i, status, start = 0, length = strlen(data);
    if (data[0] == '0')
    {
        if (length == 1)
            return TRUE;
        else
        {
            if (data[1] == 'X' || data[1] == 'x')
            {
                status = SIXTEEN;
                start = 2;
            }
            else
            {
                status = EIGHT;
                start = 1;
            }
        }
    }
    for (i = start; i < length; i++)
    {
        // 如果不是数字
        if (!isNum(data[i]))
        {
            if (status == SIXTEEN)
            {
                if ((data[i] >= 'a' && data[i] <= 'f') || (data[i] >= 'A' && data[i] <= 'F'))
                    continue;
                else
                    return FALSE;
            }
            else
                return FALSE;
            if (i == length - 1)
            {
                if (data[i] == 'u' || data[i] == 'U' || data[i] == 'l' || data[i] == 'L')
                    return TRUE;
                else
                    return FALSE;
            }
        }
        else
        {
            if (status == EIGHT && data[i] >= '8')
                return FALSE;
        }
    }
    return TRUE;
}
int main()
{
    char input[100];
    while (~scanf("%s", input))
    {
        if (isCInteger(input))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
