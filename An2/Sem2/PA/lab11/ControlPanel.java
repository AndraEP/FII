import javax.swing.*;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class ControlPanel extends JPanel {
    private final MainFrame frame;
    private final JLabel classNameLabel = new JLabel("Class name");
    private final JTextField classNameField = new JTextField(30);
    private final JLabel textLabel = new JLabel("Default text");
    private final JTextField textField = new JTextField(10);
    private final JButton createButton = new JButton("Add component");
    public ControlPanel(MainFrame frame) {
        this.frame = frame;
        init();
    }
    private void init() {
        add(classNameLabel); add(classNameField); add(textLabel); add(textField); add(createButton);
        createButton.addActionListener(e -> {
            JComponent comp = createDynamicComponent(classNameField.getText());
            if (comp != null) {
                setComponentText(comp, textField.getText());
                frame.designPanel.addAtRandomLocation(comp);
            }
        });

    }
    private JComponent createDynamicComponent(String className) {
        //implement this method
        try {
            Class myclass = Class.forName(className);
            return (JComponent) myclass.newInstance();
        } catch (IllegalAccessException | InstantiationException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }

    private void setComponentText(JComponent comp, String text) {
        //implement this method
        Class myclass = comp.getClass();
        Method a = null;
        try {
            a = myclass.getMethod("setText", String.class);
            a.invoke(comp, text);
        } catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}