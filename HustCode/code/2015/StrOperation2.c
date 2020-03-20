#include <stdio.h>
#include <stdlib.h>
/**
 * 无冗余的输入一个字符串
 * 1.输出该字符串;
 * 2.对于不是首次出现的字符,对其进行过滤,
 *      例如abcdacdef,过滤后为abcdef;
 * 3.对于字符0-9,A-F,a-f,将其对应的ASCII码的低4位进行对调,
 *      例如将1011,转换为1101,并将对应的ACSII码对应的字符输出,若为字母,转换为大写.
 **/
#define TRUE 1
#define FALSE 0
int isSmallLetter(char c)
{
    return (c >= 'a' && c <= 'z') ? TRUE : FALSE;
}
char getReverseBinary(int data[4], char sum)
{
    int i, count = 0;
    char result = 0;
    for (i = sum; i > 0; i /= 2)
        data[count++] = i % 2;
    for (i = 0; i < 4; i++)
    {
        result *= 2;
        result += data[i];
    }
    // printf("sum: %d,result: %d\n",sum,result);
    return result;
}
char charConvert(char c)
{
    // char 8bit
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
    {
        // 取出低4位
        char low = c & 0x0F;
        // 把低4位去掉
        c = c - low;
        int data[4] = {0};
        // 得到翻转后的低4位
        char reverseredLow = getReverseBinary(data, low);
        // 高4位不动,或低4位
        char result = c | reverseredLow;
        // printf("in: %d, resultLow: %d, result: %d\n",c + low,reverseredLow,result);
        return result;
    }
    else
    {
        if (isSmallLetter(c))
            return c - 'a' + 'A';
        return c;
    }
}
int main()
{
    char in, *data = NULL;
    int i, count = 0;
    while ((in = getchar()) != '\n')
    {
        if (count == 0)
            data = (char *)malloc(sizeof(char));
        else
            data = (char *)realloc(data, sizeof(char) * (count + 1));
        data[count++] = in;
    }
    data = (char *)realloc(data, sizeof(char) * (count + 1));
    data[count] = '\0';
    printf("%s\n", data);
    int j, filteredCount = 0;
    char *filtered = NULL;
    for (i = 0; i < count; i++)
    {
        if (filteredCount == 0)
        {
            filtered = (char *)malloc(sizeof(char));
            filtered[0] = data[i];
            filteredCount = 1;
        }
        else
        {
            int isFirst = 1;
            for (j = 0; j < filteredCount; j++)
            {
                if (filtered[j] == data[i])
                {
                    isFirst = 0;
                    break;
                }
            }
            if (isFirst)
            {
                filtered = (char *)realloc(filtered, sizeof(char) * (filteredCount + 1));
                filtered[filteredCount++] = data[i];
            }
        }
    }
    filtered = (char *)realloc(filtered, sizeof(char) * (filteredCount + 1));
    filtered[filteredCount] = '\0';
    printf("%s\n", filtered);
    for (i = 0; i < filteredCount; i++)
        printf("%c", charConvert(filtered[i]));
    printf("\n");
    free(filtered);
    free(data);
    return 0;
}
