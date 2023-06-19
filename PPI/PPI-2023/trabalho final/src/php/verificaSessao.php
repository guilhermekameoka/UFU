<?php

function exitWhenNotLoggedIn()
{
  if (!isset($_SESSION['loggedIn'])) {
    header("Location: ../html/public/index.html");
    exit();
  }
}
