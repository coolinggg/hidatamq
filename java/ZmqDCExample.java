/*
  消息队列例子，输入参数为服务器的IP地质、端口号。
*/

import org.zeromq.ZMQ;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

  class ZmqDCExample
  {
    public static void main (String [] args)
    {
      if (args.length != 2) {
        System.out.println ("usage: ZmqStormExample <serverip> " +
          "<serverport>");
        return;
      }

      ZmqDCClient client = new ZmqDCClient(args[0], args[1]);

      try{

      while(true)
      {
          BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
          String line = reader.readLine();
          client.send(line.getBytes()); // 发送新消息
      }
    }
    catch(IOException e)
    {
        System.out.println ("io error");
    }
    }
  }
