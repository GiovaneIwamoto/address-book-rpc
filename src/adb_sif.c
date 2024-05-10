/* rbd_sif.c - SIF for server */

#include <rpc/rpc.h>
#include "adb_server.h"
#include "adb.h" 

int *initialize_1_svc(void *arg, struct svc_req *rqstp) {
    static int result;
    result = initialize();
    return &result;
}

int *insert_1_svc(struct contact *arg, struct svc_req *rqstp) {
    static int result;
    result = insert_contact(*arg);
    return &result;
}

int *remove_1_svc(char **arg, struct svc_req *rqstp) {
    static int result;
    result = remove_contact(*arg);
    return &result;
}

struct contact *search_1_svc(char **arg, struct svc_req *rqstp) {
    static struct contact result;
    result = search_contact(*arg);
    return &result;
}