#include <stdio.h>
#include <stdlib.h>
/**
 * @description: 将n个盘子通过中转盘子B从盘子A移动到盘子C
 * @params: n:圆盘数目 A:第一个盘子名 B:第二个盘子名 C:第三个盘子名
 **/
void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("From plate:%c move to plate:%c\n", A, C);
    }
    else
    {
        // 将n-1块盘子借助C从A移动到B
        hanoi(n - 1, A, C, B);
        // 将最底层盘子从A移动到C
        printf("From plate:%c move to plate:%c\n", A, C);
        // 将n-1块盘子借助A从B移动到C
        hanoi(n - 1, B, A, C);
    }
}
// 汉诺塔
int main()
{
    hanoi(5, 'A', 'B', 'C');
    return 0;
}