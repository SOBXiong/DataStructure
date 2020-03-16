#include <stdio.h>
#include <stdlib.h>
/**
 *  一个有关城市间的公路建设，一个带权值的无向图，其中的边和顶点都有编号
 *  (1)将所有的边按权值排序输出
 *  (2)求最小生成树，求出具体路径，和最小代价
 **/
// 留待完善
typedef struct Edge
{
    int start, end, data;
} Edge;
int edgeCompare(const void *p1, const void *p2)
{
    Edge *e1 = (Edge *)p1;
    Edge *e2 = (Edge *)p2;
    if (e1->data != e2->data)
        return e1->data - e2->data;
    else if (e1->start != e2->start)
        return e1->start - e2->start;
    else
        return e1->end - e2->end;
}
// 初始图
int graph[5][5] =
    {
        {0, 1, -1, 2, 2},
        {1, 0, 2, -1, -1},
        {-1, 2, 0, 3, 4},
        {2, -1, 3, 0, -1},
        {2, -1, 4, -1, 0}};
int main()
{
    Edge *edges = NULL;
    // 边数
    int i, j, count;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (graph[i][j] != -1)
            {
                if (edges == NULL)
                {
                    edges = (Edge *)malloc(sizeof(Edge));
                    edges->start = i + 1;
                    edges->end = j + 1;
                    edges->data = graph[i][j];
                    count = 1;
                }
                else
                {
                    edges = (Edge *)realloc(edges, sizeof(Edge) * (++count));
                    edges[count - 1].start = i + 1;
                    edges[count - 1].end = j + 1;
                    edges[count - 1].data = graph[i][j];
                }
            }
        }
    }
    // 按权值排序
    qsort(edges, count, sizeof(Edge), edgeCompare);
    printf("Sorted side print: \n");
    for (i = 0; i < count; i++)
        printf("edge: %d <-> %d , data: %d\n", edges[i].start, edges[i].end, edges[i].data);

    // 生成最小生成树
    printf("MST print: \n");
    int flag[5] = {0};
    for (i = 0; i < count; i++)
    {
        if (flag[edges[i].start - 1] != 1 || flag[edges[i].end - 1] != 1)
        {
            printf("edge: %d <-> %d , data: %d\n", edges[i].start, edges[i].end, edges[i].data);
            flag[edges[i].start - 1] = flag[edges[i].end - 1] = 1;
        }
    }
    free(edges);
    return 0;
}
