#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int main()
{
    int curLongestLen = -1;
    int curShortestLen = -1;
    char data[1000], *temp;
    queue<char *> lQ;
    queue<char *> sQ;
    // scanf遇到tab、空格、回车默认不读取
    while (gets(data))
    {
        if (strlen(data) == 0)
            break;
        int curLen = strlen(data);
        // 初始化
        if (curLongestLen == -1 && curShortestLen == -1)
        {
            /**
                不能用栈内寸分配char*,因为queue传入的
                是char数组的首地址,栈内寸只有一份
                地址不变,里面的值会随着代码中的赋值而变化
                故需要利用对内存动态分配
            **/

            // 以下两份赋值同理
            temp = (char *)malloc(sizeof(char) * 100);
            strcpy(temp, data);
            lQ.push(temp);
            temp = (char *)malloc(sizeof(char) * 100);
            strcpy(temp, data);
            sQ.push(temp);
            curLongestLen = curShortestLen = curLen;
        }
        else
        {
            if (curLen > curLongestLen)
            {
                // 清空最长队列
                while (!lQ.empty())
                {
                    // 暂存首地址并释放
                    temp = lQ.front();
                    lQ.pop();
                    free(temp);
                }
                temp = (char *)malloc(sizeof(char) * 100);
                strcpy(temp, data);
                lQ.push(temp);
                curLongestLen = curLen;
            }
            else if (curLen == curLongestLen)
            {
                temp = (char *)malloc(sizeof(char) * 100);
                strcpy(temp, data);
                lQ.push(temp);
            }

            if (curLen < curShortestLen)
            {
                // 清空最短队列
                while (!sQ.empty())
                {
                    temp = sQ.front();
                    sQ.pop();
                    free(temp);
                }
                temp = (char *)malloc(sizeof(char) * 100);
                strcpy(temp, data);
                sQ.push(temp);
                curShortestLen = curLen;
            }
            else if (curLen == curShortestLen)
            {
                temp = (char *)malloc(sizeof(char) * 100);
                strcpy(temp, data);
                sQ.push(temp);
            }
        }
    }
    // 输出最短队列
    while (!sQ.empty())
    {
        temp = sQ.front();
        printf("%s\n", temp);
        sQ.pop();
        free(temp);
    }

    // 输出最长队列
    while (!lQ.empty())
    {
        temp = lQ.front();
        printf("%s\n", temp);
        lQ.pop();
        free(temp);
    }
    return 0;
}
