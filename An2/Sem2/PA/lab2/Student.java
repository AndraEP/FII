package bananas;

class Student
{
    private String name;
    private int yearOfStudy;
    private Project[] preferences;
    public String getName()
    {
        return name;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public int getYearOfStudy()
    {
        return yearOfStudy;
    }
    public void setYearOfStudy(int yearOfStudy)
    {
        this.yearOfStudy = yearOfStudy;
    }
    public Student(String name, int yearOfStudy)
    {
        this.name = name;
        this.yearOfStudy = yearOfStudy;
    }
    public Project[] getPreferences()
    {
        return preferences;
    }
    public void setPreferences(Project ... args)
    {
        preferences = new Project[args.length];
        for (int i = 0; i < args.length; ++i)
        {
            boolean ok = true;
            for (int j = 0; j < i; ++j)
            {
                if (preferences[j].equals(args[i]))
                {
                    ok = false;
                    break;
                }
            }
            if (ok == true) preferences[i] = args[i];
            else System.exit(-1);
        }
    }
    public String toString()
    {
        String result = new String("Name: " + name + ", Year of study: " + yearOfStudy);
        if (preferences != null)
        {
            result += ", Preferences: ";
            for (int i = 0; i < preferences.length; ++i)
            {
                result += preferences[i].toString() + ", ";
            }
            result = result.substring(0, result.length() - 2);
        }
        return result;
    }
    public boolean equals (Object obj)
    {
        if (obj == null) return false;
        if (!(obj instanceof Student)) return false;
        Student std = (Student) obj;
        if (!(name.equals(std.name))) return false;
        if (!(yearOfStudy == std.yearOfStudy)) return false;
        return true;
    }
}
