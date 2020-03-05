#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getLength(int data)
{
    if (data == 0)
        return 1;
    int i = 0;
    while (data != 0)
    {
        data /= 10;
        i++;
    }
    return i;
}
/**
 * @return int: 1 -> success 0 -> failed 
 */
int judgeKSNum(int data)
{
    int square = data * data;
    // 分别得到原数和平方的位数
    int dataL = getLength(data);
    int squareL = getLength(square);
    // 得到平方的末原数位
    int lowSquare = square % (int)pow(10, dataL);
    // printf("data: %d , dataL: %d, square: %d, squareL: %d, lowSquare: %d\n", data, dataL, square, squareL, lowSquare);
    return lowSquare == data ? 1 : 0;
}
int main()
{
    int data;
    while (~scanf("%d", &data))
    {
        int isKSNum = judgeKSNum(data);
        printf("%s\n", isKSNum ? "Yes!" : "No!");
    }
    return 0;
}