#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

#define MAXQSIZE 12 // 最大队列长度
typedef int ElemType;
typedef struct
{
    ElemType *base; // 初始化的动态分配存储空间
    int front;      // 头指针
    int rear;       // 尾指针
} SqQueue;

// 构造一个空队列Q
Status InitQueue(SqQueue &q)
{
    q.base = (ElemType *)malloc(MAXQSIZE * sizeof(ElemType));
    if (!q.base)
        exit(OVERFLOW);
    q.front = q.rear = 0;
    return OK;
}

// 销毁队列Q,Q不再存在
void DestoryQueue(SqQueue &q)
{
    free(q.base);
}

// 将Q清空为空队列
void ClearQueue(SqQueue &q)
{
    q.front = q.rear = 0;
}

// 判断队列是否为空
Status QueueEmpty(SqQueue q)
{
    return q.front == q.rear ? TRUE : FALSE;
}

// 返回Q的元素个数,即队列长度
int QueueLength(SqQueue q)
{
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

// 若队列不为空,则用e返回Q的队头元素,并返回OK;否则返回ERROR
Status GetHead(SqQueue q, ElemType &e)
{
    if (QueueEmpty(q))
        return ERROR;
    e = q.base[q.front];
    return OK;
}

// 插入元素e为Q的新的队尾元素
Status EnQueue(SqQueue &q, ElemType e)
{
    if ((q.rear + 1) % MAXQSIZE == q.front)
    {
        printf(">>> The Queue is full!\n");
        return ERROR;
    }
    q.base[q.rear] = e;
    q.rear = (q.rear + 1) % MAXQSIZE;
    return OK;
}

// 若队列不空,删除Q的队头元素,用e返回其值,返回OK
// 否则返回ERROR
Status DeQueue(SqQueue &q, ElemType &e)
{
    if (QueueEmpty(q))
        return ERROR;
    e = q.base[q.front];
    q.front = (q.front + 1) % MAXQSIZE;
    return OK;
}

// visit遍历函数
void visit(int i, ElemType e)
{
    printf(">>> Queue traverse %d th data: %d\n", i++, e);
}

// 从队头到队尾依次遍历元素
Status QueueTraverse(SqQueue q, void (*visit)(int, ElemType))
{
    printf("\n>>> Queue traverse start: \n");
    if (QueueEmpty(q))
        return FALSE;
    int count = 0;
    int p = q.front;
    while (p != q.rear)
    {
        visit(++count, q.base[p]);
        p = (p + 1) % MAXQSIZE;
    }
    printf(">>> Queue traverse finish! \n\n");
    return OK;
}

int main()
{
    SqQueue sq;
    InitQueue(sq);
    printf(">>> The Queue is empty : %d\n", QueueEmpty(sq));
    EnQueue(sq, 0);
    printf(">>> The Queue is empty : %d\n", QueueEmpty(sq));
    int i = 0;
    int tag = OK;
    while ((++i) < 15 && tag)
        tag = EnQueue(sq, i);
    QueueTraverse(sq, visit);
    printf(">>> The Queue length is %d\n", QueueLength(sq));
    ElemType e;
    DeQueue(sq, e);
    printf(">>> Remove the top number : %d \n", e);
    GetHead(sq, e);
    printf(">>> Get the top number : %d\n", e);
    ClearQueue(sq);
    printf(">>> After clear,the length is %d, is empty : %d\n", QueueLength(sq), QueueEmpty(sq));
    printf(">>> After clear,the base address is : %x\n", sq.base);
    DestoryQueue(sq);
    printf(">>> After destory,the base address is NULL : %d\n", sq.base ? TRUE : FALSE);
    return 0;
}