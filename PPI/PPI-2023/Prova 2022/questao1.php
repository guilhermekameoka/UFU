<?php

    require "conexaoMysql.php";
    $pdo = mysqlConnect();

    $nomeSegurado = $_GET["segurado_nome"] ?? "";
    $cpfSegurado  = $_GET["segurado_cpf"] ?? "";
    $emailSegurado = $_GET["segurado_email"] ?? "";
    $premioSegurado = $_GET["segurado_premio"] ?? "";

    $nomeDependente = $_GET["dependente_nome"] ?? "";
    $relacaoDependente = $_GET["dependente_relacao"] ?? "";
    $nascimentoDependente = $_GET["dependente_nascimento"] ?? "";



    $sql1 = <<<SQL
        INSERT INTO segurado (nome_seg, cpf, email, premio)
        VALUES (?, ?, ?, ?)
    SQL;

    $sql2 = <<<SQL
        INSERT INTO dependente (nome_dep, relacao, data_nascimento, id_segurado)
        VALUES (?, ?, ?, ?)
    SQL;

try {
    $pdo->beginTransaction();

    $stmt1 = $pdo->prepare($sql1);
    if (!$stmt1->execute([$nomeSegurado, $cpfSegurado, $emailSegurado, $premioSegurado])){
        throw new Exception('Falha na primeira inserção');
    }

    $idSegurado = $pdo->lastInsertId();
    $stmt2 = $pdo->prepare($sql2);

    if (!$stmt2->execute([$nomeDependente, $relacaoDependente, $nascimentoDependente, $idSegurado])){
        throw new Exception('Falha na segunda inserção');
    }

    $pdo->commit();

    header("location: questao1.html");
    exit();
} 
catch (Exception $e) {
    $pdo->rollBack();
    exit('Falha ao cadastrar' . $e->getMessage());
}