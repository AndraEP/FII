import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

abstract class Person {
    protected int id;
    protected String name;
    protected String job;

    abstract int getId();

    abstract void setId(int id);

    abstract String getName();

    abstract void setName(String name);

    abstract String getJob();

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("ID: ").append(this.id).append(" Nume: ").append(this.name).append(" Job: ").append(this.job);
        return sb.toString();
    }

}
