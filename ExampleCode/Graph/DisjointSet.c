#include <stdio.h>
#include <stdlib.h>
/**
 * 并查集: Disjoint set
 * 参考讲解视频: https://www.bilibili.com/video/av38498175?p=1
 **/
#define MAX_VERTICES 6 // 最大顶点

void initialise(int parent[], int rank[])
{
    int i;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        parent[i] = -1;
        rank[i] = 0;
    }
}

int findRoot(int x, int parent[])
{
    int xRoot = x;
    while (parent[xRoot] != -1)
    {
        xRoot = parent[xRoot];
    }
    return xRoot;
}

/**
 * @return 1 - success, 0 - failed
 */
int unionVertices(int x, int y, int parent[], int rank[])
{
    int xRoot = findRoot(x, parent);
    int yRoot = findRoot(y, parent);
    if (xRoot == yRoot)
    {
        return 0;
    }
    else
    {
        // parent[xRoot] = yRoot;
        // 根据rank拼接
        if (rank[xRoot] > rank[yRoot])
        {
            parent[yRoot] = xRoot;
        }
        else if (rank[yRoot > rank[xRoot]])
        {
            parent[xRoot] = yRoot;
        }
        else // 高度相同
        {
            rank[xRoot]++;
            parent[yRoot] = xRoot;
        }

        return 1;
    }
}

int main()
{
    int parent[MAX_VERTICES] = {0};
    int rank[MAX_VERTICES] = {0};
    initialise(parent, rank);
    int edges[6][2] = {
        {0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {2, 5}};
    int i;
    for (i = 0; i < 6; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        if (unionVertices(x, y, parent, rank) == 0)
        {
            printf("Find a cycle!\n");
            exit(0);
        }
    }
    printf("No cycle found!\n");
    return 0;
}