#include <stdio.h>
#include "menu.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
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

int enterChoice(Supplier supplierList[], int *supplierCount) {
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
        switch(choice) {
            case 1:
                employeeMenu();
                break;
            case 2:
                budgetMenu();
                break;
            case 3:
                supplierMenu(supplierList, supplierCount);
                break;
            break;
            case 4:
                printf("\n[INFO] Asset Management selected.\n");
                break;
            case 5:
                printf("\n[INFO] Reports selected.\n");
                break;
            case 6:
                printf("\nExiting Municipal Financial Management System.\n");
                break;
        }
        return choice;
    }
}