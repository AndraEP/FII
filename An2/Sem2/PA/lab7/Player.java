public class Player implements Runnable
{
    private final int THINKING_TIME = 500;
    private String name;
    private Game game;
    private Graph graph;

    public Player(String name)
    {
        this.name = name;
    }

    private boolean play() throws InterruptedException
    {
        Board board = game.getBoard();
        if (graph == null) graph = new Graph(board.graph.nodes);
        if (board.isEmpty() || game.isEnded()) {
            return false;
        }
        graph.add(board.extract());
        Thread.sleep(THINKING_TIME);
        if (graph.isSpanningTree()) {
            game.setWinner(this);
        }
        return true;
    }

    public void run()
    {
        try {
            while(this.play())
            {
                System.out.println(this);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void setGame(Game g)
    {
        game = g;
    }

    public String toString()
    {
        return this.name;
    }
}