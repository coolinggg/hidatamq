/*

*/

#include "ZmqStormClient.h"

int main (int argc, char *argv [])
{
    ZmqStormClient *stormClient;

    if (argc != 3) {
        printf ("usage: ZmqStormExample <ip> <port>\n");
        return 1;
    }

    stormClient = initZmq(argv[1], argv[2]);
    if (!stormClient) {
        printf ("error in zmq_socket: %s\n", zmq_strerror (errno));
        return 1;
    }

    while(true)
    {
        char * msg = receivemsg(stormClient);
        printf("%s", msg);
    }
    return 0;
}