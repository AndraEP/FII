import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {

        SocialNetworkServer server = new SocialNetworkServer();
        try {
            server.init();
            server.waitForClients();
        } catch (IOException e){
            server.stop();
            System.out.println("Exception: " + e);
        }

    }

}
