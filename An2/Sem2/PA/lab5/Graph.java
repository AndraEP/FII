import java.io.Serializable;

public class Graph implements Serializable
{
    private String name;
    private String description;
    private String descriptionPath;
    private String definitionPath;
    public Graph(String name, String descriptionPath, String definitionPath)
    {
        this.name = name;
        this.descriptionPath = descriptionPath;
        this.definitionPath = definitionPath;
    }
    public Graph(String name, String description, String descriptionPath, String definitionPath)
    {
        this.name = name;
        this.description = description;
        this.descriptionPath = descriptionPath;
        this.definitionPath = definitionPath;
    }
    public String getName()
    {
        return name;
    }
    public String getDescriptionPath()
    {
        return descriptionPath;
    }
    public String getDefinitionPath()
    {
        return definitionPath;
    }
    public String toString()
    {
        return this.getName();
    }
}
