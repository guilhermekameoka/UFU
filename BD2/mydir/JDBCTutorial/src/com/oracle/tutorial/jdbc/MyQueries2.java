package com.oracle.tutorial.jdbc;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class MyQueries2 {

  Connection con;
  JDBCUtilities settings;

  public MyQueries2(Connection connArg, JDBCUtilities settingsArg) {
    this.con = connArg;
    this.settings = settingsArg;
  }

  public static void getMyData(Connection con) throws SQLException {
    Statement stmt = null;
    // String query =
    // "SELECT COFFEES.COF_NAME FROM COFFEES, SUPPLIERS WHERE SUPPLIERS.SUP_NAME
    // LIKE '" +
    // supplierName + "' and SUPPLIERS.SUP_ID = COFFEES.SUP_ID";
    String query = "SELECT DISTINCT NOME_CLIENTE, SUM(SALDO_DEPOSITO) AS TOTAL_DEP " +
        "FROM DEPOSITO " +
        "WHERE NOME_CLIENTE NOT IN (SELECT DISTINCT NOME_CLIENTE FROM EMPRESTIMO) " +
        "GROUP BY NOME_CLIENTE";
    try {
      stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery(query);
      System.out.println("\nClientes que possuem apenas depositos:\n");
      while (rs.next()) {
        // String coffeeName = rs.getString(1);
        // System.out.println(" " + coffeeName);
        String cliente = rs.getString("NOME_CLIENTE");
        float soma = rs.getFloat("TOTAL_DEP");
        System.out.printf("Nome: %35s - Depositos: R$ %6.2f\n", cliente, soma);
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
    if (args.length == 0) {
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

      MyQueries2.getMyData(myConnection);

    } catch (SQLException e) {
      JDBCUtilities.printSQLException(e);
    } finally {
      JDBCUtilities.closeConnection(myConnection);
    }

  }
}