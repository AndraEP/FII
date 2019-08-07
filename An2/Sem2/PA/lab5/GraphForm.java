import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GraphForm extends JPanel {

    private final CatalogFrame frame;

    String[] typeList = {"simple", "directed"};
    JComboBox comboType = new JComboBox(typeList);

    JLabel name = new JLabel("Name of graph");
    JLabel type = new JLabel("Graph type");
    JLabel path1 = new JLabel("Definition path");
    JLabel path2 = new JLabel("Image path");
    JLabel vertices = new JLabel("Number of vertices");
    JLabel nodes = new JLabel("Number of nodes");

    JButton addButton = new JButton("Add");
    JButton browseButton1 = new JButton("Browse...");
    JButton browseButton2 = new JButton("Browse...");

    JTextField nameInput = new JTextField(256);
    JTextField definitionPath = new JTextField(256);
    JTextField imagePath = new JTextField(256);

    JSpinner numOfVertices = new JSpinner();
    JSpinner numOfNodes = new JSpinner();

    JFileChooser fileChooser1 = new JFileChooser();
    JFileChooser fileChooser2 = new JFileChooser();

    public GraphForm (CatalogFrame frame) {
        this.frame = frame;
        init();
        this.setLayout(new GridLayout(0 ,1));
    }

    private void init() {
        add(name);
        add(nameInput);

        add(type);
        add(comboType);

        add(path1);
        add(definitionPath);
        add(browseButton1);

        add(path2);
        add(imagePath);
        add(browseButton2);

        add(vertices);
        add(numOfVertices);

        add(nodes);
        add(numOfNodes);

        add(addButton);
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addGraph();
                JOptionPane.showMessageDialog(frame, "Added successfully.");
            }
        });

        browseButton1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                fileChooser1.showOpenDialog(frame);
                definitionPath.setText(fileChooser1.getSelectedFile().getAbsolutePath());
            }
        });

        browseButton2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                fileChooser2.showOpenDialog(frame);
                imagePath.setText(fileChooser2.getSelectedFile().getAbsolutePath());
            }
        });

        frame.getRootPane().setDefaultButton(addButton);
    }

    private void addGraph () {
        StringBuilder addedList = new StringBuilder();

        addedList.append(nameInput.getText()).append(" ")
                .append(comboType.getSelectedObjects()[0]).append(" ")
                .append(definitionPath.getText()).append(" ")
                .append(imagePath.getText()).append(" ")
                .append(numOfVertices.getValue()).append(" ")
                .append(numOfNodes.getValue());

        Graph g = new Graph(nameInput.getText(), "", definitionPath.getText(), imagePath.getText());
        frame.catalog.add(g);
        frame.addGraph(g);
    }
}