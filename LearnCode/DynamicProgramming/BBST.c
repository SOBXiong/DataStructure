#include <stdio.h>
#include <stdlib.h>
/**
 * @description: BBST(Best Binary Search Tree: 最优二叉搜索树)
 *               给定数据集S=<x1,x2,...,xn>
 *               及S的存取概率分布如下:
 *               P=<a0,b1,a1,b2,a2,...,bn,an>
 *               求一颗最优的(即平均比较次数最少的)二分检索树
 *               
 *               结点xi在T中的深度是d(xi),i=1,2,...,n
 *               空隙Lj的深度为d(Lj),j=0,1,...,n
 *               平均比较次数: t = ∑[i=1~n]bi*(1+d(xi)) + ∑[j=0~n]aj*d(Lj)
 * 
 * @method: 子问题划分:
 *          子问题边界为(i,j)
 *          数据集: S[i,j]=<xi,x[i+1],...,xj>
 *          存取概率分布: P[i,j]=<a[i-1],bi,ai,b[i+1],...,bj,aj>
 *          
 *          子问题归约:
 *          以xk作为根归结为子问题: S[i,k-1],P[i,k-1]
 *                                S[k+1,j],P[k+1,j]
 * 
 *          子问题的概率之和:
 *          子问题界定S[i,j]和P[i,j],令W[i,j]=∑[p=i-1~j]ap + ∑[q=i~j]bq
 *          是P[i,j]中所有概率(数据与空隙)之和
 * 
 *          优化函数的递推方程
 *          设m[i,j]是相对于输入S[i,j]和P[i,j]的最优二叉搜索树的平均比较次数
 *          递推方程: m[i,j]=min[i<=k<=j]{m[i,k-1] + m[k+1,j] + w[i,j]},1<=i<=j<=n
 *                   m[i,i-1]=0,i=1,2,...,n // 左或右子树为空
 *                   // small power 以新的结点为根,相当于两颗老树向下移动一个深度,即+W[i,j]
 *          
 *          时间复杂度: T(n)=O(n^3) 空间复杂度: S(n)=O(n^2)        
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=46
 *        https://www.bilibili.com/video/av7134874?p=47
 **/
int main(){

    return 0;
}