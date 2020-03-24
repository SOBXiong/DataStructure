#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 十二进制是数学中一种以12位底数的记数系统,它由0~9,a,b组成.
 * 与十进制对应关系是: 0~9对应0~9,a对应10,b对应11.
 * 例如,十二进制的a2,十进制是122.输入一个仅含十二进制数字的字符串
 * (字母一律小写,不超过8个字符),编程完成下列任务:
 *
 * 1.输出该十二进制数每一位对应的十进制数(从高位到低位顺序输出,空格隔开);(10分)
 * 2.实现"十二进制"转"十进制"算法,输出该十二进制数对应的十进制数;(10分)
 * 3.输出转换后的十进制数在内存中的每个二进制位(共4字节,字节之间空格隔开).(10分)
 * 例如,输入十二进制数: a2
 * 则输出为: 10 2
 *          122
 *          00000000 00000000 00000000 011111010
 **/
int toTen(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'b')
        return c - 'a' + 10;
    printf("输入错误,输入必须是0~9,a,b的组合!\n");
    exit(-1);
}
int getNum(char *data, int length)
{
    int i, temp, sum = 0;
    for (i = 0; i < length; i++)
    {
        temp = toTen(data[i]);
        printf("%d ", temp);
        sum = sum * 12 + temp;
    }
    printf("\n");
    return sum;
}
void printBinary(int data)
{
    int i, count = 0, *binary = NULL;
    for (i = data; i > 0; i /= 2)
    {
        if (binary == NULL)
            binary = (int *)malloc(sizeof(int));
        else
            binary = (int *)realloc(binary, sizeof(int) * (count + 1));
        binary[count++] = i % 2;
    }
    for (i = 4 * 8 - 1; i >= 0; i--)
    {
        if (i > count - 1)
            printf("0");
        else
        {
            printf("%d", binary[i]);
        }
        if ((32 - i) % 8 == 0)
            printf(" ");
    }
    free(binary);
}
int main()
{
    char input[9];
    scanf("%s", input);
    int length = strlen(input), num = getNum(input, length);
    printf("%d\n",num);
    printBinary(num);
    return 0;
}
