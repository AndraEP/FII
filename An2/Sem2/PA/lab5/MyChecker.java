import java.io.File;

public class MyChecker
{
    private String path;
    public MyChecker(String path)
    {
        this.path = path;
    }
    public void checkGraph(Graph g) throws InvalidFileFormatException, InvalidPathException
    {
        this.checkPath(g.getDescriptionPath());
        this.checkPath(g.getDefinitionPath());
        this.checkDescriptionExtension(g.getDescriptionPath());
        this.checkDefinitionExtension(g.getDefinitionPath());
    }
    public void checkDescriptionExtension(String path) throws InvalidFileFormatException
    {
        if (!path.endsWith(".tgf"))
        {
            throw new InvalidFileFormatException(getFileExtension(path));
        }
    }
    public void checkDefinitionExtension(String path) throws InvalidFileFormatException
    {
        if(!(path.endsWith(".png") || path.endsWith(".pdf")))
        {
            throw new InvalidFileFormatException(getFileExtension(path));
        }
    }
    public void checkPath(String path) throws InvalidPathException
    {
        File file = new File(path);
        if (!file.isFile())
        {
            file = new File(this.path + "\\" + path);
            if(!file.isFile())
            {
                throw new InvalidPathException(path);
            }
        }
    }
    private static String getFileExtension(String fileName)
    {
        if(fileName.lastIndexOf(".") != -1 && fileName.lastIndexOf(".") != 0)
        {
            return fileName.substring(fileName.lastIndexOf(".") + 1);
        }
        else return "";
    }
}
