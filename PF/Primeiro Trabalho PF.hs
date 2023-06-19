--Aluno: Guilherme Rimoldi Kameoka
--Trabalho "O Dia da Semana"

--Definição de tipos
type Dia = Int
type Mes = Int
type Ano = Int
type Data = (Dia,Mes,Ano)

--Determina se um ano é ou não bissexto
bissexto :: Ano -> Bool
bissexto ano
 |mod ano 4==0 || mod ano 400==0 = True
 |mod ano 100==0 = False  
 |otherwise = False
 
--Calcula o número de dias passados a partir de 31 de dezembro de 2000
numDeDiasEmCadaMesDeUmAno :: Ano -> [Int]
numDeDiasEmCadaMesDeUmAno ano = 
 [31,feb,31,30,31,30,31,31,30,31,30,31]
 where feb
        | bissexto ano = 29
        | otherwise = 28

--Calcula o número de dias passados a partir de 31 de dezembro de 2000
numDeDias :: Data -> Int
numDeDias (dia,mes,ano) =
 dia
 + sum (take (mes-1) (numDeDiasEmCadaMesDeUmAno ano))
 + (ano-2001)*365 + (ano-2001) `div` 4
 
--Calcula o dia da semana a partir do número de dias passados
nomeDoDia :: Int -> String
nomeDoDia numDeDias
 |mod numDeDias 7==0 = "Domingo"
 |mod numDeDias 7==1 = "Segunda"
 |mod numDeDias 7==2 = "Terca"
 |mod numDeDias 7==3 = "Quarta"
 |mod numDeDias 7==4 = "Quinta"
 |mod numDeDias 7==5 = "Sexta"
 |mod numDeDias 7==6 = "Sabado"
 
--Devolve o dia da semana de uma data do século XXI
diaDaSemana :: Data -> String
diaDaSemana x = nomeDoDia (numDeDias x)
