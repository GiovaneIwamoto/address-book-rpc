#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adb_cif.h"
#include "adb.h"

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
    char *server;   
    int result;     
    
    /* Usage message */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        exit(1);
    }
    server = argv[1]; 

    /* Create client handle */
    handle = clnt_create(server, ADBPROG, ADBVERS, "tcp");
    if (handle == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }
    
    /* Initialize address book */
    result = initialize();
    if (result == 0) {
        fprintf(stderr, "Error connecting to remote address book\n");
        exit(1);
    } else {
        printf("Address Book connected successfully\n");
    }

    /* Client variables */
    int option;
    char name[50];
    struct agenda address_book;
    struct contact new_contact;

    /* Client interface */
    while (1) {
        print_menu();
        scanf("%d", &option);
    
        switch (option) {
            case 1: /* Insert contact */
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
                    fprintf(stderr, "\nError inserting contact\n");
                } else {
                    printf("\nContact inserted successfully\n");
                }
                break;

            case 2: /* Remove contact */
                printf("\nEnter name of contact to remove: ");
                scanf("%s", name);
                
                int remove_result;
                remove_result = remove_contact(name);
                
                if (remove_result == 0) {
                    clnt_perror(handle, "\nError removing contact"); //FIXME: Perror use at interface
                } else {
                    printf("\nContact removed successfully\n");
                }
                break;

            case 3: /* Search contact */
                break;

            case 4: /* List contacts */
                agenda result_agenda;
                result_agenda = list_contacts(handle);

                if (result_agenda.tam == 0) {
                    fprintf(stderr, "\nNo contacts in address book\n");
                } else {
                    for (int i=0; i < result_agenda.tam; i++){
                        struct contact c = result_agenda.contacts[i];
                        printf("\nName: %s", c.name);
                    };
                    printf("\n ");
                }
                break;
                
            case 5: /* Exit client */
                printf("Exiting the program\n");
                clnt_destroy(handle);
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }
    
    return 0;
}
    
