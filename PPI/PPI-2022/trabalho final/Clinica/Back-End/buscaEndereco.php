<?php
require "../sql/conexaoMysql.php";

class Endereco
{
  public $logradouro;
  public $cidade;
  public $estado;

  function __construct($logradouro, $cidade, $estado)
  {
    $this->logradouro = $logradouro;
    $this->cidade = $cidade;
    $this->estado = $estado;
  }
}

$pdo = mysqlConnect();

$cep = $_GET['cep'] ?? '';

try {
    $sql = <<<SQL
    SELECT logradouro, cidade, estado
    FROM enderecoAjax_Trab WHERE cep = ?
    SQL;

    $stmt = $pdo->prepare($sql);
    $stmt->execute([$cep]);

} 
catch (Exception $e) {
    exit('Ocorreu uma falha: ' . $e->getMessage());
}


if($row = $stmt->fetch()){
  $endereco = new Endereco($row['logradouro'], $row['cidade'], $row['estado']);
}
else{
  $endereco = new Endereco('', '', '');
}

echo json_encode($endereco);

?>