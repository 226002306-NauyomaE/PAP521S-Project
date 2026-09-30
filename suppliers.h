#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50


typedef struct {
    char supplierID[20];
    char name[100];
    char email[100];
    char phone[30];
    char town[50];
} Supplier;


void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);
void showNameLength(const Supplier suppliers[], int count);
void constructSupplierDescription(const Supplier suppliers[], int count);
void supplierMenu(Supplier suppliers[], int *count);

#endif 