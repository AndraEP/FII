package bananas;

public class Restaurant extends Node implements Classifiable {
    Restaurant(String name) {
        super (name);
    }

    public void setRank (int rank) {
        this.rank = rank;
    }

    public int getRank () {
        return rank;
    }
}
