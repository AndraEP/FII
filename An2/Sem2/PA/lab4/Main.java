package bananas;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    static public void main(String[] args) throws IOException, CustomException
    {
        Catalog catalog = new Catalog("D:\\school\\school-work-private\\II.2\\PA\\Laborator\\lab4\\graphs");
        catalog.add (new Graph("K4", "complete\\k4.tgf", "complete\\view\\k4.png"));
        catalog.add (new Graph("Peterson", "special\\peterson.tgf", "special\\view\\peterson.pdf"));
        //catalog.open("Peterson");
        catalog.save("catalog.dat");
        catalog.load("catalog.dat");
        catalog.list();
        Shell s = new Shell(catalog);
        s.run();
    }
}
