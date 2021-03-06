#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 最大团问题: 给定无向图G = <V,E>,
 *               其中顶点集V = {1,2,...,n},边集为E.求G的最大团.
 *               解: <x1,x2,...,xn>为0-1向量,xk=1当且仅当顶点k属于最大团            
 * 
 *               G的子图: G' = <V',E'>,其中V'⊆V,E'⊆E
 *               G的补图: G" = <V,E'>,E'是E关于完全图边集的补集
 *               G中的团: G的完全子图
 *               G的最大团: 顶点数最多的团
 * 
 *               独立集与团: 
 *               G的点独立集: G的顶点子集A,且∀u,v∈A,{u,v}∉E.
 *               最大点独立集: 顶点最多的点独立集
 *               命题: U是G的最大团当且仅当U是G"的最大点独立集.
 * 
 * @method: 搜索树为子集树.
 *          结点<x1,x2,...,xk>的含义: 
 *          已检索顶点1,2,...,k,其中xi=1表示
 *          顶点i在当前的团内,i=1,2,...,k
 *          
 *          约束条件: 该顶点与当前团内每个顶点都有边相连
 *          界: 当前已检索到的极大团的顶点数
 *          
 *          代价函数: 目前的团可能扩张为极大团的顶点数上界
 *          F = Cn + n - k
 *          其中Cn为目前团的顶点数(初始为0),k为结点层数    
 *          最坏情况下时间复杂度: O(n * 2^n)
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=72
 **/
int main(){


    return 0;
}