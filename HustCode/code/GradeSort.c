#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    char name[100];
    int age;
    int grade;
} Student, *Stu;
int compare(const void *p1, const void *p2)
{
    Student *s1 = (Stu)p1;
    Student *s2 = (Stu)p2;
    if (s1->grade != s2->grade)
        return s1->grade - s2->grade;
    int result = strcmp(s1->name, s2->name);
    if (result != 0)
        return result;
    return s1->age - s2->age;
}
int main()
{
    int N, i;
    Student *students = NULL;
    scanf("%d", &N);
    students = (Stu)malloc(sizeof(Student) * N);
    for (i = 0; i < N; i++)
        scanf("%s %d %d", students[i].name, &(students[i].age), &(students[i].grade));
    qsort(students, N, sizeof(Student), compare);
    for (i = 0; i < N; i++)
        printf("%s %d %d\n", students[i].name, students[i].age, students[i].grade);
    free(students);
    return 0;
}
