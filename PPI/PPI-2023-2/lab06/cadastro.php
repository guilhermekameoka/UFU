<?php
// conexao com o banco de dados
require "conexao.php";
$pdo = mysqlConnect();

// Resgata os dados do formulário
$usuario = $_POST["usuario"] ?? "";
$senha = $_POST["senha"] ?? "";

// calcula um hash de senha seguro para armazenar no BD
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

// insere na tabela usuarios os dados do novo usuário (nome de usário e hash de senha).
$sql = <<<SQL
  INSERT INTO usuarios (usuario, hash_senha)
  VALUES (?, ?)
  SQL;

try {
    $pdo->beginTransaction();

    // Inserção na tabela usuarios
    $stmt = $pdo->prepare($sql);
    if (
        !$stmt->execute([
            $usuario,
            $hashsenha
        ])
    )
        throw new Exception('Falha na primeira inserção');

    // Efetiva as operações
    $pdo->commit();
    
    // redireciona para a pagina com todos os cadastro registrados
    header("location: mostraCadastro.php");
    exit();
    
} catch (Exception $e) {
    $pdo->rollBack();
    exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}