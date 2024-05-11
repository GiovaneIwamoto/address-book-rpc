/*  adb_server.h - SERVER PROGRAM HEADER */

#include <rpc/rpc.h>
#include "adb.h"

#define MAX_CONTACTS 100

int initialize(void);

int insert_contact(struct contact new_contact);

int remove_contact(char *name);

struct contact search_contact(char *name);

struct agenda list_contacts(void);