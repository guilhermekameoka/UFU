<?php
    require "../sql/conexaoMysql.php";
    $pdo = mysqlConnect();

    $cep = isset($_POST["cep"]) ? $_POST["cep"]: "";
    $logradouro = isset($_POST["logradouro"]) ? $_POST["logradouro"]: "";
    $cidade = isset($_POST["cidade"]) ? $_POST["cidade"] : "";
    $estado = isset($_POST["estado"]) ? $_POST["estado"] : "";

    try {
        $sql = <<<SQL
        INSERT INTO enderecoAjax_Trab (cep, logradouro, cidade, estado)
        VALUES (?, ?, ?, ?)
        SQL;

        $stmt = $pdo->prepare($sql);
        $stmt->execute([$cep, $logradouro, $cidade, $estado]);
      
        header("location: ../Front-End/index.html");
        exit();
    } 
    catch (Exception $e) {  
      if ($e->errorInfo[1] === 1062)
        exit('Dados duplicados: ' . $e->getMessage());
      else
        exit('Falha ao cadastrar os dados: ' . $e->getMessage());
    }
?>