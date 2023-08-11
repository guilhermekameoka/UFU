<?php

require_once "../../sql/conexaoMysql.php";
require_once "../../sql/autenticacao.php";

session_start();
$pdo = mysqlConnect();
exitWhenNotLogged($pdo);

?>
<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bem-vindo!</title>
    <link rel="stylesheet" href="../../style/style_restrita.css">
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6" crossorigin="anonymous">
    <style>
        main  h1{
            text-align: center;
            padding-bottom: 1vw;
            padding-top: 10px;
        }
    </style>
</head>

<body>
    <div class="container">
    <nav class="navbar navbar-expand-lg navbar-dark fixed-top  ">
            <a class="nav-link active col-1" href="../index.html">
                <img src="../../images/sanctum.png" alt="CLINICA SANCTUM SANCTORUM" height="80">
            </a>
            <button class="navbar-toggler " type="button" data-bs-toggle="collapse"
                data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false"
                aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse justify-content-center" id="navbarSupportedContent">
                <ul class="navbar-nav mr-auto">
                    <li class="nav-item active"><a class="nav-link color-white" href="homeUsuario.php">Home Usuário</a>
                    </li>
                    <li class="nav-item"><a class="nav-link color-white" href="formCadastroFuncionario.php">Cadastro de
                            Funcionário</a>
                    </li>
                    <li class="nav-item"><a class="nav-link color-white" href="formCadastroPaciente.php">Cadastro de
                            Paciente</a></li>
                    <li class="nav-item"><a class="nav-link color-white" href="dados/mostraDadosFuncionario.php">Listar
                            Funcionários</a>
                    </li>
                    <li class="nav-item"><a class="nav-link color-white" href="dados/mostraDadosPaciente.php">Listar
                            Pacientes</a></li>
                    <li class="nav-item"><a class="nav-link color-white" href="dados/mostraDadosEndereco.php">Listar
                            Endereços</a></li>
                    <li class="nav-item"><a class="nav-link color-white" href="dados/mostraDadosConsulta.php">Listar
                            Agendamentos</a>
                    </li>
                    <?php
                        if ($_SESSION['medico'] != -1)
                            echo <<<HTML
                                    <li class="nav-item"><a class="nav-link color-white" href="dados/mostrarMeusAgendamentos.php">Listar Meus Agendamentos</a>
                                    </li>
                                    HTML;
                    ?>
                    <li class="nav-item"><a class="nav-link logout-b" href="../../Back-End/logout.php">Logout</a></li>
                </ul>
            </div>
        </nav>
        <main>
          <div>
          <h1>Bem vindo</h1>
            <h3>Área restrita para funcionários</h3>
            <p>Esta é a área onde os funcionários pussuem acesso a partes restritas do site como cadastrar novos funcionarios e pacientes, além da vizualização de diversas informações como
              consultas agendadas, endereços cadastrados e as informações dos colaboradores. Então, funcionarios, não compartilhem suas senhas.
            </p>
            <h3>Informações</h3>
            <h5>Benefícios para os colaboradores</h5>
            <ul>
              <li><strong>Saúde:</strong> A Sanctum possui descontos especiais para funcionários, com isso queremos ajudar os colaboradores a economizar com problemas de saúde, 
              prevenir futuras doenças, além de impactar positivamente na sua disposição no trabalho e evitar faltas.</li>
              <li><strong>Bem-Estar:</strong> A Sanctum oferece uma folga remunerada a cada seis meses para auxiliar no seu bem-estar. Confira a agenda das folgas no seu departamento e aproveite</li>
              <li><strong>Planos de aposentadoria:</strong> Nós oferecemos a profissionais sêniores outras opções de aposentadoria, o que ajuda a reter os talentos com mais
              experiência, facilitando com o que o conhecimento adquirido seja passado adiante.</li>
            </ul>
            <h5>Eventos</h5>
            <ul>
              <li><strong>Confraternização: </strong>Data: 20/03/2022</li>
              <li><strong>Planejamento de Metas 2022: </strong>Data: 29/03/2022</li>
              <li><strong>Workshop Gestão de pessoas: </strong>Data: 15/04/2022</li>
            </ul>
            </div>
        </main>
        <!-- Bootstrap CSS -->
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-JEW9xMcG8R+pH31jmWH6WWP0WintQrMb4s7ZOdauHnUtxwoG2vI5DkLtS3qm9Ekf" crossorigin="anonymous">
            </script>
</body>

</html>