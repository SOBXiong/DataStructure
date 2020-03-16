#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 最优装载问题(相当于0-1背包问题的子问题):
 *               n个集装箱1,2,...,n装上轮船,集
 *               装箱i的重量wi,轮船装载重量限制
 *               为C,无体积限制.问如何装使得上船
 *               的集装箱最多?不妨设每个箱子的重量wi <= C
 * 
 * @model: 设<x1,x2,...,xn>表示解向量,xi=0,1;
 *         xi=1当且仅当第i个集装箱装上船
 *          
 *         目标函数: max∑[i=1~n]xi
 *         约束条件: ∑[i=1~n]wi*xi <= C
 *                  xi=0,1  i=1,2,...,n
 * 
 * @method: 贪心策略: 轻者优先
 *          算法设计: 将集装箱排序,使得w1 <= w2 <= ... <= wn
 *                   按照标号从小到大装箱,直到装入下一个箱子使
 *                   得集装箱总重超过轮船装载重量限制,则停止
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=53
 **/
int main(){


    return 0;
}