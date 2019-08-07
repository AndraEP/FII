package bananas;

import java.time.LocalTime;

public class Museum extends Node implements Visitable, Payable {
    Museum(String name) {
        super(name);
    }

    public LocalTime getOpeningHour () {
        return openingHour;
    }

    public LocalTime getClosingHour () {
        return closingHour;
    }

    public double getEntryFee () {
        return entryFee;
    }

    public void setOpeningHour (LocalTime openingHour) {
        this.openingHour = openingHour;
    }

    public void setClosingHour (LocalTime closingHour) {
        this.closingHour = closingHour;
    }

    public void setEntryFee (double entryFee) {
        this.entryFee = entryFee;
    }
}
