/*  adb_server.h - SERVER PROGRAM HEADER */

#include <rpc/rpc.h>
#include "adb.h"

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char cpf[14];
    char phone[15];
    char address[50];
};

struct agenda {
    struct contact contacts[MAX_CONTACTS];
    int tam;
};

int initialize(void);

int insert_contact(struct contact new_contact);

int remove_contact(char *name);

struct contact search_contact(char *name);

void list_contacts(void);