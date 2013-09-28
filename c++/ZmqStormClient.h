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
 }ZmqStormClient; 

ZmqStormClient * initZmq(const char *serverip, const char *serverport);
char * receivemsg(ZmqStormClient * client);
