import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class Actor extends Person {
    public Actor() {
        this.job = "actor";
    }
    public Actor(int id, String name) {
        this.id = id;
        this.name = name;
        this.job = "actor";
    }

    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getJob() {
        return this.job;
    }

    public List<Movie> getMovies() {
        int gotId, gotDirector_id;
        String gotName;
        List<Movie> movies = new ArrayList();
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select movies.id, movies.name, director_id from movies where movies.id in (select movie_id from movie_actors where actor_id = " + this.id + ")")) {
            while(rs.next()) {
                gotId = rs.getInt(1);
                gotName = rs.getString(2);
                gotDirector_id = rs.getInt(3);
                movies.add(new Movie(gotId, gotName, gotDirector_id));
            }
        }
        catch (java.sql.SQLException e) {
            System.err.println(e);
            Database.rollback();
        }
        return movies;
    }
}