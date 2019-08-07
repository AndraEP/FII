import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class Movie {
    private int id;
    private String name;
    private int director_id;
    public int actori[];
    public int nrOfActors;

    public Movie(int id, String name, int director_id) {
        this.id = id;
        this.name = name;
        this.director_id = director_id;
        nrOfActors = 0;
        actori = new int[100];
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getDirector_id() {
        return director_id;
    }

    public void setDirector_id(int director_id) {
        this.director_id = director_id;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("ID: ").append(this.id).append(" Nume: ").append(this.name).append(" ID Director: ").append(this.director_id);
        return sb.toString();
    }

    public void addActor(Actor actor) {
        Connection con = Database.getConnection();

        try (PreparedStatement pstmt = con.prepareStatement("insert into movie_actors (movie_id, actor_id) values (?, ?)")) {
            pstmt.setInt(1, this.id);
            pstmt.setInt(2, actor.getId());
            pstmt.executeUpdate();
        }
        catch (java.sql.SQLException e) {
        System.err.println(e);
        Database.rollback();
        }
    }

    public List<Person> getActors() {
        int gotId;
        String gotName, gotJob;
        List<Person> persoane = new ArrayList();
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select persons.id, persons.name, job from persons where persons.id in (select actor_id from movie_actors where movie_id = " + this.id + ")")) {
            while(rs.next()) {
                gotId = rs.getInt(1);
                gotName = rs.getString(2);
                gotJob = rs.getString(3);
                if(gotJob.equals("actor")) {
                    persoane.add(new Actor(gotId, gotName));
                }
                else {
                    persoane.add(new Director(gotId, gotName));
                }
            }
        }
        catch (java.sql.SQLException e) {
            System.err.println(e);
            Database.rollback();
        }
        return persoane;
    }
}

