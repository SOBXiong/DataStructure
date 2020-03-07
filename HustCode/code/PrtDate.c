#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    return year % 400 == 0;
}

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int year, day;
    while (~scanf("%d %d", &year, &day))
    {
        int isLeap = isLeapYear(year);
        month[1] = isLeap ? 29 : 28;
        int i = 0, last;
        while (day > 0)
        {
            last = day;
            day -= month[i++];
        }
        printf("%d-%.2d-%.2d\n", year, i, last);
    }
    return 0;
}
