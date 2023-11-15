<?php
// conexao com o banco de dados
require "conexao.php";
$pdo = mysqlConnect();

// recebe os dados do formulario de cadastro
$usuario = $_POST["usuario"] ?? "";
$senha = $_POST["senha"] ?? "";

// calcula um hash seguro para senha
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

// Query para inserir os dados na tabela de usuarios
$sql = <<<SQL
  INSERT INTO usuarios (usuario, hash_senha)
  VALUES (?, ?)
  SQL;

try {
    $pdo->beginTransaction();

    // Inserção dos dados na tabela usuarios
    $stmt = $pdo->prepare($sql);
    if (
        !$stmt->execute([
            $usuario,
            $hashsenha
        ])
    )
        throw new Exception('Falha na inserção');

    // Commita a transação
    $pdo->commit();

    // redireciona para a pagina com todos os cadastro registrados
    header("location: ../verificaUsuario.html");
    exit();

} catch (Exception $e) {
    $pdo->rollBack();
    exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
