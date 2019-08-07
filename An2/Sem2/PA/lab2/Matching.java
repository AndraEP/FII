package bananas;

public class Matching
{
    Student[] students;
    Project[] projects;

    /**
     * @param students this is a documentation example
     */
    public Matching(Student[] students)
    {
        this.students = new Student[students.length];
        this.projects = new Project[students.length];
        for (int i = 0; i < students.length; ++i)
        {
            this.students[i] = students[i];
            Project[] tmpproj = students[i].getPreferences();
            this.projects[i] = null;
            for (int j = 0; j < tmpproj.length; ++j)
            {
                boolean ok = true;
                for (int k = 0; k < i; ++k)
                {
                    if (tmpproj[j].equals(projects[k])) ok = false;
                }
                if (ok == true)
                {
                    this.projects[i] = tmpproj[j];
                    break;
                }
            }
            if (this.projects[i] == null) System.exit(-1);
        }
    }
}
