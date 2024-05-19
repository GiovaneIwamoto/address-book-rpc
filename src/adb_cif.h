#include <rpc/rpc.h> 
#include "adb.h"

CLIENT *handle; /* Client handle */

int initialize();

int insert_contact(struct contact *);

int remove_contact(char *);

struct contact search_contact(char *name);

struct agenda list_contacts();

void cli_error();
