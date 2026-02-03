#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int student_count = 101;

struct Student{
        int id;
        char name[50];
        int age;
        char department[50];
        float gpa;
        char email [50];
        char phone[15];
};

struct Student students[100];
int count = 0;

int generate_student_id();
void removeNewline(char *str);
void addStudent(struct Student *s);

int generate_student_id() {
    return student_count++;
}

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void addStudent(struct Student *s){
    s->id = generate_student_id();

    printf("Enter Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    removeNewline(s->name);

    printf("Enter Age: ");
    scanf("%d", &s->age);
    getchar();

    printf("Enter Department: ");
    fgets(s->department, sizeof(s->department), stdin);
    removeNewline(s->department);

    printf("Enter GPA: ");
    scanf("%f", &s->gpa);
    getchar();

    printf("Enter Email: ");
    fgets(s->email, sizeof(s->email), stdin);
    removeNewline(s->email);

    printf("Enter Phone Number: ");
    fgets(s->phone, sizeof(s->phone), stdin);
    removeNewline(s->phone);
}

int main()
{
    addStudent(&students[count]);
    count++;

    printf("\nStudent added successfully!\n");
    printf("Student ID: %d\n", students[0].id);


return 0;
}
