#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adb_cif.h"
#include "adb.h"
#define MAX_CONTACTS 100

void print_menu() {
    printf("\n ADDRESS BOOK \n");
    printf("------------------\n");
    printf("1. INSERT CONTACT\n");
    printf("2. REMOVE CONTACT\n");
    printf("3. SEARCH CONTACT\n");
    printf("4. LIST ALL CONTACTS\n");
    printf("5. EXIT\n");
    printf("\nChoose an option: ");
}

int main(int argc, char *argv[]) {
    CLIENT *clnt; // Client handle
    char *server; // Server adress

    // Usage message
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        exit(1);
    }
    
    server = argv[1];

    // Create client handle
    clnt = clnt_create(server, ADBPROG, ADBVERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }

    int option;
    char name[50];
    struct contact new_contact;

    while (1) {
        print_menu();
        scanf("%d", &option);
    
        switch (option) {
            case 1: // Insert contact
                printf("Enter name: ");
                scanf("%s", new_contact.name);
                
                printf("Enter CPF: ");
                scanf("%s", new_contact.cpf);
                
                printf("Enter phone: ");
                scanf("%s", new_contact.phone);
                
                printf("Enter address: ");
                scanf("%s", new_contact.address);
                
                int insert_result;
                insert_result = insert_contact(&new_contact);
                
                if (insert_result == 0) {
                    fprintf(stderr, "Error inserting contact\n");
                    exit(1);
                } else {
                    printf("Contact inserted successfully\n");
                }
                break;

            case 2: // Remove contact
                printf("Enter name of contact to remove: ");
                scanf("%s", name);
                int *remove_result;
                remove_result = remove_contact(name);
                if (*remove_result == 0) {
                    fprintf(stderr, "Error removing contact\n");
                } else {
                    printf("Contact removed successfully\n");
                }
                break;

            case 3: // Search contact
                break;

            case 4: // List all contacts
                break;

            case 5: // Exit
                printf("Exiting the program.\n");
                clnt_destroy(clnt);
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;

}
    
