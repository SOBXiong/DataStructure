#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"
using namespace std;

typedef char ElemType;
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild; // 左右孩子指针
    int ltag, rtag;                     // 左右线索标志
} ThreadNode, *ThreadTree;

// 根据先序次序键入数据构造二叉树
void CreateThreadTree(ThreadTree &t)
{
    ElemType ch;
    scanf("%c", &ch);
    if (ch == ' ' || ch == '\n')
        t = NULL;
    else
    {
        if (!(t = (ThreadTree)malloc(sizeof(ThreadNode))))
            exit(OVERFLOW);
        t->data = ch;
        t->ltag = t->rtag = 0;
        CreateThreadTree(t->lchild);
        CreateThreadTree(t->rchild);
    }
}

// 中序遍历线索化
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre);
        if (!p->lchild)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && !pre->rchild)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// 中序遍历建立中序线索二叉树
void createInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 中序线索二叉树中序序列下第一个结点
ThreadTree FirstInNode(ThreadTree p)
{
    while (!p->ltag)
        p = p->lchild;
    return p;
}

// 中序线索二叉树中序序列下后继结点
ThreadTree NextInNode(ThreadTree p)
{
    if (!p->rtag)
        return FirstInNode(p->rchild);
    else
        return p->rchild;
}

// 中序线索二叉树遍历算法
void InOrder(ThreadTree T, void (*visit)(ThreadTree))
{
    printf(">>> ltag --- rtag --- data\n");
    for (ThreadTree p = FirstInNode(T); p; p = NextInNode(p))
        visit(p);
    printf("\n");
}

// 递归中序遍历
void InOrder2(ThreadTree T, void (*visit)(ThreadTree))
{
    if (T != NULL)
    {
        if (T->ltag == 0)
            InOrder2(T->lchild, visit);
        visit(T);
        if (T->rtag == 0)
            InOrder2(T->rchild, visit);
    }
}

// visit函数
void visit(ThreadTree p)
{
    printf("%6d %8d %8c\n", p->ltag, p->rtag, p->data);
}

// 用例:-+a  *b  -c  d  /e  f  (结束)
int main()
{
    ThreadTree t;
    CreateThreadTree(t);
    createInThread(t);
    // printf(">>> ltag --- rtag --- data\n");
    // InOrder2(t, visit);
    // printf("\n");
    InOrder(t, visit);
    return 0;
}