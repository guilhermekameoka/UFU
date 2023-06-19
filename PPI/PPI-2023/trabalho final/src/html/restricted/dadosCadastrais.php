<?php
require "conexaoMysql.php";
require "verificaSessao.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();

try {
    $sql = <<<SQL
    SELECT nome, cep, email, senha, telefone
    FROM Anunciante
    SQL;

    $stmt = $pdo->query($sql);
} catch (Exception $e) {
    exit('Ocorreu uma falha: ' . $e->getMessage());
}
?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../../css/style.css">
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
    <title>Dados cadastrais</title>
</head>

<body>
    <header>
        <table>
            <tr>
                <td>
                    <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102265895292948/logo.png" width="100" height="100">
                </td>
                <td>
                    <h1>BomNegócio.com</h1>
                </td>
                <td>
                    <nav class="menu">
                        <ul>
                            <li class="navbar"><a href="cadastroAnuncio.php">Listar anúncio</a></li>
                            <li class="navbar"><a href=" ">Mensagens</a></li>
                            <li class="navbar"><a href="dadosCadastrais.php">Dados cadastrais</a></li>
                            <li class="navbar"><a href="logout.php">Logoff</a></li>
                            <li class="busca">
                                <form action="../../php/buscaAnuncio.php" class="search-bar" method="get">
                                    <input type="text" name="busca" placeholder="Pesquisar...">
                                    <button id="busca" alt="buscar"><i class='bx bx-search'></i></button>
                                </form>
                            </li>
                        </ul>
                    </nav>
                </td>
            </tr>
        </table>
    </header>
    <main class="mainCards">
        <h3>Produtos cadastrados</h3>
        <table>
            <tr>
                <th>Nome</th>
                <th>CPF</th>
                <th>E-mail</th>
                <th>Preço</th>
                <th>Senha</th>
                <th>Telefone</th>
            </tr>

            <?php
            while ($row = $stmt->fetch()) {

                // Limpa os dados produzidos pelo usuário
                // com possibilidade de ataque XSS
                // antes de inserí-los na página HTML
                $nome = htmlspecialchars($row['nome']);
                $cpf = htmlspecialchars($row['cpf']);
                $email = htmlspecialchars($row['email']);
                $senha = htmlspecialchars($row['preco']);
                $telefone = htmlspecialchars($row['telefone']);

                echo <<<HTML
                 <tr>
                 <td>$nome</td> 
                 <td>$cpf</td> 
                 <td>$email</td>
                 <td>$senha</td>
                 <td>$telefone</td>
                 </tr>      
                HTML;
            }

            ?>

        </table>
    </main>
    <footer>
        <div>
            <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102266096627852/telefone.png"><a href="tel:(00)12345-6789">(00)12345-6789</a>
            <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102265526198433/email.png"><a href="mailto:email@bomnegocio.com">email@bomnecogio.com</a>
        </div>
    </footer>
</body>

</html>