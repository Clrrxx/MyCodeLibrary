import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;


public class RFC865TcpServer {
    public static void main(String[] args) {
        ServerSocket parentSocket = null;
        try{
            parentSocket = new ServerSocket(8017);
            
        } catch (IOException e){
            System.err.println("Socket Error " + e.getMessage());
            return;
        }

        while(true){
            try{
                Socket childsocket = parentSocket.accept();
                
                ClientHandler client = new ClientHandler(childsocket);
                Thread thread = new Thread(client);
                thread.start();

            } catch (IOException e){
                System.err.println("Error "+ e.getMessage());
            }
        }
    }
}

class ClientHandler implements Runnable{
    private Socket socket;

    ClientHandler(Socket socket){
        this.socket = socket;
    }
    public void run(){
        try{
            OutputStream os = socket.getOutputStream();
            String quote = "This is the string.";
            os.write(quote.getBytes());
            os.flush();
        } catch (Exception e){
            System.err.println("Error" + e.getMessage());
        } finally{
            try{
                socket.close();
            } catch(IOException e){}
        }
    }
}
