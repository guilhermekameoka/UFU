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
    <title>Home Page</title>
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
    <main class="mainCards">
        <table>
            <tr>
                <td>
                    <div class="card">
                        <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102181422010508/anuncio1.webp" alt="Produto 1">
                        <h2>Pendrive 16gb</h2>
                        <h2 class="preco">R$ 150</h2>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Porro labore aut quos
                            asperiores.
                            Minima dolor a ipsa explicabo, deleniti magnam iusto praesentium id quam, facilis natus
                            nisi
                            nostrum labore consequuntur!</p>
                    </div>
                </td>
                <td>
                    <div class="card">
                        <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102181854036108/anuncio2.jpg" alt="Produto 2">
                        <h2>Monitor 27 polegadas</h2>
                        <h2 class="preco">R$ 2.500</h2>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Numquam consequuntur eos aut
                            accusantium doloribus cumque modi fugit quaerat, voluptatum neque et harum cupiditate
                            soluta, illo eum animi iste eligendi dolorem?</p>
                    </div>
                </td>
                <td>
                    <div class="card">
                        <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102182139232306/anuncio3.jpg" alt="Produto 3">
                        <h2>Mouse Óptico modelo S</h2>
                        <h2 class="preco">R$ 200</h2>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Quae aut necessitatibus
                            laboriosam
                            libero soluta nemo perferendis aliquid, rerum facere enim, nisi obcaecati cum inventore
                            ratione temporibus? Doloribus aliquid accusamus odio?</p>
                    </div>
                </td>
            </tr>
            <tr>
                <td>
                    <div class="card">
                        <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102182365741096/anuncio4.jpg" alt="Produto 4">
                        <h2>Teclado sem fio</h2>
                        <h2 class="preco">R$ 100</h2>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Assumenda officia vero cumque
                            quas
                            dicta blanditiis ut ea consectetur dignissimos, nam aperiam ab! Numquam ratione
                            molestias,
                            reprehenderit a facere vitae facilis.</p>
                    </div>
                </td>
                <td>
                    <div class="card">
                        <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102180805447780/anuncio5.jpg" alt="Produto 5">
                        <h2>Webcam FullHD 60FPS</h2>
                        <h2 class="preco">R$ 450</h2>
                        <p>Lorem, ipsum dolor sit amet consectetur adipisicing elit. Et nostrum doloribus expedita
                            laboriosam aspernatur! Error soluta molestias, commodi harum autem, facilis accusantium
                            porro, minus a laudantium esse itaque. Dignissimos, nostrum.</p>
                    </div>
                </td>
                <td>
                    <div class="card">
                        <img src="https://cdn.discordapp.com/attachments/976517774874640424/1099102228364677241/anuncio6.webp" alt="Produto 6">
                        <h2>Notebook 15 polegadas</h2>
                        <h2 class="preco">R$ 3.500</h2>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Consequatur, at minima! Fuga
                            distinctio aliquam ipsum sunt? Excepturi, officiis quasi minima maxime possimus,
                            veritatis
                            deserunt quos illo aut non suscipit nihil..</p>
                    </div>
                </td>
            </tr>
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