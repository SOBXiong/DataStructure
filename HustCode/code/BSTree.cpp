#include <stdio.h>
#include <stdlib.h>
typedef struct BTree
{
    struct BTree *left;
    struct BTree *right;
    int data;
}BTree,*BNode;

// 得到待插入结点的父节点
BNode searchParent(BNode node, int data)
{
    // 根为空
    if (node == NULL)
    {
        return node;
    }
    else
    { // 根不为空
        BNode p = data > node->data ? searchParent(node->right, data) : searchParent(node->left, data);
        if (p == NULL)
        {
            return node;
        }
        return searchParent(p, data);
    }
}

void insertNode(BNode &parent, int data)
{
    // 如果为空,插入根
    if (parent == NULL)
    {
        parent = (BNode)malloc(sizeof(BTree));
        parent->left = parent->right = NULL;
        parent->data = data;
    }else{ // 不为根,根据data插入子结点
        if(data > parent->data){
            parent->right = (BNode)malloc(sizeof(BTree));
            BNode p = parent->right;
            p->right = p->left = NULL;
            p->data = data;
        }else{
            parent->left = (BNode)malloc(sizeof(BTree));
            BNode p = parent->left;
            p->right = p->left = NULL;
            p->data = data;
        }
    }
}
int main()
{
    int n,i,data;
    scanf("%d", &n);
    BNode p = NULL,q = NULL;
    int *result = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&data);
        q = searchParent(p,data);
        result[i] = q == NULL ? -1 : q->data;
        q == NULL ? insertNode(p,data) : insertNode(q,data);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n",result[i]);
    }
    free(result);
    return 0;
}