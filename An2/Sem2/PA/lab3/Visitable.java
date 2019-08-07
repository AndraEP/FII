package bananas;

import java.time.LocalTime;

interface Visitable {
    LocalTime getOpeningHour ();
    LocalTime getClosingHour ();

    void setOpeningHour (LocalTime openingHour);
    void setClosingHour (LocalTime closingHour);
}
