#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 要求: 以二进制方式输入两个正整数(即0和1组成的字符串),
 *       然后输入一个4则运算符(+、-、*、/),按short型计算
 *       这两个数的运算结果,并将结果按二进制输出(高位0可不输出).
 *
 * 例如: 输入 101 100 *
 *       输出 10100(或00000000000010100)
 *       输入 101 100 +
 *       输出 1001
 **/
short strToShort(char *str)
{
    int length = strlen(str), i;
    short data = 0;
    for (i = 0; i < length; i++)
    {
        data *= 2;
        data += str[i] - '0';
    }
    return data;
}
short calculate(short n1, short n2, char op)
{
    short result;
    switch (op)
    {
    case '+':
        result = n1 + n2;
        break;
    case '-':
        result = n1 - n2;
        break;
    case '*':
        result = n1 * n2;
        break;
    case '/':
        result = n1 / n2;
        break;
    default:
        printf("Input op error!\n");
        exit(-1);
    }
    return result;
}
char *shortToStr(short data)
{
    char *str = (char *)malloc(sizeof(char) * 16);
    int count = 0, i;
    for (i = data; i > 0; i /= 2)
        str[count++] = i % 2 + '0';
    str[count] = '\0';
    return str;
}
int main()
{
    char n1[16], n2[16], op;
    // 有空格,不适用gets
    while (~scanf("%s %s %c", n1, n2, &op))
    {
        int i;
        short result = calculate(strToShort(n1), strToShort(n2), op);
        char *output = shortToStr(result);
        for (i = strlen(output) - 1; i >= 0; i--)
            printf("%c", output[i]);
        printf("\n");
        free(output);
    }
    return 0;
}
