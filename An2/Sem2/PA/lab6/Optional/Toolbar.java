import javax.swing.*;
import java.awt.*;

public class Toolbar extends JPanel {

    JLabel radiusLabel = new JLabel("Radius: ");
    JLabel strokeLabel = new JLabel("Stroke: ");

    JTextField shapesRadius = new JFormattedTextField();
    JTextField shapesStroke = new JFormattedTextField();
    JButton deleteButton = new JButton("Delete");

    public Toolbar(DrawingFrame frame) {
        this.setBorder(BorderFactory.createTitledBorder("Toolbar"));
        init();
        this.setLayout(new GridLayout(2,4, 20, 0));
    }

    private void init() {
       
        shapesRadius.setText("30");
        shapesStroke.setText("1");
        add(radiusLabel);
       
        add(strokeLabel);
        add(deleteButton);
        add(shapesRadius);
        add(shapesStroke);
    }

}
