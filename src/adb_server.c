/*  adb_server.c - SERVER PROGRAM */
#include <string.h>
#include <ctype.h>
#include "adb_server.h"

/* Server Remote Procedures and Global Data */

struct agenda address_book = {.tam = 0};

/* Init address book data */

int initialize(){
    printf("Initializing empty address book\n");
    address_book.tam = 0; 
    return 1; 
}

/* Insert new contact */

int insert_contact(struct contact new_contact){
    if (address_book.tam < MAX_CONTACTS) {
        memcpy(&address_book.contacts[address_book.tam], &new_contact, sizeof(struct contact));
        address_book.tam++;
        printf("Contact inserted: %s\n", new_contact.name);
        return 1; /* Successful insertion */ 
    } else {
        printf("Failed to insert contact: Address book is full\n");
        return 0; /* Unable to insert */
    }
}

/* Remove contact */

int remove_contact(char *name){
    for (int i = 0; i < address_book.tam; i++){
        if(strcmp(name, address_book.contacts[i].name) == 0){
            printf("Contact removed: %s\n",address_book.contacts[i].name);
            
            /* Filling empty gap */
            for (int j = i; j < address_book.tam - 1; j++) {
                address_book.contacts[j] = address_book.contacts[j + 1];
            }
            address_book.tam--;
            return 1; /* Contact successfully removed */
        }
    }
    return 0; /* Contact not found */
}

/* Search by name and returns all info */

struct contact search_contact(char *name) 
{ 
    for (int i = 0; i < address_book.tam; i++) {
        if (strcmp(name, address_book.contacts[i].name) == 0) {
            printf("Contact found: %s\n", name);
            return address_book.contacts[i];
        }
    }
    /* Return an empty contact */
    
    //printf("Contact not found: %s\n", name);
    struct contact empty_contact;
    strcpy(empty_contact.name, "not_found");    
    return empty_contact;
} 

/* List all contacts name */

struct agenda list_contacts() 
{ 
    return address_book;
}