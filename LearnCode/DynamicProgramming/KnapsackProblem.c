#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 一个旅行者随身携带一个背包.可以放
 *               入背包的物品有n种,每种物品的重量
 *               和价值分别为wi,vi.如果背包的最大
 *               重量限制是b,每种物品可以放多个.怎
 *               样选择放入背包的物品以使得背包的
 *               价值最大?不妨设上述wi,vi,b都是
 *               正整数.
 * 
 * @model: 解是<x1,x2,...,xn>,其中xi是装入背包的
 *         第i种物品个数
 *         目标函数: max∑[i=1~n]vi*xi
 *         约束条件: ∑[i=1~n]wixi≤b,xi∈N
 * 
 * @method: Fk(y): 装前k种物品,总重不超过y,
 *          背包达到的最大价值
 *          递推方程:
 *              Fk(y)=max{F[k-1](y),Fk(y-wk)+vk}
 *          边界条件:
 *              F0(y)=0,0<=y<=b
 *              Fk(0)=0,0<=k<=n
 *              F1(y)=⌊y/w1⌋*v1(全装1)
 *              Fk(y)=-∞,y<0(此时超重)
 *          标记函数:
 *              ik(y): 装前k种物品,总重不超过y,背包
 *              达到最大价值时装入物品的最大标号
 *              当F[k-1](y) > Fk(y-wk)+vk时,ik(y)=i[k-1](y)
 *              当F[k-1](y) <= Fk(y-wk)+vk时,ik(y)=k
 *              当y<w1时,i1(y)=0
 *              当y>=w1时,i1(y)=1
 *          时间复杂度: O(n*b)
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=41
 **/
int main(){

    return 0;
}