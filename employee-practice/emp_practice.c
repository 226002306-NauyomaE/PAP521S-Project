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
    void addEmployee(void)
    {
    printf("Employee ID: ");
    scanf("%9s", empIds[employeeCount]);

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

    printf("Salary: " );
    scanf("%lf", &empBasic[employeeCount]);
    printf("Salary: %.2f\n", empBasic[employeeCount]);

    printf("Housing: ");
    scanf("%lf", &empHousing[employeeCount]);

    printf("Transport: ");
    scanf("%lf", &empTransport[employeeCount]);

    printf("Transport: %.2f\n", empTransport[employeeCount]);
    printf("Housing: %.2f\n", empHousing[employeeCount]);

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
int main(void)
{
    addEmployee();
    addEmployee();
    displayEmployees();
    searchEmployeeById();
    return 0;
}