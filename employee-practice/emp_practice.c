#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define ID_LEN 10
#define NAME_LEN 50
#define DEPT_LEN 30
#define POS_LEN 30
char empIds[MAX_EMPLOYEES][ID_LEN];
double empBasic[MAX_EMPLOYEES];
char empNames[MAX_EMPLOYEES][NAME_LEN] ;
    char empDepartments[MAX_EMPLOYEES][DEPT_LEN];
    char empPositions[MAX_EMPLOYEES][POS_LEN];
    double empHousing[MAX_EMPLOYEES];
    double empTransport[MAX_EMPLOYEES];
    int employeeCount = 0;
int main(void)
{
    printf("Employee ID: ");
    scanf("%9s", empIds[0]);

    printf("You entered: %s\n", empIds[0]);

    char firstName[25];
    char surname[25];

    printf("First Name: ");
    scanf("%24s", firstName);

    printf("Surname: ");
    scanf("%24s", surname);

    strcpy(empNames[0], firstName);
    strcat(empNames[0], " ");
    strcat(empNames[0], surname);

    printf("Full Name: %s\n", empNames[0]);
    printf("Department: ");
    scanf("%29s", empDepartments[0]);

    printf("Position: ");
    scanf("%29s", empPositions[0]);

    printf("Department: %s\n", empDepartments[0]);
    printf("Position: %s\n", empPositions[0]);

    printf("Salary: " );
    scanf("%lf", &empBasic[0]);
    printf("Salary: %.2f\n", empBasic[0]);

    printf("Housing: ");
    scanf("%lf", &empHousing[0]);

    printf("Transport: ");
    scanf("%lf", &empTransport[0]);

    printf("Transport: %.2f\n", empTransport[0]);
    printf("Housing: %.2f\n", empHousing[0]);


    return 0;
}