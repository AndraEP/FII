package bananas;

import java.util.StringTokenizer;

public class OpenCommand
{
    public OpenCommand(Catalog c, String input)
    {
        StringTokenizer st = new StringTokenizer(input, " ");
        String command = st.nextToken(); while(command.equals(" ")) command = st.nextToken();
        String name = st.nextToken(); while(name.equals(" ")) name = st.nextToken();
        c.open(name);
    }
}
