#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 要求要一系列数字中,选择互不相邻的数字
 *               使得这些数字加起来的总和为最大
 * 
 * @method: 设一个OPT(optimize)数组: 记录各个子问题的最优解
 *          人话 -> OPT(i): 在0~i范围中(前i+i个数),最佳方案,最大的总和
 *          递推式(动态规划方程): 
 *              OPT(i) = max{OPT(i-2) + arr[i], OPT(i-1)}
 *          递归出口:
 *              OPT(0) = arr[0] , OPT(1) = max{arr[0], arr[1]}
 *          => i-2是由于不相邻,max前部分为选了i号元素,后部分为不选
 * 
 * @link: https://www.bilibili.com/video/av18512769
 **/

/**
 * @description: 利用递归的方法得到不相邻数字的最大和
 *               递归存在问题,很多重叠子问题被重复计算,
 *               时间复杂度可能趋近O(2^n)
 * @params: arr[]
 * @params: i 
 **/ 
int recursiveOpt(int arr[], int i)
{
    if (i == 0)
        return arr[0];
    else if (i == 1)
        return arr[0] > arr[1] ? arr[0] : arr[1];
    else
    {
        // 选择的结果
        int selRes = recursiveOpt(arr,i - 2) + arr[i];
        // 不选择的结果
        int unselRes = recursiveOpt(arr,i - 1);
        return selRes > unselRes ? selRes : unselRes;
    }
}

int nonRecursiveOpt(int arr[],int n){
    int i,*opt = (int*)malloc(sizeof(int));
    opt[0] = arr[0];
    opt[1] = arr[0] > arr[1] ? arr[0] : arr[1];
    for (i = 2; i < n; i++)
    {
        // 选择的结果
        int selRes = opt[i-2] + arr[i];
        // 不选择的结果
        int unselRes = opt[i-1];
        opt[i] =  selRes > unselRes ? selRes : unselRes;
    }
    return opt[n-1];
}
int main()
{
    int arr[7] = {1, 2, 4, 1, 7, 8, 3};
    printf("max sum => %d\n",recursiveOpt(arr,6));
    printf("max sum => %d\n",nonRecursiveOpt(arr,7));
    return 0;
}