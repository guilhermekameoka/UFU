<?php
require "conexao.php";
$pdo = mysqlConnect();

try {
    $sql = "SELECT usuario FROM usuarios";
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    $usuarios = $stmt->fetchAll(PDO::FETCH_ASSOC);
    
    header('Content-Type: application/json');
    echo json_encode($usuarios);
} catch (Exception $e) {
    echo json_encode(['error' => 'Falha ao buscar os dados: ' . $e->getMessage()]);
}
?>