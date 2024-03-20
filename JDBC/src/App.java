import java.sql.*;

public class App {
    
    static final String DB_URL = "jdbc:mysql://localhost:3306/demo";
    static final String USER = "root";
    static final String PASS = "";
    static final String QUERY = "SELECT id, first, last, age FROM Employees";
    
    public static void main(String[] args) throws Exception {
    //    Class.forName("com.mysql.jdbc.Driver");
      // Open a connection
      try(Connection conn = DriverManager.getConnection(DB_URL, "root", "");
         Statement stmt = conn.createStatement();
         ResultSet rs = stmt.executeQuery(QUERY);) {
         // Extract data from result set
         while (rs.next()) {
            // Retrieve by column name
            System.out.print("ID: " + rs.getInt("id"));
            System.out.print(", Age: " + rs.getInt("age"));
            System.out.print(", First: " + rs.getString("first"));
            System.out.println(", Last: " + rs.getString("last"));
         }
      } catch (SQLException e) {
         e.printStackTrace();
      } 
   }
}