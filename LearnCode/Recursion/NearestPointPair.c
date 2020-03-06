#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 求解最近点对的问题,给出一系列二维坐标点,找出最近的一对点
 * @method: 1、初始化两张表用于存储这些点的根据x,y排序后的结果 -> (O(nlogn))
 *          2、依据分治法,把点设为Left、mid、right,设置一条中线,那么应该有三种距离：①左边的线、②横跨的线、③右边的线
 *          3、现选择一条线得到距离D,根据D将x或y间距大于该值的点对排除
 *          4、递归上述三步,从左边找到Dl,从右边找到Dr,从中间找到Dm,返回min(Dl,Dr,Dm)
 **/
int main(){
    return 0;
}