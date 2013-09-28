/*
  消息队列例子，输入参数为服务器的IP地质、端口号。
*/

  import org.zeromq.ZMQ;

  class ZmqStormExample
  {
    public static void main (String [] args)
    {
      if (args.length != 2) {
        System.out.println ("usage: ZmqStormExample <DC-Storm> <serverip> " +
          "<serverport>");
        return;
      }

      ZmqStormClient client = new ZmqStormClient(args[0], args[1]);

      while(true)
      {
          byte[] msg= client.receive(); // 阻塞获取新消息
          System.out.println (new String(msg));
      }
    }
  }
