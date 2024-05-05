/*  adb_server.c - SERVER PROGRAM */

#include "adb_server.h"

/* Server Remote Procedures and Global Data */

struct agenda_contact address_book[MAX_CONTACTS];
int num_contacts = 0;

/* Init address book data */

int initialize(){
    printf("Initializing address book\n");
    num_contacts = 0; 
    return 1; 
}

/* Insert new contact */

int insert(agenda_contact new_contact){
    if (num_contacts < MAX_CONTACTS) {
        printf("Inserting contact: %s\n", new_contact.name);
        address_book[num_contacts] = new_contact;
        num_contacts++;
        return 1; /* Successful insertion */ 
    } else {
        printf("Failed to insert contact: Address book is full\n");
        return 0; /* Unable to insert */
    }
}

/* Remove contact */

int remove(string name){
    for (int i=0; i<num_contacts; i++){
        if(strcmp(name, address_book[i].name) == 0){
            printf("Removing contact: %s\n",address_book[i].name);
            
            /* Filling empty gap */
            for (int j = i; j < num_contacts - 1; j++) {
                address_book[j] = address_book[j + 1];
            }
            num_contacts--;
            return 1; /* Contact successfully removed */
        }
    }
    printf("Contact %s not found\n", name);
    return 0; /* Contact not found */
}

/* List all contacts name */

void list(void) 
{ 
    printf("Listing contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone: %s\nAddress: %s\n", address_book[i].name, address_book[i].phone, address_book[i].address);
    }
}

/* Search by name and returns all info */

agenda_contact search(string name) 
{ 
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, address_book[i].name) == 0) {
            printf("Contact %s found\n", name);
            return address_book[i];
        }
    }
    /* Return an empty contact */
    
    printf("Contact %s not found\n", name);
    agenda_contact empty_contact = {"", "", ""};
    return empty_contact;
} 