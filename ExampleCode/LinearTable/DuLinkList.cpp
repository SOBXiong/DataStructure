#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

typedef int ElemType;

// 带头节点的双循环线性表
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

// 获取第i个位置的节点(0 <= i <= 表长)
DuLinkList getElemNode(DuLinkList &L, int i)
{
    DuLinkList p = L->next;
    int cur = 0;
    while (cur < i - 1)
    {
        p = p->next;
        if (p->data == -1)
        { // 循环到头结点
            p = NULL;
            break;
        }
    }
    return p;
}

// 在第i个位置前插入元素(1 <= i <= 表长)
Status ListInsert(DuLinkList &L, int i, ElemType e)
{
    DuLinkList p;
    if (!(p = getElemNode(L, i)))
        return ERROR;
    DuLinkList s;
    if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
        return OVERFLOW;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

// 在第i个位置后插入元素(1 <= i <= 表长)
Status ListInsertAfter(DuLinkList &L, int i, ElemType e)
{
    DuLinkList p;
    if (!(p = getElemNode(L, i - 1)))
        return ERROR;
    DuLinkList s;
    if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
        return OVERFLOW;
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return OK;
}

// 删除第i个元素(1 <= i <= 表长)
Status ListDelete(DuLinkList &L, int i, ElemType e)
{
    DuLinkList p;
    if (!(p = getElemNode(L, i)))
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

// 遍历
void ListTraverse(DuLinkList L, void (*visit)(int, ElemType), bool fromFront)
{
    if (L == NULL)
    {
        printf(">>> Empty List !\n");
        return;
    }
    DuLNode *p = fromFront ? L->next : L->prior;
    int i = 1;
    while (p->data != -1)
    {
        visit(i++, p->data);
        p = fromFront ? p->next : p->prior;
    }
    printf(">>> ListTraverse finish\n");
}

// visit函数
void visit(int i, ElemType e)
{
    printf(">>> ListTraverse Node: %d == data: %d\n", i++, e);
}

int main()
{
    DuLinkList p;
    p = (DuLinkList)malloc(sizeof(DuLNode));
    p->next = p->prior = p;
    p->data = -1;
    ListInsertAfter(p, 1, 5);
    ListInsertAfter(p, 2, 12);
    ListInsert(p, 1, 4);
    ListTraverse(p, visit, true);
    ListTraverse(p, visit, false);
    return 0;
}