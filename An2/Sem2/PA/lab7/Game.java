import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Game
{
    private Board board;
    private final List<Player> players = new ArrayList<>();
    private String winner = null;
    private static ExecutorService executors = Executors.newFixedThreadPool(8);

    public void addPlayer(Player player)
    {
        players.add(player);
        player.setGame(this);
    }
    public void setBoard(Board b)
    {
        board = b;
    }
    public Board getBoard()
    {
        return board;
    }
    public synchronized void setWinner(Player p) {
        if (winner == null) {
            winner = p.toString();
        }
    }
    public void start() throws InterruptedException  {
        for(Player p : players) {
            executors.execute(p);
        }
        executors.shutdown();
        while (!executors.isTerminated()) {
            Thread.sleep(100);
        }
        System.out.println("Winner is " + winner);
    }

    public boolean isEnded()
    {
        return winner != null;
    }

}