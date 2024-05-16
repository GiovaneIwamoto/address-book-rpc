/* rbd_cif.c - CIF for client */

#include "adb_cif.h"

/* Init agenda */
int initialize() {
    int * result;
    result = initialize_1(NULL, handle);
    if (result == (int *)NULL) 
        cli_error();
     
    return *result; 
} 

/* Insert new contact */
int insert_contact(struct contact *new_contact) {
    static int result;
    result = *insert_1(new_contact, handle);
    if (result == 0) {
        cli_error();
    }
    return result;
}

/* Remove contact */
int remove_contact(char *name) {
    static int result;
    result = *remove_1(&name, handle);
    if (result == 0) {
        cli_error();
    }
    return result;
}

/* Search contact */
struct contact search_contact(char *name) {
    static struct contact result;
    struct contact *result_ptr = search_1(&name, handle);
    if (result_ptr == NULL) {
        clnt_perror(handle, "Contact not found");
    } else {
        result = *result_ptr;
    }
    return result;
}

/* List contacts */
struct agenda list_contacts(){
    static struct agenda result;
    struct agenda *result_ptr = list_1(NULL, handle);
    if(result_ptr == NULL){
        clnt_perror(handle, "Error listing all contacts");
    } else {
        result = *result_ptr;
    }
    return result;
}

void cli_error()
{
/*  An error occurred while calling the server
    Print error message and die */
    
   printf("RPC Failed\n");
   clnt_perror(handle, "RPC Error");
   clnt_destroy( handle );
   exit(1);
}
