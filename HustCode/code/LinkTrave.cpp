#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
    int data;
    LinkNode *next;
} LinkNode, *LinkList;
void insertList(LinkList &l, int data)
{
    // 只有头节点
    if (l->next == NULL)
    {
        // 插入
        LinkList p = (LinkList)malloc(sizeof(LinkNode));
        p->next = NULL;
        p->data = data;
        l->next = p;
    }
    else
    {
        // 工作节点p,q
        LinkList q = l;
        LinkList p = l->next;
        while (NULL != p)
        {
            if(p->data > data) break;
            p = p->next;
            q = q->next;
        }
        // q、p之间为需要插入的位置
        LinkList s = (LinkList)malloc(sizeof(LinkNode));
        s->next = p;
        s->data = data;
        q->next = s;
    }
}
void printList(LinkList l)
{
    // 工作节点
    LinkList p = l->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void freeList(LinkList &l)
{
    // 工作节点
    LinkList p = l->next->next, q = l->next;
    while (q != NULL)
    {
        // 释放q
        q->next = NULL;
        free(q);
        // 将下一个需要释放的结点交给q
        q = p;
        // p继续推进
        if (p != NULL)
            p = p->next;
    }
    // 最后将l的next置空
    l->next = NULL;
}
int main()
{
    int n, data, i;
    LinkList l = (LinkList)malloc(sizeof(LinkNode));
    l->next = NULL;
    while (~scanf("%d", &n))
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &data);
            insertList(l, data);
        }
        printList(l);
        freeList(l);
    }
    free(l);
    return 0;
}