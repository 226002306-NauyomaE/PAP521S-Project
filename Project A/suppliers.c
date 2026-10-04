#include <stdio.h>
#include <string.h> 
#include "suppliers.h"


void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("\nError: Supplier storage is full!\n");
        return;
    }

    Supplier temp;
    char backupName[100];

    printf("\n=== ADD NEW SUPPLIER ===\n");

    
    printf("Enter Supplier ID: ");
    fgets(temp.supplierID, sizeof(temp.supplierID), stdin);
    temp.supplierID[strcspn(temp.supplierID, "\n")] = '\0';

    
    printf("Enter Supplier Name: ");
    fgets(temp.name, sizeof(temp.name), stdin);
    temp.name[strcspn(temp.name, "\n")] = '\0';

    
    strcpy(backupName, temp.name);

    
    printf("Enter Email: ");
    fgets(temp.email, sizeof(temp.email), stdin);
    temp.email[strcspn(temp.email, "\n")] = '\0';

    
    printf("Enter Phone: ");
    fgets(temp.phone, sizeof(temp.phone), stdin);
    temp.phone[strcspn(temp.phone, "\n")] = '\0';

    
    printf("Enter Town: ");
    fgets(temp.town, sizeof(temp.town), stdin);
    temp.town[strcspn(temp.town, "\n")] = '\0';

    
    suppliers[*count] = temp;
    (*count)++;

    printf("\nSupplier added successfully! (Backup verification name: %s)\n", backupName);
}


void displaySuppliers(const Supplier suppliers[], int count) {
    printf("\n=== SUPPLIER LIST ===\n");
    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("%-12s | %-25s | %-25s | %-15s | %-15s\n", "Supplier ID", "Name", "Email", "Phone", "Town");
    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-12s | %-25s | %-25s | %-15s | %-15s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
}


void searchSupplier(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers available to search.\n");
        return;
    }

    char searchName[100];
    int found = 0;

    printf("\n=== SEARCH SUPPLIER ===\n");
    printf("Enter Supplier Name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    for (int i = 0; i < count; i++) {
        
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("\nSupplier Found!\n");
            printf("ID: %s\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",
                   suppliers[i].supplierID,
                   suppliers[i].name,
                   suppliers[i].email,
                   suppliers[i].phone,
                   suppliers[i].town);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Supplier not found.\n");
    }
}


void showNameLength(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n=== SUPPLIER NAME LENGTHS ===\n");
    for (int i = 0; i < count; i++) {
        printf("Supplier: %s | Name Length: %zu | Email Length: %zu | Town Length: %zu\n",
               suppliers[i].name,
               strlen(suppliers[i].name),
               strlen(suppliers[i].email),
               strlen(suppliers[i].town));
    }
}


void constructSupplierDescription(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }

    char description[200];

    printf("\n=== GENERATED SUPPLIER DESCRIPTIONS ===\n");
    for (int i = 0; i < count; i++) {
        
        strcpy(description, suppliers[i].name);
        strcat(description, " can be found in ");
        strcat(description, suppliers[i].town);
        strcat(description, ".");

        printf("%s\n", description);
    }
}


void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n================================\n");
        printf("   MFMS - SUPPLIER MANAGEMENT   \n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Field Lengths\n");
        printf("5. Construct Description\n");
        printf("6. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0;
        } else {
            while (getchar() != '\n'); 
        }

        switch (choice) {
            case 1:
                addSupplier(suppliers, count);
                break;
            case 2:
                displaySuppliers(suppliers, *count);
                break;
            case 3:
                searchSupplier(suppliers, *count);
                break;
            case 4:
                showNameLength(suppliers, *count);
                break;
            case 5:
                constructSupplierDescription(suppliers, *count);
                break;
            case 6:
                printf("Returning to Main Menu\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}