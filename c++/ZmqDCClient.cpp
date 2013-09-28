/*

*/

#include "ZmqDCClient.h"

ZmqDCClient * initZmq(const char *serverip, const char *serverport)
{
    ZmqDCClient * zmqClient = new ZmqDCClient();
    zmqClient->ctx = zmq_init (1);
    if (!zmqClient->ctx) {
        printf ("error in zmq_init: %s\n", zmq_strerror (errno));
        return NULL;
    }

    zmqClient->s = zmq_socket (zmqClient->ctx, ZMQ_PUSH);
    if (!zmqClient->s) {
        printf ("error in zmq_socket: %s\n", zmq_strerror (errno));
        return NULL;
    }
    char *serveraddr = (char *)malloc(10+strlen(serverip)+strlen(serverport)); 
    memcpy (serveraddr, "tcp://", 6);
    memcpy (serveraddr+6,                    serverip,      strlen(serverip));
    memcpy (serveraddr+6+strlen(serverip),                    ":",        1);
    memcpy (serveraddr+6+1+strlen(serverip), serverport,    strlen(serverport)+1);

    printf("dc connect to %s\n", serveraddr);
    int rc = zmq_connect (zmqClient->s, serveraddr);
    if (rc != 0) {
        printf ("error in zmq_connect: %s\n", zmq_strerror (errno));
        return NULL;
    }
    return zmqClient;
}
void sendmsg(ZmqDCClient * client, const char * sendmsg)
{
    zmq_msg_t msg;
    int rc = zmq_msg_init_size (&msg, strlen(sendmsg)+1);
    if (rc != 0) {
        printf ("error in zmq_msg_init_size: %s\n", zmq_strerror (errno));
        return;
    }
    memcpy (zmq_msg_data (&msg), sendmsg, strlen(sendmsg)+1);

    rc = zmq_sendmsg (client->s, &msg, 0);
    if (rc < 0) {
        printf ("error in zmq_sendmsg: %s\n", zmq_strerror (errno));
        return;
    }
}

