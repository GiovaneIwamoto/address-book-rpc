#include <rpc/rpc.h> 
#include "adb.h"

CLIENT *clnt;

int initialize();
int insert_contact(struct contact *);
int remove_contact(char *);
struct contact search_contact(char *);

