produto([],0). %produto de lista vazia = 0
produto([H],H). %se tiver apenas a cabeça, o resultado do produto é a própria cabeça
produto([H|T], P) :- produto(T, R), P is H * R. %faz o produto de todos os elementos da lista

verifica_cabeca(H,[H|_]). %verifica se o elemento é a cabeça
verifica_cabeca(H,[T]) :- verifica_cabeca(H,T). %verifica se a cabeça da lista faz parte da cauda

remove_repetido([],[]). %entra com uma lista e devolve uma lista
remove_repetido([H|T],R) :- verifica_cabeca(H,T), !, remove_repetido(T,R). %verifica se a cabeca faz parte da cauda e remove elemento repetido
remove_repetido([H|T],[H|R]) :- remove_repetido(T,R).
 
resultado([H|T]) :- remove_repetido([H|T], X), produto(X, Y), writeln(X), writeln(Y). %entra com uma lista, aplica sobre ela os predicados remove_repetido e produto, após isso imprime o resultado da multiplicação de todos os elementos da lista
