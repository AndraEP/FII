import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

class ClientThread extends Thread
{
    private Socket socket;
    private SocialNetworkServer object;
    private String client = null;

    public ClientThread(Socket socket, SocialNetworkServer object) {
        this.socket = socket;
        this.object = object;
    }

    public void run()
    {
        try {
            InputStreamReader input = new InputStreamReader(socket.getInputStream());
            BufferedReader in = new BufferedReader(input);
            String line;
            while ((line = in.readLine()) != null)
            {
                String[] command = line.split(" ");
                if (command[0].equals("register"))
                {
                    if(client == null) {
                        if(object.findInList(command[1]) == false)
                        {
                            object.addUser(command[1]);
                            writeToClient("Registered successfully!");
                        }
                        else {
                            writeToClient("The user is already in the list!");
                        }
                    }
                    else {
                        writeToClient("You may not register people while you are logged in!");
                    }
                }
                else if (command[0].equals("login"))
                {
                    if(client == null)
                    {
                        if(object.findInList(command[1]) == true)
                        {
                            client = command[1];
                            writeToClient("Successfully logged in!");
                        }
                        else {
                            writeToClient("This user is not registered");
                        }
                    }
                    else {
                        writeToClient("You are already logged in. You may not log in again!");
                    }
                }
                else if(command[0].equals("friend"))
                {
                    if(client == null) {
                        writeToClient("You may not add friendships because you are not logged in!");
                    }
                    else
                    {
                        object.addFriendship(client, command[1]);
                        writeToClient("Friendship added!");
                    }
                }
                else if(command[0].equals("message"))
                {
                    if (client == null)
                    {
                        writeToClient("You may not send messages. You are not logged in!");
                    }
                    else
                    {
                        String text = client + ": ";
                        for(int i = 1; i < command.length; ++i) {
                            text = text + " " + command[i];
                        }
                        object.addMessage(client, text);
                        writeToClient("Message added!");
                    }
                }
                else if(command[0].equals("read"))
                {
                    if (client == null)
                    {
                        writeToClient("You may not read your messages. You are not logged in!");
                    }
                    else
                    {
                        writeToClient(object.readMessage(client));
                    }
                }
                else if(command[0].equals("stop"))
                {
                    writeToClient("Exitting...");
                    System.exit(1);
                }
                else
                {
                    writeToClient("Unknown command.");
                    object.printNetwork();
                }
            }
        } catch (Exception e) {
            e.getMessage();
        }
    }

    public void writeToClient(String message)
    {
        try
        {
            PrintWriter out=new PrintWriter(socket.getOutputStream());
            out.println(message);
            out.flush();
        } catch(Exception e)
        {
            e.getMessage();
        }
    }
}