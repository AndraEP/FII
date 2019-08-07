import java.sql.*;

public class Database
{
    private static Connection connection = null;
    private static ConnectionManager connectionManager = new ConnectionManager();

    public Database() { }

    public static Connection getConnection() throws ClassNotFoundException, SQLException
    {
        if(connection == null)
            connection = connectionManager.createConnection();
        return connection;
    }

    public static void closeConnection() throws SQLException
    {
        connection.close();
    }

    public static void rollback() throws SQLException, ClassNotFoundException
    {

        String delPersons = "DELETE FROM persons WHERE id >= 1";
        String delMovies = "DELETE FROM movies WHERE id >= 1";
        Statement statement = getConnection().createStatement();
        statement.executeQuery(delMovies);
        statement.executeQuery(delPersons);
    }
    public static void commit() throws SQLException {
        connection.commit();
    }
}