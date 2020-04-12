#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

typedef struct BNode
{
    int data;
    BNode *left, *right;
} BNode, *BTree;

BNode *insertNode(BTree &root, int data)
{
    // 如果当前为空节点
    if (root == NULL)
    {
        BTree t = (BNode *)malloc(sizeof(BNode));
        t->left = t->right = NULL;
        t->data = data;
        return t;
    }

    // 工作节点
    BTree p = root;
    // 当前节点不为空
    while (TRUE)
    {
        // 应插入左子树
        if (data < p->data)
        {
            // 左子树不为空
            if (p->left != NULL)
            {
                // 继续往左边找应插入位置
                p = p->left;
            }
            else
            { // 左子树为空
                BTree t = (BNode *)malloc(sizeof(BNode));
                t->left = t->right = NULL;
                t->data = data;
                // 链接
                p->left = t;
                break;
            }
        }
        else // 应插入右子树
        {
            // 右子树不为空
            if (p->right != NULL)
            {
                // 继续往右边找应插入位置
                p = p->right;
            }
            else // 右子树为空
            {
                BTree t = (BNode *)malloc(sizeof(BNode));
                t->left = t->right = NULL;
                t->data = data;
                // 链接
                p->right = t;
                break;
            }
        }
    }
    return root;
}

BNode *searchNode(BTree &node, int data)
{
    // 搜索路径当前节点为空
    if(node == NULL){
        return NULL;
    }

    if(data > node->data){
        searchNode(node->right,data);
    }else if(data < node->data){
        searchNode(node->left,data);
    }else{
        return node;
    }
}

int main()
{

    return 0;
}