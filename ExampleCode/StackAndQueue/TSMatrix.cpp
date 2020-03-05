#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"

#define MAXSIZE 100 // 最大个数
typedef int ElemType;

typedef struct
{
    int i, j; // 行列下标
    ElemType e;
} Triple;
typedef struct
{
    Triple data[MAXSIZE + 1]; // 非零元三元组表,data[0]未用
    int mu, nu, tu;           // 矩阵的行数、列数和非零元个数
} TSMatrix;

Status createSMatrix(TSMatrix &M)
{
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
    for (int i = 1; i <= M.tu; i++)
    {
        scanf("%d %d %d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
    }
    return OK;
}

// 遍历函数
void traverse(TSMatrix M, void (*visit)(Triple))
{
    printf(">>> i --- j --- e\n");
    for (int i = 1; i <= M.tu; i++)
        visit(M.data[i]);
    printf("\n");
}

// visit函数
void visit(Triple T)
{
    printf("%5d %5d %5d\n", T.i, T.j, T.e);
}

// 普通转置
Status TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu)
    {
        int q = 1;
        for (int col = 1; col <= M.nu; ++col)
        {
            for (int p = 1; p <= M.tu; ++p)
            {
                if (M.data[p].j == col)
                {
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }
            }
        }
    }
    return OK;
}

// 快速转置
Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu)
    {
        int num[M.tu + 1], cpot[M.tu + 1];
        int col, q;
        for (col = 1; col <= M.nu; ++col)
            num[col] = 0;
        for (int t = 1; t <= M.tu; ++t)
            ++num[M.data[t].j]; // 求M中每一列含非零元的个数
        cpot[1] = 1;
        for (col = 2; col <= M.nu; ++col)
            cpot[col] = cpot[col - 1] + num[col - 1];
        for (int p = 1; p <= M.tu; ++p)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}

/*
6 6 8
1 2 12
1 3 9
3 1 -3
3 6 14
4 3 24
5 2 18
6 1 15
6 4 -7
 */
int main()
{
    TSMatrix M;
    createSMatrix(M);
    traverse(M, visit);
    TSMatrix T;
    // TransposeSMatrix(M, T);
    FastTransposeSMatrix(M, T);
    traverse(T, visit);
    return 0;
}