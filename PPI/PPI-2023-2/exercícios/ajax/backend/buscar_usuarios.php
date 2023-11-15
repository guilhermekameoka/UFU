<?php
// configuração lado do servidor (CORS)
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: GET, POST, OPTIONS');
header('Access-Control-Allow-Headers: Content-Type');
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