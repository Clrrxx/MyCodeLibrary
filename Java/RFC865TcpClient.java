import java.net.*;
import java.io.*;

/**
 * Name: YourName
 * Group: YourLabGroup
 * IP Address: YourClientIPAddress
 *
 * RFC 865 Quote of the Day (QOTD) - TCP Client
 *
 * Usage: java Rfc865TcpClient <server-host> [server-port]
 *   server-port defaults to 17 (the well-known QOTD port).
 */
public class RFC865TcpClient {

    public static void main(String[] argv) {
        Socket socket = null;
        String serverHost = "192.168.1.140";
        int port = 17;
        try{
            socket = new Socket(serverHost, port);
            System.out.println("Connected");
        }catch(IOException e){
            System.err.println("Socket error: ");
        }
            OutputStream os = socket.getOutputStream();
            os.flush();

            InputStream is = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(is));

            StringBuilder quote = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                quote.append(line).append(System.lineSeparator());
            }
            System.out.println(quote.toString().trim());
        }catch (UnknownHostException e) {
            System.err.println("Unknown host: " + serverHost);
        } catch (IOException e) {
            System.err.println("I/O error: " + e.getMessage());
        } finally {
            if (socket != null) {
                try {
                    socket.close();
                } catch (IOException e){}
            }
        }
    }
}