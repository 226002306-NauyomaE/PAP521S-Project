#include <stdio.h>
#include <string.h>
#include "assets.h"

void assetMenu(Asset* assets, int* count) {
    int choice;
    do {
        printf("\n===== ASSETS MANAGEMENT MENU ======:\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAsset(assets, count);
                break;
            case 2:
                displayAssets(assets, *count);
                break;
            case 3: {
                int id;
                printf("Enter asset ID to search: ");
                scanf("%d", &id);
                searchAsset(assets, *count, id);
                break;
            }
            case 4:
                printf("Exiting Asset Management Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
void addAsset(Asset* assets, int *count) {
    Asset newAsset;
    printf("Enter asset ID: ");
    scanf("%d", &newAsset.id);

    if (newAsset.id <= 0) {
        printf("Invalid ID. Must be a positive integer.\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        if (assets[i].id == newAsset.id) {
            printf("Asset with ID %d already exists. Please use a unique ID.\n", newAsset.id);
            return;
        }
    }
    newAsset.id = *count + 1; // Assign a unique ID based on the current count

    printf("Enter asset name: ");
    scanf("%49s", newAsset.name);

    printf("Enter asset type: ");
    scanf("%29s", newAsset.type);

    printf("Enter asset value: ");
    scanf("%f", &newAsset.value);

    printf("Enter asset department: ");
    scanf("%29s", newAsset.department);

    printf("Enter asset condition: ");
    scanf("%19s", newAsset.condition);

    assets[*count] = newAsset; // Add the new asset to the array
    (*count)++; // Increment the count of assets

    printf("Asset added successfully!\n");
}

void displayAssets(const Asset* assets, int count) {
    if (count == 0) {
        printf("No assets to display.\n");
        return;
    }

    printf("ID\tName\tType\tValue\tDepartment\tCondition\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%.2f\t%s\t%s\n", assets[i].id, assets[i].name, assets[i].type, assets[i].value, assets[i].department, assets[i].condition);
    }
}

void searchAsset(Asset* assets, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (assets[i].id == id) {
            printf("Asset found:\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Value: %.2f\n", assets[i].value);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);
            return;
        }
    }
    printf("Asset with ID %d not found.\n", id);
}