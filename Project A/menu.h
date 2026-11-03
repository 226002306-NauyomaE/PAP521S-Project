#ifndef MENU_H
#define MENU_H

#include "suppliers.h"
#include "assets.h"

void displayMenu(void);
int enterChoice(void);
void processChoice(int choice, Supplier suppliers[], int *supplierCount, Asset assets[], int *assetCount);
void runMenu(void);

#endif