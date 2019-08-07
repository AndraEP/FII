import javax.swing.*;
import java.util.Map;

public class CatalogList extends JList {
    private DefaultListModel model = new DefaultListModel<>();

    public CatalogList() {
        String title = "<html><i><font color='blue'>" +
                "Catalog Graphs" + "</font></i></hmtl>";

        this.setBorder(BorderFactory.createTitledBorder(title));
        this.setModel(model);
    }

    public void addGraph(String item) {
        model.addElement(item);
    }
    public void setCatalog(Catalog catalog){
        model.clear();
        for(Map.Entry<String, Graph> entry : catalog.map.entrySet())
        {
            model.addElement(entry.getKey());
            System.out.println(entry.getKey());
        }
    }
}