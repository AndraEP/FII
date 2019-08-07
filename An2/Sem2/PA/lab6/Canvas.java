

package geoshapes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.util.Random;

public class Canvas extends JPanel {

    private BufferedImage image;
    private Graphics2D graphics;

    public Canvas() {
        this.setBorder(BorderFactory.createTitledBorder("Drawing paper:"));
        setDoubleBuffered(false);
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if(graphics != null) {
                    int stroke = Integer.parseInt(DrawingFrame.form.shapesStroke.getText());
                    
                    drawNode(e.getX(), e.getY(), stroke);
                    repaint();
                }
            }
        });
    }

    protected void paintComponent(Graphics g) {
        if(image == null) {
            image = new BufferedImage(470, 230, BufferedImage.TYPE_INT_ARGB);
            graphics = image.createGraphics();
            graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            clear();
        }
        g.drawImage(image, 0, 0, null);
    }

    public void clear() {
        graphics.setPaint(Color.white);
        graphics.fillRect(0, 0, getSize().width, getSize().height);
        graphics.setPaint(Color.black);
        repaint();
    }

    public void drawNode(int x, int y, int stroke) {
        Random rand = new Random();
        graphics.setColor(new Color(rand.nextInt(0xFFFFFF)));

            graphics.fill(new NodeShape(x-(stroke/2),y-(stroke/2),stroke));
    }

    public void drawShapeRandom(int repeatNo) {
        while (repeatNo>0) {
            Random rand = new Random();
            graphics.setColor(new Color(rand.nextInt(0xFFFFFF)));
            int random_x = rand.nextInt(getWidth() - 5);
            int random_y = rand.nextInt(getHeight() - 20);
            int random_circle_radius = rand.nextInt(50-5) + 6;
            
                graphics.fillOval(random_x,random_y,random_circle_radius,random_circle_radius);
            repeatNo--;
        }
    }

    public BufferedImage getImage() {
        return image;
    }

    public void setImage(BufferedImage image) {
        this.image = image;
        graphics = image.createGraphics();
        graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
    }

}
