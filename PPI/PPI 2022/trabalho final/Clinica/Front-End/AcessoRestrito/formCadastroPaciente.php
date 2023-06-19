<?php

require_once "../../sql/conexaoMysql.php";
require_once "../../sql/autenticacao.php";

session_start();
$pdo = mysqlConnect();
exitWhenNotLogged($pdo);

?>
<!DOCTYPE html>
<html lang="pt-BR">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../../style/style_restrita.css">
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6" crossorigin="anonymous">


    <title>Cadastro Pacientes</title>


</head>

<body>

    <nav class="navbar navbar-expand-lg navbar-dark fixed-top  ">
        <a class="nav-link active col-1" href="../index.html">
            <img src="../../images/sanctum.png" alt="CLINICA SANCTUM SANCTORUM" height="80">
        </a>
        <button class="navbar-toggler " type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
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

    <div class="container">
        <main>
            <h3>
                Cadastrar novo paciente
            </h3>

            <form action="../../Back-End/cadastraPaciente.php" method="post">
                <div class="row">
                    <div class="col-sm-6">
                        <label for="nome" class="form-label">Nome:</label>
                        <input type="text" class="form-control" id="nome" name="nome">
                    </div>
                    <div class="col-sm-6">
                        <label for="sexo" class="form-label">Sexo:</label>
                        <select name="sexo" id="sexo" class="form-select">
                            <option selected>Selecione</option>
                            <option value="Masculino">Masculino</option>
                            <option value="Feminino">Feminino</option>
                            <option value="Outro">Outro</option>
                        </select>
                    </div>
                </div>

                <div class="row">
                    <div class="col-sm-6">
                        <label for="email" class="form-label">E-mail:</label>
                        <input type="text" class="form-control" id="email" name="email">
                    </div>
                    <div class="col-sm-6">
                        <label for="telefone" class="form-label">Telefone:</label>
                        <input type="text" class="form-control" id="telefone" name="telefone">
                    </div>
                </div>

                <div class="row">
                    <div class="col-sm-6">
                        <label for="cep" class="form-label">CEP:</label>
                        <input type="text" class="form-control" id="cep" name="cep">
                    </div>
                    <div class="col-sm-6">
                        <label for="logradouro" class="form-label">Logradouro:</label>
                        <input type="text" class="form-control" id="logradouro" name="logradouro">
                    </div>
                </div>

                <div class="row">
                    <div class="col-sm-6">
                        <label for="cidade" class="form-label">Cidade:</label>
                        <input type="text" class="form-control" id="cidade" name="cidade">
                    </div>
                    <div class="col-sm-6">
                        <label for="estado" class="form-label">Estado:</label>
                        <select name="estado" id="estado" class="form-select">
                            <option selected>Selecione</option>
                            <option value="AC">AC</option>
                            <option value="AL">AL</option>
                            <option value="AP">AP</option>
                            <option value="AM">AM</option>
                            <option value="BA">BA</option>
                            <option value="CE">CE</option>
                            <option value="ES">ES</option>
                            <option value="GO">GO</option>
                            <option value="MA">MA</option>
                            <option value="MT">MT</option>
                            <option value="MS">MS</option>
                            <option value="MG">MG</option>
                            <option value="PA">PA</option>
                            <option value="PB">PB</option>
                            <option value="PR">PR</option>
                            <option value="PE">PE</option>
                            <option value="PI">PI</option>
                            <option value="RJ">RJ</option>
                            <option value="RN">RN</option>
                            <option value="RS">RS</option>
                            <option value="RO">RO</option>
                            <option value="RR">RR</option>
                            <option value="SC">SC</option>
                            <option value="SP">SP</option>
                            <option value="SE">SE</option>
                            <option value="TO">TO</option>
                            <option value="DF">DF</option>
                        </select>
                    </div>
                </div>

                <div class="row">
                    <div class="col-sm-4">
                        <label for="peso" class="form-label">Peso(kg):</label>
                        <input type="number" step="0.01" class="form-control" id="peso" name="peso">
                    </div>
                    <div class="col-sm-4">
                        <label for="cidade" class="form-label">Altura(cm):</label>
                        <input type="number" class="form-control" id="altura" name="altura">
                    </div>
                    <div class="col-sm-4">
                        <label for="sangue" class="form-label">Tipo sanguíneo:</label>
                        <select name="sangue" id="sangue" class="form-select">
                            <option selected>Selecione</option>
                            <option value="A+">A+</option>
                            <option value="A-">A-</option>
                            <option value="B+">B+</option>
                            <option value="B-">B-</option>
                            <option value="AB">AB</option>
                            <option value="O+">O+</option>
                            <option value="O-">O-</option>
                        </select>
                    </div>
                </div>
                <button class="btn btn-primary my-2 btn-success">Cadastrar</button>
            </form>
        </main>
    </div>

    <script src="../../js/ajaxEndereco.js"></script>
    <!-- Bootstrap CSS -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js" integrity="sha384-JEW9xMcG8R+pH31jmWH6WWP0WintQrMb4s7ZOdauHnUtxwoG2vI5DkLtS3qm9Ekf" crossorigin="anonymous">
    </script>
</body>

</html>