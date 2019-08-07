package bananas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Shell {
    private Catalog c;

    public Shell(Catalog c) {
        this.c = c;
    }

    public void run() throws IOException, CustomException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (1 != 0) {
            String input = reader.readLine();
            String command;
            StringTokenizer st = new StringTokenizer(input, " ");
            if (st.hasMoreTokens()) {
                command = st.nextToken();
                if (command.equals("add")) new AddCommand(c, input);
                else if (command.equals("list")) new ListCommand(c);
                else if (command.equals("save")) new SaveCommand(c, input);
                else if (command.equals("load")) new LoadCommand(c, input);
                else if (command.equals("open")) new OpenCommand(c, input);
                else if (command.equals("report")) new ReportCommand(c, input);
                else throw new CustomException("Command not recognized");
            }
        }
    }
}
