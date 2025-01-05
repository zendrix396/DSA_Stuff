#include <stdio.h>
#include <string.h>
#define max_name 50
#define max_students 100

struct Student
{
    char name[max_name];
    int age;
};

int main()
{
    FILE *file;
    struct Student student[max_students];
    struct Student temp;
    int count = 0;
    file = fopen("students.txt", "r");
    while (fscanf(file, "%s %d", student[count].name, &student[count].age) != EOF)
    {
        count++;
    }
    fclose(file);
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(student[j].name, student[j + 1].name) > 0)
            {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s %d\n", student[i].name, student[i].age);
    }

    return 0;
}