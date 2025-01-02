#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact addressBook[MAX_ENTRIES];
int totalContacts = 0;

void createAddressBook() {
    totalContacts = 0;
    printf("Address Book created!\n");
}

void viewAddressBook() {
    if (totalContacts == 0) {
        printf("Address Book is empty.\n");
        return;
    }
    for (int i = 0; i < totalContacts; i++) {
        printf("Record %d: Name: %s, Phone: %s, Email: %s\n", i + 1, addressBook[i].name, addressBook[i].phone, addressBook[i].email);
    }
}

void insertRecord() {
    if (totalContacts < MAX_ENTRIES) {
        printf("Enter Name: ");
        scanf("%s", addressBook[totalContacts].name);
        printf("Enter Phone: ");
        scanf("%s", addressBook[totalContacts].phone);
        printf("Enter Email: ");
        scanf("%s", addressBook[totalContacts].email);
        totalContacts++;
        printf("Record inserted!\n");
    } else {
        printf("Address Book is full.\n");
    }
}

void deleteRecord() {
    int index;
    printf("Enter record number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > totalContacts) {
        printf("Invalid record number.\n");
        return;
    }
    for (int i = index - 1; i < totalContacts - 1; i++) {
        addressBook[i] = addressBook[i + 1];
    }
    totalContacts--;
    printf("Record deleted!\n");
}

void modifyRecord() {
    int index;
    printf("Enter record number to modify: ");
    scanf("%d", &index);
    if (index < 1 || index > totalContacts) {
        printf("Invalid record number.\n");
        return;
    }
    printf("Enter New Name: ");
    scanf("%s", addressBook[index - 1].name);
    printf("Enter New Phone: ");
    scanf("%s", addressBook[index - 1].phone);
    printf("Enter New Email: ");
    scanf("%s", addressBook[index - 1].email);
    printf("Record modified!\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Create Address Book\n2. View Address Book\n3. Insert Record\n4. Delete Record\n5. Modify Record\n6. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAddressBook(); break;
            case 2: viewAddressBook(); break;
            case 3: insertRecord(); break;
            case 4: deleteRecord(); break;
            case 5: modifyRecord(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 6);
    return 0;
}
