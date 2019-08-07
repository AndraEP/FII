import javax.swing.*;

public class ControlPanel extends JPanel {
    private final CatalogFrame frame;

    JButton loadButton = new JButton("Load");
    JButton saveButton = new JButton("Save");

    public ControlPanel(CatalogFrame frame) {
        this.frame = frame;
        init();
    }
    private void init() {
        add(saveButton);
        add(loadButton);

        loadButton.addActionListener(e -> {JOptionPane.showMessageDialog(frame, "Loaded successfully."); frame.catalog.load("catalog.dat"); frame.setCatalog(frame.catalog);});
        saveButton.addActionListener(e -> {JOptionPane.showMessageDialog(frame, "Saved successfully."); frame.catalog.save("catalog.dat");});
    }
}