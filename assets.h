#ifndef ASSET_H
#define ASSET_H

typedef struct {
    int id;
    char name[50];
    char type[30];
    float value;
    char department[30];
    char condition[20];
} Asset;

void assetMenu(Asset* assets, int* count);
void addAsset(Asset* assets, int *count);
void displayAssets(const Asset* assets, int count);
void searchAsset(Asset* assets, int count,int id);

#endif