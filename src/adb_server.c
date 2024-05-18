/*  adb_server.c - SERVER PROGRAM */
#include <string.h>
#include <ctype.h>
#include "adb_server.h"

/* Server Remote Procedures and Global Data */

struct agenda address_book = {.tam = 0};

/* Init address book data */

int initialize(){
    printf("Initializing address book\n");
    address_book.tam = 0; 
    return 1; 
}

// FIXME: Should be at client side
/* Validation functions for each field */
int validate_name(const char *name) {
    return strlen(name) > 0 && strlen(name) <= 50;
}

int validate_cpf(const char *cpf) {
    return strlen(cpf) > 0 && strlen(cpf) <= 14;
}

int validate_phone(const char *phone) {
    return strlen(phone) > 0 && strlen(phone) <= 15;
}

int validate_address(const char *address) {
    return strlen(address) > 0 && strlen(address) <= 50;
}

/* Insert new contact */

int insert_contact(struct contact new_contact){
    if (!validate_name(new_contact.name)) {
        printf("Failed to insert contact: Invalid name\n");
        return 0;
    }
    if (!validate_cpf(new_contact.cpf)) {
        printf("Failed to insert contact: Invalid CPF\n");
        return 0;
    }
    if (!validate_phone(new_contact.phone)) {
        printf("Failed to insert contact: Invalid phone\n");
        return 0;
    }
    if (!validate_address(new_contact.address)) {
        printf("Failed to insert contact: Invalid address\n");
        return 0;
    }

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
            printf("Contact %s found\n", name);
            return address_book.contacts[i];
        }
    }
    /* Return an empty contact */
    
    printf("Contact %s not found\n", name);
    struct contact empty_contact = {"", "", "", ""};
    return empty_contact;
} 

/* List all contacts name */

struct agenda list_contacts() 
{ 
    return address_book;
}