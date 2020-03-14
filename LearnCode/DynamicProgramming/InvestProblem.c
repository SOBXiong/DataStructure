#include <stdio.h>
#include <stdlib.h>
/**
 * @description: m元钱,n项投资,fi(x):将x
 *               元投入第i个项目的效益.求使得总
 *               效益最大的投资方案
 * 
 * @model: 问题的解是向量<x1,x2,...,xn>
 *         x是投给项目i的钱数,i=1,2,...,n.
 *         目标函数: max{f1(x1)+f2(x2)+...+fn(xn)}
 *         约束条件: x1+x2+...+xn=m,xi∈N(有限种可能)
 * 
 * @method: 递推方程:
 *              Fk(x)=max{fk(xk)+F[k-1](x-xk)} k>1,0<=xk<=x
 *          边界条件:
 *              F1(x)=f1(x)
 *          时间复杂度:
 *              O(n*m^2)
 **/ 
int main(){


    return 0;
}