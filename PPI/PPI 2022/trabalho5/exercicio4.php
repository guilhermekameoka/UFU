<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 4</title>
</head>

<body>
    <div class="table table-stripped table-hover">
        <tr>
            <th>E-mail</th>
            <th>Senha</th>
        </tr>

        <?php

        function carregaString($arquivo)
        {
            $arq = fopen($arquivo, "r");
            $string = fgets($arq);
            fclose($arq);
            return $string;
        }

        $email = htmlspecialchars(carregaString("email.txt"));
        $senha = htmlspecialchars(carregaString("senhaHash.txt"));

        echo <<<HTML
    <table>
        <tr>
            <td> $email  </td>
            <td> $senha </td>
        </tr>
    </table>

    HTML;
    ?>

</body>

</html>