package bananas;

import java.time.LocalTime;

public class Church extends Node implements Visitable {
    Church(String name) {
        super (name);
    }

    public void setOpeningHour (LocalTime openingHour) {
        this.openingHour = openingHour;
    }

    public void setClosingHour (LocalTime closingHour) {
        this.closingHour = closingHour;
    }

    public LocalTime getOpeningHour () {
        return openingHour;
    }

    public LocalTime getClosingHour () {
        return closingHour;
    }
}
