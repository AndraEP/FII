package bananas;

import java.time.LocalDate;

class Application extends Project
{
    private Language language;
    public Application(String name, LocalDate deadline, Language language)
    {
        this.name = name;
        this.deadline = deadline;
        this.language = language;
    }
    public Language getLanguage()
    {
        return language;
    }
    public void setLanguage(Language language)
    {
        this.language = language;
    }
    public String toString()
    {
        return super.toString() + "Language: " + language + ")";
    }
    public boolean equals (Object obj)
    {
        if (obj == null) return false;
        if (!(obj instanceof Application)) return false;
        Application app = (Application) obj;
        if (!(super.equals(obj))) return false;
        if (!(language.equals(app.language))) return false;
        return true;
    }
}
