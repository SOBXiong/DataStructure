#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 输入一个字符串,长度小于80要求
 * 1. 对于字符串加密输出,加密方法为:
 *    对于字母字符输出其ASCII码值右移2(就是+2)后的字母,但是对于字母y,z
 *    加密后输出a,b(加密后字母大小写不变)
 * 2. 奇偶校验,对于加密后的字符串,判断每个ASCII码值(2进制)中1的个数,如果不是奇数个1,那么最高位取1
 * 3. 输出第二问奇偶校验后的数值,十进制表示
 * 举例:
 *      输入: aD
 *      输出: cF
 *            c 11100011 227
 *            F 01000110 70
 **/
#define TRUE 1
#define FALSE 0
int isUpCase(char c)
{
    return (c >= 'A' && c <= 'Z') ? TRUE : FALSE;
}
int isLowCase(char c)
{
    return (c >= 'a' && c <= 'z') ? TRUE : FALSE;
}
void charOperate(char c)
{
    int i, bit[8] = {0}, allCount = 0, oddNum = 0, result = c;
    for (i = c; i > 0; i /= 2)
    {
        bit[7 - allCount] = i % 2;
        if (bit[i] == 1)
            oddNum++;
        allCount++;
    }
    printf("%c ", result);
    if (oddNum % 2 == 0)
    {
        bit[0] = 1;
        // char -127~128,需要新的单元存放结果
        result += 128;
    }
    for (i = 0; i < 8; i++)
        printf("%d", bit[i]);
    printf(" %d\n", result);
}
int main()
{
    char input[80];
    scanf("%s", input);
    int i, length = strlen(input);
    for (i = 0; i < length; i++)
    {
        if (isUpCase(input[i]))
        {
            if (input[i] >= 'Y')
                input[i] = (input[i] == 'Y') ? 'A' : 'B';
            else
                input[i] += 2;
        }
        else if (isLowCase(input[i]))
        {
            if (input[i] >= 'y')
                input[i] = (input[i] == 'y') ? 'a' : 'b';
            else
                input[i] += 2;
        }
        else
        {
            printf("输入的字符串不是纯字母串!\n");
            exit(-1);
        }
    }
    printf("%s\n", input);
    for (i = 0; i < length; i++)
        charOperate(input[i]);
    return 0;
}
