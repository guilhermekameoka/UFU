<?php
if (isset($_POST["usuario"]) && isset($_POST["senha"])) {
    require_once "conexao.php";
    $pdo = mysqlConnect();

    $sql = "SELECT usuario, hash_senha FROM usuarios WHERE usuario = ?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_POST["usuario"]]);
    $row = $stmt->fetch(PDO::FETCH_ASSOC);

    if ($row !== false && password_verify($_POST["senha"], $row['hash_senha'])) {
        session_start();
        $_SESSION["login"] = "1";
        $_SESSION["usuario"] = $row['usuario'];
        header("Location: home.php");
    } else {
        echo "Usuário ou senha inválidos";
    }
}
?>