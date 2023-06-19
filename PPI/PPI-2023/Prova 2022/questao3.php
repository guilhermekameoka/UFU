<?php

class Automovel
{
  public $marca;
  public $modelo;
  public $cor;

  function __construct($marca, $modelo, $cor)
  {
    $this->marca = $marca;
    $this->modelo = $modelo; 
    $this->cor = $cor;
  }
}

$id = $_GET['id'] ?? '';

if ($id == '1')
  $automovel = new Automovel('A', 'Carro Elétrico XYZ', 'Bege');
else if ($id == '2')
  $automovel = new Automovel('B', 'Carro Flex 123', 'Prata');
else if ($id == '3')
  $automovel = new Automovel('C', 'SUV Diesel de luxo', 'Preto');
else 
  $automovel = new Automovel('', '', '');

header('Content-type: application/json');
echo json_encode($automovel);