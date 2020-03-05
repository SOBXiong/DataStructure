#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
} componet, SLinkList[MAXSIZE];

// 返回对应数据的下标
int LocateElem(SLinkList s, ElemType e)
{
    int i = s[0].cur;
    while (i && s[i].data != e)
        i = s[i].cur;
    return i;
}

// 初始化静态链表
void InitSpace(SLinkList &space)
{
    // 链接
    for (int i = 0; i < MAXSIZE - 1; ++i)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
}

// 返回分配节点下标
int Malloc(SLinkList &space)
{
    // 当前备用空间
    int i = space[0].cur;
    // 找到下一个空闲节点
    if (space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

// 释放k节点
void Free(SLinkList &space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

// 遍历静态链表
void ListTraverse(int head, SLinkList space, void (*visit)(int, ElemType))
{
    // cur[0]为备用链表头,cur[head]为头指针
    int cur = space[head].cur;
    int i = 0;
    while (cur)
    {
        visit(++i, space[cur].data);
        cur = space[cur].cur;
    }
    printf(">>> ListTraverse finish! \n\n");
}

void visit(int i, ElemType e)
{
    printf(">>> the data in index %2d is %2d \n", i, e);
}

// 在space中建立(A-B)∪(B-A)
void difference(SLinkList &space, int &s)
{
    InitSpace(space);
    s = Malloc(space);
    // 头结点
    int r = s;
    int m, n;
    scanf("%d %d", &m, &n);
    // 将输入的A的元素值入链表
    for (int j = 1; j <= m; ++j)
    {
        int i = Malloc(space);
        scanf("%d", &space[i].data);
        space[r].cur = i;
        r = i;
    }
    // 尾结点置空
    space[r].cur = 0;
    printf(">>> A's numbers : \n");
    ListTraverse(s, space, visit);
    // 对输入的B的元素操作
    for (int j = 1; j <= n; ++j)
    {
        int b;
        scanf("%d", &b);
        int p = s;
        int k = space[s].cur;
        // 查找b元素
        while (k != space[r].cur && space[k].data != b)
        {
            p = k;
            k = space[k].cur;
        }
        // 不存在该元素
        if (k == space[r].cur)
        {
            int i = Malloc(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
        }
        else
        { // 该元素在表中
            space[p].cur = space[k].cur;
            Free(space, k);
            if (r == k)
                r = p;
        }
    }
}

/**
 * 示例: A = {3,2,5,7,6,4} , B = {1,2,19,6}
 **/

int main()
{
    SLinkList s;
    int head;
    difference(s, head);
    printf("\n >>> After diffence : \n");
    ListTraverse(head, s, visit);
    return 0;
}