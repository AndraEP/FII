package app;

import java.text.DateFormatSymbols;
import java.text.MessageFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Currency;
import java.util.Locale;
import java.util.ResourceBundle;

public class LocaleContext
{
    private static final String baseName = "Messages";
    private static Locale locale;
    private static ResourceBundle resourceBundle;

    public static String message(String key, String ... arguments) {
        String pattern = resourceBundle.getString(key);
        String message = new MessageFormat(pattern).format(arguments);
        return message;
    }
    public static void setLocale(String languageTag) {
        LocaleContext.locale = Locale.forLanguageTag(languageTag);
        LocaleContext.resourceBundle = ResourceBundle.getBundle(baseName, locale);
        message("locale.set", languageTag);
    }

    public static void displayLocales() {
        System.out.println(LocaleContext.message("locales"));
        for (Locale locale : Locale.getAvailableLocales())
        {
            System.out.println(locale.toString());
        }
    }
    public static void localeInfo() {
        System.out.println(LocaleContext.message("locale.set",LocaleContext.getLocale().getDisplayName()));
        Currency currency  = Currency.getInstance(LocaleContext.getLocale());
        DateFormatSymbols fo = DateFormatSymbols.getInstance(LocaleContext.getLocale());
        System.out.println(LocaleContext.getLocale().getCountry());
        System.out.println(LocaleContext.getLocale().getLanguage());
        System.out.println(currency.getCurrencyCode());
        for (String s : fo.getWeekdays()) {
            System.out.print(s + " ");
        }
        System.out.println();
        for (String s : fo.getMonths()) {
            System.out.print(s + " ");
        }
        System.out.println();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd MMM yyyy", LocaleContext.getLocale());
        LocalDateTime now = LocalDateTime.now();
        System.out.println(dtf.format(now));
    }

    public static Locale getLocale()
    {
        return LocaleContext.locale;
    }
}
