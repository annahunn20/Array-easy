#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    struct Date dob; // Date of birth
    float salary;
};

int main() {
    struct Employee emp;

    printf("Enter employee name: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Enter employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter employee date of birth (day month year): ");
    scanf("%d %d %d", &emp.dob.day, &emp.dob.month, &emp.dob.year);

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    printf("\nEmployee Details:\n");
    printf("Name: %s", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Date of Birth: %02d/%02d/%04d\n", emp.dob.day, emp.dob.month, emp.dob.year);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}
