<?php

use PDOException;

require "./conexaoMysql.php";
$pdo = mysqlConnect();

// tabela Anuncio
$titulo = $_POST["titulo"] ?? "";
$descricao = $_POST["descricao"] ?? "";
$preco = $_POST["preco"] ?? "";
$datahora = $_POST["datahora"] ?? "";
$cep = $_POST["cep"] ?? "";
$bairro = $_POST["bairro"] ?? "";
$cidade = $_POST["cidade"] ?? "";
$estado = $_POST["estado"] ?? "";

// tabela Foto
$foto = $_POST["nomearquivo"] ?? "";

$sql1 = <<<SQL
        INSERT INTO Anuncio (titulo, descricao, preco, datahora, cep, bairro, cidade, estado)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?)
        SQL;

$sql2 = <<<SQL
        INSERT INTO Foto (nomearquivo)
        VALUES (?)
        SQL;

// inicio da transação
try {
    $pdo->beginTransaction();
    // Inserção na tabela cliente
    // Neste caso utilize prepared statements para prevenir
    // ataques do tipo SQL Injection, pois estamos
    // inseririndo dados fornecidos pelo usuário
    $stmt1 = $pdo->prepare($sql1);
    if (!$stmt1->execute([$titulo, $descricao, $preco, $datahora, $cep, $bairo, $cidade, $estado]))
        throw new Exception('Falha na primeira inserção');

    // Inserção na tabela endereco_cliente
    // Precisamos do id do cliente cadastrado, que
    // foi gerado automaticamente pelo MySQL
    // na operação acima (campo auto_increment), para
    // prover valor para o campo do tipo chave estrangeira
    $stmt2 = $pdo->prepare($sql2);
    if (!$stmt2->execute([$foto]))
        throw new Exception('Falha na segunda inserção');

    // Efetiva as operações
    $pdo->commit();
    header("location: listaAnuncios.php");
    exit();
    
} catch (PDOException $e) {
    $pdo->rollBack();
    if ($e->errorInfo[1] === 1062)
        exit('Dados duplicados: ' . $e->getMessage());
    else
        exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
