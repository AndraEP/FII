import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class SocialNetworkClient {
    private static String SERVER_ADDRESS = "127.0.0.1";
    private static int PORT = 8100;
    Socket socket = null;

    public SocialNetworkClient() throws IOException {
        this.socket = new Socket(SERVER_ADDRESS, PORT);
    }

    private String readFromKeyboard () {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    private void sendRequestToServer(String request) throws IOException {
        OutputStreamWriter output = new OutputStreamWriter(socket.getOutputStream());
        BufferedWriter out = new BufferedWriter(output);
        out.write(request + "\n");
        out.flush();
    }

    private void receiveResponseFromServer() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String rsp = in.readLine();
        if (rsp != null) {
            System.out.println(rsp);
        }
    }

    public static void main(String[] args) throws IOException {
        SocialNetworkClient client = new SocialNetworkClient();
        while (true) {
            String request = client.readFromKeyboard();
            if (request.equalsIgnoreCase("exit")) {
                break;
            } else {
                client.sendRequestToServer(request);
                client.receiveResponseFromServer();
            }
        }
    }
}