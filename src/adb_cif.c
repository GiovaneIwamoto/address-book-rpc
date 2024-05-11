/* rbd_cif.c - CIF for client */

#include "adb_cif.h"

/* Init agenda */
int initialize() {
    static int result;
    result = *initialize_1_svc(NULL, NULL);
    if (result == 0) {
        clnt_perror(clnt, "Error initializing agenda");
    }
    return &result;
}

/* Insert new contact */
int insert_contact(struct contact *new_contact) {
    static int result;
    result = *insert_1_svc(new_contact, clnt);
    if (result == 0) {
        clnt_perror(clnt, "Error inserting contact");
    }
    return &result;
}

/* Remove contact */
int remove_contact(char *name) {
    static int result;
    result = *remove_1_svc(&name, clnt);
    if (result == 0) {
        clnt_perror(clnt, "Error removing contact");
    }
    return &result;
}

/* Search contact */
struct contact *search_contact(char *name) {
    static struct contact result;
    struct contact *result_ptr = search_1_svc(&name, clnt);
    if (result_ptr == NULL) {
        clnt_perror(clnt, "Contact not found");
    } else {
        result = *result_ptr;
    }
    return &result;
}

