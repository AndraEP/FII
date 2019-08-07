package bananas;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

abstract class Project
{
    protected String name;
    protected LocalDate deadline;
    public String getName()
    {
        return name;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public LocalDate getDeadline()
    {
        return deadline;
    }
    public void setDeadline(LocalDate deadline)
    {
        this.deadline = deadline;
    }
    public String toString()
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.LL.yyyy");
        return "(Name: " + name + ", Deadline: " + deadline.format(formatter) + ", ";
    }
    public boolean equals (Object obj)
    {
        if (obj == null) return false;
        if (!(obj instanceof Project)) return false;
        Project prj = (Project) obj;
        if (!(name.equals(prj.name))) return false;
        if (!(deadline.equals(prj.deadline))) return false;
        return true;
    }
}
