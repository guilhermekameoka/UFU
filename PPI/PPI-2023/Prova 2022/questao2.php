<?php

    require "conexaoMysql.php";
    $pdo = mysqlConnect();

    try {

        $sql = <<<SQL
        SELECT nome_dep, relacao, data_nascimento, nome_seg, cpf, email, premio
        FROM dependente, segurado
        WHERE segurado.id = dependente.id_segurado
        SQL;

        $stmt = $pdo->query($sql);
    } 
    catch (Exception $e) {
        exit('Ocorreu uma falha: ' . $e->getMessage());
    }
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dados</title>
</head>
<body>
    <h3>Dados Cadastrados</h3>
    <table>
      <tr>
        <th>Nome Dependente</th>
        <th>Relacao</th>
        <th>Data Nascimento</th>
        <th>Nome Segurado</th>
        <th>CPF</th>
        <th>Email</th>
        <th>Premio</th>
      </tr>

      <?php
      while ($row = $stmt->fetch()) {

        $nome_dep = htmlspecialchars($row['nome_dep']);
        $relacao = htmlspecialchars($row['relacao']);
        $data_nascimento = htmlspecialchars($row['data_nascimento']);
        $nome_seg = htmlspecialchars($row['nome_seg']);
        $cpf = htmlspecialchars($row['cpf']);
        $email = htmlspecialchars($row['email']);
        $premio = htmlspecialchars($row['premio']);

        echo <<<HTML
          <tr>
            <td>$nome_dep</td>
            <td>$relacao</td>
            <td>$data_nascimento</td>
            <td>$nome_seg</td>
            <td>$cpf</td>
            <td>$email</td>
            <td>$premio</td>
          </tr>      
        HTML;

      }
      ?>
    </table>
</body>
</html>