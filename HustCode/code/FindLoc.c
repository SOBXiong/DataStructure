#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    while (~scanf("%s", str))
    {
        int strLen = strlen(str);
        int i, j;
        int *flag = (int *)malloc(sizeof(int) * strLen);
        // 初始化flag数组
        for (i = 0; i < strLen; i++)
        {
            flag[i] = 1;
        }
        for (i = 0; i < strLen; i++)
        {
            // 如果没被标记过,说明0次
            if (flag[i])
            {
                flag[i] = 0;
                int second = 0;
                // 继续往后找
                for (j = i + 1; j < strLen; j++)
                {
                    if (str[j] == str[i])
                    {
                        // 标记已被访问
                        flag[j] = 0;
                        if (second == 0)
                        {
                            printf("%c:%d,%c:%d", str[i], i, str[j], j);
                            second = 1;
                        }
                        else
                        {
                            printf(",%c:%d", str[j], j);
                        }
                    }
                    // 到结尾了
                    if (j == strLen - 1 && second)
                    {
                        printf("\n");
                    }
                }
            }
        }
        free(flag);
    }
    return 0;
}
