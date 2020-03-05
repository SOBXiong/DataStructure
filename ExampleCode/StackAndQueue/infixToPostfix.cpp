#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"
#define MAX_SIZE 20

typedef int ElemType;
typedef struct
{
    char data;    // 字符
    int priority; // 优先级
} Priority;

typedef struct
{
    char data[MAX_SIZE]; // 数据
    int len;             // 当前长度
} stack;

Priority Isp[7], Icp[7];

// 初始化运算符优先级表
void init()
{
    char data[8] = "#(*/+-)";
    int isp[7] = {0, 1, 5, 5, 3, 3, 6};
    int icp[7] = {0, 6, 4, 4, 2, 2, 1};
    for (int i = 0; i < 7; i++)
    {
        Icp[i].data = Isp[i].data = data[i];
        Icp[i].priority = icp[i];
        Isp[i].priority = isp[i];
    }
}

// 根据运算符优先表查询优先级
int getPriority(char c, int isp)
{
    Priority p;
    for (int i = 0; i < 7; i++)
    {
        p = isp == 1 ? Isp[i] : Icp[i];
        if (p.data == c)
            return p.priority;
    }
    return -1;
}

// 转换函数
void match(char *exp, int len, void (*print)(stack, stack, int, char))
{
    stack in, out;
    in.len = out.len = -1;
    char cur;
    for (int i = 0; i < len; i++)
    {
        cur = exp[i];
        // 操作数直接输出
        if (cur >= 'a' && cur <= 'z')
            out.data[++out.len] = cur;
        else // 运算符进行判断
        {
            // 查询栈外、栈内优先级
            int outPriority = getPriority(cur, 0);
            int inPriority = getPriority(in.data[in.len], 1);
            if (outPriority > inPriority) // 栈外优先级高,进栈
                in.data[++in.len] = cur;
            else if (outPriority == inPriority) // 优先级一样高,直接退栈
                in.len--;
            else
            { // 栈内优先级高,退栈并输出;栈外进栈
                while (outPriority < inPriority)
                {
                    out.data[++out.len] = in.data[in.len--];
                    inPriority = getPriority(in.data[in.len], 1);
                }
                if (outPriority > inPriority) // 栈外优先级高,进栈
                    in.data[++in.len] = cur;
                else // 优先级一样高,直接退栈
                    in.len--;
            }
        }
        print(in, out, i, cur);
    }
    printf("\n");
}

// 打印当前输入输出栈的内容
void print(stack in, stack out, int round, char data)
{
    printf(">>> In round : %d   data : %c\n>>> In stack : ", round, data);
    if (in.len != -1)
        for (int i = 0; i <= in.len; i++)
            printf("%c", in.data[i]);
    printf("\n>>> Output : ");
    if (out.len != -1)
        for (int i = 0; i <= out.len; i++)
            printf("%c", out.data[i]);
    printf("\n");
}

// 示例: 19 a+b-a*((c+d)/e-f)+g
// 23 a+((b*c-d)/e+f*g/h)+i/j
int main()
{
    init();
    int len;
    scanf("%d", &len);
    char *exp = (char *)malloc((len + 3) * sizeof(char)); // 两个# 一个\0结束标志符
    scanf("%s", exp + 1);
    exp[0] = exp[len + 1] = '#';
    match(exp, len + 2, print);
}