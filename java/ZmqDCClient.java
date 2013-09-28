/*
  Copyright (c) 2007-2010 iMatix Corporation

  This file is part of 0MQ.

  0MQ is free software; you can redistribute it and/or modify it under
  the terms of the Lesser GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  0MQ is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  Lesser GNU General Public License for more details.

  You should have received a copy of the Lesser GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import org.zeromq.ZMQ;


class ZmqDCClient
{
    private String serverip;
    private String serverport;
    private ZMQ.Socket s;
    public ZmqDCClient(String serverip, String serverport)
    {
      this.serverip = serverip;
      this.serverport = serverport;
      ZMQ.Context ctx = ZMQ.context (1);
      s = ctx.socket (ZMQ.PUSH);
      s.connect ("tcp://" + this.serverip + ":" + this.serverport);
    }
    public void send(byte[] data)
    {
      try
      {
        s.send(data, 0);
      }
      catch(Exception e)
      {
        System.out.println ("there some errors.");
      }
    }
}
