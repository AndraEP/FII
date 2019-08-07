import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class MovieController {

    Integer index;

    public void create(String name, Integer dir_id) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select max(id) from movies group by null")) {
            index = rs.next() ? rs.getInt(1) + 1 : 1;
        }

        try (PreparedStatement pstmt = con.prepareStatement("insert into movies (id, name, director_id) values (?, ?, ?)")) {
            pstmt.setInt(1, index);
            pstmt.setString(2, name);
            pstmt.setInt (3, dir_id);
            pstmt.executeUpdate();
        }
    }

    public Integer findByName(String name) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select id from movies where name like '" + name + "'")) {
            return rs.next() ? rs.getInt(1) : null;
        }
    }
    public String findById(int id) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select name from movies where id = '" + id + "'")) {
            return rs.next() ? rs.getString(2) : null;
        }
    }

    public List<Movie> findAll() {
        int gotId, gotDirector_id;
        String gotName;
        List<Movie> movies = new ArrayList();
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select id, name, director_id from movies")) {
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