<?php
function checkLogin($pdo, $email, $senha)
{
    $sql = <<<SQL
    SELECT hash_senha
    FROM Cliente
    WHERE email = ?
    SQL;

    try {
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$email]);
        $row = $stmt->fetch();
        if (!$row) return false;
        else
            return password_verify($senha, $row['hash_senha']);
    } catch (Exception $e) {
        exit('Falha inesperada: ' . $e->getMessage());
    }
}
$errorMsg = "";
if ($_SERVER["REQUEST_METHOD" == "POST"]) {

    require "conexaoMysql.php";
    $pdo = mysqlConnect();
}

$email = $senha = "";
if (isset($_POST["email"])) $email = $_POST["email"];
if (isset($_POST["senha"])) $senha = $_POST["senha"];


if (checkLogin($pdo, $email, $senha)) {
    header("location: home.html");
    exit();
} else
    $errorMsg = "Dados incorretos";
