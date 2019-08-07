import java.util.StringTokenizer;

public class AddCommand
{
    public AddCommand(Catalog c, String input)
    {
        StringTokenizer st = new StringTokenizer(input, "\",");
        String command = st.nextToken(); while(command.equals(" ")) command = st.nextToken();
        String name = st.nextToken(); while(name.equals(" ")) name = st.nextToken();
        String description = st.nextToken(); while(description.equals(" ")) description = st.nextToken();
        String descriptionPath = st.nextToken(); while(descriptionPath.equals(" ")) descriptionPath = st.nextToken();
        String definitionPath = st.nextToken(); while(definitionPath.equals(" ")) definitionPath = st.nextToken();
        c.add(new Graph(name, description, descriptionPath, definitionPath));
    }
}
