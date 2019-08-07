import java.sql.*;

public class ConnectionManager
{
    private static final String URL = "jdbc:oracle:thin:@localhost:1521/XE";
    private static final String user = "student";
    private static final String password = "STUDENT";
    private static final int nrMaxConn = 10;
    private static int nrConn = 0;

    public Connection createConnection() throws SQLException, ClassNotFoundException
    {
        Class.forName("oracle.jdbc.driver.OracleDriver");
        return (++nrConn <= nrMaxConn) ? DriverManager.getConnection(URL, user, password) : null;
    }
}
