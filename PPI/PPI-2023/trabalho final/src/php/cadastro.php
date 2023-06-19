<?php
use PDOException;

require "./conexaoMysql.php";
$pdo = mysqlConnect();

$codigo = $_POST["codigo"] ?? "";
$nome = $_POST["nome"] ?? "";
$cpf = $_POST["cpf"] ?? "";
$email = $_POST["email"] ?? "";
$senha = $_POST["senha"] ?? "";
$telefone = $_POST["telefone"] ?? "";

// calcula um hash de senha seguro para armazenar no BD
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

try {

  $sql = <<<SQL
  -- Repare que a coluna Id foi omitida por ser auto_increment
  INSERT INTO Anunciante (codigo, nome, cpf, email, hashsenha, telefone)
  VALUES (?, ?, ?, ?, ?, ?)
  SQL;

  // Neste caso utilize prepared statements para prevenir
  // ataques do tipo SQL Injection, pois precisamos
  // cadastrar dados fornecidos pelo usuário 
  $stmt = $pdo->prepare($sql);
  $stmt->execute([$codigo, $nome, $cpf, $email, $hashsenha, $telefone]);

  header("location: ../html/public/index.html");
  exit();
} 
catch (PDOException $e) {  
    echo "Código de erro: " . $e->errorInfo[1];
    if ($e->errorInfo[1] === 1062)
      exit('Dados duplicados: ' . $e->getMessage());
    else
      exit('Falha ao cadastrar os dados: ' . $e->getMessage());
  }
