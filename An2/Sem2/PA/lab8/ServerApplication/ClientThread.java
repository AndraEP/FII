import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

class ClientThread extends Thread
{
    private Socket socket;

    public ClientThread(Socket socket) {
        this.socket=socket;
    }

    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
            String request;
            while((request = in.readLine()) != null) {
                String response = this.execute(request);
                PrintWriter out = new PrintWriter(socket.getOutputStream());
                out.println(response);
                out.flush();
            }
            socket.close();
        } catch(Exception e) {
            System.out.println("Exception: " + e);
        }
    }

    public String execute(String request){
        System.out.println("Server received the request: " + request);
        return "ok";
    }
}