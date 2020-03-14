#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 平面点集的凸包: 给定大量离散点的集合Q,
 *               求一个最小的凸多边形,使得Q中的点在该多
 *               边形内或者边上
 * 
 * @strategy: 1.以连接最大纵坐标点Ymax和最小纵坐标点Ymin的线段
 *            d={Ymax,Ymin}划分L为左点集Ll和右点集Lr
 *            2.Deal(Ll);Deal(Lr)
 *            Deal(Ll): 确定距d最远的点P;P,Ymax,Ymin三点构成
 *            三角形,在三角形内的点删除;设a=PYmin,在a外的点与
 *            a构成Ll的子问题;设b=PYmax,在b外的点与b构成另一
 *            个子问题
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=34
 **/ 
int main(){

    return 0;
}