#ifndef REPORTS_H
#define REPORTS_H

#include "suppliers.h"

// Employee Data
extern int employeeCount;
extern char empIDs[50][10];
extern char empNames[50][50];
extern char empDepts[50][30];
extern double basicSalaries[50];
extern double housingAllowances[50];
extern double transportAllowances[50];

// Budget Data
extern int departmentCount;
extern char departmentNames[50][30];
extern float allocatedBudgets[10];
extern float expenditures[10];

// Asset Data
extern int assetCount;
extern char assetIDs[50][10];
extern char assetNames[50][50];
extern double assetValues[50];
extern char assetTypes[50][20];


// ==========================================
//  REPORTS FUNCTIONS DECLARATIONS
// ==========================================
void displayReportsMenu(const Supplier suppliers[], int supplierCount);
void displayReportsOptions();
void generateEmployeeReport();
void generateBudgetReport();
void generateSupplierReport(const Supplier suppliers[], int supplierCount);
void generateAssetReport();

#endif     //REPORTS_H