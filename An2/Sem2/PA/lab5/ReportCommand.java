import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class ReportCommand {
    public ReportCommand(Catalog c, String input)
    {
        StringTokenizer st = new StringTokenizer(input, " ");
        String command = st.nextToken(); while(command.equals(" ")) command = st.nextToken();
        String name = st.nextToken(); while(name.equals(" ")) name = st.nextToken();
        if (name.equals("html"))
        {
            ReportHTML(c);
        }
    }
    public void ReportHTML(Catalog c)
    {
        try {
            StringBuilder htmlStringBuilder = new StringBuilder();
            htmlStringBuilder.append("<html><head><title>Catalog</title></head><body>");
            for(Map.Entry<String, Graph> entry : c.getMap().entrySet())
            {
                Graph g = entry.getValue();
                htmlStringBuilder.append("<a href=\"");
                htmlStringBuilder.append(c.getPath() + "/" + g.getDefinitionPath());
                htmlStringBuilder.append("\">");
                htmlStringBuilder.append(g.getName());
                htmlStringBuilder.append("</a><br>");
            }
            htmlStringBuilder.append("</body></html>");
            WriteToFile(htmlStringBuilder.toString(),"testfile.html");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void WriteToFile(String fileContent, String fileName) throws IOException {
        String projectPath = System.getProperty("user.dir");
        String tempFile = projectPath + File.separator + fileName;
        File file = new File(tempFile);
        OutputStream outputStream = new FileOutputStream(file.getAbsoluteFile());
        Writer writer = new OutputStreamWriter(outputStream);
        writer.write(fileContent);
        writer.close();
    }
}
