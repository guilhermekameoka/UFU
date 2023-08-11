<?php

// inicia a sessão
session_start();

// apaga as variáveis de sessão
session_unset();

// destrói a sessão
session_destroy();

header('Location: http://victoralves.atwebpages.com/clinica');
exit();

?>