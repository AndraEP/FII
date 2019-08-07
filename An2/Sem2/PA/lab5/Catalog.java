import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

public class Catalog implements Serializable
{
    private String path;
    protected HashMap<String, Graph> map;
    private transient CatalogIO io;
    private transient MyChecker checker;
    public Catalog(String path)
    {
        this.path = path;
        this.io = new CatalogIO(path);
        this.map = new HashMap<>();
        this.checker = new MyChecker(path);
    }
    public void add(Graph g)
    {
        try
        {
            checker.checkGraph(g);
            this.map.put(g.toString(), g);
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    public void open(String name)
    {
        this.io.open(map.get(name).getDefinitionPath());
    }
    public void save(String name)
    {
        io.save(this, path + "/" + name);
    }
    public void load(String name)
    {
        io.load(this, path + "/" + name);
    }
    public void list()
    {
        for(Map.Entry<String, Graph> entry : map.entrySet())
        {
            System.out.println(entry.getKey());
        }
    }
    public HashMap<String, Graph> getMap()
    {
        return map;
    }
    public String getPath()
    {
        return path;
    }
}
