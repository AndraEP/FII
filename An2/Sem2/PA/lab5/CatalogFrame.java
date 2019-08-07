import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.Map;

public class CatalogFrame extends JFrame{

    ControlPanel control;
    GraphForm form;
    JTable table;
    Catalog catalog;
    DefaultTableModel model;

    CatalogFrame() {
        super("Visual Graph Manager");
        init();
    }
    private void init() {
        setSize(800, 800);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        catalog = new Catalog("D:\\school\\school-work-private\\II.2\\PA\\Laborator\\lab4\\graphs");
        catalog.add (new Graph("K4", "complete\\k4.tgf", "complete\\view\\k4.png"));
        catalog.add (new Graph("Peterson", "special\\peterson.tgf", "special\\view\\peterson.pdf"));
        control = new ControlPanel(this);
        form = new GraphForm(this);
        Object[][] data = {
                {"Kathy", "Smith",
                        "Snowboarding", new Integer(5), new Boolean(false)},
                {"John", "Doe",
                        "Rowing", new Integer(3), new Boolean(true)},
                {"Sue", "Black",
                        "Knitting", new Integer(2), new Boolean(false)},
                {"Jane", "White",
                        "Speed reading", new Integer(20), new Boolean(true)},
                {"Joe", "Brown",
                        "Pool", new Integer(10), new Boolean(false)}
        };
        String[] columnNames = {"First Name",
                "Last Name",
                "Sport",
                "# of Years",
                "Vegetarian"};
        model = new DefaultTableModel();
        table = new JTable(model);
        model.addColumn("Name");
        model.addColumn("DefinitionPath");
        model.addColumn("DescriptionPath");
        add(control, BorderLayout.SOUTH);
        add(form, BorderLayout.NORTH);
        add(table, BorderLayout.CENTER);
    }

    public void setCatalog(Catalog catalog){
        model.setRowCount(0);
        for(Map.Entry<String, Graph> entry : catalog.map.entrySet())
        {
            model.addRow(new Object[]{entry.getValue().getName(), entry.getValue().getDefinitionPath(), entry.getValue().getDescriptionPath()});
        }
    }

    public void addGraph(Graph g) {
        model.addRow(new Object[]{g.getName(), g.getDefinitionPath(), g.getDescriptionPath()});
    }
}