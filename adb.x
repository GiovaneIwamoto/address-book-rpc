/* adb.x  
    RPC specification for an address book program that 
    offers the procedures INSERT, REMOVE, LIST, and SEARCH
*/

struct agenda_contact {            
    char name[255];
    char phone[15];
    char address[255];
}; 

program ADBPROG{     
    version ADBVERS{
          int INITIALIZE(void) = 1; 
          int INSERT(agenda_contact) = 2; 
          int REMOVE(string) = 3;
          void LIST(void) = 4;
          agenda_contact SEARCH(string) = 5;
    } = 1; /* Program version */
} = 0x30090950;
