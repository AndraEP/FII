public class Edge {
    Node from;
    Node to;
    int stroke;

    public Edge(Node from, Node to, int stroke) {
        this.from = from;
        this.to = to;
        this.stroke = stroke;
    }

    public Node getFrom() {
        return from;
    }

    public Node getTo() {
        return to;
    }

    public int getStroke() {
        return stroke;
    }
}
