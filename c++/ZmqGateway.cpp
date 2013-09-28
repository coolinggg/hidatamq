/*

*/

#include "zmq.h"
#include "zmq_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv [])
{
    void *ctx;
    int rc;

    const char *frontendaddr;
    const char *backendaddr;

    void *frontend;
    void *backend;

    if (argc != 3) {
        printf ("usage: geateway <front-end> <back-end> \n");
        return 1;
    }
    frontendaddr = argv [1];
    backendaddr = argv[2];

    ctx = zmq_init (1);
    if (!ctx) {
        printf ("error in zmq_init: %s\n", zmq_strerror (errno));
        return -1;
    }

    frontend = zmq_socket (ctx, ZMQ_PULL);
    if (!frontend) {
        printf ("error in zmq_socket: %s\n", zmq_strerror (errno));
        return -1;
    }


    backend = zmq_socket (ctx, ZMQ_PUSH);
    if (!backend) {
        printf ("error in zmq_socket: %s\n", zmq_strerror (errno));
        return -1;
    }

    rc = zmq_bind (frontend, frontendaddr);
    if (rc != 0) {
        printf ("error in zmq_bind: %s\n", zmq_strerror (errno));
        return -1;
    }

    rc = zmq_bind (backend, backendaddr);
    if (rc != 0) {
        printf ("error in zmq_bind: %s\n", zmq_strerror (errno));
        return -1;
    }

    zmq_device(ZMQ_STREAMER,frontend,backend);

    rc = zmq_close (frontend);
    if (rc != 0) {
        printf ("error in zmq_close: %s\n", zmq_strerror (errno));
        return -1;
    }
    rc = zmq_close (backend);
    if (rc != 0) {
        printf ("error in zmq_close: %s\n", zmq_strerror (errno));
        return -1;
    }
    rc = zmq_term (ctx);
    if (rc != 0) {
        printf ("error in zmq_term: %s\n", zmq_strerror (errno));
        return -1;
    }

    return 0;
}
