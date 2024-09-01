% O objetivo desse programa é resolver o problema do caixeiro viajante
% A partir de um nó de origem, o programa irá retornar o percurso cujo caminho é o menor

% Integrantes do grupo:
% Gabriel Kato
% Ana Luisa Sticca
% Bruno Oliveira
% Julio Cesar
% Guilherme Kameoka
% Carlos Livus
% Vitor Yuji
% Tais Damasceno

% Define cada aresta do grafo com a respectiva distancia
aresta(ribeirao_preto, uberaba, 170).  
aresta(uberaba, uberlandia, 108).
aresta(uberlandia, itumbiara, 133).
aresta(itumbiara, goiania, 208).
aresta(ribeirao_preto, franca, 87).
aresta(uberlandia, araguari, 37).
aresta(uberaba, franca, 124).
aresta(uberaba, monte_alegre, 177).
aresta(uberlandia, patos_de_minas, 100).
aresta(patos_de_minas, uberaba, 216).
aresta(patos_de_minas, franca, 326).
aresta(uberlandia, caldas_novas, 150).
aresta(caldas_novas, goiania, 170).
aresta(caldas_novas, araguari, 135).
aresta(ribeirao_preto, araraquara, 91).
aresta(araraquara, sao_carlos, 44).
aresta(sao_carlos, rio_claro, 66).
aresta(rio_claro, limeira, 28).
aresta(limeira, campinas, 58).
aresta(campinas, jundiai, 38).
aresta(jundiai, sao_paulo, 59).
aresta(ribeirao_preto, cravinhos, 23).
aresta(cravinhos, pirassununga, 84).
aresta(pirassununga, limeira, 68).
aresta(sao_paulo, santos, 80).

% Define que o grafo é nao direcionado
conectado(X, Y, D) :- aresta(X, Y, D).
conectado(X, Y, D) :- aresta(Y, X, D).

% Funcao principal que inicia a busca
buscar_todos_caminhos(Inicio, Destino, Caminhos) :-
    findall((Caminho, Distancia), busca_profundidade(Inicio, Destino, [Inicio], Caminho, 0, Distancia), Caminhos).

% Caso base da busca em profundidade
%	   				atual   fianal						 acumulada    fianal
busca_profundidade(Destino, Destino, Visitados, Caminho, Distancia, Distancia) 
	:- reverse(Visitados, Caminho).

% Busca em profundidade recursiva
busca_profundidade(Atual, Destino, Visitados, CaminhoFinal, DistanciaAcumulada, DistanciaTotal) :-
    conectado(Atual, Proximo, Distancia),
    \+ member(Proximo, Visitados),  % Verifica se "Proximo" não está na lista de visitados.
    NovaDistancia is DistanciaAcumulada + Distancia,
    busca_profundidade(Proximo, Destino, [Proximo|Visitados], CaminhoFinal, NovaDistancia, DistanciaTotal).

% Encontra o menor caminho em uma lista de caminhos e distâncias
menor_caminho([CaminhoDistancia], CaminhoDistancia).
menor_caminho([(Caminho1, Distancia1), (Caminho2, Distancia2) | T], Menor) :-
    (Distancia1 =< Distancia2 ->
        menor_caminho([(Caminho1, Distancia1) | T], Menor)
    ;   menor_caminho([(Caminho2, Distancia2) | T], Menor)
    ).

% Regra principal para iniciar a pesquisa e encontrar o caminho mais curto
encontrar_caminho(Inicio, Destino) :-
    buscar_todos_caminhos(Inicio, Destino, Caminhos),
    (Caminhos \= [] ->
        menor_caminho(Caminhos, (MenorCaminho, MenorDistancia)),
        write('Menor caminho: '), write(MenorCaminho), nl,
        write('Distancia total: '), write(MenorDistancia), write(' km'), nl
    ;   write('Nenhum caminho encontrado.'), nl).