#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @description: 编写一个C程序,完成下列任务:
 *               1.从键盘输入一个文本(ASCI码文件)，并将该文本输出到D盘根目录下的abc0.txt文件中，
 *               再关闭该文件。输入以Ctrl+Z结束。(10分)
 *               2.打开D盘根目录下的abc0.txt文件，将单词之间2个以上的空格都压缩为1个空格，
 *               输出处理后的文本，同时将处理后的文本输出到D盘根目录下的abel.txtt文件中
 *               并关闭该文件。(10分)
 *               3.打开D盘根目录下的abc1.txt文件，统计文件中字符的个数，单词的个数
 *               以及句子的个数并输出统计结果。(20分)
 * 
 * @testcase: HSBC  on  Monday  started  construction on a  global  training center  in Guangzhou, capital of south China's Guangdong Province.
 *            The  training  center in Nansha, HSBC's largest in the world, involves  a total  investment of more than 150 million US dollars, said the bank and the local government.
 *            The center,  scheduled  to  be put  in operation  in  2024, is  designed to offer training  services for about 14,000 staff workers of HSBC Asia Pacific as well as its global senior management staff annually.
 * 
 * @tips: 当前代码只能解决句末的'.',但对于用例"U.S."无法解决
 *        且当前代码不能处理回车的输入
 *        三个方法可以合并写
**/
void strSaveToFile()
{
    // str长度必须给足
    char str[1024];
    FILE *fp = NULL;
    // 打开文件,\\为\的转义
    fp = fopen("D:\\abc0.txt", "w");
    if (fp == NULL)
    {
        printf("打开文件D:\\abc0.txt失败!\n");
        exit(-1);
    }
    int result;
    // Ctrl+Z相当于scanf的EOF
    // scanf接收到空格也会截断
    // 需要使用gets,gets遇到Ctrl+Z返回NULL
    while (gets(str) != NULL)
    {
        result = fputs(str, fp);
        if (result == EOF)
        {
            printf("字符串写入文件D:\\abc0.txt出错!\n");
            exit(-1);
        }
    }
    // 关闭文件
    result = fclose(fp);
    if (result == EOF)
    {
        printf("文件D:\\abc0.txt关闭失败!\n");
        exit(-1);
    }
}
void trimStr()
{
    int result, i, last = -1;
    FILE *finp, *foup;
    finp = foup = NULL;
    finp = fopen("D:\\abc0.txt", "r");
    foup = fopen("D:\\abc1.txt", "w");
    if (finp == NULL)
    {
        printf("打开文件D:\\abc0.txt失败!\n");
        exit(-1);
    }
    if (foup == NULL)
    {
        printf("打开文件D:\\abc1.txt失败!\n");
        exit(-1);
    }
    char str[1024];
    while (fgets(str, 1024, finp))
    {
        int len = strlen(str);
        for (i = 0; i < len; i++)
        {
            // 如果是空格
            if (str[i] == ' ')
            {
                if (last == -1)
                {
                    printf("%c", str[i]);
                    result = fputc(str[i], foup);
                    if (result == EOF)
                    {
                        printf("写入字符到文件D:\\abc1.txt出错!\n");
                        exit(-1);
                    }
                    last = i;
                }
                else
                {
                    continue;
                }
            }
            else // 不是空格
            {
                printf("%c", str[i]);
                result = fputc(str[i], foup);
                if (result == EOF)
                {
                    printf("写入字符到文件D:\\abc1.txt出错!\n");
                    exit(-1);
                }
                if (last != -1)
                {
                    last = -1;
                }
            }
        }
    }
    result = fclose(foup);
    if (result == EOF)
    {
        printf("关闭文件D:\\abc1.txt失败!\n");
        exit(-1);
    }
    result = fclose(finp);
    if (result == EOF)
    {
        printf("关闭文件D:\\abc0.txt失败!\n");
        exit(-1);
    }
}
void countStr()
{
    FILE *fp = NULL;
    fp = fopen("D:\\abc1.txt", "r");
    if (fp == NULL)
    {
        printf("打开文件D:\\abc0.txt失败!\n");
        exit(-1);
    }
    char str[1024];
    int i, length, wordCount, sentenceCount;
    length = wordCount = sentenceCount = 0;
    while (fgets(str, 1024, fp))
    {
        int strLength = strlen(str);
        length += strLength;
        for (i = 0; i < strLength; i++)
        {
            if (str[i] == ' ' || str[i] == ',' || str[i] == '.')
            {
                wordCount++;
                if (str[i] == '.')
                {
                    sentenceCount++;
                }
            }
        }
    }
    printf("Char Count: %d\nWord Count: %d\nSentence Count: %d\n", length, wordCount, sentenceCount);
    if (fclose(fp) == EOF)
    {
        printf("文件D:\\abc1.txt关闭失败!\n");
        exit(-1);
    }
}
int main()
{
    strSaveToFile();
    trimStr();
    countStr();
    return 0;
}
