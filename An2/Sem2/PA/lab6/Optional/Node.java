public class Node {
    public int x;
    public int y;
    public int stroke;

    public Node(int x, int y, int stroke) {
        this.x = x;
        this.y = y;
        this.stroke = stroke;
    }

    @Override
    public String toString() {
        return "Node{" +
                "x=" + x +
                ", y=" + y +
                ", stroke=" + stroke +
                '}';
    }
}
