import java.sql.SQLException;

public class Main
{
    public static void main(String[] args) throws ClassNotFoundException, SQLException
    {
        try {
            Database.rollback();
            PersonController person = new PersonController();
            MovieController movie = new MovieController();
            person.create("Francis Ford Coppola");
            person.create("Marlon Brando");
            person.create("Al Pacino");
            Database.commit();
            movie.create("Godfather", person.findByName("Coppola"));
            Database.commit();
            Database.closeConnection();
        }
        catch (SQLException e) {
            System.err.println(e);
            Database.rollback();
        }
    }
}