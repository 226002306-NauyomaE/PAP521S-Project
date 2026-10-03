#include <stdio.h>
#include "asset.h"

int main() {
    Asset assets[100];
    int count = 0;
    int choice;

    do {
        printf("\nAsset Management System\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAsset(assets, &count);
                break;
            case 2:
                displayAssets(assets, count);
                break;
            case 3: {
                int id;
                printf("Enter asset ID to search: ");
                scanf("%d", &id);
                searchAsset(assets, count, id);
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}