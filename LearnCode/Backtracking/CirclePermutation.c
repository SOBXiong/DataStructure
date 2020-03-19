#include <stdio.h>
#include <stdlib.h>
/**
 * @description: Circle permutation problem(圆排列问题)
 *               给定n个源的半径序列,各圆与底线相切排列,假定每个
 *               圆占大于1的长度,求具有最小长度ln的圆的排列顺序.
 * 
 * @method: 解: <i1,i2,...,in>为1,2,...,n的排列
 *          搜索空间为排列树
 *          部分解向量<i1,i2,...,ik>: 表示前k个圆已排好.
 *          令B = {i1,i2,...,ik},下一个圆选择i[k+1]
 * 
 *          约束条件: i[k+1]∈{1,2,...,n} - B
 *          界: 当前得到的最小圆排列长度
 *          
 *          符号说明: 
 *              k: 算法已经选择了第1~k个圆
 *              rk: 第k个圆的半径
 *              dk: 第k-1个圆到第k个圆的圆心水平距离,k > 1
 *              xk: 第k个圆的圆心坐标,规定x1 = 0
 *              lk: 第1~k个圆的排列长度
 *              Lk: 放好1~k个圆以后,对应结点的代价函数值Lk ≤ ln
 * 
 *          圆排列长度估计: 
 *          xk = x[k-1] + dk
 *          部分排列长度lk = xk + rk + r1
 *          排列长度ln = xk + d[k+1] + d[k+2] + ... + dn + rn + r1
 *          
 *          dk = sqrt{(rk + r[k-1])^2 - (rk - r[k-1])^2}    
 *             = 2*sqrt(r[k-1]*rk)
 *          
 *          带入dk,有ln = xk + 2*sqrt(rk*r[k+1]) + 2*sqrt(r[k+1]*r[k+2])
 *                       + ... + 2*sqrt(r[n-1]*rn) + rn + r1
 *                     ≥ xk + 2(n-k)*r + r + r1
 *          
 *          Lk = xk + (2n - 2k + 1)*r + r1
 *          r = min(r[ij],rk)
 *          ij ∈ {1,2,...,n} - B
 * 
 *          时间复杂度:
 *          搜索树树叶树为O(n!)
 *          每条路径代价函数的计算为O(n)
 *          最坏情况下算法时间复杂度: O(n*n!) = O((n+1)!)
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=74
 **/
int main(){

    return 0;
}