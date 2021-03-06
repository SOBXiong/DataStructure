#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 着色问题: 
 *               输入: 无向连通图G和m种颜色的集合
 *               用这些颜色给图的顶点着色,每个
 *               顶点一种颜色.
 *               要求: G的每条边的两个顶点着不同颜色
 *               
 *               输出: 所有可能的着色方案.
 *               如果不存在着色方案,回答No
 * 
 * @method: 设G=(V,E), V={1,2,...,n}
 *          颜色编号: 1,2,...,m
 *          
 *          解向量: <x1,x2,...,xn>, x1,x2,...,xn∈{1,2,...,m}
 *          结点的部分向量<x1,x2,...,xk>, 1≤k≤n
 *          表示只给顶点1,2,...,k着色的部分方案
 * 
 *          搜索树: m又树
 *          
 *          约束条件: 在结点<x1,x2,...,xk>处,
 *          顶点k+1的邻接表中结点已用过的颜色不能再用
 *          如果邻接表中结点已用过m种颜色,
 *          则结点k+1没法着色,从该结点回溯
 *          到其父结点.满足多米诺性质
 *          
 *          搜索策略: 深度优先
 *          
 *          时间复杂度: O(n * m^n)
 *          
 *          改进: 对称性,增加判定工作量...
 * 
 *          应用: 会场分配问题、
 **/
int main(){

    return 0;
}