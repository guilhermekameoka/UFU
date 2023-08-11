<?php

require_once "../../../sql/conexaoMysql.php";
require_once "../../../sql/autenticacao.php";

session_start();
$pdo = mysqlConnect();
exitWhenNotLogged($pdo);

try {
  $sql = <<<SQL
        SELECT dataAgenda, horario, nome as nomePaciente, sexo, email
        FROM agenda_Trab
        WHERE codigo_medico = ?
        SQL;

    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['medico']]);
} catch (Exception $e) {
  exit('Ocorreu uma falha: ' . $e->getMessage());
}
?>


<!doctype html>
<html lang="pt-BR">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Minha Agenda</title>
  <link rel="stylesheet" href="../../../style/style_restrita.css">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">

</head>

<body>

  <div class="container">
    <nav class="navbar navbar-expand-lg navbar-dark fixed-top  ">
     <a class="nav-link active col-1" href="../../index.html">
        <img src="../../../images/sanctum.png" alt="CLINICA SANCTUM SANCTORUM" height="80">
      </a>
      <button class="navbar-toggler " type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>

      <div class="collapse navbar-collapse justify-content-center" id="navbarSupportedContent">
        <ul class="navbar-nav mr-auto">
          <li class="nav-item active"><a class="nav-link color-white" href="../homeUsuario.php">Home Usuário</a>
          </li>
          <li class="nav-item"><a class="nav-link color-white" href="../formCadastroFuncionario.php">Cadastro de
              Funcionário</a>
          </li>
          <li class="nav-item"><a class="nav-link color-white" href="../formCadastroPaciente.php">Cadastro de
              Paciente</a></li>
          <li class="nav-item"><a class="nav-link color-white" href="mostraDadosFuncionario.php">Listar
              Funcionários</a>
          </li>
          <li class="nav-item"><a class="nav-link color-white" href="mostraDadosPaciente.php">Listar
              Pacientes</a></li>
          <li class="nav-item"><a class="nav-link color-white" href="mostraDadosEndereco.php">Listar
              Endereços</a></li>
          <li class="nav-item"><a class="nav-link color-white" href="mostraDadosConsulta.php">Listar
              Agendamentos</a>
          </li>
            <?php
                if ($_SESSION['medico'] != -1)
                    echo <<<HTML
                            <li class="nav-item"><a class="nav-link color-white" href="mostrarMeusAgendamentos.php">Listar Meus Agendamentos</a>
                            </li>
                            HTML;
            ?>
          <li class="nav-item"><a class="nav-link logout-b" href="../../../Back-End/logout.php">Logout</a></li>
        </ul>
      </div>
    </nav>
    <main>

      <h3>Minhas Consultas Agendadas</h3>
      <table class="table table-striped table-hover">
        <tr>
          <th>Data</th>
          <th>Horário</th>
          <th>Nome Paciete</th>
          <th>Sexo Paciente</th>
          <th>Email Paciente</th>
        </tr>
        <?php
        while ($row = $stmt->fetch()) {

          $dataAgenda = htmlspecialchars($row['dataAgenda']);
          $horario = htmlspecialchars($row['horario']);
          $nomePaciente = htmlspecialchars($row['nomePaciente']);
          $sexoPaciente = htmlspecialchars($row['sexo']);
          $emailPaciente = htmlspecialchars($row['email']);

          echo <<<HTML
          <tr>
            <td>$dataAgenda</td> 
            <td>$horario</td>
            <td>$nomePaciente</td>
            <td>$sexoPaciente</td>
            <td>$emailPaciente</td>
          </tr>      
        HTML;
        }
        ?>

      </table>
    </main>
  </div>

</body>

</html>