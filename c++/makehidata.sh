#!/bin/sh

g++ -g -Wall -fPIC -I../zmq/include -shared -c ZmqDCClient.cpp  -o ZmqDCClient.o
g++ -g -Wall -fPIC -I../zmq/include -shared -c ZmqDCExample.cpp -o ZmqDCExample.o
cc -L../zmq/lib -g -lstdc++ -lzmq -o ZmqDCExample ZmqDCClient.o ZmqDCExample.o

g++ -g -Wall -fPIC -I../zmq/include -shared -c ZmqStormClient.cpp  -o ZmqStormClient.o
g++ -g -Wall -fPIC -I../zmq/include -shared -c ZmqStormExample.cpp -o ZmqStormExample.o
cc -L../zmq/lib -g -lstdc++ -lzmq -o ZmqStormExample ZmqStormClient.o ZmqStormExample.o

g++ -g -Wall -fPIC -I../zmq/include -shared -c ZmqGateway.cpp -o ZmqGateway.o
cc -L../zmq/lib -g -lstdc++ -lzmq -o ZmqGateway ZmqGateway.o

gcc -shared -fPCI -o libhidatamq.so ZmqDCClient.o ZmqDCExample.o

#