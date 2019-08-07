package app;


import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.text.DateFormatSymbols;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Currency;
import java.util.Locale;
import java.util.Properties;
import java.util.Scanner;

public class LocaleExplorer {
    Properties commands = new Properties();
    public void run() throws ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException, IOException {
        commands.load(this.getClass().getClassLoader().getResourceAsStream("Commands.properties"));
        LocaleContext.setLocale("en-US");
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print(LocaleContext.message("prompt"));
            String command = scanner.nextLine();
            if (command.equals("exit")) break;
            String[] params = command.trim().split("\\s+");
            switch (params[0]) {
                case "locales" : {
                    Class clazz = Class.forName(commands.getProperty("display-locale.impl"));
                    clazz.getConstructor().newInstance();
                    break;
                }
                case "set" : {
                    Class clazz = Class.forName(commands.getProperty("set-locale.impl"));
                    clazz.getConstructor(String.class).newInstance(params[1]);
                    break;
                }
                case "info" : {
                    Class clazz = Class.forName(commands.getProperty("info-locale.impl"));
                    clazz.getConstructor().newInstance();
                    break;
                }
                default : System.out.println(LocaleContext.message("invalid"));

            }
        }
    }


    public static void main(String args[]) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException, IOException {
        new LocaleExplorer().run();
    }
}