#include <stdio.h>
#include <string.h>
#include "reports.h"


// ============================================================
// REPORTS STRUCTURAL DATABASE ARRAYS (for storage of records)
// ============================================================

// Employee Module Databases
int empCount = 0; 
char empIDs[50][10] = {0};
char empNames[50][50] = {0};
char empDepts[50][30] = {0};
double basicSalaries[50] = {0};
double housingAllowances[50] = {0};
double transportAllowances[50] = {0};

// Budget Module Databases
int deptCount = 0;
char deptNames[50][30] = {0};
double allocatedBudgets[50] = {0};
double expenditures[50] = {0};

// Supplier Module Databases
int supplierCount = 0;
char supplierIDs[50][10] = {0};
char supplierNames[50][50] = {0};
char supplierEmails[50][50] = {0};
char supplierPhone[50][15] = {0};

// Asset Module Databases
int assetCount = 0;
char assetIDs[50][10] = {0};
char assetNames[50][50] = {0};
char assetTypes[50][20] = {0};
double assetValues[50] = {0};


// ==========================================
//  REPORTS SWITCH DECISION CONTROLLER
// ==========================================
int main() {
    int choice;
    
    do {
        DisplayReportsMenu();
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
            generateSupplierReport();
            break;

            case 4: 
            generateAssetReport();
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
    
    return 0;
}


// ==========================================
//  REPORTS MENU
// ==========================================
void DisplayReportsMenu() {
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
    if (empCount == 0) {
        printf("No employee records found.\n");
        return;
    }

    double totalSalary = 0;
    double highestSalary = 0;
    double lowestSalary = 9999999999.0;

    for (int i = 0; i < empCount; i++) {
        // Gross Salary Calculation = Basic + Housing + Transport
        double gross = basicSalaries[i] + housingAllowances[i] + transportAllowances[i];
        totalSalary += gross;

        if (gross > highestSalary) highestSalary = gross;
        if (gross < lowestSalary) lowestSalary = gross;
    }

        if (empCount <= 0) {
        printf("\n[VALIDATION ERROR] Cannot calculate statistics. No employee records found.\n");
        return;
    }

        if (empCount > 50) {
        printf("\n[CRITICAL ERROR] Data array overflow! Restricting report view to the first 50 entries.\n");
        empCount = 50; 
    }


    if (lowestSalary == 9999999999.0) lowestSalary = 0; // Handle case with no employees


    printf("Total Employees: %d\n", empCount);
    printf("Average Salary: N$%.2f\n", totalSalary / empCount);
    printf("Highest Salary: N$%.2f\n", highestSalary);
    printf("Lowest Salary:  N$%.2f\n", lowestSalary);
}



// --- Report 2: Budget Summaries & Deficit Detection ---
void generateBudgetReport() {
    printf("\n--- MUNICIPAL BUDGET REPORT ---\n");
    if (deptCount == 0) {
        printf("No departmental budget records found.\n");
        return;
    }

    double totalAllocated = 0, totalExpenditure = 0;

    for (int i = 0; i < deptCount; i++) {
        totalAllocated += allocatedBudgets[i];
        totalExpenditure += expenditures[i];
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments Exceeding Budget:\n");
    int deficitFound = 0;
    for (int i = 0; i < deptCount; i++) {
        if (expenditures[i] > allocatedBudgets[i]) {
            printf("- %-12s (Budget exceeded by: N$%.2f)\n", deptNames[i], expenditures[i] - allocatedBudgets[i]);
            deficitFound = 1;
        }
    }
    if (!deficitFound) {
        printf("None. All operational departments are within budget.\n");
    }
}



// --- Report 3: Supplier Logs ---
void generateSupplierReport() {
    printf("\n--- REGISTERED SUPPLIERS REPORT ---\n");
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("%-10s %-20s %-25s %-20s\n", "ID", "Supplier Name", "Email Address", "Phone Number");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%-10s %-20s %-25s %-20s\n", supplierIDs[i], supplierNames[i], supplierEmails[i], supplierPhone[i]);
    }
}



// --- Report 4: Asset Tracking Logs ---
void generateAssetReport() {
    printf("\n--- MUNICIPAL ASSET REGISTER REPORT ---\n");
    if (assetCount == 0) {
        printf("No municipal assets found.\n");
        return;
    }
    printf("%-10s %-20s %-20s N$%-15.2f\n", "ID", "Asset Name", "Type", "Value");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-10s %-20s %-20s N$%-15.2f\n", assetIDs[i], assetNames[i], assetTypes[i], assetValues[i]);
    }
}
