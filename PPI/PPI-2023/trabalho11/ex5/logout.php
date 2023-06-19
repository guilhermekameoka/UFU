<?php

// inicia a sessão
session_start();

// apaga as variáveis de sessão
session_unset();

// destrói a sessão
session_destroy();

// exclui o cookie da sessão
setcookie(session_name(), "", 1, "/");

header('Location: index.html');
exit();

?>