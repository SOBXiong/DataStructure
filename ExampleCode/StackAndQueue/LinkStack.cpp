#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;         // 数据域
    struct LinkNode *next; // 指针域
} * LinkStack, LinkNode;

// 创建一个空栈
void InitStack(LinkStack &s)
{
    s->data = -1;
    s->next = NULL;
}

// 返回栈是否为空
Status StackEmtpy(LinkStack s)
{
    return !s->next ? TRUE : FALSE;
}

// 返回s的栈顶元素
Status GetTop(LinkStack s, ElemType &e)
{
    if (StackEmtpy(s))
        return ERROR;
    e = s->next->data;
    return OK;
}

// 插入新的栈顶元素
Status Push(LinkStack &s, ElemType e)
{
    LinkStack p = (LinkNode *)malloc(sizeof(LinkNode));
    if (!p)
        exit(OVERFLOW); // 存储分配失败
    p->next = s->next;
    p->data = e;
    s->next = p;
    return OK;
}

// 删除s的栈顶元素并返回
Status Pop(LinkStack &s, ElemType &e)
{
    if (StackEmtpy(s))
        return ERROR;
    LinkNode *p = s->next;
    e = p->data;
    s->next = p->next;
    p->next = NULL;
    free(p);
    return OK;
}

// 返回栈的长度(元素个数)
int StackLength(LinkStack s)
{
    int count = 0;
    LinkNode *p = s;
    while (p = p->next)
        count++;
    return count;
}

// visit函数
void visit(int i, ElemType e)
{
    printf(">>> Stack traverse %d th data: %d\n", i++, e);
}

// 从栈底至栈顶遍历元素
Status StackTraverse(LinkStack s, void (*visit)(int, ElemType))
{
    printf("\n>>> Stack traverse start: \n");
    if (StackEmtpy(s))
        return FALSE;
    int count = 0;
    LinkNode *p = s;
    while (p = p->next)
        visit(++count, p->data);
    printf(">>> Stack traverse finish! \n\n");
    return OK;
}

// 把s置为空栈
void ClearStack(LinkStack &s)
{
    LinkNode *p;
    while (s->next)
    {
        p = s->next;
        s->next = p->next;
        p->next = NULL;
        free(p);
    }
}

// 销毁栈s,s不再存在
void DestoryStack(LinkStack &s)
{
    ClearStack(s);
    s = NULL;
}

int main()
{
    LinkStack ls = (LinkNode *)malloc(sizeof(LinkNode));
    InitStack(ls);
    printf(">>> The Stack is empty : %d\n", StackEmtpy(ls));
    Push(ls, 0);
    printf(">>> The Stack is empty : %d\n", StackEmtpy(ls));
    int i = 0;
    while ((++i) < 15)
        Push(ls, i);
    StackTraverse(ls, visit);
    printf(">>> The Stack length is %d\n", StackLength(ls));
    ElemType e;
    Pop(ls, e);
    printf(">>> Remove the top number : %d \n", e);
    GetTop(ls, e);
    printf(">>> Get the top number : %d\n", e);
    ClearStack(ls);
    printf(">>> After clear,the length is %d, is empty : %d\n", StackLength(ls), StackEmtpy(ls));
    DestoryStack(ls);
    printf(">>> After destory,the struct address is null : %d\n", ls == NULL ? TRUE : FALSE);
    return 0;
}