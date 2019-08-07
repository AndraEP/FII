import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class SocialNetworkServer
{
    private int PORT = 8100;
    private ServerSocket serverSocket;
    private Boolean running = false;
    private List<ClientThread> clients;

    public SocialNetworkServer() {
        this.clients = new ArrayList<>();
    }

    public void init() throws IOException {
        if (!this.running){
            serverSocket=new ServerSocket(PORT);
            this.running = true;
            System.out.println("Server started!");
        }
    }

    public void stop() throws IOException {
        if(this.running) {
            this.running = false;
            serverSocket.close();
        }
    }

    public void waitForClients() throws IOException {
        while(this.running) {
            Socket socket=serverSocket.accept();
            System.out.println("A client has connected");
            ClientThread c = new ClientThread(socket);
            c.start();
            clients.add(c);
        }
    }


}