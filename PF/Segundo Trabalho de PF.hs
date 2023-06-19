--Aluno:Guilherme Rimoldi Kameoka
--Produção de um recibo fiscal em um supermercado

--Definição dos tipos
type Nome = String
type Preco = Int
type CodBar = Int
type BaseDeDados = [(CodBar,Nome,Preco)]
type ListaDeCodigos = [CodBar]
type Recibo = [(Nome,Preco)]

--Banco de dados de todos os produtos, com codigo de barras, nome e preço
listaDeProdutos :: BaseDeDados
listaDeProdutos =  [
 (1234, "Oleo DoBom, 1l", 195), 
 (4756, "Chocolate Cazzeiro, 250g", 180), 
 (3216, "Arroz DoBom, 5Kg", 213),
 (5823, "Balas Pedregulho, 1Kg", 379), 
 (4719, "Queijo Mineirim, 1Kg", 449), 
 (6832, "Iogurte Maravilha, 1Kg", 499),
 (1112, "Rapadura QuebraDente, 1Kg", 80), 
 (1111, "Sal Donorte, 1Kg", 221),
 (1113, "Cafe DoBom, 1Kg", 285),
 (1115, "Biscoito Bibi, 1Kg", 80), 
 (3814, "Sorvete QGelo, 1l", 695)]

--Define o tamanha da linha
tamanhoLinha :: Int
tamanhoLinha = 40

--Transforma o valor em centavos para reais (decimal)
formataCentavos :: Preco -> String
formataCentavos preco = show quociente ++ "." ++ (if resto < 10 then "0" else "") ++ show resto
 where
 (quociente,resto) = divMod preco 100

--Recebe um par formado pelo nome e preço da mercadoria e entrega um string que representa uma linha da conta do supermercado
formataLinha :: (Nome,Preco) -> String 
formataLinha (nome,preco) = nome ++ (replicate numerodepontos '.') ++ precoStr ++ "\n"
 where
 precoStr = formataCentavos preco
 numerodepontos = tamanhoLinha - length nome - length precoStr

--Recebe nomes das mercadorias e seus respectivos preços e devolve um string que corresponde à conta do supermercado
formataLinhas :: [(Nome,Preco)] -> String
formataLinhas x = foldl (++) "" (map formataLinha x)

--Resulta na lista dos pares (Nome,Preco) para as mercadorias compradas
achaItem :: CodBar -> (Nome,Preco)
achaItem x = acha listaDeProdutos x

--Recebe os nomes e preços das mercadorias disponíveis no supermercado e o código de barras
--Devolve o preço da mercadoria e, se o código de barras não constar no banco de dados, o resultado será "item desconhecido"
acha :: BaseDeDados -> CodBar -> (Nome, Preco)
acha [] _ = ("item desconhecido", 0)
acha ((codbar1,nome,preco):resto) codbar2 
 | codbar1 == codbar2 = (nome,preco)
 | otherwise = acha resto codbar2

--Recebe um código de barras e devolve um string com nome e preço
fazRecibo :: ListaDeCodigos -> Recibo
fazRecibo [] = []
fazRecibo x = map achaItem x

--Formata a compra para um string
formataRecibo :: Recibo -> String
formataRecibo produtos = "Supermercado QLegal\n" ++ "\n" ++ formataLinhas produtos ++ formataTotal (geraTotal produtos)

--Gera o recibo da compra
geraRecibo :: ListaDeCodigos -> String
geraRecibo lc = formataRecibo (fazRecibo lc)

--Resulta o preço final da conta
geraTotal :: Recibo -> Preco
geraTotal produtos = sum (map snd produtos)

--Recebe a lista dos itens comprados e entrega uma string que representa a conta do supermercado
formataTotal :: Preco -> String
formataTotal preco = "\nTotal" ++ (replicate numerodepontos '.') ++ precoStr
 where
 precoStr = formataCentavos preco
 numerodepontos = tamanhoLinha - length "Total" - length precoStr

--Função principal do programa
main :: IO ()
main = do
 x <- getLine
 putStrLn ((geraRecibo (read x :: ListaDeCodigos)))
 y <- getLine
 putStrLn ("End")