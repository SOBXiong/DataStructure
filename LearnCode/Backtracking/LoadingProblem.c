#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 问题: 有n个集装箱,需要装上两艘载
 *               重分别为c1和c2的轮船.wi为第i个集
 *               装箱的重量,且w1+w2+...+wn ≤ c1+c2
 *               
 *               问: 是否存在一种合理的装载方案把
 *               这n个集装箱装上船?如果有,请给出一种方案.
 *               
 *               输入: W=<w1,w2,...,wn>为集装箱重量
 *               c1和c2为船的最大载重量
 * 
 * @method: 算法思想: 令第一艘船的装入量为W1
 *          1.用回溯算法求使得c1-W1达到最小的装载方案;
 *          2.若满足w1+w2+...+wn-W1 ≤ c2 
 *            则回答Yes,否则回答No
 *          
 *          最坏时间复杂度: O(2^n)
 * 
 * @pseudocode: 算法 Loading(W,c1)
 *              Sort(W);
 *              B ← c1; best ← c1; i ← 1; // B为当前空隙,best最小空隙
 *              while: while i ≤ n do
 *                     if 装入i后重量不超过c1
 *                     then B ← B-wi; x[i] ← 1; i ← i+1;
 *                     else x[i] ← 0; i ← i+1;
 *              if B < best then 记录解; best ← B;
 *              Backtrack(i); // 回溯
 *              if i=1 then return 最优解
 *              else goto while
 *              
 *              子过程 Backtrack(i)
 *              while i > 1 and x[i] = 0 do
 *                  i ← i-1;
 *              if x[i] = 1 // 沿右分支一直回溯发现左分支边,或到根为止
 *              then x[i] ← 0;
 *                  B ← B+wi;
 *                  i ← i+1;
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=67
 **/
int main()
{

    return 0;
}