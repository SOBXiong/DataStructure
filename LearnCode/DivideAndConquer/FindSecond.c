#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 从n个元素的数组中找到第二大的数(竞标赛算法)
 *               O(n) = n + ⌈logn⌉ - 2(最好)
 * 
 * @pseudocode: 1.k <- n //参与淘汰的元素数
 *              2.将k个元素两两一组,分成⌊k/2⌋组
 *              3.每组的2个数比较,找到较大数
 *              4.将被淘汰数记入较大数的链表 //空间换时间
 *              5.if k为奇数 then k <- ⌊k/2⌋+1
 *              6.else k <- ⌊k/2⌋
 *              7.if k>1 then goto 2 //继续分组淘汰
 *              8.max <- 最大数
 *              9.second <- max的链表中的最大
 * 
 * @link: https://www.bilibili.com/video/av7134874?p=28
 **/ 
int main(){

    return 0;
}