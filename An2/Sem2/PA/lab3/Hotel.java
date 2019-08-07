package bananas;

public class Hotel extends Node implements Classifiable {
    public void setRank (int rank) {
        this.rank = rank;
    }

    public int getRank () {
        return rank;
    }

    Hotel(String name) {
        super (name);
    }
}