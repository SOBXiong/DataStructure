#include <stdio.h>
#include <stdlib.h>
/**
 * @description: Continuous postage problem: 连续邮资问题
 *               问题: 给定n种不同面值的邮票,每个信封至多贴m张,
 *               试给出邮票的最佳设计,使得从1开始,增量为1的连续邮资区间达到最大?
 * 
 * @method: 可行解: <x1,x2,...,xn>,x1 = 1,x1<x2<...<xn
 * 
 *          搜索策略: 深度优先
 * 
 *          约束条件: 在结点<x1,x2,...,xi>处,邮资最大连续区间
 *          为{1,...,ri},x[i+1]的取值范围是{xi+1,...,ri+1}
 *          若x[i+1] > ri+1, ri+1的邮资将没法支付.
 * 
 *          ri的计算: 
 *          yi(j): 用至多m张面值xi的邮票加上x1,x2,...,x[i-1]
 *                 面值的邮票贴j邮资时的最少邮票树,则
 *          yi(j) = min[1≤t≤m]{t + y[i-1](j - t*xi)}
 *          y1(j) = j
 *          ri = min{j|yi(j) ≤ m,yi(j+1) > m}
 *          
 *          界: max,m张邮票连续付的最大邮资
 **/
int main(){


    return 0;
}