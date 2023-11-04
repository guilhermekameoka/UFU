<?php

require "conexao.php";
$pdo = mysqlConnect();

try {
    $sql = "SELECT usuario FROM usuarios";
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    $usuarios = $stmt->fetchAll();
} catch (Exception $e) {
    exit('Falha ao buscar os dados: ' . $e->getMessage());
}

?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Usuários Cadastrados</title>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/5.3.0/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdn.datatables.net/1.13.6/css/dataTables.bootstrap5.min.css" rel="stylesheet">
</head>

<body>
    <h1>Usuários Cadastrados</h1>
    <table id="tabelaUsuarios" class="table table-striped">
        <thead>
            <tr>
                <th>Nome do Usuário</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($usuarios as $usuario): ?>
                <tr>
                    <td>
                        <?php echo htmlspecialchars($usuario['usuario']); ?>
                    </td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
    <button id="limparTabela">Limpar Tabela</button>

    <script src="https://code.jquery.com/jquery-3.5.1.js"></script>
    <script src="https://cdn.datatables.net/1.13.6/js/jquery.dataTables.min.js"></script>
    <script src="https://cdn.datatables.net/1.13.6/js/dataTables.bootstrap5.min.js"></script>
    <script>
        $(document).ready(function () {
            var tabela = $('#tabelaUsuarios').DataTable();

            $('#limparTabela').click(function () {
                tabela.clear().draw();
            });
        });
    </script>
</body>

</html>