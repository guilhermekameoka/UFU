package com.oracle.tutorial.jdbc;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.sql.DatabaseMetaData;
import java.sql.PreparedStatement;
import java.sql.Date;

public class MyQueries {

    Connection con;
    JDBCUtilities settings;

    public MyQueries(Connection connArg, JDBCUtilities settingsArg) {
        this.con = connArg;
        this.settings = settingsArg;
    }

    public static void populateTable(Connection con) throws SQLException, IOException {
        BufferedReader inputStream = null;
        Scanner scanned_line = null;
        String line;
        String[] value;
        value = new String[7];
        int countv;
        Statement stmt = null;
        String create = "";

        try {
            inputStream = new BufferedReader(
                    new FileReader(
                            "/Users/guilhermekameoka/Desktop/mydir/JDBCTutorial/BD2-15-debito-populate-table.txt"));

            stmt = con.createStatement();
            stmt.executeUpdate("truncate table debito;");

            while ((line = inputStream.readLine()) != null) {
                countv = 0;

                scanned_line = new Scanner(line);

                scanned_line.useDelimiter("\t");

                while (scanned_line.hasNext()) {
                    value[countv++] = scanned_line.next();
                }

                if (scanned_line != null) {
                    scanned_line.close();
                }

                create = "insert into debito (numero_debito, valor_debito,  motivo_debito, data_debito, numero_conta, nome_agencia, nome_cliente) "
                        + "values (" + value[0] + ", " + value[1] + ", " + value[2] + ", '" + value[3] + "', "
                        + value[4] + ", '"
                        + value[5] + "', '" + value[6] + "');";

                System.out.println("Inserindo na tabela: " + value[0]);

                stmt.executeUpdate(create);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.out.println("Falha na leitura do arquivo!");
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Arquivo não encontrado!");
        } catch (SQLException e) {
            JDBCUtilities.printSQLException(e);
        } finally {
            if (stmt != null) {
                stmt.close();
            }
        }
    }

    public static void populateTableBatch(Connection con) throws SQLException {
        Statement stmt = null;
        String create = "";
        con.setAutoCommit(false);

        try {
            stmt = con.createStatement();
            stmt.executeUpdate("TRUNCATE TABLE debito");

            BufferedReader inputStream = new BufferedReader(new FileReader(
                    "/Users/guilhermekameoka/Desktop/mydir/JDBCTutorial/BD2-15-debito-populate-table.txt"));
            String line;

            while ((line = inputStream.readLine()) != null) {
                create = "INSERT INTO debito (numero_debito, valor_debito, motivo_debito, data_debito, numero_conta, nome_agencia, nome_cliente) ";
                create += "VALUES " + line;

                stmt.addBatch(create);
            }

            inputStream.close();

            // int[] updateCounts = stmt.executeBatch();
            con.commit();
        } catch (SQLException e) {
            e.printStackTrace();
            con.rollback();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Falha na leitura do arquivo!");
        } finally {
            if (stmt != null) {
                stmt.close();
            }
            con.setAutoCommit(true);
        }
    }

    public static void getMyData3(Connection con) throws SQLException {
        Statement stmt = null;
        String query = "SELECT * FROM CONTA";
        try {
            stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(query);
            System.out.println("Contas da Instituição Bancária: ");
            while (rs.next()) {
                Integer conta = rs.getInt(1);
                String agencia = rs.getString(2);
                System.out.println(conta.toString() + ", " + agencia);
            }
        } catch (SQLException e) {
            JDBCUtilities.printSQLException(e);
        } finally {
            if (stmt != null) {
                stmt.close();
            }
        }
    }

    public static void getMyData4(Connection con) throws SQLException {
        Statement stmt = null;
        String query = "SELECT nome_cliente, nome_agencia, numero_conta, " +
                "COALESCE(SUM(saldo_deposito), 0) AS total_depositos, " +
                "COALESCE(SUM(valor_emprestimo), 0) AS total_emprestimos " +
                "FROM ( " +
                "SELECT nome_cliente, nome_agencia, numero_conta, saldo_deposito, 0 AS valor_emprestimo " +
                "FROM deposito " +
                "UNION ALL " +
                "SELECT nome_cliente, nome_agencia, numero_conta, 0 AS saldo_deposito, valor_emprestimo " +
                "FROM emprestimo " +
                ") AS aux_query " +
                "GROUP BY nome_cliente, nome_agencia, numero_conta " +
                "ORDER BY nome_cliente";

        try {
            stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(query);
            System.out.println("Clientes e suas somas de depósitos e empréstimos:");
            while (rs.next()) {
                String clienteNome = rs.getString("nome_cliente");
                String agenciaNome = rs.getString("nome_agencia");
                int numeroConta = rs.getInt("numero_conta");
                double totalDepositos = rs.getDouble("total_depositos");
                double totalEmprestimos = rs.getDouble("total_emprestimos");

                System.out.println("Cliente: " + clienteNome);
                System.out.println("Agência: " + agenciaNome);
                System.out.println("Número da Conta: " + numeroConta);
                System.out.println("Total de Depósitos: " + totalDepositos);
                System.out.println("Total de Empréstimos: " + totalEmprestimos);
                System.out.println();
            }
        } catch (SQLException e) {
            JDBCUtilities.printSQLException(e);
        } finally {
            if (stmt != null) {
                stmt.close();
            }
        }
    }

    public static void cursorHoldabilitySupport(Connection conn)
            throws SQLException {
        DatabaseMetaData dbMetaData = conn.getMetaData();
        System.out.println("ResultSet.HOLD_CURSORS_OVER_COMMIT = " +
                ResultSet.HOLD_CURSORS_OVER_COMMIT);
        System.out.println("ResultSet.CLOSE_CURSORS_AT_COMMIT = " +
                ResultSet.CLOSE_CURSORS_AT_COMMIT);
        System.out.println("Default cursor holdability: " +
                dbMetaData.getResultSetHoldability());
        System.out.println("Supports HOLD_CURSORS_OVER_COMMIT? " +
                dbMetaData.supportsResultSetHoldability(
                        ResultSet.HOLD_CURSORS_OVER_COMMIT));
        System.out.println("Supports CLOSE_CURSORS_AT_COMMIT? " +
                dbMetaData.supportsResultSetHoldability(
                        ResultSet.CLOSE_CURSORS_AT_COMMIT));
    }

    public static void supportsResultSetConcurrency(Connection conn) throws SQLException {
        DatabaseMetaData dbMetaData = conn.getMetaData();

        int[] resultSetTypes = { ResultSet.TYPE_FORWARD_ONLY, ResultSet.TYPE_SCROLL_INSENSITIVE,
                ResultSet.TYPE_SCROLL_SENSITIVE };
        int[] concurrencyTypes = { ResultSet.CONCUR_READ_ONLY, ResultSet.CONCUR_UPDATABLE };

        for (int resultSetType : resultSetTypes) {
            for (int concurrencyType : concurrencyTypes) {
                boolean supports = dbMetaData.supportsResultSetConcurrency(resultSetType, concurrencyType);
                System.out.println("ResultSet type: " + resultSetType + ", Concurrency type: " + concurrencyType
                        + ", Supports: " + supports);
            }
        }
    }

    public static void modifyPricesJuros(Connection con) throws SQLException {
        Statement stmt = null;
        try {
            stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_UPDATABLE);
            ResultSet uprs = stmt.executeQuery("SELECT * FROM deposito");
            while (uprs.next()) {
                double saldo_deposito = uprs.getDouble("saldo_deposito");
                double updatedBalance = saldo_deposito * 1.005;
                uprs.updateDouble("saldo_deposito", updatedBalance);
                uprs.updateRow();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (stmt != null) {
                stmt.close();
            }
        }
    }

    public static void modifyPricesJurosTeclado(Connection con) throws SQLException {
        Statement stmt = null;
        try {
            System.out.println("Digite a porcentagem de juros a ser aplicada (Exemplo: 5% = 5.0):");
            Scanner in = new Scanner(System.in);
            double percentage = in.nextDouble();

            stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_UPDATABLE);
            ResultSet uprs = stmt.executeQuery("SELECT * FROM deposito");
            while (uprs.next()) {
                double saldo_deposito = uprs.getDouble("saldo_deposito");
                double updatedBalance = saldo_deposito * (1 + (percentage / 100.0));
                uprs.updateDouble("saldo_deposito", updatedBalance);
                uprs.updateRow();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (stmt != null) {
                stmt.close();
            }
        }
    }

    public static void insertRows(Connection con) throws SQLException {
        String sql = "INSERT INTO debito (numero_debito, valor_debito, motivo_debito, data_debito, numero_conta, nome_agencia, nome_cliente) "
                + "VALUES (?, ?, ?, ?, ?, ?, ?)";

        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // Primeira inserção
            pstmt.setInt(1, 2000);
            pstmt.setDouble(2, 150);
            pstmt.setInt(3, 1);
            pstmt.setDate(4, Date.valueOf("2014-01-23"));
            pstmt.setInt(5, 46248);
            pstmt.setString(6, "UFU");
            pstmt.setString(7, "Carla Soares Sousa");
            pstmt.executeUpdate();

            // Segunda inserção
            pstmt.setInt(1, 2001);
            pstmt.setDouble(2, 200);
            pstmt.setInt(3, 2);
            pstmt.setDate(4, Date.valueOf("2014-01-23"));
            pstmt.setInt(5, 26892);
            pstmt.setString(6, "Glória");
            pstmt.setString(7, "Carolina Soares Souza");
            pstmt.executeUpdate();

            // Terceira inserção
            pstmt.setInt(1, 2002);
            pstmt.setDouble(2, 500);
            pstmt.setInt(3, 3);
            pstmt.setDate(4, Date.valueOf("2014-01-23"));
            pstmt.setInt(5, 70044);
            pstmt.setString(6, "Cidade Jardim");
            pstmt.setString(7, "Eurides Alves da Silva");
            pstmt.executeUpdate();
        } catch (SQLException e) {
            JDBCUtilities.printSQLException(e);
        }
    }

    public static void main(String[] args) throws IOException {
        JDBCUtilities myJDBCUtilities;
        Connection myConnection = null;
        if (args[0] == null) {
            System.err.println("Properties file not specified at the command line");
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
            // MyQueries.populateTable(myConnection);
            // MyQueries.getMyData3(myConnection);
            // MyQueries.getMyData4(myConnection);
            // MyQueries.cursorHoldabilitySupport(myConnection);
            // MyQueries.supportsResultSetConcurrency(myConnection);
            // MyQueries.modifyPricesJuros(myConnection);
            // MyQueries.modifyPricesJurosTeclado(myConnection);
            // MyQueries.populateTableBatch(myConnection);
            MyQueries.insertRows(myConnection);

        } catch (SQLException e) {
            JDBCUtilities.printSQLException(e);
        } finally {
            JDBCUtilities.closeConnection(myConnection);
        }

    }
}
