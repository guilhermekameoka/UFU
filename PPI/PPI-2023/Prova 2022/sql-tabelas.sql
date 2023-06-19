CREATE TABLE segurado
(
   id int PRIMARY KEY auto_increment,
   nome_seg varchar(50),
   cpf varchar(15),
   email varchar(30),
   premio decimal(10,2)
) ENGINE=InnoDB;

CREATE TABLE dependente
(
   id int PRIMARY KEY auto_increment,
   nome_dep varchar(50),
   relacao varchar(50),
   data_nascimento date,
   id_segurado int not null,
   FOREIGN KEY (id_segurado) REFERENCES segurado(id) ON DELETE CASCADE
) ENGINE=InnoDB;