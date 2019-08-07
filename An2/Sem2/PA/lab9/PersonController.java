import java.sql.*;

public class PersonController
{
    public void create(String name) throws ClassNotFoundException, SQLException
    {
        try
        {
            Connection connection = Database.getConnection();
            String count = "select count(*) from persons";
            Statement statement = connection.createStatement();
            ResultSet resultCount = statement.executeQuery(count);
            String sql="insert into persons values(?,?)";
            PreparedStatement preparedStatement=connection.prepareStatement(sql);
            resultCount.next();
            preparedStatement.setObject(1, resultCount.getInt(1) + 1);
            preparedStatement.setObject(2, name);
            preparedStatement.executeUpdate();
        } catch(Exception e)
        {
            e.getMessage();
        }
    }

    public Integer findByName(String name) throws ClassNotFoundException, SQLException
    {
        try
        {
            Connection connection = Database.getConnection();
            String sql = "select id from persons where name like ?";
            PreparedStatement preparedStatement = connection.prepareStatement(sql);
            preparedStatement.setString(1, "%" + name + "%");
            ResultSet result = preparedStatement.executeQuery();
            result.next();
            return result.getInt(1);
        } catch(Exception e)
        {
            e.getMessage();
        }
        return null;
    }

    public String findByID(Integer id)
    {
        try
        {
            Connection connection = Database.getConnection();
            String sql = "select name from persons where id=?";
            PreparedStatement preparedStatement = connection.prepareStatement(sql);
            preparedStatement.setObject(1, id);
            ResultSet result = preparedStatement.executeQuery();
            result.next();
            return (String)result.getObject("name");
        } catch(Exception e)
        {
            e.getMessage();
        }
        return null;
    }
}