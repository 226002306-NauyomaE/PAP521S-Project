#ifndef MENU_H
#define MENU_H

#include "suppliers.h"

void displayMenu(void);
int enterChoice(void);
void processChoice(int choice, Supplier suppliers[], int *supplierCount);
void runMenu(void);

#endif