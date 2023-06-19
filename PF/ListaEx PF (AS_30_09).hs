--Aluno: Guilherme Rimoldi Kameoka
--Lista: AS_30_09 (no lugar da prova oral)

import Data.Char

--Exercício 01: Nos items a seguir, escreva primeiramente uma função recursiva. Em seguida, reescreva essa função utilizando a função de ordem superior map, vista em aula.


--Item (a): Função primeiros :: [(a,b)] -> [a] que extrai o primeiro elemento de cada tupla-2 dentro de uma lista. Dica: utilize a função fst

primeiros :: [(a,b)] -> [a] 
primeiros [] = []
primeiros (x:xs) = fst x : primeiros xs

primeiros' :: [(a,b)] -> [a]
primeiros' x = map (fst) x

--Item (b): Função maiusculas :: String -> String que converte uma string para outra string com letras maiusculas. Dica: utilize a função toUpper da biblioteca Data.Char

maiusculas :: String -> String
maiusculas [] = []
maiusculas (x:xs) = toUpper x : maiusculas xs

maiusculas' :: String -> String
maiusculas' x = map (toUpper) x

--Item (c): Função dobra :: Num a => [a] -> [a] que dobra todos os elementos de uma lista

dobra :: Num a => a -> a
dobra x = 2*x

dobra' :: Num a => [a] -> [a]
dobra' a = map dobra a

--Item (d): Função hora_em_seg :: [Float] -> [Float] que converte uma lista de horas em uma lista de segundos

hora_em_seg :: [Float] -> [Float]
hora_em_seg [] = []
hora_em_seg (x:xs) = x * 3600 : hora_em_seg xs

hora_em_seg' :: [Float] -> [Float]
hora_em_seg' x = map (*3600) x


--Exercício 07: Nos itens a seguir, escreva primeiramente uma função recursiva. Em seguida, reescreva essa função utilizando a funçãoo de ordem superior filter, vista em aula.


--Item (a): Função pares :: [Int] -> [Int] que remove todos os elementos ımpares de uma lista. Dica: implemente uma função que verifique se um número é par

pares :: [Int] -> [Int]
pares [] = []
pares (x:xs)
 | even x = x : pares xs
 | otherwise = pares xs

pares' :: [Int] -> [Int]
pares' x = filter even x

--Item (b): Função alfa :: String -> String que remove todos os caracteres nao-alfabéticos de uma string. Dica: utilize a função isAlpha da biblioteca Data.Char

alfa :: String -> String
alfa [] = []
alfa (x:xs)
 | isAlpha x = x : alfa xs
 | otherwise = alfa xs

alfa' :: String -> String
alfa' x = filter isAlpha x

--Item (c): Defina a função rm char :: Char -> String -> String que remove todas as ocorrencias de um caractere em uma string

rm_char :: Char -> String -> String
rm_char a [] = []
rm_char a (x:xs)
 | a == x = rm_char a xs
 |otherwise = x : rm_char a xs

rm_char' :: Char -> String -> String
rm_char' a x = filter (a /=) x

--Item (d): Defina a função acima :: Int -> [Int] -> [Int] que remove todos os numeros menores ou iguais a um determinado valor

acima :: Int -> [Int] -> [Int]
acima a [] = []
acima a (x:xs)
 | a >= x = acima a xs
 |otherwise = x : acima a xs

acima' :: Int -> [Int] -> [Int]
acima' a x = filter (a <) x

--Item (e): Escreva uma função desiguais :: Eq t => [(t,t)] -> [(t,t)] que remove todos os pares (x,y) em que x == y

desiguais :: Eq t => [(t,t)] -> [(t,t)]
desiguais [] = []
desiguais (x:xs)
 | fst x == snd x = desiguais xs
 |otherwise = x : desiguais xs

desiguais' :: Eq t => [(t,t)] -> [(t,t)]
desiguais' a = filter (\(x,y) -> x /= y) a


--Exercício 08: Nos exercícios a seguir, escreva primeiramente uma função recursiva. Em seguida, reescreva essa função utilizando a função de ordem superior foldr, vista em aula.


--Item (a): Função produto :: Num a => [a] -> a que computa o produto dos numeros de uma lista

produto :: Num a => [a] -> a
produto [] = 0
produto (x:xs) = x * produto xs

produto' :: Num a => [a] -> a
produto' x = foldr (*) 0 x

--Item (b): Função e_logico :: [Bool] -> Bool que “e logico” de todos os itens em uma lista

e_logico :: [Bool] -> Bool
e_logico [] = False
e_logico (x:xs) = x && e_logico xs

e_logico' :: [Bool] -> Bool
e_logico' x = foldr (&&) False x

--Item (c): Função concatena :: [String] -> String que junta uma lista de strings em uma unica string

concatena :: [String] -> String
concatena [] = ""
concatena (x:xs) = x ++ concatena xs

concatena' :: [String] -> String
concatena' x = foldr (++) "" x

--Item (d): Função maior :: Num a => a -> [a] -> a que considera um numero e o compara com os elementos de uma lista. Caso esse numero seja maior que todos os elementos da lista, ele será retornado pela função. Caso contrário, a função retorna o maior elemento da lista

maior :: (Num a, Ord a) => a -> [a] -> a
maior a [] = a
maior a (x:xs)
 | x > a = maior x xs
 | otherwise = maior a xs

maior' :: (Num a, Ord a) => a -> [a] -> a
maior' a b = foldr max a b