#include <stdio.h>
#include <stdlib.h>
/**
 * 输入一个字符,打印如下结构:
 * 例子1:
 * 输入: D
 * 输出: A B C D C B A
 *         A B C B A
 *           A B A
 *             A
 * 例子2:
 * 输入: c
 * 输出: a b c b a
 *         a b a
 *           a
 **/
#define TRUE 1
#define FALSE 0
int isUpLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ? TRUE : FALSE;
}
int isLowLetter(char c)
{
    return (c >= 'a' && c <= 'z') ? TRUE : FALSE;
}
void printUp(char c, int height)
{
    int i;

    // 打印前面的空格
    for (i = 1; i < height; i++)
        printf("  ");
    // 递归出口
    if (c + 1 - height == 'A')
    {
        printf("A\n");
        return;
    }
    char cur = 'A';
    while (cur != c + 1 - height)
        printf("%c ", cur++);
    while (cur != 'A' - 1)
        printf("%c ", cur--);
    printf("\n");
    printUp(c, ++height);
}
void printLow(char c, int height)
{
    int i;

    // 打印前面的空格
    for (i = 1; i < height; i++)
        printf("  ");
    // 递归出口
    if (c + 1 - height == 'a')
    {
        printf("a\n");
        return;
    }
    char cur = 'a';
    while (cur != c + 1 - height)
        printf("%c ", cur++);
    while (cur != 'a' - 1)
        printf("%c ", cur--);
    printf("\n");
    printLow(c, ++height);
}
int main()
{
    char input;
    scanf("%c", &input);
    if (isLowLetter(input))
        printLow(input, 1);
    else if (isUpLetter(input))
        printUp(input, 1);
    else
    {
        printf("输入的字符不是字母!\n");
        exit(-1);
    }
    return 0;
}
