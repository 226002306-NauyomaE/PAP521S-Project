#include <stdio.h>
#include "suppliers.h"

void displayMainMenu(void) {
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Supplier Management\n");
    printf("2. Exit\n");
    printf("Enter choice: ");
}

int main(void) {
    Supplier supplierList[MAX_SUPPLIERS];
    int supplierCount = 0;
    int choice;

    do {
        displayMainMenu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0;
        } else {
            while (getchar() != '\n'); 
        }

        switch (choice) {
            case 1:
                
                supplierMenu(supplierList, &supplierCount);
                break;
            case 2:
                printf("\nExit\n");
                break;
            default:
                printf("\nInvalid choice! Please enter 1 or 2.\n");
        }
    } while (choice != 2);

    return 0;
}