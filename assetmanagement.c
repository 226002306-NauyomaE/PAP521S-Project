// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <string.h>

int main() {

    int assetID;
    char assetName[50];
    char assetType[50];
    float purchaseValue;
    char department[50];
    char condition[50];
    char searchName[50];

    printf("Enter asset ID: ");
    scanf("%d", &assetID);
    getchar();

    printf("Enter asset name: ");
    fgets(assetName, sizeof(assetName), stdin);

    printf("Enter asset type: ");
    fgets(assetType, sizeof(assetType), stdin);

    printf("Enter purchase value: ");
    scanf("%f", &purchaseValue);
    getchar();

    printf("Enter department: ");
    fgets(department, sizeof(department), stdin);

    printf("Enter condition: ");
    fgets(condition, sizeof(condition), stdin);

    printf("\n--- ASSET REGISTER---\n");
    printf("ID: %d", assetID);
    //getchar();
    printf("\nType: %s", assetType);
    printf("value: %.2f\n", purchaseValue);
    printf("department: %s", department);
    printf("condition: %s", condition);

    printf("Enter Asset Name to search: ");
    fgets(searchName, sizeof(searchName), stdin);

    if(strcmp(searchName, assetName) == 0) {
        printf("Asset found\n");
    } else {
        printf("Asset not found\n");
    }
        
    return 0;
}