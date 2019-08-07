package bananas;

import java.util.Arrays;

class Problem
{
    private Student[] students;
    public Student[] getStudents()
    {
        return students;
    }
    public void setStudents(Student ... args)
    {
        students = new Student[args.length];
        for (int i = 0; i < args.length; ++i)
        {
            boolean ok = true;
            for (int j = 0; j < i; ++j)
            {
                if (students[j].equals(args[i]))
                {
                    ok = false;
                    break;
                }
            }
            if (ok == true) students[i] = args[i];
            else System.exit(-1);
        }
    }
    public String toString()
    {
        String result = new String();
        for (int i = 0; i < students.length; ++i)
        {
            result += students[i].toString() + "\n";
        }
        return result;
    }
    public Project[] getProjects()
    {
        Project[] projects = new Project[1000];
        int index = 0;
        for (int i = 0; i < students.length; ++i)
        {
            Project[] prj = students[i].getPreferences();
            for (int j = 0; j < prj.length; ++j)
            {
                boolean ok = true;
                for (int k = 0; k < index; ++k)
                {
                    if (prj[j].equals(projects[k])) ok = false;
                }
                if (ok == true) projects[index++] = prj[j];
            }
        }
        return Arrays.copyOf(projects, index);
    }
}
