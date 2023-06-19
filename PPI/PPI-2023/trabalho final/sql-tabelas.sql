CREATE TABLE Anunciante
(
   codigo int PRIMARY KEY auto_increment,
   nome varchar(50),
   cpf char(14) UNIQUE,
   email varchar(50) UNIQUE,
   hashsenha varchar(255),
   telefone varchar(11)
) ENGINE=InnoDB;

CREATE TABLE Anuncio 
(
    codigo int PRIMARY KEY auto_increment,
    titulo varchar(50),
    descricao varchar(255),
    preco decimal(10,2),
    datahora datetime,
    cep char(8),
    bairro varchar(50),
    cidade varchar(50),
    estado char(2),
    codcategoria int,
    codanunciante int,
    FOREIGN KEY (codcategoria) REFERENCES Categoria(codigo),
    FOREIGN KEY (codanunciante) REFERENCES Anunciante(codigo)
    ) ENGINE=InnoDB;

CREATE TABLE Categoria
(
    codigo int PRIMARY KEY auto_increment,
    nome varchar(50),
    descricao varchar(255)
) ENGINE=InnoDB;

CREATE TABLE Foto
(
    codigo int PRIMARY KEY auto_increment,
    codanuncio int,
    nomearquivo varchar(50),
    FOREIGN KEY (codanuncio) REFERENCES Anuncio(codigo)
) ENGINE=InnoDB;

CREATE TABLE Ajax
(
    cep char(8),
    bairro varchar(50),
    cidade varchar(50),
    estado char(2)
) ENGINE=InnoDB;

CREATE TABLE Interesse (
   codigo INT PRIMARY KEY AUTO_INCREMENT,
   mensagem VARCHAR(255),
   datahora DATETIME,
   contato VARCHAR(255),
   codAnuncio INT,
   FOREIGN KEY (CodAnuncio) REFERENCES Anuncio(Codigo)
) ENGINE=InnoDB;
