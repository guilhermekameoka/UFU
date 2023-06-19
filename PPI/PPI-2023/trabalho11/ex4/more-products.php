<?php

class Product
{
  public $id;
  public $name;
  public $price;
  public $imagePath;

  function __construct($id, $name, $price, $imagePath)
  {
    $this->id = $id;
    $this->name = $name;
    $this->price = $price;
    $this->imagePath = $imagePath;
  }
}

// Criação da classe products com as características dos produtos

$products = array(
  new Product(1, 'Smart TV LED 55', 2900, 'tv.webp'),
  new Product(2, 'Smartphone 6.5 ABC', 1590, 'smartphone.webp'),
  new Product(3, 'Notebook 17 Ultra Slim', 4299, 'notebook.webp'),
  new Product(4, 'Mouse Óptico XYZ', 149, 'mouse.webp'),
  new Product(5, 'Monitor 28 4k', 1460, 'monitor.webp'),
  new Product(6, 'Fone Headset ABC', 250, 'headset.webp'),
  new Product(7, 'Pen-drive de 64GB', 90, 'pen-drive.webp')
);

// Representação da lista de produtos em forma de array

$randProds = [
  $products[rand(0, 6)],
  $products[rand(0, 6)],
  $products[rand(0, 6)],
  $products[rand(0, 6)],
  $products[rand(0, 6)]
];

// Define o cabeçalho da resposta HTTP como JSON e imprime o array $randProds codificado em JSON
header('Content-type: application/json');
echo json_encode($randProds);
