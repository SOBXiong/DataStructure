#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct BNode
{
    int data;
    struct BNode *left, *right;
} BNode, *BTree;
void createBST(BTree &t, int data, int isFirst)
{
    if (isFirst)
    {
        t->data = data;
        return;
    }
    // 插到右边
    if (data > t->data)
    {
        if (t->right != NULL)
            createBST(t->right, data, FALSE);
        else
        {
            BTree child = (BNode *)malloc(sizeof(BNode));
            child->left = child->right = NULL;
            child->data = data;
            t->right = child;
        }
    }
    else if(data < t->data)
    {
        // 插到左边
        if (t->left != NULL)
            createBST(t->left, data, FALSE);
        else
        {
            BTree child = (BNode *)malloc(sizeof(BNode));
            child->left = child->right = NULL;
            child->data = data;
            t->left = child;
        }
    }
}
void preOrder(BTree t)
{
    if (t == NULL)
        return;
    printf("%d ",t->data);
    preOrder(t->left);
    preOrder(t->right);
}
void inOrder(BTree t)
{
    if (t == NULL)
        return;
    inOrder(t->left);
    printf("%d ",t->data);
    inOrder(t->right);
}
void postOrder(BTree t)
{
    if (t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    printf("%d ",t->data);
}
void freeTree(BTree &t)
{
    if(t == NULL)
        return;
    // 工作指针
    BTree p = t->left,q = t->right;
    if(p != NULL)
    {
        freeTree(p->left);
        freeTree(p->right);
        free(p);
        p = NULL;
    }
    if(q != NULL)
    {
        freeTree(q->left);
        freeTree(q->right);
        free(q);
        q = NULL;
    }
}
int main()
{
    BTree root = NULL;
    int n,i,data;
    while(~scanf("%d",&n))
    {
        if(n < 1 || n > 100)
            exit(-1);
        root = (BNode *)malloc(sizeof(BNode));
        root->left = root->right = NULL;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&data);
            createBST(root,data,i == 0 ? TRUE : FALSE);
        }
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        freeTree(root);
        free(root);
    }
    return 0;
}
