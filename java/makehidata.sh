#!/bin/sh
rm mqhidata.jar  ZmqStormClient.class ZmqStormExample.class ZmqDCClient.class ZmqDCExample.class

javac -classpath "../zmq/zmq.jar:." ZmqStormClient.java ZmqStormExample.java ZmqDCClient.java ZmqDCExample.java

jar cf mqhidata.jar  ZmqStormClient.class ZmqStormExample.class ZmqDCClient.class ZmqDCExample.class

