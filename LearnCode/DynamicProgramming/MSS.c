#include <stdio.h>
#include <stdlib.h>
/**
 * @description: MSS(Maximum Subsegments Sum: 最大子段和)
 *               给定n个数(可以为负数)的序列(a1,a2,...,an)
 *               求max{0, max[i<=i<=j<=n]∑[k=i~j]ak}
 * 
 * @method: 子问题界定: 前边界为1,后边界为i
 *          C[i]是A[1...i]中必须包含元素A[i]的向前
 *          连续延伸的最大子段和: C[i]=max[1<=k<=i]{∑[j=k~i]A[j]}
 *          
 *          递推方程
 *          C[i]=max{C[i-1]+A[i], A[i]} i=2,...,n
 *          若A[1] > 0,则C[1]=A[1]
 *          否则C[1]=0
 *          OPT(A)=max[1<=i<=n]{C[i]}
 * 
 * @pseudocode: 算法MaxSum(A,n)
 *              输入: 数组A
 *              输出: 最大子段和sum,子段最后位置c
 *              sum <- 0
 *              b <- 0
 *              for i <- 1 to n do
 *                  if b > 0
 *                  then b <- b + A[i]
 *                  else b <- A[i]
 *                  if b > sum
 *                  then sum <- b
 *                       c <- i
 *              return sum,c
 *              
 *              时间复杂度: O(n), 空间复杂度: O(n)
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=45
 **/
int main(){

    return 0;
}