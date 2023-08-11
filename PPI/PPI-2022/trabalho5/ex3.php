<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 3</title>
</head>

<body>
    <?php

    $email =  $_POST["email"];
    $senha =  $_POST["senha"];

    function salvaString($string, $arquivo)
    {
        $arq = fopen($arquivo, "w");
        fwrite($arq, $string);
        fclose($arq);
    }

    $senhaHash = password_hash($senha, PASSWORD_DEFAULT);

    salvaString ($email, "email.txt");
    salvaString ($senhaHash, "senhaHash.txt");

    ?>
</body>

</html>