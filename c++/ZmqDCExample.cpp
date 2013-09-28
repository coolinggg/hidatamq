/*
*/

#include "ZmqDCClient.h"

    
int main (int argc, char *argv [])
{
    ZmqDCClient *dcClient;

    if (argc != 3) {
        printf ("usage: ZmqDCExample <ip> <port>\n");
        return 1;
    }

    dcClient = initZmq(argv[1], argv[2]);
    if (!dcClient) {
        printf ("error in zmq_socket: %s\n", zmq_strerror (errno));
        return 1;
    }

    while(true)
    {
        char input[100];
        fgets(input,100,stdin);
        sendmsg(dcClient, input);
    }

    return 0;
}
