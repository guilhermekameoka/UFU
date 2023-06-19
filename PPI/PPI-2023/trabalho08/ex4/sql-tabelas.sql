CREATE TABLE cliente
(
   codigo_cliente int PRIMARY KEY auto_increment,
   nome varchar(50),
   cpf char(14) UNIQUE,
   email varchar(50) UNIQUE,
   hash_senha varchar(255),
) ENGINE=InnoDB;

CREATE TABLE clienteEndereco
(
   cep char(10),
   endereco varchar(100),
   bairro varchar(50),
   cidade varchar(50),
   estado varchar(50),
   codigo_cliente int not null,
   FOREIGN KEY (codigo_cliente) REFERENCES cliente(codigo_cliente) ON DELETE CASCADE
) ENGINE=InnoDB;