#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 从键盘输入一行英文句子,句子中只有英文单词和空格,每个单词之间由若干个
 * 空格隔开,英文单词由大小写字母组成,变成完成下列任务:
 * 1.统计并输出此句子中英文字母的个数;(10分)
 * 2.统计并输出此句子中单词的个数;(10分)
 * 3.查找此句子中出现次数最多的字母(不区分大小写,大小写字母是相同的)和次数,
 * 当出现最多的字符不只一个时,都能找到,并输出找到的所有字母及次数.(输出字母时大小写均可) (20分)
 *
 * 例如: 输入句子 -> This  Is  An  Pencil   Case
 * 则输出为:
 *      字母个数: 18
 *      单词个数: 5
 *      最多的字母: i,s
 *      出现的次数: 3
 **/
#define TRUE 1
#define FALSE 0
typedef struct LetterData
{
    int count;
    char data;
} LetterData, *Letter;
int compare(const void *p1, const void *p2)
{
    LetterData *ld1 = (Letter)p1;
    LetterData *ld2 = (Letter)p2;
    return ld2->count - ld1->count;
}
char toLowLetter(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}
int findIndex(LetterData *ld, char data, int length)
{
    int i, index = -1;
    for (i = 0; i < length; i++)
    {
        if (ld[i].data == data)
        {
            index = i;
            break;
        }
    }
    return index;
}
int main()
{
    char input[1024], cur;
    gets(input);
    int i, length = strlen(input), letterCount = 0, wordCount = 0, wordFlag = FALSE;
    int count;
    LetterData *ld = NULL;
    for (i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        { // 是空格
            if (wordFlag)
            {
                wordCount++;
                wordFlag = FALSE;
            }
        }
        else
        { // 是字母
            letterCount++;
            cur = input[i];
            if (!wordCount)
                wordCount = TRUE;
            if (ld == NULL)
            {
                ld = (Letter)malloc(sizeof(LetterData));
                ld[0].count = 1;
                ld[0].data = toLowLetter(cur);
                count = 1;
            }
            else
            {
                int index = findIndex(ld, toLowLetter(cur), count);
                if (index == -1)
                {
                    ld = (Letter)realloc(ld, sizeof(LetterData) * (count + 1));
                    ld[count].count = 1;
                    ld[count++].data = toLowLetter(cur);
                }
                else
                    ld[index].count++;
            }
        }
    }
    printf("字母个数: %d\n单词个数: %d\n最多的字母: ", letterCount, wordCount);
    qsort(ld, count, sizeof(LetterData), compare);
    int max = 0;
    for (i = 0; i < count; i++)
    {
        if (max == 0)
        {
            max = ld[i].count;
            printf("%c", ld[i].data);
        }
        else
        {
            if (max == ld[i].count)
                printf(",%c", ld[i].data);
            else
            {
                printf("\n");
                break;
            }
        }
    }
    printf("出现的次数: %d\n", max);
    free(ld);
    return 0;
}
