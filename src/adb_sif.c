/* rbd_sif.c - SIF for server */

#include <rpc/rpc.h>
#include "adb_server.h"
#include "adb.h" 

int *initialize_1_svc(void *arg, struct svc_req *rqstp) {
    static int retcode;
    retcode = initialize();
    return &retcode;
}

int *insert_1_svc(struct contact *arg, struct svc_req *rqstp) {
    static int retcode;
    retcode = insert_contact(*arg);
    return &retcode;
}

int *remove_1_svc(char **arg, struct svc_req *rqstp) {
    static int retcode;
    retcode = remove_contact(*arg);
    return &retcode;
}

struct contact *search_1_svc(char **arg, struct svc_req *rqstp) {
    static struct contact result;
    result = search_contact(*arg);
    return &result;
}

struct agenda *list_1_svc(void *, struct svc_req *rqstp) {
    static struct agenda result;
    result = list_contacts();
    return &result;
}