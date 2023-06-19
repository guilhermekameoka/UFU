<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

try {

  $sql = <<<SQL
  SELECT endereco, bairro, cidade, estado, nome, email
  FROM cliente INNER JOIN clienteEndereco ON cliente.codigo_cliente = cod_cliente
  SQL;

  $stmt = $pdo->query($sql);
} 
catch (Exception $e) {
  //error_log($e->getMessage(), 3, 'log.php');
  exit('Ocorreu uma falha: ' . $e->getMessage());
}
?>

<!doctype html>
<html lang="pt-BR">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Mostra Cadastro</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">

</head>

<body>

  <div class="container">
    <h3>Entregas Programadas</h3>
    <table class="table table-striped table-hover">
      <tr>
        <th>Endereço</th>
        <th>Bairro</th>
        <th>Cidade</th>
        <th>Estado</th>
        <th>Nome Cliente</th>
        <th>Email</th>
      </tr>

      <?php

      while ($row = $stmt->fetch()) {

        // Limpa os dados produzidos pelo usuário
        // com possibilidade de ataque XSS
        $endereco = htmlspecialchars($row['endereco']);
        $bairro = htmlspecialchars($row['bairro']);
        $cidade = htmlspecialchars($row['cidade']);
        $estado = htmlspecialchars($row['estado']);
        $nome = htmlspecialchars($row['nome']);
        $email = htmlspecialchars($row['email']);

        echo <<<HTML
          <tr>
            <td>$endereco</td>
            <td>$bairro</td>
            <td>$cidade</td>
            <td>$estado</td>
            <td>$nome</td> 
            <td>$email</td>
          </tr>      
        HTML;
      }
      ?>

    </table>
  </div>

</body>

</html>