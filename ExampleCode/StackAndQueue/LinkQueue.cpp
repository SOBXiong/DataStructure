#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

typedef int ElemType;
typedef struct QNode
{
    ElemType data;      // 数据域
    struct QNode *next; // 指针域
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear;  // 队尾指针
} LinkQueue;

// 构造一个空队列Q
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = (QNode *)malloc(sizeof(QNode));
    if (!q.front)
        exit(OVERFLOW);
    q.front->next = q.rear->next = NULL;
}

// 销毁队列Q,Q不再存在
void DestoryQueue(LinkQueue &q)
{
    while (q.front)
    {
        q.rear = q.front->next;
        free(q.front);
        q.front = q.rear;
    }
}

// 将Q清空为空队列
void ClearQueue(LinkQueue &q)
{
    QNode *p = q.front->next;
    while (p)
    {
        q.front->next = p->next;
        free(p);
        p = q.front->next;
    }
    q.rear = q.front;
}

// 判断队列是否为空
Status QueueEmpty(LinkQueue q)
{
    return q.front == q.rear ? TRUE : FALSE;
}

// 返回Q的元素个数(队列的长度)
int QueueLength(LinkQueue q)
{
    if (QueueEmpty(q))
        return 0;
    QNode *p = q.front->next;
    int count = 0;
    while (p != q.rear)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 若队列不为空,则用e返回Q的队头元素,并返回OK;否则返回ERROR
Status GetHead(LinkQueue q, ElemType &e)
{
    if (QueueEmpty(q))
        return ERROR;
    e = q.front->next->data;
    return OK;
}

// 插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue &q, ElemType e)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
    return OK;
}

// 若队列不空,则删除Q的队头元素,并用e返回其值,并返回OK;
// 否则返回ERROR
Status DeQueue(LinkQueue &q, ElemType &e)
{
    if (QueueEmpty(q))
        return ERROR;
    QNode *p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if (q.rear == p)
        q.rear = q.front;
    free(p);
    return OK;
}

// visit遍历函数
void visit(int i, ElemType e)
{
    printf(">>> Queue traverse %d th data: %d\n", i++, e);
}

// 从队头到队尾依次遍历元素
Status QueueTraverse(LinkQueue q, void (*visit)(int, ElemType))
{
    printf("\n>>> Queue traverse start: \n");
    if (QueueEmpty(q))
        return FALSE;
    int count = 0;
    QNode *p = q.front->next;
    while (p != q.rear)
    {
        visit(++count, p->data);
        p = p->next;
    }
    printf(">>> Queue traverse finish! \n\n");
    return OK;
}

int main()
{
    LinkQueue lq;
    InitQueue(lq);
    printf(">>> The Queue is empty : %d\n", QueueEmpty(lq));
    EnQueue(lq, 0);
    printf(">>> The Queue is empty : %d\n", QueueEmpty(lq));
    int i = 0;
    while ((++i) < 15)
        EnQueue(lq, i);
    QueueTraverse(lq, visit);
    printf(">>> The Queue length is %d\n", QueueLength(lq));
    ElemType e;
    DeQueue(lq, e);
    printf(">>> Remove the top number : %d \n", e);
    GetHead(lq, e);
    printf(">>> Get the top number : %d\n", e);
    ClearQueue(lq);
    printf(">>> After clear,the length is %d, is empty : %d\n", QueueLength(lq), QueueEmpty(lq));
    printf(">>> After clear,the front address is : %x,the rear address is : %x\n", lq.front, lq.rear);
    DestoryQueue(lq);
    printf(">>> After destory,the front address is NULL : %d,the rear address is NULL : %d\n",
           lq.front == NULL ? TRUE : FALSE, lq.rear == NULL ? TRUE : FALSE);
    return 0;
}