<?php

    require "../sql/conexaoMysql.php";
    $pdo = mysqlConnect();

    $nome = $_POST["nome"] ?? "";
    $sexo  = $_POST["sexo"] ?? "";
    $email = $_POST["email"] ?? "";
    $telefone = $_POST["telefone"] ?? "";

    $cep = isset($_POST["cep"]) ? $_POST["cep"]: "";
    $logradouro = isset($_POST["logradouro"]) ? $_POST["logradouro"]: "";
    $cidade = isset($_POST["cidade"]) ? $_POST["cidade"] : "";
    $estado = isset($_POST["estado"]) ? $_POST["estado"] : "";

    $peso = $_POST["peso"] ?? "";
    $altura = $_POST["altura"] ?? "";
    $tipoSanguineo = $_POST["sangue"] ?? "";



    $sql1 = <<<SQL
        INSERT INTO pessoa_Trab (nome, sexo, email, telefone, cep, logradouro, cidade, estado)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?)
    SQL;

    $sql2 = <<<SQL
        INSERT INTO paciente_Trab (peso, altura, tipoSanguineo, codigo)
        VALUES (?, ?, ?, ?)
    SQL;

try {
    $pdo->beginTransaction();

    $stmt1 = $pdo->prepare($sql1);
    if (!$stmt1->execute([$nome, $sexo, $email, $telefone, $cep, $logradouro, $cidade, $estado])){
        throw new Exception('Falha na primeira inserção');
    }

    $codigoPessoa = $pdo->lastInsertId();
    $stmt2 = $pdo->prepare($sql2);

    if (!$stmt2->execute([$peso, $altura, $tipoSanguineo, $codigoPessoa])){
        throw new Exception('Falha na segunda inserção');

    }

    $pdo->commit();

    header("location: ../Front-End/AcessoRestrito/homeUsuario.php");
    exit();
} 
catch (Exception $e) {
    $pdo->rollBack();
    if ($e->errorInfo[1] === 1062)
        exit('Dados duplicados: ' . $e->getMessage());
    else
        exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}