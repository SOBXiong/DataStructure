#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 有疑问
typedef struct Student
{
    char name[101];
    int age;
    int grade;
} Student;
void sort(Student *s, int n)
{
    int i, j;
    Student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // 如果前面的成绩大于后面的,那么交换
            if (s[i].grade > s[j].grade)
            {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
            // 如果成绩相同
            else if (s[i].grade == s[j].grade)
            {
                int result = strcmp(s[i].name,s[j].name);
                if(result > 0){
                    temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                }
            }
        }
    }
}
// 如果compar返回值小于0,那么p1所指向元素会被排在p2所指向元素的左面
int compare(const void *p1, const void *p2)
{
    Student *s1 = (Student *)p1;
    Student *s2 = (Student *)p2;
    if (s1->grade != s2->grade)
        return s1->grade - s2->grade;
    int nameResult = strcmp(s1->name, s2->name);
    if (nameResult != 0)
        return nameResult;
    return s1->age - s2->age;
}
int main()
{
    int n;
    scanf("%d", &n);
    Student *s = (Student *)malloc(sizeof(Student) * n);
    int i = 0;
    while (i < n)
    {
        scanf("%s %d %d", s[i].name, &s[i].age, &s[i].grade);
        i++;
    }
    qsort(s, n, sizeof(Student), compare);
    // sort(s, n);
    for (i = 0; i < n; i++)
    {
        printf("%s %d %d\n", s[i].name, s[i].age, s[i].grade);
    }
    free(s);
    return 0;
}