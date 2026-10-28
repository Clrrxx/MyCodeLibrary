import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class RFC865UdpServer{
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try{
            socket = new DatagramSocket(17);
        } catch (SocketException e){
            System.err.println("Error Port: "+e.getMessage());
        }

        while (true){
            try{
                byte[] buffer = new byte[1024];

                DatagramPacket request = new DatagramPacket(buffer, buffer.length);
                socket.receive(request);
                InetAddress replyAddress = request.getAddress();
                int replyPort = request.getPort();

                buffer = "Your Quote of the Day is here: ".getBytes();
                DatagramPacket reply = new DatagramPacket(buffer, buffer.length, replyAddress, replyPort);
                socket.send(reply);
                socket.close();
            } catch (IOException e){
                System.err.println("Error."+e.getMessage());
            }
        }
    }
}