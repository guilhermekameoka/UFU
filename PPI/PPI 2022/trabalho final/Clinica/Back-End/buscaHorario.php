<?php
require "../sql/conexaoMysql.php";

$pdo = mysqlConnect();

$dataAgenda = $_GET['data'] ?? '';
$codigo = $_GET['codigo'] ?? '';

$sql = <<<SQL
    SELECT horario
    FROM agenda_Trab
    WHERE dataAgenda = ? and codigo_medico = ? 
    SQL;

try {
    $horariosMarcados = [];
    $disponiveis = [];
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$dataAgenda, $codigo]);


    while ($row = $stmt->fetch()) {
        $horariosMarcados[] = $row['horario'];
    }

    foreach (array(8, 9, 10, 11, 12, 13, 14, 15, 16, 17) as $horario) {
        if (!in_array($horario, $horariosMarcados)) //se nao tiver um horario ja marcado, add o horario no array dos disponiveis
            $disponiveis[] = $horario;
    }

    echo json_encode($disponiveis);
}

catch (Exception $e) {
    exit('Falha inesperada: ' . $e->getMessage());
}
?>
