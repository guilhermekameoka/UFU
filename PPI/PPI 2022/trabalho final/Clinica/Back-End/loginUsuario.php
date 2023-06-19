<?php
require_once "../sql/conexaoMysql.php";
require_once "../sql/autenticacao.php";
session_start();

class RequestResponse{
    public $success;
    public $destination;
  
    function __construct($success, $destination){
      $this->success = $success;
      $this->destination = $destination;
    }
    
}

$pdo = mysqlConnect();

$email = $_POST['email'] ?? '';
$senha = $_POST['senha'] ?? '';

try {
    $sql = <<<SQL
        SELECT senhaHash
        FROM pessoa_Trab INNER JOIN funcionario_Trab ON pessoa_Trab.codigo = funcionario_Trab.codigo
        WHERE email = ?
        SQL;
    $sqlMedico = <<<SQL
        SELECT m.codigo from pessoa_Trab p inner join medico_Trab m on p.codigo = m.codigo
        where p.email = ?
        SQL;

    $stmt = $pdo->prepare($sql);
    $stmt->execute([$email]);

    $row = $stmt->fetch();
    if (!$row){
        $request = new RequestResponse(false, null);
    }
    else if ($senhaHash = checkPassword($pdo, $email, $senha)) {
        $_SESSION['emailUsuario'] = $email;
        $_SESSION['loginString'] = hash('sha512', $senhaHash . $_SERVER['HTTP_USER_AGENT']);

        $stmtMedico = $pdo->prepare($sqlMedico);
        $stmtMedico->execute([$email]);
        if($rowMedico = $stmtMedico->fetch()){
            $_SESSION['medico'] = $rowMedico['codigo'];
        }
        else{
            $_SESSION['medico'] = -1;
        }
        $request = new RequestResponse(true, 'AcessoRestrito/homeUsuario.php');
    } 
    else{
        $request = new RequestResponse(false, null);
    }
} 
catch (Exception $e) {
    exit('Ocorreu uma falha: ' . $e->getMessage());
}

echo json_encode($request);
            
?>