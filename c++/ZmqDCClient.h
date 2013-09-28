/*

*/

#include "zmq.h"
#include "zmq_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    void *ctx;
    void *s;
 }ZmqDCClient; 

ZmqDCClient * initZmq(const char *serverip, const char *serverport);
void sendmsg(ZmqDCClient * client, const char * sendmsg);
