import java.util.StringTokenizer;

public class SaveCommand
{
    public SaveCommand(Catalog c, String input)
    {
        StringTokenizer st = new StringTokenizer(input, " ");
        String command = st.nextToken(); while(command.equals(" ")) command = st.nextToken();
        String name = st.nextToken(); while(name.equals(" ")) name = st.nextToken();
        c.save(name);
    }
}
