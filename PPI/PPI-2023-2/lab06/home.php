<?php
session_start();

// verifica se o usuario está logado
// se nao estiver logado, volta para tela de login
if (!isset($_SESSION["login"]) || $_SESSION["login"] !== "1") {
    header("Location: login.php");
    exit();
}

?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
</head>

<body>
    <!-- mensagem de boas vindas -->
    <h1>Bem-vindo,
        <?php echo htmlspecialchars($_SESSION["usuario"]); ?>!
    </h1>
</body>

</html>