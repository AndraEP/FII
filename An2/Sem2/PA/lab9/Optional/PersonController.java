import java.sql.*;
import java.util.ArrayList;
import java.util.*;

public class PersonController {

    Integer index;

    public void create(String name, String job) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select max(id) from persons group by null")) {
            index = rs.next() ? rs.getInt(1) + 1 : 1;
        }

        try (PreparedStatement pstmt = con.prepareStatement("insert into persons (id, name, job) values (?, ?, ?)")) {
            //pstmt.setInt(1, index);
            pstmt.setInt(1, index);
            pstmt.setString(2, name);
            pstmt.setString(3,job);
            pstmt.executeUpdate();
        }
    }

    public Integer findByName(String name) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select * from persons where name like '%" + name + "%'")) {
            return rs.next() ? rs.getInt(1) : null;
        }
    }
    public String findById(int id) throws SQLException {
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select name from persons where id = '" + id + "'")) {
            return rs.next() ? rs.getString(2) : null;
        }
    }

    public List<Person> findAll() {
        int gotId;
        String gotName, gotJob;
        List<Person> persoane = new ArrayList();
        Connection con = Database.getConnection();
        try (Statement stmt = con.createStatement();
             ResultSet rs = stmt.executeQuery("select id, name, job from persons")) {
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