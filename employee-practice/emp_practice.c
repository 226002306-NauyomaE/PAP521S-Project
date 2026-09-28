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
    
    strcpy(empIds[0], "EMP001");
    strcpy(empNames[0], "Brooklyn September");

    empBasic[0] = 38500.00;
    employeeCount++;

// checking if it works 
printf("ID: %s\n", empIds[0]);
printf("Name: %s\n", empNames[0]);
printf("Basic Salary: %.2f\n", empBasic[0]);
printf("Employee stored: %d\n", employeeCount);
//28/09/2026 storing data successfully adding more employees on 29
    return 0;
}