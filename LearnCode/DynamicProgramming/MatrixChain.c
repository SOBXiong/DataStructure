#include <stdio.h>
#include <stdlib.h>
/**
 * @desciption: 矩阵链相乘问题:设A1,A2,…,An为矩阵序列,
 *              A1为P(i-1)*Pi阶矩阵,i=1,2,...,n.
 *              试确定矩阵的乘法顺序,使得元素相乘的总次数最少
 * 
 * @pseudocode: Matrix chain(P,n) ——时间复杂度O(n^3),迭代实现
 *              1.令所有的mi初值为0
 *              2.for r <- 2 to n do // r为链长
 *              3.    for i <- 1 to n-r+1 do // 左边界i,遍历长r子问题
 *              4.        j <- i+r-1 // 右边界j
 *              5.        m[i,j] <- m[i+1,j]+P(i-1)*Pi*Pj // k=i
 *              6.        S[i,j] <- i // 记录k
 *              7.        for k <- 1 to j-1 do // 遍历所有划分
 *              8.            t <- m[i,k]+m[k+1,j]+P(i-1)*Pk*Pj
 *              9.            if  t < m[i,j]
 *              10.           then m[i,j] <- t // 更新解
 *              11.               s[i,j] <- k
 *              二维数组m与s为备忘录,m存放乘法数目,s标记路径
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=39
 **/ 
int main(){

    return 0;
}