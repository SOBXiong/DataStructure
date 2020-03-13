#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
    编写一个C程序，完成下列任务:
    1.无冗余接收键盘输入的n个字符串，并将其无冗余的存放到对应的字符数组中，
    再按照每行1串的格式输出这些字符串。(15分)
    2.以单个字符串为数据域，按字典顺序将n个字符串生成一棵二叉搜索树，
    并且规定左子树(数据域)小于右子树(数据域)。(10分)
    3.先序遍历该二叉搜索树井输出结果。(5分)
**/
typedef struct BSTNode
{
    char *data;
    struct BSTNode *left, *right;
} BSTNode, *BSTree;

void insertNode(BSTree &tree, char *data, int isFirst)
{
    if (isFirst)
    {
        tree->data = (char *)malloc(sizeof(char) * strlen(data));
        strcpy(tree->data, data);
    }
    else
    {
        int result = strcmp(data, tree->data);
        if (result > 0) // 插右子树
        {
            // 右子树为空
            if (tree->right != NULL)
                insertNode(tree->right, data, 0);
            else
            {
                // 右子树不为空
                BSTree p = (BSTNode *)malloc(sizeof(BSTNode));
                p->left = NULL;
                p->right = NULL;
                p->data = (char *)malloc(sizeof(char) * strlen(data));
                strcpy(p->data, data);
                tree->right = p;
            }
        }
        else // 插左子树
        {
            // 左子树为空
            if (tree->left != NULL)
                insertNode(tree->left, data, 0);
            else
            {
                // 左子树不为空
                BSTree p = (BSTNode *)malloc(sizeof(BSTNode));
                p->left = NULL;
                p->right = NULL;
                p->data = (char *)malloc(sizeof(char) * strlen(data));
                strcpy(p->data, data);
                tree->left = p;
            }
        }
    }
}
void inOrderPrint(BSTree tree)
{
    if (tree != NULL && tree->data != NULL)
        printf("%s\n", tree->data);
    else
        return;
    inOrderPrint(tree->left);
    inOrderPrint(tree->right);
}
// Crtl+Z结束输入
// 优化 => 释放节点BSTNode,太麻烦
int main()
{
    char **data = NULL;
    char in[1024];
    int count = 0, length, i;
    // scanf遇空格终止
    while (gets(in) != NULL)
    {
        length = strlen(in);
        if (data == NULL)
        {
            data = (char **)malloc(sizeof(char *));
            data[0] = (char *)malloc(sizeof(char) * length);
            strcpy(data[0], in);
            count++;
        }
        else
        {
            data = (char **)realloc(data, sizeof(char *) * (++count));
            data[count - 1] = (char *)malloc(sizeof(char) * length);
            strcpy(data[count - 1], in);
        }
    }
    BSTree root = (BSTNode *)malloc(sizeof(BSTNode));
    root->left = NULL;
    root->right = NULL;
    // 打印输出
    for (i = 0; i < count; i++)
    {
        printf("%s\n", data[i]);
        // 插入节点
        insertNode(root, data[i], i == 0 ? 1 : 0);
    }
    printf("\n");
    inOrderPrint(root);
    printf("\n");
    for (i = count - 1; i >= 0; i--)
        free(data[i]);
    free(data);
    return 0;
}
