<?php
require "conexaoMysql.php";

class Endereco
{
    public $cep;
    public $bairro;
    public $cidade;
    public $estado;

    function __construct($cep, $bairro, $cidade, $estado)
    {
        $this->cep = $cep;
        $this->bairro = $bairro;
        $this->cidade = $cidade;
        $this->estado = $estado;
    }
}

$pdo = mysqlConnect();

$cep = $_GET['cep'] ?? '';

try {
    $sql = <<<SQL
    SELECT cep, bairro, cidade, estado
    FROM Ajax WHERE cep = ?
    SQL;

    $stmt = $pdo->prepare($sql);
    $stmt->execute([$cep]);
    
} catch (Exception $e) {
    exit('Ocorreu uma falha: ' . $e->getMessage());
}

if ($row = $stmt->fetch()) {
    $endereco = new Endereco($row['cep'], $row['bairro'], $row['cidade'], $row['estado']);
} else {
    $endereco = new Endereco('', '', '', '');
}

echo json_encode($endereco);
