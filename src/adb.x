/* adb.x  
    RPC specification for an address book program that 
    offers the procedures INSERT, REMOVE, LIST, and SEARCH
*/

struct contact {            
    char name[50];
    char cpf[14];
    char phone[15];
    char address[50];
};

struct agenda{
    contact contacts[100];
    int tam;
};

program ADBPROG{     
    version ADBVERS{
          int INITIALIZE(void) = 1; 
          int INSERT(contact) = 2; 
          int REMOVE(string) = 3;
          int SEARCH(string) = 4;
          agenda LIST(void) = 5;
    } = 1; /* Program version */
} = 0x30090950;
