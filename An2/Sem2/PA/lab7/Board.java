public class Board
{
    Integer nodes;
    public Graph graph;

    public Board(int nodes)
    {
        this.nodes = nodes;
        graph = new Graph(nodes);
        graph.CreateCompleteGraph();
    }

    public synchronized Edge extract()
    {
        Edge edge = graph.pollFirst();
        return edge;
    }

    public boolean isEmpty()
    {
        if(graph.empty()) {
            return true;
        }
        return false;
    }
}