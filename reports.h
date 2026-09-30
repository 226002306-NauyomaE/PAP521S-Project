#ifndef REPORTS_H
#define REPORTS_H

// ==========================================
// REPORT ARRAYS
// ==========================================

// Employee Data
int empCount;
char empIDs[50][10];
char empNames[50][50];
char empDepts[50][30];
double basicSalaries[50];
double housingAllowances[50];
double transportAllowances[50];

// Budget Data
int deptCount;
char deptNames[50][30];
double allocatedBudgets[50];
double expenditures[50];

// Supplier Data
int supplierCount;
char supplierIDs[50][10];
char supplierNames[50][50];
char supplierEmails[50][50];
char supplierPhone[50][15];

// Asset Data
int assetCount;
char assetIDs[50][10];
char assetNames[50][50];
double assetValues[50];
char assetTypes[50][20];


// ==========================================
//  REPORTS FUNCTIONS DECLARATIONS
// ==========================================
void DisplayReportsMenu();
void generateEmployeeReport();
void generateBudgetReport();
void generateSupplierReport();
void generateAssetReport();

#endif // REPORTS_H