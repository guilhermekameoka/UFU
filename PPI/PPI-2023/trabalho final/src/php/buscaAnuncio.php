<?php

use PDOException;

require "./conexaoMysql.php";
$pdo = mysqlConnect();

$entrada = $_GET["busca"];
$palavras_chave = explode(' ', $entrada);

$where_clause = "WHERE 1=1";
foreach ($palavras_chave as $palavra) {
    $where_clause .= " AND descricao LIKE '%" . $palavra . "%'";
}

try {
    $consulta_sql = <<<SQL
    SELECT *
    FROM Annuncio
    $where_clause
    SQL;

    $stmt = $pdo->prepare($consulta_sql);
    $stmt->execute();
    $resultados = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo json_encode($resultados);
    
} catch (PDOException $e) {
    echo "Erro na consulta: " . $e->getMessage();
    exit();
}
