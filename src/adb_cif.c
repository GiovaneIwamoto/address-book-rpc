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
    int * result;
    result = insert_1(new_contact, handle);
    if (result == (int *)NULL) 
        cli_error();
    
    return *result;
}

/* Remove contact */
int remove_contact(char *name) {
    int * result;
    result = remove_1(&name, handle);
    if (result == (int *)NULL) 
        cli_error();
    
    return *result;
}

/* Search contact */
struct contact search_contact(char *name) {
    static struct contact result;
    struct contact *result_ptr = search_1(&name, handle);
    if (result_ptr == NULL) {
        cli_error();
    } else {
        return *result_ptr;
    }
}

/* List contacts */
struct agenda list_contacts(){
    static struct agenda result;
    struct agenda *result_ptr = list_1(NULL, handle);
    if(result_ptr == NULL){
        cli_error();
    } else {
        return *result_ptr;
    }
}

void cli_error()
{
/*  An error occurred while calling the server
    Print error message and die */
    
   clnt_perror(handle, "RPC Failed");
   clnt_destroy( handle );
   exit(1);
}
