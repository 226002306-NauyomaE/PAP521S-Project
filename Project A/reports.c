#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "reports.h"

// ============================================================
// REPORTS STRUCTURAL DATABASE ARRAYS (for storage of records)
// ============================================================

// Employee Module Databases
extern int employeeCount; 
extern char empIds[50][10];
extern char empNames[50][50];
extern char empDepartments[50][30];
extern double empBasic[50];
extern double empHousing[50];
extern double empTransport[50];

// Budget Module Databases
extern int departmentCount;
extern char departmentNames[10][50];
extern float allocatedBudgets[10];
extern float expenditures[10];

// ==========================================
//  REPORTS SWITCH DECISION CONTROLLER
// ==========================================

void displayReportsMenu(const Supplier suppliers[], int supplierCount, Asset assets[], int assetCount)
{
        int choice;
        
        do
        {
        displayReportsOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
            generateEmployeeReport();
            break;

            case 2: 
            generateBudgetReport();
            break;

            case 3:
            generateSupplierReport(suppliers, supplierCount);
            break;

            case 4: 
            generateAssetReport(assets, assetCount);
            break;

            case 5: printf("\nExiting Municipal Report System. Goodbye!\n"); 
            break;

            default: 
            printf("\n[VALIDATION ERROR] '%d' is an invalid choice! Please enter a number between 1 and 5.\n", choice);
            // Clear input buffer in case a letter was typed to prevent infinite loops
            while (getchar() != '\n');
                break;
            }  
    } while(choice != 5);
}  

// ==========================================
//  REPORTS MENU
// ==========================================
void displayReportsOptions() {
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL REPORTS SYSTEM  \n");
    printf("========================================\n");
    printf("1. Employee Report\n");
    printf("2. Budget Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
    printf("5. Exit\n");
    printf("========================================\n");
}


// --- Report 1: Employee Statistics Calculations ---
void generateEmployeeReport() {
    printf("\n--- MUNICIPAL EMPLOYEE REPORT ---\n");
    if (employeeCount == 0) {
        printf("No employee records found.\n");
        return;
    }

    double totalSalary = 0;
    double highestSalary = 0;
    double lowestSalary = 9999999999.0;

    for (int i = 0; i < employeeCount; i++) {
        // Gross Salary Calculation = Basic + Housing + Transport
        double gross = empBasic[i] + empHousing[i] + empTransport[i];
        totalSalary += gross;

        if (gross > highestSalary) highestSalary = gross;
        if (gross < lowestSalary) lowestSalary = gross;
    }

        if (employeeCount <= 0) {
        printf("\n[VALIDATION ERROR] Cannot calculate statistics. No employee records found.\n");
        return;
    }

        if (employeeCount > 50) {
        printf("\n[CRITICAL ERROR] Data array overflow! Restricting report view to the first 50 entries.\n");
        employeeCount = 50; 
    }


    if (lowestSalary == 9999999999.0) lowestSalary = 0; // Handle case with no employees


    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: N$%.2f\n", totalSalary / employeeCount);
    printf("Highest Salary: N$%.2f\n", highestSalary);
    printf("Lowest Salary:  N$%.2f\n", lowestSalary);
}



// --- Report 2: Budget Summaries & Deficit Detection ---
void generateBudgetReport() {
    printf("\n--- MUNICIPAL BUDGET REPORT ---\n");
    if (departmentCount == 0) {
        printf("No departmental budget records found.\n");
        return;
    }

    double totalAllocated = 0, totalExpenditure = 0;

    for (int i = 0; i < departmentCount; i++) {
        totalAllocated += allocatedBudgets[i];
        totalExpenditure += expenditures[i];
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments Exceeding Budget:\n");
    int deficitFound = 0;
    for (int i = 0; i < departmentCount; i++) {
        if (expenditures[i] > allocatedBudgets[i]) {
            printf("- %-12s (Budget exceeded by: N$%.2f)\n", departmentNames[i], expenditures[i] - allocatedBudgets[i]);
            deficitFound = 1;
        }
    }
    if (!deficitFound) {
        printf("None. All operational departments are within budget.\n");
    }
}



// --- Report 3: Supplier Logs ---
void generateSupplierReport(const Supplier suppliers[], int supplierCount) {
    printf("\n--- REGISTERED SUPPLIERS REPORT ---\n");
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("%-10s %-20s %-25s %-20s\n", "ID", "Supplier Name", "Email Address", "Phone Number");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%-10s %-20s %-25s %-20s\n", suppliers[i].supplierID, suppliers[i].name, suppliers[i].email, suppliers[i].phone);
    }
}



// --- Report 4: Asset Tracking Logs ---
void generateAssetReport(const Asset assets[], int assetCount) {
    printf("\n--- MUNICIPAL ASSET REGISTER REPORT ---\n");
    if (assetCount == 0) {
        printf("No municipal assets found.\n");
        return;
    }
    printf("%-10s %-20s %-20s N$%-15.2f\n", "ID", "Asset Name", "Type", "Value");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-10s %-20s %-20s N$%-15.2f\n", assets[i].id, assets[i].name, assets[i].type, assets[i].value);
    }
}
