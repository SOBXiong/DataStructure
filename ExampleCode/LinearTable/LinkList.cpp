#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

typedef int ElemType; //定义ElemType为int类型
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

// 尾插
void ListEndInsert(LinkedList l, ElemType e)
{
    LNode *p = l;
    while (p->next)
    {
        p = p->next;
    }
    LNode *s = (LinkedList)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    p->next = s;
}

// 在指定位置后插入
Status ListInsert(LinkedList l, int i, ElemType e)
{
    LNode *p = l;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    LNode *s = (LinkedList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 遍历
void ListTraverse(LinkedList l, void (*visit)(int, ElemType))
{
    if (l == NULL)
    {
        printf(">>> Empty List !\n");
        return;
    }
    LNode *p = l->next;
    int i = 1;
    while (p)
    {
        visit(i++, p->data);
        p = p->next;
    }
}

// visit函数
void visit(int i, ElemType e)
{
    printf("ListTraverse >>> Node: %d == data: %d\n", i++, e);
}

// 取指定位置的元素
Status GetElem(LinkedList l, int i, ElemType *e)
{
    LNode *p = l->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

// 删除元素
Status ListDelete(LinkedList l, int i, ElemType *e)
{
    LNode *p = l;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    *e = q->data;
    q->next = NULL;
    free(q);
    return OK;
}

// 创建n个数据的线性链表
void CreateList(LinkedList *l, int n)
{
    // *ll 是变量,ll是地址,*ll可以改变
    *l = (LinkedList)malloc(sizeof(LNode));
    if (!*l)
        exit(OVERFLOW);
    (*l)->next = NULL;
    LNode *p;
    for (int i = n; i > 0; --i)
    {
        fflush(stdin);
        p = (LinkedList)malloc(sizeof(LNode));
        if (!p)
            exit(OVERFLOW);
        scanf("%d", &p->data);
        // 尾插法
        p->next = (*l)->next;
        (*l)->next = p;
    }
}

// 合并非递减排列的la和lb成lc
void MergeList(LinkedList *la, LinkedList *lb, LinkedList *lc)
{
    LNode *pa = (*la)->next;
    LNode *pb = (*lb)->next;
    LNode *pc;
    *lc = pc = *la;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(lb);
}

// 清空链表
void ClearList(LinkedList *l)
{
    LNode *p = (*l)->next;
    (*l)->next = NULL;
    LNode *q;
    while (p->next)
    {
        q = p;
        p = p->next;
        q->next = NULL;
        free(q);
    }
}

// 销毁链表
void DestoryList(LinkedList *l)
{
    ClearList(l);
    // 使用后该指针变量一定要重新指向NULL，防止野指针出现，有效规避错误操作。
    free(l);
    (*l) = NULL;
}

// 判断是否为空
Status ListEmpty(LinkedList l)
{
    return l->next ? TRUE : FALSE;
}

// 返回线性表的长度
int ListLength(LinkedList l)
{
    int i = 0;
    LNode *p = l->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

// 是否相等的比较函数
Status compare(ElemType e1, ElemType e2)
{
    return e1 == e2 ? TRUE : FALSE;
}

// 返回元素e第一次在线性表的位置
int LocateElem(LinkedList l, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int length = ListLength(l);
    if (l == 0)
        return ERROR;
    ElemType temp;
    int i = 1;
    while (i <= length)
    {
        GetElem(l, i, &temp);
        if (compare(temp, e))
            break;
        i++;
    }
    if (i > length)
        return ERROR;
    return i;
}

// 返回元素e的前一个元素
Status PriorElem(LinkedList l, ElemType e, ElemType *pre)
{
    int index = LocateElem(l, e, compare);
    if (index <= 1 || index > ListLength(l))
        return ERROR;
    GetElem(l, index - 1, pre);
    return OK;
}

// 返回元素e的后一个元素
Status NextElem(LinkedList l, ElemType e, ElemType *next)
{
    int index = LocateElem(l, e, compare);
    if (index < 1 || index >= ListLength(l))
        return ERROR;
    GetElem(l, index + 1, next);
    return OK;
}

// 使用头插法逆置
void Reverse_1(LinkedList &l)
{
    if (!l || !l->next)
        return;
    LinkedList r, p;
    p = l->next;
    l->next = NULL;
    for (; p != NULL; p = r)
    {
        r = p->next;
        // 头插法
        p->next = l->next;
        l->next = p;
    }
}

// 使用普通倒置法
void Reverse_2(LinkedList &l)
{
    if (!l || !l->next)
        return;
    LinkedList pre, p = l->next, r = p->next;
    p->next = NULL;
    while (r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    l->next = p;
}

int main()
{
    LinkedList l = (LinkedList)malloc(sizeof(LNode));
    l->next = NULL;
    printf("Length l is >>> %d\n", ListLength(l));
    ListEndInsert(l, 1);
    ListEndInsert(l, 2);
    ListEndInsert(l, 3);
    ListInsert(l, 1, 4);
    ListInsert(l, 1, 5);
    printf("Length l is >>> %d\n", ListLength(l));
    printf("data 0 in l index is >>> %d \n", LocateElem(l, 0, compare));
    ElemType e;
    PriorElem(l, 5, &e);
    printf("data 4 pre data is >>> %d \n", e);
    NextElem(l, 3, &e);
    printf("data 2 next data is >>> %d \n", e);
    ListTraverse(l, visit);
    // Reverse_1(l);
    Reverse_2(l);
    printf("After ListTraverse:\n");
    ListTraverse(l, visit);
    ClearList(&l);
    printf("\n");
    ListEndInsert(l, 1);
    ListEndInsert(l, 2);
    ListEndInsert(l, 3);
    ListTraverse(l, visit);
    DestoryList(&l);
    ListTraverse(l, visit);
    return 0;
}
