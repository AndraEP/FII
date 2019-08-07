import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Graph
{
    int nodes;
    private List<Edge> edges = new ArrayList<>();

    public Graph(int nodes)
    {
        this.nodes = nodes;
    }

    public void CreateCompleteGraph()
    {
        for(int i = 1; i < nodes ; ++i) {
            for (int j = i + 1; j <= nodes; ++j) {
                edges.add(new Edge(i, j));
            }
        }
        Collections.shuffle(edges);
    }

    public Edge pollFirst()
    {
        Edge e = edges.get(0);
        edges.remove(e);
        return e;
}

    public boolean empty()
    {
        if(edges.isEmpty())
            return true;
        return false;
    }

    public boolean isSpanningTree()
    {
        int n = nodes;
        int[] freqVector = new int[n+1];
        for(int i = 1; i <= n; ++i) {
            freqVector[i] = 0;
        }
        for(Edge e: edges) {
            freqVector[e.A]=1;
            freqVector[e.B]=1;
        }
        for (int i = 1; i <= n; ++i) {
            if (freqVector[i] == 0) {
                return false;
            }
        }
        return true;
    }
    public void add(Edge e)
    {
        edges.add(e);
    }
}