--Aluno:Guilherme Rimoldi Kameoka
--Lista:AS_15_09

import Data.Char

--Exercício 2(h)
ultimo :: [Int] -> Int
ultimo x = head (reverse x)

--Exercício 2(i)
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = x:x:(duplica xs)

--Exercício 2(k)
substituir_todos :: Int -> Int -> [Int] -> [Int]
substituir_todos a b [] = []
substituir_todos a b (x:xs)
 | a == x = b : substituir_todos a b xs
 | otherwise = x : substituir_todos a b xs

--Exercício 2(n)
maior :: [Int] -> Int
maior [x] = x
maior (x:xs)
 | x > maior xs = x 
 | otherwise = maior xs
 
-- Exercício 3(b)
pertence :: Eq t => t -> [t] -> Bool
pertence a [] = False
pertence a (x:z) = if (a == x) then True else pertence a z

uniao :: Eq t => [t] -> [t] -> [t]
uniao as bs = as ++ [b | b <- bs, not (pertence b as)]

-- Exercício 3(c)

-- Exercício 4(c)
maiusculo :: String -> String
maiusculo [] = []
maiusculo (x:xs) = toUpper x : maiusculo xs
maiusculo2 :: String -> (String, String)
maiusculo2 x = (x, maiusculo x)

-- Exercício 7
converte :: [Int] -> Int
converte [] = 0
converte x = head x * 2 ^ (length x - 1) + converte (tail x)

-- Exercício 8
digitos :: Int -> [Int]
digitos 0 = []
digitos x = digitos (x `div` 10) ++ [x `mod` 10]