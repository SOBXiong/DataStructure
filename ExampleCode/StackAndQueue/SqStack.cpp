#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

#define STACK_INIT_SIZE 12     // 存储空间初始分配量
#define STACK_INCREMENT_SIZE 6 // 存储空间分配增量
typedef int ElemType;
typedef struct
{
    ElemType *base; // 栈基址
    ElemType *top;  // 栈顶指针
    int stackSize;  // 当前已分配的存储空间
} SqStack;

// 创建一个空栈
Status InitStack(SqStack &s)
{
    s.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s.base)
        exit(OVERFLOW); // 存储分配失败
    s.top = s.base;
    s.stackSize = STACK_INIT_SIZE;
    return OK;
}

// 返回栈是否为空
Status StackEmtpy(SqStack s)
{
    return s.top == s.base ? TRUE : FALSE;
}

// 返回s的栈顶元素
Status GetTop(SqStack s, ElemType &e)
{
    if (StackEmtpy(s))
        return ERROR;
    e = *(s.top - 1);
    return OK;
}

// 插入新的栈顶元素
Status Push(SqStack &s, ElemType e)
{
    if (s.top - s.base >= s.stackSize)
    {
        printf(">>> Before increment the base address is %x,the top %x\n",s.base,s.top);
        s.base = (ElemType *)realloc(s.base, (s.stackSize + STACK_INCREMENT_SIZE) * sizeof(ElemType));
        if (!s.base)
            exit(OVERFLOW); // 存储分配失败
        s.top = s.base + s.stackSize;
        printf(">>> After realloc the base address is %x,the top %x\n",s.base,s.top);
        s.stackSize += STACK_INCREMENT_SIZE;
    }
    *s.top++ = e;
    return OK;
}

// 删除s的栈顶元素并返回
Status Pop(SqStack &s, ElemType &e)
{
    if (StackEmtpy(s))
        return ERROR;
    e = *--s.top;
    return OK;
}

// 返回栈的长度(元素个数)
int StackLength(SqStack s)
{
    return s.top - s.base;
}

// visit函数
void visit(int i, ElemType e)
{
    printf(">>> Stack traverse %d th data: %d\n", i++, e);
}

// 从栈底至栈顶遍历元素
Status StackTraverse(SqStack s, void (*visit)(int, ElemType))
{
    printf("\n>>> Stack traverse start: \n");
    if (StackEmtpy(s))
        return FALSE;
    ElemType *p = s.base;
    while (p != s.top)
        visit(p - s.base, *p++);
    printf(">>> Stack traverse finish! \n\n");
    return OK;
}

// 把s置为空栈
void ClearStack(SqStack &s)
{
    s.top = s.base;
}

// 销毁栈s,s不再存在
void DestoryStack(SqStack &s)
{
    s.top = NULL;
    ElemType *p = s.base;
    s.base = NULL;
    free(s.base);
}

int main()
{
    SqStack ss;
    InitStack(ss);
    printf(">>> The Stack is empty : %d\n", StackEmtpy(ss));
    Push(ss, -1);
    printf(">>> The Stack is empty : %d\n", StackEmtpy(ss));
    int i = -1;
    while ((++i) < 15)
        Push(ss, i);
    StackTraverse(ss, visit);
    printf(">>> The Stack length is %d\n", StackLength(ss));
    ElemType e;
    Pop(ss, e);
    printf(">>> Remove the top number : %d \n", e);
    GetTop(ss, e);
    printf(">>> Get the top number : %d\n", e);
    ClearStack(ss);
    printf(">>> After clear,the length is %d, is empty : %d\n", StackLength(ss), StackEmtpy(ss));
    DestoryStack(ss);
    printf(">>> After destory,the base address is null : %d\n", ss.base == NULL ? TRUE : FALSE);
    return 0;
}