<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

// Resgata os dados do cliente
$nome = $_POST["nome"] ?? "";
$cpf  = $_POST["cpf"] ?? "";
$email = $_POST["email"] ?? "";
$senha = $_POST["senha"] ?? "";

// Resgata os dados do endereço de entrega
$cep = $_POST["cep"] ?? "";
$endereco = $_POST["endereco"] ?? "";
$bairro = $_POST["bairro"] ?? "";
$cidade = $_POST["cidade"] ?? "";
$estado = $_POST["estado"] ?? "";

// calcula um hash de senha seguro para armazenar no BD
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

$sql1 = <<<SQL
  INSERT INTO cliente (codigo_cliente, nome, cpf, email, hash_senha)
  VALUES (?, ?, ?, ?, ?)
  SQL;

$sql2 = <<<SQL
  INSERT INTO clienteEndereco
    (cep, endereco, bairro, cidade, estado, codigo_cliente)
  VALUES (?, ?, ?, ?, ?, ?)
  SQL;

try {
  $pdo->beginTransaction();

  // Inserção na tabela cliente
  // Neste caso utilize prepared statements para prevenir
  // ataques do tipo SQL Injection, pois estamos
  // inseririndo dados fornecidos pelo usuário
  $stmt1 = $pdo->prepare($sql1);
  if (!$stmt1->execute([
    $nome, $cpf, $email, $hashsenha
  ])) throw new Exception('Falha na primeira inserção');

  // Inserção na tabela endereco_cliente
  // Precisamos do id do cliente cadastrado, que
  // foi gerado automaticamente pelo MySQL
  // na operação acima (campo auto_increment), para
  // prover valor para o campo do tipo chave estrangeira
  $idNovoCliente = $pdo->lastInsertId();
  $stmt2 = $pdo->prepare($sql2);
  if (!$stmt2->execute([
    $cep, $endereco, $bairro, $cidade, $estado, $idNovoCliente
  ])) throw new Exception('Falha na segunda inserção');

  // Efetiva as operações
  $pdo->commit();

  header("location: mostraCadastro.php");
  exit();
} 
catch (Exception $e) {
  $pdo->rollBack();
    exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
