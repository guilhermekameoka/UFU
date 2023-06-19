<?php
require "conexaoMysql.php";
require "verificaSessao.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();

?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../../css/style.css">
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
    <script src="../../js/validaCadastroAnuncio.js"></script>
    <script src="../../js/buscaEndereco.js"></script>
    <title>Página de Cadastro</title>
</head>

<body>
    <header>
        <table>
            <tr>
                <td>
                    <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102265895292948/logo.png"
                        width="100" height="100">
                </td>
                <td>
                    <h1>BomNegócio.com</h1>
                </td>
                <td>
                    <nav class="menu">
                        <ul>
                            <li class="navbar"><a href="home.php">Home</a></li>
                            <li class="navbar"><a href="listaAnuncios.php">Seus anúncios</a></li>
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

    <main class="mainCadastroAnuncio">
        <h1 class="h1Formulario">Cadastro de anúncio</h1>
        <form id="formCadastroAnuncio" action="../../php/cadastroAnuncioBD.php" method="post">

            <div class="campoFormulario">
                <label class="labelFormulario" for="titulo">Titulo:</label>
                <input class="inputFormulario" type="text" name="titulo" id="titulo">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="titulo">Foto:</label>
                <input class="inputFormulario" type="file" name="foto" id="foto" accept="images/*">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="descricao">Descrição:</label>
                <textarea class="labelFormulario" name="descricao" id="descricao" rows="4" cols="45"
                    placeholder="Descreva seu produto"></textarea>
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="preco">Preço:</label>
                <input class="inputFormulario" type="text" name="preco" id="preco">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="datahora">Data e Hora:</label>
                <input class="inputFormulario" type="datetime-local" name="datahora" id="datahora">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="cep">CEP:</label>
                <input class="inputFormulario" type="text" name="cep" id="cep" pattern="\d{5}\-\d{3}\"
                    placeholder="xxxxx-xxx">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="bairro">Bairro:</label>
                <input class="inputFormulario" type="text" name="bairro" id="bairro">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="cidade">Cidade:</label>
                <input class="inputFormulario" type="text" name="cidade" id="cidade">
                <span></span>
            </div>

            <div class="campoFormulario">
                <label class="labelFormulario" for="estado">Estado:</label>
                <input class="inputFormulario" type="text" name="estado" id="estado">
                <span></span>
            </div>
            <button class="botaoFormulario">Cadastrar</button>
        </form>
    </main>
    <footer>
        <div>
            <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102266096627852/telefone.png"><a
                href="tel:(00)12345-6789">(00)12345-6789</a>
            <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102265526198433/email.png"><a
                href="mailto:email@bomnegocio.com">email@bomnecogio.com</a>
        </div>
    </footer>
</body>

</html>