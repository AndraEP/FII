import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class SocialNetworkServer
{
    private final int PORT = 8100;
    private ServerSocket serverSocket;
    public static List<String> listOfUsers = new ArrayList<String>();
    private List<String> listOfMessages = new ArrayList<String>();
    private int[][] matrix = new int[101][101];

    public SocialNetworkServer() throws IOException
    {
        serverSocket = new ServerSocket(PORT);
        serverSocket.setSoTimeout(15000);
        while (true)
        {
            Socket socket = serverSocket.accept();
            System.out.println("A client has connected");
            new ClientThread(socket, this).start();
        }
    }

    public void addUser(String user)
    {
        listOfUsers.add(user);
        listOfMessages.add("");
    }

    public void addMessage(String from, String message)
    {
        int index = listOfUsers.indexOf(from);
        for(int j = 0; j < listOfUsers.size(); j++)
            if(matrix[index][j] == 1) {
                listOfMessages.add(j, listOfMessages.get(j) + message + "\n");
            }
    }

    public void addFriendship(String user1, String user2)
    {
        int index1 = listOfUsers.indexOf(user1);
        int index2 = listOfUsers.indexOf(user2);
        matrix[index1][index2] = 1;
        matrix[index2][index1] = 1;
    }

    public String readMessage(String name)
    {
        return listOfMessages.get(listOfUsers.indexOf(name));
    }

    public void printNetwork()
    {
        for (int i = 0; i < listOfUsers.size(); i++) {
            System.out.println(listOfUsers.get(i));
        }

        System.out.println();

        for (int i = 0; i < listOfUsers.size(); i++)
        {
            for (int j = 0; j < listOfUsers.size(); j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        for (int i = 0; i < listOfUsers.size(); i++) {
            System.out.println(listOfMessages.get(i));
        }
    }

    public boolean findInList(String name)
    {
        for(String user : listOfUsers) {
            if (user.equals(name)) {
                return true;
            }
        }
        return false;

    }

    public List<String> getUsers()
    {
        return listOfUsers;
    }

    public List<String> getMessages()
    {
        return listOfMessages;
    }

    public int[][] getMatrix()
    {
        return matrix;
    }

    public static void main(String[] args) throws IOException
    {
        try {
            new SocialNetworkServer();
        } catch(Exception e)
        {
            e.getMessage();
        }
    }
}