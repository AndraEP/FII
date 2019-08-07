import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

public class Canvas extends JPanel {

	private BufferedImage image;
	private Graphics2D graphics;
	public int currentMouseX, currentMouseY;
	int lastX = -1, lastY = -1;

	BufferedImage rabbit;

	Graph graph;

	public Canvas() {
		graph = new Graph();
		setBackground(Color.white);

		this.setBorder(BorderFactory.createTitledBorder("Drawing paper:"));
		setDoubleBuffered(false);
		addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				currentMouseX = e.getX();
				currentMouseY = e.getY();

				if (e.getButton() == MouseEvent.BUTTON3) {
					Node node = graph.getNodeAt(currentMouseX, currentMouseY);

					if(node != null) {
						graph.deleteNode(node);
					}
				}
				else {
					if (graphics != null) {
						int radius = Integer.parseInt(DrawingFrame.form.shapesRadius.getText());
						int stroke = Integer.parseInt(DrawingFrame.form.shapesStroke.getText());

						Node node = graph.getNodeAt(currentMouseX, currentMouseY);

						if(node != null) {
							if (lastX == -1 && lastY == -1) {
								lastX = currentMouseX;
								lastY = currentMouseY;
							} else {
								Node from = graph.getNodeAt(lastX, lastY);
								Node to = graph.getNodeAt(currentMouseX, currentMouseY);

								if(from != null && to != null) {
									graph.addEdge(from, to, stroke);
								}

								lastX = -1;
								lastY = -1;
							}
						} else {
							graph.addNode(currentMouseX, currentMouseY, radius);

							lastX = -1;
							lastY = -1;
						}

					}
				}

				repaint();
			}
		});

	}

	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		image = new BufferedImage(800, 600, BufferedImage.TYPE_INT_ARGB);
		graphics = (Graphics2D)image.getGraphics();
		graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

		for (Node node: graph.getNodes()) {
			drawShapeAt(node.x, node.y, node.stroke);
		}

		for (Edge edge: graph.getEdges()) {
			drawLine(edge.getFrom().x, edge.getFrom().y, edge.getTo().x, edge.getTo().y, edge.getStroke());
		}
		g.drawImage(image, 0, 0, null);
	}

	public void clear() {
		graphics.setPaint(Color.white);
		graphics.fillRect(0, 0, 800, 600);
		graphics.setPaint(Color.black);
		repaint();
	}

	public void drawShapeAt(int x, int y, int radius) {
		graphics.setColor(new Color(122, 0, 122));
		graphics.fillOval(x - (radius / 2), y - (radius / 2), radius, radius);
	}

	public void drawLine(int x1, int y1, int x2, int y2, int stroke) {
		graphics.setStroke(new BasicStroke(stroke));
		graphics.drawLine(x1, y1, x2, y2);
	}


	public BufferedImage getImage() {
		return image;
	}

	public void setImage(BufferedImage image) {
		this.image = image;
		graphics = image.createGraphics();
		graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		graphics.drawImage(image, 0, 0, null);
	}

}
