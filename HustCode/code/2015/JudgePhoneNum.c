#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 输入一串字符,并验证其是否为正确的电话号码.长度必须为 11位
 * 第一位必须为1,第二位为3、5、6、8中的一个,其余位必须为0-9中的一个数.
 **/
#define TRUE 1
#define FALSE 0
int isNum(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}
int isPhoneNum(char *data)
{
    int i, length = strlen(data);
    // printf("length: %d , data: %s\n",length,data);
    if (length != 11)
        return FALSE;
    if (data[0] != '1')
        return FALSE;
    if (data[1] != '3' && data[1] != '5' && data[1] != '6' && data[1] != '8')
        return FALSE;
    for (i = 2; i < length; i++)
        if (!isNum(data[i]))
            return FALSE;
    return TRUE;
}
int main()
{
    char input[100];
    while (~scanf("%s", input))
    {
        if (isPhoneNum(input))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
