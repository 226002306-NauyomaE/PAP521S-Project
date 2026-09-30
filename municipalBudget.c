#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 10
char  departmentNames[MAX_DEPARTMENTS][50];
float allocatedBudgets[MAX_DEPARTMENTS];
float expenditures[MAX_DEPARTMENTS];
float remainingBudgets[MAX_DEPARTMENTS];
char  statuses[MAX_DEPARTMENTS][20];
float totalBudget = 0;
float totalExpenditure = 0;
int choice;

int departmentCount = 0;

void displayMenu();
float calculateBudget(float allocated, float expenditure);
void enterBudget();
void displayBudget();
void identifyOverBudget();


void displayMenu()
{
    printf("\n==============================================\n");
    printf("     MUNICIPAL BUDGET MANAGEMENT SYSTEM\n");
    printf("===============================================\n");
    printf("1. Enter Departmental Budget\n");
    printf("2. Display Budget Information\n");
    printf("3. Identify Departments Over Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
}

float calculateBudget(float allocated, float expenditure)
{
    return allocated - expenditure;
}


void enterBudget()
{
    int i = departmentCount;

    if (departmentCount >= MAX_DEPARTMENTS)
    {
        printf("\nMaximum number of departments reached!\n");
        return;
    }

    printf("\nEnter department name: ");
    fgets(departmentNames[i], sizeof(departmentNames[i]), stdin);
    if (fgets(departmentNames[i], sizeof(departmentNames[i]), stdin) == NULL)
    {
        printf("\nInvalid name. Entry cancelled.\n");
        return;
    }
    if (strchr(departmentNames[i], '\n') != NULL)
    {
        departmentNames[i][strcspn(departmentNames[i], "\n")] = '\0';
    }

    printf("Enter allocated budget (N): ");
    if (scanf("%f", &allocatedBudgets[i]) != 1 || allocatedBudgets[i] < 0)
   {
        return;
    }

    printf("Enter expenditure (N): ");
    if (scanf("%f", &expenditures[i]) != 1 || expenditures[i] < 0)
   {
        return;
    }
    
    remainingBudgets[i] = calculateBudget(allocatedBudgets[i], expenditures[i]);

    if (expenditures[i] <= allocatedBudgets[i])
    {
        strcpy(statuses[i], "WITHIN BUDGET");
    }
    else
    {
        strcpy(statuses[i], "OVER BUDGET");
    }

    departmentCount++;

    printf("\nBudget information saved successfully!\n");
}

void displayBudget()
{
    if (departmentCount == 0)
    {
        printf("\nNo budget information available.\n");
        return;
    }


    printf("\n--- BUDGET INFORMATION ---\n");

    for (int i = 0; i < departmentCount; i++)
    {
        totalBudget = totalBudget + allocatedBudgets[i];
        totalExpenditure = totalExpenditure + expenditures[i];
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nDepartment: %s\n", departmentNames[i]);
        printf("Allocated Budget: N%.2f\n", allocatedBudgets[i]);
        printf("Expenditure: N%.2f\n", expenditures[i]);
        printf("Remaining Budget: N%.2f\n", remainingBudgets[i]);
        printf("Status: %s\n", statuses[i]);   
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");  
}
printf("\n========================================\n");
     printf("TOTAL ALLOCATED BUDGET: N$%.2f\n", totalBudget);
     printf("TOTAL EXPENDITURE:      N$%.2f\n", totalExpenditure);
     printf("TOTAL REMAINING BUDGET: N%.2f\n", calculateBudget(totalBudget, totalExpenditure));
     printf("========================================\n");
}

void identifyOverBudget()
{
    int found = 0;

    printf("\n+++++++ DEPARTMENTS OVER BUDGET +++++++\n");

    for (int i = 0; i < departmentCount; i++)
    {
        if (expenditures[i] > allocatedBudgets[i])
        {
            printf("\nDepartment: %s\n", departmentNames[i]);
            printf("Allocated Budget: N$%.2f\n", allocatedBudgets[i]);
            printf("Expenditure: N$%.2f\n", expenditures[i]);
            printf("Excess Amount: N$%.2f\n", expenditures[i] - allocatedBudgets[i]);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo department has exceeded its allocated budget.\n");
    }

    printf("\n=====================================\n");
}
int main()
{
do {
    {
        displayMenu();

        switch (choice)
        {
            case 1:
                enterBudget();
                break;

            case 2:
                displayBudget();
                break;

            case 3:
                identifyOverBudget();
                break;

            case 4:
                printf("\nThank you for using the Budget Management System. Have a nice day.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
    }
    }
} while (choice !=4);
    return 0;
}
