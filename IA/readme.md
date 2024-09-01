## Primeiro trabalho de IA - Busca em profundidade
O objetivo desse código é resolver o problema do viajante caixeirom, implementando o algorítimo de busca em profundidade. Dado um ponto de origem e destino, o programa retornará o percurso com a menor distância.

## Explicando o funcionamento
Primeiramente precisamos defenir quais são as arestas do grafo.  
O predicado `aresta` possui três argumentos (Origem, Destino, Distância).

```
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
```

Cada linha desse trecho de código representa uma conexão direta entre duas cidades, junto com a distância em Km.  
Então a distância entre Ribeirão Preto e Uberaba seria de 170 km.

>``aresta(ribeirao_preto, uberaba, 170).``

Em seguida foi definido que o grafo é não direcionado, ou seja, se dois nós estão conectados então é possível fazer tanto o caminho de ida quanto o de volta.

```
conectado(X, Y, D) :- aresta(X, Y, D).
conectado(X, Y, D) :- aresta(Y, X, D).
```

O predicado `conectado` indica que as cidades X e Y estão conectados por uma distância D se as arestas X, Y, D ou Y, X, D existirem. Então o retorno desse predicado será verdadeiro se as regras acima forem atendidas, caso contrário ele irá retornar falso.  

Dito isto, agora sabemos a lógica por trás de como os nós estão conectados, então podemos dar sequência e entender como o mecanismo da busca funciona.

````
buscar_todos_caminhos(Inicio, Destino, Caminhos) :-
    findall((Caminho, Distancia), busca_profundidade(Inicio, Destino, [Inicio], Caminho, 0, Distancia), Caminhos).
````

O predicado `busca_todos_caminhos` é responsável por encontrar todos os caminhos possíveis entre dois nós e calcular a distância total de cada caminho. Ele usa o predicado `findall` nativo do Prolog, que é um construtor de listas, para encontrar e coletar todas as soluções (caminho, distância) possíveis e as armazena na lista `Caminhos`.  

Depois é feito a chamada do predicado `busca_profundidade` (que iremos abordar em seguida) para explorar todas as conexões possíveis que existe no grafo para garantir que todos os caminhos possíveis sejam considerados. Isso é necessário porque para saber o menor caminho possível entre dois pontos precisamos ter a certeza que todas as possibilidades de rotas foram levadas em consideração.

```
busca_profundidade(Inicio, Destino, [Inicio], Caminho, 0, Distancia).
```
> - Inicio: Nó de origem atual
> - Destino: Nó destino desejado
> - [Inicio]: Lista de nós visitados até o momento (começa apenas com o nó inicial)
> - Caminho: Caminho completo encontrado da origem até o destino
> - 0: Distância acumulada até o momento
> - Distancia: Distância total percorrida até chegar no destino

Ao final da execução do findall, a variável `Caminhos` irá conter todos os caminhos possíveis da origem até o destino, cada uma com sua respectiva distância. Então, se quisermos listar todos os caminhos possíveis além do menor de todos, podemos fazer a seguinte consulta:

> ``busca_todos_caminhos(ribeirao_preto, uberaba, Caminhos).``

O predicado `busca_profundidade` possui duas abordagens diferentes:  
- Caso Base: Define a condição de parada, ou seja, quando o destino for encontrado.
  
    ```
    busca_profundidade(Destino, Destino, Visitados, Caminho, Distancia, Distancia) 
        :- reverse(Visitados, Caminho).
    ```
    > - Destino, Destino: Indicam o nó atual e o nó de destino. No caso base, ambos são iguais, o que significa que o algoritmo chegou ao nó de destino e pode parar.
    > - Visitados: Lista que mantém todos os nós visitados ao longo do caminho desde o início até o destino.
    > - Caminho: É o caminho completo do ponto de partida até o destino, armazenado como uma lista de nós na ordem correta. Durante a busca, a lista Visitados acumula os nós na ordem inversa porque o próximo nó visitado é sempre adicionado ao início da lista. Quando o destino é encontrado, usamos reverse para inverter essa lista e obter o caminho correto. 
    > - Distancia, Distancia: A distância acumulada percorrida até o nó de destino. No caso base, a distância acumulada (Distancia) é simplesmente passada para o resultado final, sem nenhuma modificação, pois o caminho está completo.  

    Pode parecer redundante repetir os mesmos termos, mas nesse caso não é. A repetição dos parâmetros em Prolog tem um propósito específico de unificação.
    -  Em `Destino, Destino`, o primeiro termo é o parâmetro que está sendo comparado com o segundo. Só é verdadeiro se ambos os valores forem iguais. Nesse caso usamos para verificar se o ponto atual é o destino fianal.
    -  Em `Distancia, Distancia`, da mesma, isso verifica se a distância acumulada até o ponto atual (último ponto do caminho) é igual a distância final. Dessa forma podemos garantir que a distância final é a mesma da distância acumulada no caminho.  
  
- Caso recursivo: Define como o algoritmo deve explorar o grafo para encontrar o caminho até o destino.
  
    ```
    busca_profundidade(Atual, Destino, Visitados, CaminhoFinal, DistanciaAcumulada, DistanciaTotal) :-
    conectado(Atual, Proximo, Distancia),
    \+ member(Proximo, Visitados),  % Verifica se "Proximo" não está na lista de visitados.
    NovaDistancia is DistanciaAcumulada + Distancia,
    busca_profundidade(Proximo, Destino, [Proximo|Visitados], CaminhoFinal, NovaDistancia, DistanciaTotal).
    ```
    Primeiro, o predicado `conectado(Atual, Proximo, Distancia)` busca por um nó `Próximo` que esteja conectado ao nó `Atual` por uma aresta com distância `Distancia`. Isso identifica as possíveis cidades vizinhas que podem ser exploradas a partir do nó atual. O predicado \\+ (NOT) `member(Proximo, Visitados)` é usado para garantir que o próximo nó ainda não foi visitado.  
    Depois de verificar que `Proximo` é um nó que ainda não foi visitado, a distância acumulada até o próximo nó é calculada com `NovaDistancia is DistanciaAcumulada + Distancia`.  
    Com o próximo nó e a nova distância calculados, o predicado `busca_profundidade` faz uma chamada recursiva:  
    ```
    busca_profundidade(Proximo, Destino, [Proximo|Visitados], CaminhoFinal, NovaDistancia, DistanciaTotal). 
    ```
    Nessa nova chamada, o nó `Proximo` se torna o novo nó `Atual`, e a lista de `Visitados` é atualizada para incluir `Proximo` no início da lista. A recursão continua até que que o destino seja alcançado, atingindo o caso base, onde o mecanismo de parada é acionado e o caminho completo e a distância total são calculados e retornados.  
    Esse processo é repetido para cada nó conectado, permitindo explorar todas as possíveis rotas do nó inicial até o nó de destino. Quando todos os caminhos forem encontrados, o programa irá escolher o melhor caminho com base no critério de menor distância.  

A lógica para calcular o menor caminho é definida no predicado `menor_caminho`, responsável por encntrar o caminho com a menor distância em uma lista de caminho possíveis.
```
menor_caminho([CaminhoDistancia], CaminhoDistancia).
menor_caminho([(Caminho1, Distancia1), (Caminho2, Distancia2) | T], Menor) :-
    (Distancia1 =< Distancia2 ->
        menor_caminho([(Caminho1, Distancia1) | T], Menor)
    ;   menor_caminho([(Caminho2, Distancia2) | T], Menor)
    ).
```
Usamos a recursão para comparar as distâncias dos caminhos na lista e identificar aquele que possui a menor distância.

````
menor_caminho([CaminhoDistancia], CaminhoDistancia).
````
Aqui, o predicado recebe uma lista contendo apenas um elemento, `CaminhoDistancia`, que representa o único caminho disponível junto com sua distância (como só tem um caminho na lista, então ele será o menor caminho, então ele simplemente retorna esse caminho e sua distância como resultado).  
A recurssão começa aqui:
````
menor_caminho([(Caminho1, Distancia1), (Caminho2, Distancia2) | T], Menor) :-
    (Distancia1 =< Distancia2 ->
        menor_caminho([(Caminho1, Distancia1) | T], Menor)
    ;   menor_caminho([(Caminho2, Distancia2) | T], Menor)
    ).
````

Aqui, o predicado recebe uma lista de caminhos que representa dois caminhos diferentes com o objetivo de compará-los `(Caminho1, Distancia1), (Caminho2, Distancia2)`. T é a cauda da lista (todo o resto da lista) que será usada para percorrer a lista recursivamente.  
Ele compara `Distancia1` e `Distancia2`. Se `Distancia1` <= `Distancia2`, então o caminho `(Caminho1, Distancia1)` é considerado o menor entre os dois, pelo menos até esse ponto.  

Dependendo do resultado da comparação, se:  
-  `Distancia1` <= `Distancia2`, o predicado faz uma chamada recursiva de `menor_caminho` com `(Caminho1, Distancia1)` na frente da lista com a cauda.
-   Caso contrário, ele faz a chamada recursiva com `(Caminho2, Distancia2)`.  

O processo continua até que a lista seja reduzida a um único elemento (caso base). O caminho com a menor distância entre todos os comparados será retornado como resultado.  

Com isso, finalmente chegamos no predicado principal `encontrar_caminho`. Ele tem três partes principais: busca de todos os caminhos, verificação de caminhos encontrados, e exibição do resultado. 

```
encontrar_caminho(Inicio, Destino) :-
    buscar_todos_caminhos(Inicio, Destino, Caminhos),
    (Caminhos \= [] ->
        menor_caminho(Caminhos, (MenorCaminho, MenorDistancia)),
        write('Menor caminho: '), write(MenorCaminho), nl,
        write('Distancia total: '), write(MenorDistancia), write(' km'), nl
    ;   write('Nenhum caminho encontrado.'), nl).
```
Como já vimos anteriormente, o predicado `buscar_todos_caminhos(Inicio, Destino, Caminhos)` é chamado para encontrar todos os caminhos possíveis entre o nó de origem e o nó de destino e os armazena na lista `Caminhos`.  

Após obter a lista de todos os caminhos (Caminhos), o próximo passo é verificar se algum caminho foi encontrado.

```
(Caminhos \= [] ->
        menor_caminho(Caminhos, (MenorCaminho, MenorDistancia)),
        write('Menor caminho: '), write(MenorCaminho), nl,
        write('Distancia total: '), write(MenorDistancia), write(' km'), nl
    ;   write('Nenhum caminho encontrado.'), nl).
```

`Caminhos \= [] ->` pode ser lido como "se a lista de caminhos não for vazia, então execute o seguinte bloco de código, caso contrário, execute o bloco de código após o ponto e vírgula".  
Se a lista não for vazia, então obviamente existe pelo menos um caminho do nó de origem para o nó destino, então irá executar:
```
menor_caminho(Caminhos, (MenorCaminho, MenorDistancia)),
```
comparando todos os caminhos da lista `Caminhos` e suas distâncias totais. 
   
Mas, se a lista for vazia, então apenas irá mostrar na tela a mensagem que nenhum caminho foi encontrado.

