#include <stdio.h>
#include <string.h>

#define STUDENTS 5

// Structure to hold student data
struct Student {
    int rollNumber;
    char firstName[50];
    char lastName[50];
};

// Function to swap two Student records
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort students by roll number using Bubble Sort
void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int main() {
    struct Student students[STUDENTS];

    // Input student details
    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter roll number, first name and last name of student %d: ", i + 1);
        scanf("%d %s %s", &students[i].rollNumber, students[i].firstName, students[i].lastName);
    }

    // Sort the students by roll number
    sortStudents(students, STUDENTS);

    // Print sorted student details
    printf("\nStudent Records in Ascending Order of Roll Number:\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("Roll Number: %d, First Name: %s, Last Name: %s\n",
               students[i].rollNumber, students[i].firstName, students[i].lastName);
    }

    return 0;
}