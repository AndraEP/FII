package bananas;

import java.util.ArrayList;

public class TravelMap {
    ArrayList <Node> nodes = new ArrayList <Node> ();
    ArrayList <Edge> edges = new ArrayList <Edge> ();

    void addNode (Node node) {
        nodes.add(node);
    }

    void addEdge (Node v1, Node v2, int cost) {
        edges.add (new Edge (v1, v2, cost));
        edges.add (new Edge (v2, v1, cost));
    }

    void addEdge (Node v1, Node v2, int cost, boolean twoway) {
        edges.add (new Edge (v1, v2, cost));
        if (twoway)
            edges.add (new Edge (v2, v1, cost));
    }

    String getNodes () {
        StringBuilder result = new StringBuilder();

        /*Arrays.sort (nodes, (Object o1, Object o2) -> {
            Node p1 = (Node) o1;
            Node p2 = (Node) o2;

            return p1.getName().compareTo(p2.getName());
        });*/

        nodes.sort((Object o1, Object o2) ->
        {
            Node p1 = (Node) o1;
            Node p2 = (Node) o2;
            return p1.getName().compareTo(p2.getName());
        });

        for (Node node : nodes) {
            result.append(node.getName());
            result.append("\n");
        }

        return result.toString();
    }
}
