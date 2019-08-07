
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;
public class SocialNetworkClient
{
    private int PORT=8100;
    private String SERVER_ADDRESS="127.0.0.1";
    private Socket socket;

    public SocialNetworkClient() throws UnknownHostException, IOException
    {
        try
        {
            Socket socket = new Socket(SERVER_ADDRESS, PORT);
            Scanner scanner = new Scanner(System.in);
            OutputStreamWriter output = new OutputStreamWriter(socket.getOutputStream());
            BufferedWriter out = new BufferedWriter(output);

            String text;
            while(!(text=scanner.nextLine()).equals("exit"))
            {
                out.write(text + "\n");
                out.flush();

                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String msg;
                msg=in.readLine();
                System.out.println(msg);
            }

        }catch(Exception e)
        {

        }
    }

    public static void main(String[] args) throws UnknownHostException, IOException
    {
        new SocialNetworkClient();
    }
}