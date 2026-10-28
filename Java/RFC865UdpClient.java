import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class RFC865UdpClient{
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try{
            socket = new DatagramSocket(17);
        } catch(SocketException e){
            System.err.println("Socket Error: "+e.getMessage());
        }

        try {
            byte[] outbuffer = "Joshua, SCEC, 10.96.181.236".getBytes();
            InetAddress serverAddress = InetAddress.getByName("10.96.181.236");
            DatagramPacket request = new DatagramPacket(outbuffer, outbuffer.length, serverAddress, 17);
            socket.send(request);

            byte[] inbuffer = new byte[1024];
            DatagramPacket reply = new DatagramPacket(inbuffer, inbuffer.length);
            socket.receive(reply);
            String quote = new String(reply.getData(), 0, reply.getLength());
            System.out.print(quote);
            
        } catch(IOException e){
            System.err.println("Error" + e.getMessage());
        }
    }
}
//Joshua
//SCEC
//10.96.181.236