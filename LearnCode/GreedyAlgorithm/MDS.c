#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 最小延迟调度问题(MDS: Minimum delay scheduling):
 *               客户集合A,∀i∈A,ti为服务时间,di为
 *               要求完成时间,ti,di为正整数.
 *               一个调度f: A-> N,f(i)为客户i的开始时间.
 *               求最大延迟达到最小的调度,即求f使得
 *               fmin{max[i∈A]{f(i) + ti -di}}
 *               ∀i,j∈A, i!=j, f(i) + ti <= f(j)
 *               or f(j) + tj <= f(i)
 * 
 * @method: 按照di从小到大安排(证明: 交换论证)
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=54
 **/
int main(){

    return 0;
}