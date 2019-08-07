package commands;
import app.LocaleContext;

public class SetLocaleCommand {
    public SetLocaleCommand(String languageTag) {
        LocaleContext.setLocale(languageTag);
    }
}
