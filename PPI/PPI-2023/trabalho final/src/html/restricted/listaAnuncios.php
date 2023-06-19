<?php
require "./conexaoMysql.php";
$pdo = mysqlConnect();

try {
    $sql = <<<SQL
    SELECT codigo, titulo, descricao, preco, datahora, cep, bairro, cidade, estado
    FROM Anuncio
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
    <title>Lista de Anúncios</title>
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
                            <li class="navbar"><a href="cadastroAnuncio.html">Listar anúncio</a></li>
                            <li class="navbar"><a href="cadastroAnuncio.html">Mensagens</a></li>
                            <li class="navbar"><a href="cadastroAnuncio.html">Dados cadastrais</a></li>
                            <li class="navbar"><a href="../public/home.html">Logoff</a></li>
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
                <th>Código</th>
                <th>Titulo</th>
                <th>Descrição</th>
                <th>Preço</th>
                <th>Data e hora</th>
                <th>CEP</th>
                <th>Bairro</th>
                <th>Cidade</th>
                <th>Estado</th>
            </tr>

            <?php
            while ($row = $stmt->fetch()) {

                // Limpa os dados produzidos pelo usuário
                // com possibilidade de ataque XSS
                // antes de inserí-los na página HTML
                $codigo = htmlspecialchars($row['codigo']);
                $titulo = htmlspecialchars($row['titulo']);
                $descricao = htmlspecialchars($row['descricao']);
                $preco = htmlspecialchars($row['preco']);
                $datahora = htmlspecialchars($row['datahora']);
                $cep = htmlspecialchars($row['cep']);
                $bairro = htmlspecialchars($row['bairro']);
                $cidade = htmlspecialchars($row['cidade']);
                $estado = htmlspecialchars($row['estado']);

                echo <<<HTML
                 <tr>
                 <td>
                    <a href="excluiAnuncio.php?codigo=$codigo">
                    <img src="https://cdn.discordapp.com/attachments/762766437932597278/1116268448549445772/pngwing.com.png" width="20" height="20">
                    </a>
                 </td> 
                 
                 <td>$codigo</td> 
                 <td>$titulo</td> 
                 <td>$descricao</td>
                 <td>$preco</td>
                 <td>$datahora</td>
                 <td>$cep</td>
                 <td>$bairro</td>
                 <td>$cidade</td>
                 <td>$estado</td>
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