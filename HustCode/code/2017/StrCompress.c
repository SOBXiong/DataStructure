#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 字符串压缩: 以字符串的方式接收一串数字,如: 123456
 *            然后把每2位对应的数字+32,保存为对应的ASCII码字符保存
 *            如: 12+32=44,把44对应的字符保存到新的字符串
 *            如果数字个数为奇数,末尾补0
 **/
#define TRUE 1
#define FALSE 0
int isNum(char c)
{
    return (c >= '0' && c <= '9') ? TRUE : FALSE;
}
int main()
{
    char input[1024];
    scanf("%s", input);
    int i, length = strlen(input), count = 0, flag = -1;
    // 当前字符串长度模2加结束符'\0'
    // 5 -> 3 + 1,6 -> 3 + 1
    char *output = (char *)malloc(sizeof(char) * ((length + 1) / 2 + 1));
    for (i = 0; i < length; i++)
    {
        if (!isNum(input[i]))
        {
            printf("当前输入的字符串不是纯数串!\n");
            exit(-1);
        }
        else
        {
            if (flag == -1)
                flag = input[i] - '0';
            else
            {
                // 十位数 + 个位数
                flag = flag * 10 + input[i] - '0' + 32;
                output[count++] = flag;
                flag = -1;
            }
        }
    }
    // 奇数
    if (flag != -1)
        output[count++] = flag * 10 + 32;
    output[count] = '\0';
    printf("Compress str ->%s\n", output);
    free(output);
    return 0;
}
