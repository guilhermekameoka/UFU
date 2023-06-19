<?php
require "../sql/conexaoMysql.php";

$pdo = mysqlConnect();

try {
    $sql = <<<SQL
    SELECT especialidade
        FROM medico_Trab
            GROUP BY especialidade;
    SQL;

    $stmt = $pdo->query($sql);
    
} 
catch (Exception $e) {
    exit('Ocorreu uma falha: ' . $e->getMessage());
}

while($row = $stmt->fetch()){
    $especialidades[] = $row['especialidade'];
}


echo json_encode($especialidades);

?>