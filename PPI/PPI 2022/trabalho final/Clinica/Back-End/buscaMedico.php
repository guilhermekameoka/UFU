<?php
require "../sql/conexaoMysql.php";

class Medico
{
  public $nome;
  public $cod_medico;
  public $especialidade;

  function __construct($nome, $cod_medico, $especialidade)
  {
    $this->nome = $nome;
    $this->cod_medico = $cod_medico; 
    $this->especialidade = $especialidade;
  }
}

$pdo = mysqlConnect();

$especialidade = $_GET['especialidade'] ?? '';

try {
    $sql = <<<SQL
    SELECT nome, m.codigo as cod, especialidade
    FROM medico_Trab m inner join pessoa_Trab p ON m.codigo = p.codigo WHERE especialidade = ?
    SQL;

    $stmt = $pdo->prepare($sql);
    $stmt->execute([$especialidade]);

} 
catch (Exception $e) {
    exit('Ocorreu uma falha: ' . $e->getMessage());
}

while($row = $stmt->fetch()){
    $medicos[] = new Medico($row['nome'], $row['cod'], $row['especialidade']);
}


echo json_encode($medicos);

?>