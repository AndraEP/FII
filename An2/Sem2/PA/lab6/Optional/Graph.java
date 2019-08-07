import java.util.ArrayList;
import java.util.List;

public class Graph {
    List<Node> nodes;
    List<Edge> edges;

    public Graph() {
        this.nodes = new ArrayList<>();
        this.edges = new ArrayList<>();
    }

    public void addNode(int x, int y, int stroke) {
        this.nodes.add(new Node(x, y, stroke));
    }

    public void addEdge(Node from, Node to, int stroke) {
        this.edges.add(new Edge(from, to, stroke));
    }

    public Node getNodeAt(int x, int y) {
        for (Node node: nodes) {
            double distSq = Math.pow(node.x - x, 2) + Math.pow(node.y - y, 2);

            if (distSq <= Math.pow(node.stroke, 2)) {
                return node;
            }
        }

        return null;
    }

    public List<Node> getNodes() {
        return nodes;
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public void deleteNode(Node node) {
        this.nodes.remove(node);

        List<Edge> edgesToRemove = new ArrayList<>();

        for (Edge edge: edges) {
            if(edge.getTo() == node || edge.getFrom() == node) {
                edgesToRemove.add(edge);
            }
        }

        edges.removeAll(edgesToRemove);
    }
}
