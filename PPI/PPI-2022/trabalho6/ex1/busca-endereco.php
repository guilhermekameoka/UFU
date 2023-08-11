<?php

class Endereco
{
  public $rua;
  public $bairro;
  public $cidade;

  function __construct($rua, $bairro, $cidade)
  {
    $this->rua = $rua;
    $this->bairro = $bairro; 
    $this->cidade = $cidade;
  }
}

$endereco1 = new Endereco('Av João Naves', 'Santa Mônica', 'Uberlândia');
$endereco2 = new Endereco('Av Floriano Peixoto', 'Centro', 'Uberlândia');
$endereco3 = new Endereco('Av Afonso Pena','Martins', 'Uberlândia');

$enderecos = array(
  '38400-100' => $endereco1,
  '38400-200' => $endereco2,
  '38400-300' => $endereco3
);

$cep = $_GET['cep'] ?? '';
  
$endereco = array_key_exists($cep, $enderecos) ? 
  $enderecos[$cep] : new Endereco('', '', '');
  
echo json_encode($endereco);