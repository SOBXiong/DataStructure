#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matrix[4][5], max[2][5], i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
            scanf("%d", &matrix[i][j]);
    }
    for (j = 0; j < 5; j++)
    {
        int firstIndex = (matrix[0][j] > matrix[1][j]) ? 0 : 1;
        int secondIndex = (firstIndex == 0) ? 1 : 0;
        for (i = 2; i < 4; i++)
        {
            if (matrix[i][j] > matrix[firstIndex][j])
            {
                secondIndex = firstIndex;
                firstIndex = i;
            }
            else if (matrix[i][j] > matrix[secondIndex][j])
                secondIndex = i;
        }
        // printf("first: %d,second: %d\n",firstIndex,secondIndex);
        if (firstIndex > secondIndex)
        {
            int temp = firstIndex;
            firstIndex = secondIndex;
            secondIndex = temp;
        }
        max[0][j] = matrix[firstIndex][j];
        max[1][j] = matrix[secondIndex][j];
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%2d ", max[i][j]);
        printf("\n");
    }
    return 0;
}
