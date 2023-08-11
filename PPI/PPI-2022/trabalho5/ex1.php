<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercício 1</title>
</head>

<body>

    <?php

    $nome = $POST["CEP"];
    $nome = $POST["Logadouro"];
    $nome = $POST["Bairro"];
    $nome = $POST["Cidade"];
    $nome = $POST["Estado"];

    echo <<<HTML
    <table>
        <tr>
            <td> $CEP </td>
            <td> $Logadouro </td>
            <td> $Bairro </td>
            <td> $Cidade </td>
            <td> $Estado </td>
        </tr>
    </table>

    HTML;
    ?>

</body>

</html>