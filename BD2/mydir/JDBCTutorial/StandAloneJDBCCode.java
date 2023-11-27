import java.util.Properties; //Objeto genérico que armazena propriedades com usuário e senha
import java.sql.DriverManager; //Objeto que criará a conexão do sistema de banco de dados
import java.sql.Connection; //Objeto que armazenará o objeto de conexão ao banco de dados
import java.sql.Statement; //Objeto para disparar um comando para o SGBD
import java.sql.ResultSet; //Objeto que armazenará as tuplas resultantes de um comando SQL
import java.sql.SQLException; //Objeto para capturar eventos de erro no acesso ao banco de dados

public class StandAloneJDBCCode {
    public static Connection getConnection() {
        Connection con = null;
        String currentUrlString = null;
        Properties connectionProps = new Properties();

        connectionProps.put("user", "guilhermekameoka");
        connectionProps.put("password", "postgres");

        currentUrlString = "jdbc:postgresql://localhost:5432/IB2";

        try {
            con = DriverManager.getConnection(currentUrlString, connectionProps);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return con;

    }

    public static void myquery(Connection con) throws SQLException {
        Statement stmt = null;
        String query = "SELECT DISTINCT NOME_CLIENTE, SUM(SALDO_DEPOSITO) AS TOTAL_DEP " +
                "FROM DEPOSITO " +
                "WHERE NOME_CLIENTE NOT IN (SELECT DISTINCT NOME_CLIENTE FROM EMPRESTIMO) " +
                "GROUP BY NOME_CLIENTE";
        try {
            stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(query);
            System.out.println("\nClientes que possuem apenas depositos:\n");
            while (rs.next()) {
                String cliente = rs.getString("NOME_CLIENTE");
                float soma = rs.getFloat("TOTAL_DEP");
                System.out.printf("     Nome: %35s - Depositos: R$ %6.2f\n", cliente, soma);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (stmt != null) {
                stmt.close();
            }
        }
    }

    public static void closeConnection(Connection con) {
        try {
            System.out.println("Released all database resources.");
            if (con != null) {
                con.close();
                con = null;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("No arguments.");
        }
        Connection myConnection = null;
        try {
            myConnection = StandAloneJDBCCode.getConnection();
            StandAloneJDBCCode.myquery(myConnection);
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            StandAloneJDBCCode.closeConnection(myConnection);
        }
    }

}