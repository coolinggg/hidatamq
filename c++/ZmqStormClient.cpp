/*

*/
#include "ZmqStormClient.h"

ZmqStormClient * initZmq(const char *serverip, const char *serverport)
{
    ZmqStormClient * zmqClient = new ZmqStormClient();
    zmqClient->ctx = zmq_init (1);
    if (!zmqClient->ctx) {
        printf ("error in zmq_init: %s\n", zmq_strerror (errno));
        return NULL;
    }

    zmqClient->s = zmq_socket (zmqClient->ctx, ZMQ_PULL);
    if (!zmqClient->s) {
        printf ("error in zmq_socket: %s\n", zmq_strerror (errno));
        return NULL;
    }
    char *serveraddr = (char *)malloc(10+strlen(serverip)+strlen(serverport)); 
    memcpy (serveraddr, "tcp://", 6);
    memcpy (serveraddr+6,                    serverip,      strlen(serverip));
    memcpy (serveraddr+6+strlen(serverip),      ":",        1);
    memcpy (serveraddr+6+1+strlen(serverip), serverport,    strlen(serverport)+1);

    printf("storm connect to %s\n", serveraddr);
    int rc = zmq_connect (zmqClient->s, serveraddr);
    if (rc != 0) {
        printf ("error in zmq_connect: %s\n", zmq_strerror (errno));
        return NULL;
    }
    return zmqClient;
}
char * receivemsg(ZmqStormClient * client)
{
    zmq_msg_t msg;
    int rc = zmq_msg_init (&msg);
    if (rc != 0) {
        printf ("error in zmq_msg_init_size: %s\n", zmq_strerror (errno));
        return NULL;
    }

    rc = zmq_msg_recv (&msg, client->s, 0);
    if (rc < 0) {
        printf ("error in zmq_recvmsg: %s\n", zmq_strerror (errno));
        return NULL;
    }
    int size = zmq_msg_size (&msg);
    char *returnmsg = (char*)malloc (size + 1);
    memcpy (returnmsg, zmq_msg_data (&msg), size);
    return returnmsg;
}

