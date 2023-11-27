package com.oracle.tutorial.jdbc;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class MyQueries3 {

  Connection con;
  JDBCUtilities settings;

  public MyQueries3(Connection connArg, JDBCUtilities settingsArg) {
    this.con = connArg;
    this.settings = settingsArg;
  }

  public static void getMyData(Connection con) throws SQLException {
    Statement stmt = null;
    String query2 = "SELECT D.NOME_CLIENTE, SUM(SALDO_DEPOSITO) AS TOTAL_DEP, SUM(VALOR_EMPRESTIMO) AS TOTAL_EMP " +
        "FROM DEPOSITO D, " +
        "EMPRESTIMO E " +
        "WHERE D.NOME_CLIENTE = E.NOME_CLIENTE " +
        "GROUP BY D.NOME_CLIENTE";

    try {
      stmt = con.createStatement();
      ResultSet rs2 = stmt.executeQuery(query2);
      System.out.println("\nClientes que possuem depositos e emprestimos:\n");
      while (rs2.next()) {
        String cliente = rs2.getString("NOME_CLIENTE");
        float deposito = rs2.getFloat("TOTAL_DEP");
        float emprestimo = rs2.getFloat("TOTAL_EMP");
        System.out.printf("Nome: %35s - Depositos: R$ %10.2f - Emprestimos: R$ %12.2f\n", cliente, deposito, emprestimo);
      }
    } catch (SQLException e) {
      JDBCUtilities.printSQLException(e);
    } finally {
      if (stmt != null) {
        stmt.close();
      }
    }
  }

  public static void main(String[] args) {
    JDBCUtilities myJDBCUtilities;
    Connection myConnection = null;
    if (args[0] == null) {
      System.err.println("Properties file not specified at command line");
      return;
    } else {
      try {
        myJDBCUtilities = new JDBCUtilities(args[0]);
      } catch (Exception e) {
        System.err.println("Problem reading properties file " + args[0]);
        e.printStackTrace();
        return;
      }
    }

    try {
      myConnection = myJDBCUtilities.getConnection();

      MyQueries3.getMyData(myConnection);

    } catch (SQLException e) {
      JDBCUtilities.printSQLException(e);
    } finally {
      JDBCUtilities.closeConnection(myConnection);
    }

  }
}
