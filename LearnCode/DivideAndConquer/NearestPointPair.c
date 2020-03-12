#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 输入: 平面点集P中有n个点,n>1
 *               输出: P中的两个点,其距离最小
 * @strategy: P划分为大小相等的Pl和Pr
 *            1.分别计算Pl、Pr中最近点对
 *            2.计算Pl与Pr中各一个点的最近点对
 *            3.上述情况下的最近点对是解
 * @pseudocode: MinDistance(P,X,Y)
 *              输入: 点集P,X和Y为横、纵坐标数组
 *              输出: 最近的两个点及距离
 *              1.若|P|<=3,直接计算其最小距离
 *              2.排序X,Y
 *              3.做中垂线l将P划分为Pl和Pr
 *              4.MinDidtance(Pl,Xl,Yl)
 *              5.MinDistance(Pr,Xr,Yr)
 *              // δl,δr为子问题的距离
 *              6.δ=min(δl,δr)
 *              // 检查中垂线附近的点
 *              7.检查距l不超过δ两侧各1个点的距
 *              离.若小于δ,修改δ为这个值
 * @link: https://www.bilibili.com/video/av7134874?p=25
 **/
int main(){

    return 0;
}