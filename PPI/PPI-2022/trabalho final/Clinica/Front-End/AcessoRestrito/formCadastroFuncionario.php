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
    <title>Cadastrar novo Funcionário</title>
    <link rel="stylesheet" href="../../style/style_restrita.css">
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-eOJMYsd53ii+scO/bJGFsiCZc+5NDVN2yr8+0RDqr0Ql0h+rP48ckxlpbzKgwra6" crossorigin="anonymous">
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
            <div class="container">
                <h3>Cadastrar novo Funcionário</h3>

                <form action="../../Back-End/cadastraFuncionario.php" method="post">
                        
                        <div class="row">
                            <div class="col-sm-8">
                                <label for="nome" class="form-label">Nome</label>
                                <input type="text" class="form-control" id="nome" name="nome">
                            </div>
                            <div class="col-sm-4">
                                <label for="sexo" class="form-label">Sexo</label>
                                <select name="sexo" id="sexo" class="form-select">
                                    <option value="Masculino">Masculino</option>
                                    <option value="Feminino">Feminino</option>
                                    <option value="Outro">Outro</option>
                                </select>
                            </div>
                            <div class="col-sm-4">
                                <label class="form-label" for="email">Email</label>
                                <input class="form-control" type="email" id="email" name="email" required>
                            </div>
                            <div class="col-sm-3">
                                <label class="form-label" for="telefone">Telefone</label>
                                <input class="form-control" type="tel" id="telefone" name="telefone">
                            </div>
                            
                                <div class="col-sm-5">
                                    <label for="cep" class="form-label">CEP</label>
                                    <input type="text" class="form-control" id="cep" name="cep">
                                </div>
                                <div class="col-sm-5">
                                    <label for="logradouro" class="form-label">Logradouro</label>
                                    <input type="text" class="form-control" id="logradouro" name="logradouro">
                                </div>
                            
                            
                                <div class="col-sm-4">
                                    <label for="cidade" class="form-label">Cidade</label>
                                    <input type="text" class="form-control" id="cidade" name="cidade">
                                </div>
                                <div class="col-sm-3">
                                    <label for="estado" class="form-label">Estado</label>
                                    <select name="estado" id="estado" class="form-select">
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
                                <div class="col-sm-4">
                                    <label class="form-label" for="dataContrato">Data Contrato</label>
                                    <input class="form-control" type="date" id="dataContrato" name="dataContrato">
                                </div>
                                <div class="col-sm-4">
                                    <label class="form-label" for="salario">Salario</label>
                                    <input class="form-control" type="number" step=0.01 id="salario" name="salario">
                                </div>
                                <div class="col-sm-4">
                                    <label class="form-label" for="senha">Senha</label>
                                    <input class="form-control" type="password" id="senha" name="senha" require>
                                </div>
                                <h5>É médico ?</h5>
                                <div>
                                    <input class="ehMedico .form-check-input " type="radio" onclick="verificaMedico();" id="simMedico" name="medico" value="simMedico"checked>
                                    <label for="simMedico">Sim</label>
                                    <input class="ehMedico .form-check-input " type="radio" onclick="verificaMedico();" id="naoMedico" name="medico" value="naoMedico">
                                    <label for="naoMedico">Não</label>
                                </div>
                                
                                    <div class="col-sm-6">
                                        <label class="form-label" for="especialidade">Especialidade</label>
                                        <input class="form-control medico" type="text" id="especialidade" name="especialidade">
                                    </div>
                                    <div class="col-sm-6">
                                        <label class="form-label" for="crm">CRM</label>
                                        <input class="form-control medico" type="number" id="crm" name="crm">
                                    </div>
                        </div>
                        
                        
                        <button class="btn btn-primary my-2 btn-success">Cadastrar</button>
    
                    </form>
            </div>
        </main>
    </div>
    <script src="../../js/ajaxEndereco.js"></script>
    <script>
        function verificaMedico() {
            let radio = document.querySelector("input[type='radio']:checked").value;
            let campoEspecialidade = document.getElementById("especialidade");
            let campoCrm = document.getElementById("crm");

            if(radio == "simMedico"){
               campoEspecialidade.removeAttribute('disabled');
               campoCrm.removeAttribute('disabled');
            }
            else if(radio == "naoMedico"){
                campoEspecialidade.setAttribute('disabled', 'disabled');
                campoCrm.setAttribute('disabled', 'disabled');
                campoEspecialidade.value = '';
                campoCrm.value = '';
            }
        }
    </script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
</body>
</html>