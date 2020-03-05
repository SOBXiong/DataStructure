#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include "../rule.h"
#define MAX_SIZE 20
using namespace std;

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

typedef struct
{
    BiTree t;
    int tag;
} SStack; // tag=0表示左子女被访问,tag=1表示右子女被访问

// 根据先序次序键入数据构造二叉树
void CreateBiTree(BiTree &t)
{
    ElemType ch;
    scanf("%c", &ch);
    if (ch == ' ' || ch == '\n')
        t = NULL;
    else
    {
        if (!(t = (BiTree)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        t->data = ch;
        CreateBiTree(t->lchild);
        CreateBiTree(t->rchild);
    }
}

//按值查找二叉树中结点
BiTree FindBiNode(BiTree &bt, ElemType e)
{
    if (bt == NULL)
        return NULL;
    if (bt->data == e)
        return bt;
    BiTree p = FindBiNode(bt->lchild, e);
    if (p != NULL)
        return p;
    return FindBiNode(bt->rchild, e);
}

// 销毁二叉树
void DestoryBiTree(BiTree &t)
{
    if (t->lchild)
        DestoryBiTree(t->lchild);
    if (t->rchild)
        DestoryBiTree(t->rchild);
    free(t);
}

// 若T为空二叉树,则返回Ture,否则返回FALSE
Status BiTreeEmpty(BiTree t)
{
    return t ? FALSE : TRUE;
}

// 返回T的深度(递归)
int BiTreeDepth(BiTree t)
{
    if (t == NULL)
        return 0;
    else
    {
        int left = BiTreeDepth(t->lchild);
        int right = BiTreeDepth(t->rchild);
        return left - right >= 0 ? 1 + left : 1 + right;
    }
}

// 返回T的深度(非递归)
int BiTreeDepth2(BiTree t)
{
    queue<BiTree> q;
    if (!t)
        return 0;
    q.push(t);
    int level = 0;
    while (!q.empty())
    {
        int len = q.size();
        level++;
        while (len--)
        {
            BiTree tem = q.front();
            q.pop();
            if (tem->lchild)
                q.push(tem->lchild);
            if (tem->rchild)
                q.push(tem->rchild);
        }
    }
    return level;
}

//有点问题
//统计二叉树t上叶子结点数leaf和非叶子结点数nLeaf
void CountLeaf(BiTree &t, int &leaf, int &nLeaf)
{
    if (t)
    {
        if (t->lchild == NULL && t->rchild == NULL)
            leaf++; //叶子结点
        else
            nLeaf++; //非叶结点
        CountLeaf(t->lchild, leaf, nLeaf);
        CountLeaf(t->rchild, leaf, nLeaf);
    }
} //结束 Count

// visit函数
void visit(ElemType e)
{
    printf("%c", e);
}

// 先序遍历T(非递归)
void PreOrderTraverse(BiTree t, void (*visit)(ElemType))
{
    if (BiTreeEmpty(t))
        return;
    stack<BiTree> temp;
    BiTree p = t;
    printf("\n>>> PreOrderTraverse start : \n");
    while (p || !temp.empty())
    {
        if (p)
        {
            visit(p->data);
            temp.push(p);
            p = p->lchild;
        }
        else
        {
            p = temp.top();
            temp.pop();
            p = p->rchild;
        }
    }
    printf("\n>>> PreOrderTraverse finish!\n");
}

// 中序遍历T(非递归)
void InOrderTraverse(BiTree t, void (*visit)(ElemType))
{
    if (BiTreeEmpty(t))
        return;
    stack<BiTree> temp;
    BiTree p = t;
    printf("\n>>> InOrderTraverse start : \n");
    while (p || !temp.empty())
    {
        if (p)
        {
            temp.push(p);
            p = p->lchild;
        }
        else
        {
            p = temp.top();
            temp.pop();
            visit(p->data);
            p = p->rchild;
        }
    }
    printf("\n>>> InOrderTraverse finish!\n");
}

// 后序遍历T(非递归)
void PostOrderTraverse(BiTree t, void (*visit)(ElemType))
{
    if (BiTreeEmpty(t))
        return;
    stack<BiTree> temp;
    BiTree pre, cur;
    pre = cur = NULL; //pre保存上次操作的结点;cur表示当前栈顶结点
    temp.push(t);
    printf("\n>>> PostOrderTraverse start : \n");
    while (!temp.empty())
    {
        cur = temp.top();                                            //将栈顶元素赋给cur
        if (pre == NULL || pre->lchild == cur || pre->rchild == cur) //若pre为NULL或是cur的父节点
        {
            if (cur->lchild != NULL)
                temp.push(cur->lchild);
            else if (cur->rchild != NULL)
                temp.push(cur->rchild);
        }
        else if (cur->lchild == pre) //若pre是cur的左儿子
        {
            if (cur->rchild != NULL)
                temp.push(cur->rchild);
        }
        else
        {
            visit(cur->data); //访问当前节点
            temp.pop();       //访问后弹出
        }
        pre = cur; //处理完当前节点后将cur节点变为pre节点
    }
    printf("\n>>> PostOrderTraverse finish!\n");
}

// 层次遍历T(非递归)
void LevelOrderTraverse(BiTree t, void (*visit)(ElemType))
{
    queue<BiTree> temp;
    BiTree p;
    temp.push(t);
    printf("\n>>> LevelOrderTraverse start : \n");
    while (!temp.empty())
    {
        p = temp.front();
        temp.pop();
        visit(p->data);
        if (p->lchild)
            temp.push(p->lchild);
        if (p->rchild)
            temp.push(p->rchild);
    }
    printf("\n>>> LevelOrderTraverse finish!\n");
}

// 寻找所有祖先节点
void SearchAncestor(BiTree bt, ElemType e)
{
    SStack s[20];
    int top = 0;
    while (bt != NULL || top > 0)
    {
        while (bt != NULL && bt->data != e)
        {
            s[++top].t = bt;
            s[top].tag = 0;
            bt = bt->lchild;
        }
        if (bt && bt->data == e)
        {
            printf(">>> The searched all ancestors : \n");
            for (int i = 1; i <= top; i++)
                printf("%2c", s[i].t->data);
            break;
        }
        while (top != 0 && s[top].tag == 1)
            top--;
        if (top != 0)
        {
            s[top].tag = 1;
            bt = s[top].t->rchild;
        }
    }
    printf("\n");
}

// 还没弄懂
// 查找两个结点最近的共同祖先节点
BiTree SearchCommonAncestor(BiTree &bt, ElemType e1, ElemType e2)
{
    BiTree p = FindBiNode(bt, e1);
    BiTree q = FindBiNode(bt, e2);
    if (!p || !q)
    {
        printf(">>> Can't find the node!\n");
        return NULL;
    }
    BiTree t = bt;
    int top1, top2;
    SStack s1[20], s2[20];
    top1 = top2 = 0;
    while (t != NULL || top1 > 0)
    {
        while (t != NULL)
        {
            if (t != p && t != q)
            {
                s1[++top1].t = bt;
                s1[top1].tag = 0;
                t = t->lchild;
            }
            else
            {
                s1[++top1].t = t;
                s1[top1].tag = 1;
                break;
            }
        }
        while (top1 != 0 && s1[top1].tag == 1)
        {
            if (s1[top1].t == p)
            {
                for (int i = 1; i <= top1; i++)
                {
                    s2[i] = s1[i];
                    top2 = top1;
                }
            }
            else if (t == q)
            {
                for (int i = top1; i > 0; i--)
                {
                    for (int j = top2; j > 0; j--)
                    {
                        if (s1[i].t == s2[j].t)
                        {
                            return s1[i].t;
                        }
                    }
                }
            }
            top1--;
        }
        if (top1 != 0)
        {
            s1[top1].tag = 1;
            bt = s1[top1].t->rchild;
        }
    }
    return NULL;
}

/**
 * 因为后序遍历栈中保留当前结点的祖先的信息,用一变量保存栈的最高栈顶指针,每当退栈
 * 时,栈顶指针高于保存最高栈顶指针的值时,则将该栈倒入辅助栈中,辅助栈始终保存最长
 * 路径长度上的结点,直至后序遍历完毕,则辅助栈中内容即为所求 
 */
void LongestPath(BiTree bt) //求二叉树中的第一条最长路径长度
{
    BiTree p = bt, l[MAX_SIZE], s[MAX_SIZE]; //l,s是栈,元素是二叉树结点指针;l中保留当前最长路径中的结点
    int i, top = 0, tag[MAX_SIZE], longest = 0;
    while (p || top > 0)
    {
        while (p)
        {
            //沿左分枝向下
            s[++top] = p;
            tag[top] = 0;
            p = p->lchild;
        }
        if (tag[top] == 1) //当前结点的右分枝已遍历
        {
            if (!s[top]->lchild && !s[top]->rchild)
            { //到叶子结点时,查看路径长度
                if (top > longest)
                {
                    //保留当前最长路径到l栈,记住最高栈顶指针,退栈
                    for (i = 1; i <= top; i++)
                        l[i] = s[i];
                    longest = top;
                    top--;
                }
                else
                {
                    // 退到没有右分支遍历的结点
                    while (tag[top])
                        top--;
                }
            }
        }
        else if (top > 0)
        { //沿右子分枝向下
            tag[top] = 1;
            p = s[top]->rchild;
        }
    }
    printf(">>> The longest length is %d\n", longest);
    for (int i = 1; i <= longest; i++)
        printf(">>> In round %d data %c \n", i, l[i]->data);
}

// 用例:-+a  *b  -c  d  /e  f  (结束)
int main()
{
    BiTree t;
    CreateBiTree(t);
    // printf(">>> The Tree's depth is %d \n", BiTreeDepth(t));
    // printf(">>> The Tree's depth is %d \n", BiTreeDepth2(t));
    PreOrderTraverse(t, visit);
    int leaf = 0, nLeaf = 0;
    CountLeaf(t, leaf, nLeaf);
    printf(">>> The leaf num = %d , the nLeaf num = %d \n", leaf, nLeaf);
    LongestPath(t);
    // BiTree result = SearchCommonAncestor(t, 'b', 'c');
    // printf(">>> Searched common ancestor %2c \n:", result == NULL ? '\0' : result->data);
    // SearchAncestor(t, 'c');
    // InOrderTraverse(t, visit);
    // PostOrderTraverse(t, visit);
    // LevelOrderTraverse(t, visit);
    return 0;
}