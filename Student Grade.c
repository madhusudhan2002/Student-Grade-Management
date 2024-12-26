#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
typedef struct {
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;
void addStudent(Student students[], int *num_students) {
    if (*num_students >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    printf("Enter the name of student %d: ", *num_students + 1);
    scanf("%s", students[*num_students].name);
    printf("Enter the grade of student %d: ", *num_students + 1);
    scanf("%f", &students[*num_students].grade);
    (*num_students)++;
}
void displayStudents(Student students[], int num_students) {
    printf("\nStudent Grade List:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Grade: %.2f\n", students[i].name, students[i].grade);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int choice;
    while (1) {
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                displayStudents(students, num_students);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
