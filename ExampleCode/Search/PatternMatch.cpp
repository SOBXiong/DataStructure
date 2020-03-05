#include <stdio.h>
#include <stdlib.h>
#include "../rule.h"
#define MAXSIZE 30

typedef struct
{
    char data[MAXSIZE];
    int len;
} String;

int NormalMatch(String s, String t, int pos)
{
    int i = pos, j = 1;
    while (i <= s.len && j <= t.len)
    {
        if (s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > t.len)
        return i - t.len;
    else
        return 0;
}

void GetNext(String t, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < t.len)
    {
        if (j == 0 || t.data[i] == t.data[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int PatterMatch(String s, String t, int next[], int pos)
{
    int i = pos, j = 1;
    while (i <= s.len && j <= t.len)
    {
        if (j == 0 || s.data[i] == t.data[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > t.len)
        return i - t.len;
    else
        return 0;
}

int main()
{
    return 0;
}