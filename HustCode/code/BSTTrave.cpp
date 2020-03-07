#include <stdio.h>
#include <stdlib.h>
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
            createBST(t->right, data, 0);
        else
        {
            BTree child = (BNode *)malloc(sizeof(BNode));
            child->left = child->right = NULL;
            child->data = data;
            t->right = child;
        }
    }
    else
    { // 插到左边
        if (t->left != NULL)
            createBST(t->left, data, 0);
        else
        {
            BTree child = (BNode *)malloc(sizeof(BNode));
            child->left = child->right = NULL;
            child->data = data;
            t->left = child;
        }
    }
}
int contains(int datas[], int &n, int data)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (datas[i] == data)
            return 1;
    }
    datas[n++] = data;
    return 0;
}
void preOrder(BTree t, int datas[], int &n)
{
    if (t == NULL)
        return;
    if (t != NULL)
    {
        // 如果没输出过,在输出
        if (!contains(datas, n, t->data))
            printf("%d ", t->data);
    }
    preOrder(t->left, datas, n);
    preOrder(t->right, datas, n);
}
void inOrder(BTree t, int datas[], int &n)
{
    if (t == NULL)
        return;
    inOrder(t->left, datas, n);
    if (t != NULL)
    {
        // 如果没输出过,在输出
        if (!contains(datas, n, t->data))
            printf("%d ", t->data);
    }
    inOrder(t->right, datas, n);
}
void postOrder(BTree t, int datas[], int &n)
{
    if (t == NULL)
        return;
    postOrder(t->left, datas, n);
    postOrder(t->right, datas, n);
    if (t != NULL)
    {
        // 如果没输出过,在输出
        if (!contains(datas, n, t->data))
            printf("%d ", t->data);
    }
}
int main()
{
    BTree root = (BNode *)malloc(sizeof(BNode));
    root->left = root->right = NULL;
    int n, i, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        if (i == 0)
            createBST(root, data, 1);
        else
            createBST(root, data, 0);
    }
    int *result = (int*)malloc(sizeof(int)*n);
    int p = 0;
    preOrder(root, result, p);
    printf("\n");
    p = 0;
    inOrder(root, result, p);
    printf("\n");
    p = 0;
    postOrder(root, result, p);
    printf("\n");
    // inOrderFree(root);
    // free(root);
    return 0;
}
