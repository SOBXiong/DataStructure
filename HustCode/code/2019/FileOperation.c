#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 打开第一题的代码源文件.c/.cpp,要求原文件里含"//"和"\* xxxxx *\"注释('\' → '/')
 * 输出该文件,共有三小问
 * 1. 给每行代码加上序号,表明这是第几行; (10分)
 * 2. 对于"//"字符,不予输出"//"及该行之后的文本; (10分)
 * 3、同上要求不输出"\* *\"及其之内的文本('\' → '/'). (10分)
 **/
#define TRUE 1
#define FALSE 0
int flag = FALSE;
int startWithMultipleNotes(char *data)
{
    int i, length = strlen(data);
    for (i = 0; i < length; i++)
    {
        if (data[i] == '/' && i + 1 < length && data[i + 1] == '*')
            return TRUE;
    }
    return FALSE;
}
int endWithMultipleNotes(char *data)
{
    int i, length = strlen(data);
    for (i = 0; i < length; i++)
    {
        if (data[i] == '*' && i + 1 < length && data[i + 1] == '/')
            return TRUE;
    }
    return FALSE;
}
int containsSingleNotes(char *data)
{
    int i, length = strlen(data);
    for (i = 0; i < length; i++)
    {
        if (data[i] == '/')
        {
            if (i + 1 < length && data[i + 1] == '/')
                return TRUE;
        }
    }
    return FALSE;
}
// 有局限性,如果"/* */"匹配不上
// 就不会输出中间部分(上一步.c/.cpp文件编译不过)
int main()
{
    FILE *fp = NULL;
    char temp[1024];
    fp = fopen("MerPriNum.c", "r");
    if (fp == NULL)
    {
        printf("文件打开错误\n");
        exit(-1);
    }
    // feof用检测流上的文件结束符,
    // 其返回值有两种情况:
    // 如果遇到文件结束,函数值为非零值;否则函数值为0.
    int count = 0;
    while (!feof(fp))
    {
        fgets(temp, 1024, fp);
        count++;
        if (!flag)
        {
            if (startWithMultipleNotes(temp))
                flag = TRUE;
            else if (!containsSingleNotes(temp))
                printf("%d: %s", count, temp);
        }
        else
        {
            if (endWithMultipleNotes(temp))
                flag = FALSE;
        }
        // feof函数要读取到最后一个位置的内容,要强调位置和内容.
        // 举例说,我叫你去火车的最后一节车厢,这就是位置;
        // 我叫你一直往前走,直到摸到铁轨,这就是内容.
        // 所以feof函数实际上是根据读取到最后一个位置的内容来判断的,所以要多走一字节.
        // 多走一字节
        char ch = fgetc(fp);
        // 如果走到结尾,退出
        if (ch == EOF)
            break;
        // 往前挪动-1个单位,少走一字节
        // int fseek(FILE *stream, long offset, int fromwhere);
        // 函数设置文件指针stream的位置.如果执行成功,
        // stream将指向以fromwhere(偏移起始位置: 文件头0(SEEK_SET),当前位置1(SEEK_CUR),文件尾2(SEEK_END))为基准
        // 偏移offset(指针偏移量)个字节的位置.如果执行失败(比如offset超过文件自身大小),则不改变stream指向的位置.
        fseek(fp, -1, SEEK_CUR);
    }
    return 0;
}
