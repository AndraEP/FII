package bananas;

public class Edge {
    private Node v1, v2;
    private int cost;

    Edge(Node v1, Node v2, int cost) {
        this.v1 = v1;
        this.v2 = v2;
        this.cost = cost;
    }
}
