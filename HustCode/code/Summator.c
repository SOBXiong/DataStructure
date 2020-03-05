#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    // 长的长度
    int max = lenA > lenB ? lenA : lenB;
    // 短的长度
    int min = lenA > lenB ? lenB : lenA;
    int i;
    // 进位
    int carry = 0;
    // 最多进一位,分配max+1个位置,再+1个位置,用于存放结束位'\0'
    char *result = (char*)malloc(max + 2);
    result[max + 1] = '\0';
    // 兼顾地遍历两个字符串
    for (i = 1; i <= min; i++) // 从1开始方便,不需要每次再-1
    { // 两个指针从尾到头遍历
        // 得到总和,a + b + 上一次的进位
        // 最后一次,max - min,min - min
        int sum = a[lenA - i] - '0' + b[lenB - i] - '0' + carry;
        // 进位置0
        carry = 0;
        if(sum > 9){ // 进位了
            // 记录进位
            carry = 1;
        }
        // 填入结果,sum的个数位, + '0' 转为char型
        // 0 ~ max : max + 1位
        result[max + 1 - i] = sum % 10 + '0';
    }
    // 得到长的字符串
    char* maxChars = lenA == max ? a : b;
    // 遍历长的,i = min + 1
    for (; i <= max; i++)
    {
        // 上一次for循环的最后一次carry是这次的输入
        int sum = maxChars[max - i] - '0' + carry;
        carry = 0;
        if(sum > 9){
            carry = 1;
        }
        result[max + 1 - i] = sum % 10 + '0';
    }
    if(carry == 0){
        printf("%s",&(result[1]));
    }else{
        result[0] = '1';
        printf("%s",result);
    }
    free(result);
}
int main()
{
    char a[1001], b[1001];
    /*
        ~是按位取反
        scanf的返回值是输入值的个数如果没有输入值就是返回-1
        -1按位取反结果是0
        while(~scanf("%d", &n))就是当没有输入的时候退出循环
    */ 
    while (~scanf("%s %s", a, b))
    {
        add(a, b);
        // 刷新输入缓冲区
        fflush(stdin);
    }
    return 0;
}