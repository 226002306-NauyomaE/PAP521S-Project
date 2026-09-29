#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMPLOYEES 50
#define ID_LEN 10
#define NAME_LEN 50
#define DEPT_LEN 30
#define POS_LEN 30
char empIds[MAX_EMPLOYEES][ID_LEN];
double empBasic[MAX_EMPLOYEES];
char empNames[MAX_EMPLOYEES][NAME_LEN];
char empDepartments[MAX_EMPLOYEES][DEPT_LEN];
char empPositions[MAX_EMPLOYEES][POS_LEN];
double empHousing[MAX_EMPLOYEES];
double empTransport[MAX_EMPLOYEES];
int employeeCount = 0;

void toUpperCase(char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        text[i] = toupper(text[i]);
    }
}
int idExists(char id[])
{
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(empIds[i], id) == 0)
        {
            return 1; // ID exists
        }
    }
    return 0; // ID does not exist
}
void addEmployee(void)
{
    do
    {
        printf("Employee ID: ");
        scanf("%9s", empIds[employeeCount]);
        toUpperCase(empIds[employeeCount]);

        if (idExists(empIds[employeeCount]))
        {
            printf("That ID already exists. Try another.\n");
        }
    } while (idExists(empIds[employeeCount]));

    printf("You entered: %s\n", empIds[employeeCount]);

    char firstName[25];
    char surname[25];

    printf("First Name: ");
    scanf("%24s", firstName);

    printf("Surname: ");
    scanf("%24s", surname);

    strcpy(empNames[employeeCount], firstName);
    strcat(empNames[employeeCount], " ");
    strcat(empNames[employeeCount], surname);

    printf("Full Name: %s\n", empNames[employeeCount]);
    printf("Department: ");
    scanf("%29s", empDepartments[employeeCount]);

    printf("Position: ");
    scanf("%29s", empPositions[employeeCount]);

    printf("Department: %s\n", empDepartments[employeeCount]);
    printf("Position: %s\n", empPositions[employeeCount]);

    int ok;

    do
    {
        printf("Basic salary: ");
        ok = scanf("%lf", &empBasic[employeeCount]);

        if (ok != 1)
        {
            printf("Please enter a number.\n");
            while (getchar() != '\n')
                ;
        }
        else if (empBasic[employeeCount] <= 0)
        {
            printf("Salary must be more than 0. Try again.\n");
        }
    } while (ok != 1 || empBasic[employeeCount] <= 0);
    do
    {
        printf("Housing allowance: ");
        ok = scanf("%lf", &empHousing[employeeCount]);

        if (ok != 1)
        {
            printf("Please enter a number.\n");
            while (getchar() != '\n')
                ;
        }
        else if (empHousing[employeeCount] < 0)
        {
            printf("Housing allowance cannot be negative. Try again.\n");
        }
    } while (ok != 1 || empHousing[employeeCount] < 0);

    do
    {
        printf("Transport allowance: ");
        ok = scanf("%lf", &empTransport[employeeCount]);

        if (ok != 1)
        {
            printf("Please enter a number.\n");
            while (getchar() != '\n')
                ;
        }
        else if (empTransport[employeeCount] < 0)
        {
            printf("Transport allowance cannot be negative. Try again.\n");
        }

    } while (ok != 1 || empTransport[employeeCount] < 0);

    employeeCount++;
    printf("Employee Count: %d\n", employeeCount);
}

double calculateGross(double basic, double housing, double transport)
{
    return basic + housing + transport;
}
double calculateTax(double gross)
{
    if (gross <= 10000)
        return 0; // No tax for income up to 10,000
    else if (gross <= 30000)
        return gross * 0.15; // 15% tax for income between 10,001 and 30,000
    else
        return gross * 0.25; // 25% tax for income above 30,000
}
double calculateNet(double gross, double tax)
{
    return gross - tax;
}

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("No employees to display.\n");
        return;
    }
    printf("Employee List:\n");
    for (int i = 0; i < employeeCount; i++)
    {
        double gross = calculateGross(empBasic[i], empHousing[i], empTransport[i]);
        double tax = calculateTax(gross);
        double net = calculateNet(gross, tax);
        printf("ID: %s, Name: %s, Department: %s, Position: %s, Salary: %.2f, Housing: %.2f, Transport: %.2f, Gross: %.2f, Tax: %.2f, Net: %.2f\n",
               empIds[i], empNames[i], empDepartments[i], empPositions[i], empBasic[i], empHousing[i], empTransport[i], gross, tax, net);
    }
}
void searchEmployeeById(void)
{
    char searchId[ID_LEN];
    printf("Enter Employee ID to search: ");
    scanf("%9s", searchId);
    toUpperCase(searchId);
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(empIds[i], searchId) == 0)
        {
            double gross = calculateGross(empBasic[i], empHousing[i], empTransport[i]);
            double tax = calculateTax(gross);
            double net = calculateNet(gross, tax);
            printf("Employee Found:\n");
            printf("ID: %s, Name: %s, Department: %s, Position: %s, Salary: %.2f, Housing: %.2f, Transport: %.2f, Gross: %.2f, Tax: %.2f, Net: %.2f\n",
                   empIds[i], empNames[i], empDepartments[i], empPositions[i], empBasic[i], empHousing[i], empTransport[i], gross, tax, net);
            return;
        }
    }
    printf("Employee with ID %s not found.\n", searchId);
}
void searchEmployeeByName(void)
{
    char searchName[NAME_LEN];
    printf("Enter Employee Name to search: ");
    scanf("%49s", searchName);
    toUpperCase(searchName);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strstr(empNames[i], searchName) != NULL)
        {
            double gross = calculateGross(empBasic[i], empHousing[i], empTransport[i]);
            double tax = calculateTax(gross);
            double net = calculateNet(gross, tax);
            printf("Employee Found:\n");
            printf("ID: %s, Name: %s, Department: %s, Position: %s, Salary: %.2f, Housing: %.2f, Transport: %.2f, Gross: %.2f, Tax: %.2f, Net: %.2f\n",
                   empIds[i], empNames[i], empDepartments[i], empPositions[i], empBasic[i], empHousing[i], empTransport[i], gross, tax, net);
            return;
        }
    }
    printf("Employee with Name %s not found.\n", searchName);
}
void displayByDepartment(void)
{
    char searchDept[DEPT_LEN];
    printf("Enter Department to display: ");
    scanf("%29s", searchDept);
    toUpperCase(searchDept);

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(empDepartments[i], searchDept) == 0)
        {
            double gross = calculateGross(empBasic[i], empHousing[i], empTransport[i]);
            double tax = calculateTax(gross);
            double net = calculateNet(gross, tax);
            printf("ID: %s, Name: %s, Department: %s, Position: %s, Salary: %.2f, Housing: %.2f, Transport: %.2f, Gross: %.2f, Tax: %.2f, Net: %.2f\n",
                   empIds[i], empNames[i], empDepartments[i], empPositions[i], empBasic[i], empHousing[i], empTransport[i], gross, tax, net);
            found++;
        }
    }
    if (!found)
    {
        printf("No employees found in Department %s.\n", searchDept);
    }
    else
    {
        printf("Total employees found in Department %s: %d\n", searchDept, found);
    }
}
int main(void)
{
    addEmployee();
    addEmployee();
    displayEmployees();
    searchEmployeeById();
    searchEmployeeByName();
    displayByDepartment();
    return 0;
}