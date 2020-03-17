#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  LSPS: Longest son palindrome string最长子回文串
 *    输入一个字符串,求出其中最长的回文子串.子串的含义是: 在原串连续出现的字符串片段.
 *  回文的含义是: 正着看和倒着看是相同的,如abba和abbebba.在判断是要求忽略所有的
 *  标点和空格,且忽略大小写,但输出时按原样输出(首尾不要输出多余的字符串).输入字
 *  符串长度大于等于1小于等于5000
 *    样例输入
 *  She say:Madam,I'm Adam.
 *    样例输出
 *  Madam,I'm Adam
 **/
#define TRUE 1
#define FALSE 0
int startIndex = -1;
int endIndex = -1;
int isLetter(char data)
{
    return ((data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z')) ? TRUE : FALSE;
}
char toLower(char data)
{
    if (data >= 'A' && data <= 'Z')
        return data - 'A' + 'a';
    else
        return data;
}
int findCommonFromBack(char *data, int end, char cur)
{
    int i;
    for (i = end; i >= 0; i--)
    {
        if (data[i] == cur)
            return i;
    }
    // 不可能找不到
    exit(-1);
}
int isPs(char *data, int start, int end)
{
    while (start < end)
    {
        if (data[start] != data[end])
            return FALSE;
        start++;
        end--;
    }
    return TRUE;
}
void findMaxPS(char *data, int length)
{
    int i, start, end;
    char cur;
    // 回文,至少要两个字符
    for (i = 0; i < length - 1; i++)
    {
        // 从第i个位置开始扫描
        start = i;
        // 初始结束位置
        end = length - 1;
        cur = data[start];
        while (TRUE) // 开始找
        {
            // 找到倒数匹配的位置
            int index = findCommonFromBack(data, end, cur);
            // 匹配不上(找到start)
            if (index == start)
                break;
            if (isPs(data, start, index))
            {
                // 长度大于之前找到的
                if (index - start > endIndex - startIndex)
                {
                    startIndex = start;
                    endIndex = index;
                }
                // 找到回文退出while,当前一定是从start开始最长的
                break;
            }
            else // 不是回文,截止位置往前移动
                end = index - 1;
        }
    }
}
int main()
{
    char input[5000];
    gets(input);
    int i, length = strlen(input), count = 0;
    char *lowerLetter = (char *)malloc(sizeof(char) * length);
    int *index = (int *)malloc(sizeof(int) * length);
    for (i = 0; i < length; i++)
    {
        if (isLetter(input[i]))
        {
            // 设置字符
            lowerLetter[count] = toLower(input[i]);
            // 记录坐标,方便后面输出
            index[count] = i;
            count++;
        }
    }
    lowerLetter[count] = '\0';
    // printf("%s\n",lowerLetter);
    findMaxPS(lowerLetter, count);
    // printf("%d %d\n",startIndex,endIndex);
    if (startIndex == -1 && endIndex == -1)
    {
        printf("没有回文找到!\n");
        exit(-1);
    }
    else
    {
        for (i = index[startIndex]; i <= index[endIndex]; i++)
            printf("%c", input[i]);
    }
    free(lowerLetter);
    free(index);
    return 0;
}
