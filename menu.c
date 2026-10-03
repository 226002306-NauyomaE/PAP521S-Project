#include <stdio.h>
#include "menu.h"
#include "employees.h"
#include "budget.h"
#include "assets.h"
#include "reports.h"

void displayMenu() {
    printf("\n==============================================\n");
    printf("\n   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM    \n");
    printf("\n==============================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}

int enterChoice(void) {
    int choice;

    while(1) {
        printf("\nEnter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("\n[VALIDATION ERROR] Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (choice < 1 || choice > 6) {
            printf("\n[VALIDATION ERROR] '%d' is an invalid choice! Please enter a number between 1 and 6.\n", choice);
            continue;
        }
        return choice;
    }
}
void processChoice(int choice, Supplier suppliers[], int *supplierCount, Asset assets[], int *assetCount) {
    switch (choice) {
        case 1:
            employeeMenu();
            break;
        case 2:
            budgetMenu();
            break;
        case 3:
            supplierMenu(suppliers, supplierCount);
            break;
        case 4:
            assetMenu(assets, assetCount);
            break;
        case 5:
            displayReportsMenu(suppliers, *supplierCount, assets, *assetCount);
            break;
        case 6:
            printf("\nThank you for using the Municipal Financial Management System. Goodbye!\n");
            break;
        default:
            printf("\n[ERROR] Invalid choice! Please try again.\n");
    }
}
void runMenu(void) {
    int choice;
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;
    Asset assets[50];
    int assetCount = 0;
    do {
        displayMenu();
        choice = enterChoice();
        processChoice(choice, suppliers, &supplierCount, assets, &assetCount);
    } while (choice != 6);
}
