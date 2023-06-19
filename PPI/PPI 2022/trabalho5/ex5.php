<?php
    function carregaString($arquivo)
    {
        $arq = fopen($arquivo, "r");
        $string = fgets($arq);
        fclose($arq);
        return $string;
    }

    $email_bd = carregaString("email.txt");
    $senha_bd = carregaString("senhaHash.txt");

    $senha = $_POST["senha"] ?? "";
    $email = $_POST["email"] ?? "";

    if (password_verify($senha, $senha_bd) && $email_bd == $email) {
        header ("Location: sucesso.html");
        exit();
    } else {
        header("Location: exercicio5.html");
        exit();
    }
?>