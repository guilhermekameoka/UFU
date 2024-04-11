import matplotlib.pyplot as plt
import numpy as np
import sys

def calcula_precisao_revocacao(ideal, obtido):
    """
    Calcula a precisão e a revocação para os documentos de um resultado de busca.

    A precisão é calculada dividindo o número de documentos relevantes até o momento
    pelo número de documentos processados até o momento (incluindo o documento atual).
    A revocação é calculada dividindo o número de documentos relevantes até o momento
    pelo número total de documentos relevantes (tamanho do conjunto de documentos ideais).

    Os resultados são devolvidos em pares de listas: precisão e revocação.
    """
    
    precisao = []
    revocacao = []

    # Inicialmente, não há nenhum documento relevante processado.
    docs_relevantes = 0

    # Para cada documento obtido, verificamos se ele é relevante (se ele está na lista de documentos ideais). 
    # Se for relevante, atualizamos a contagem de documentos relevantes.
    for i, doc in enumerate(obtido):
        if doc in ideal:
            docs_relevantes += 1

        # Calculamos a precisão e a revocação para o documento atual.
        precisao.append(docs_relevantes / (i + 1))
        revocacao.append(docs_relevantes / len(ideal))

    return precisao, revocacao


def interpola_precisao(precisao, revocacao):
    """
    Interpola os valores de precisão para os níveis de revocação padrão (0%, 10%, 20%, ..., 90%, 100%).

    A regra de interpolação é a seguinte:
    - Cria uma lista com os níveis de revocação padrão (de 0% a 100% em incrementos de 10%).
    - Para cada nível de revocação na lista de níveis de revocação padrão, procura o índice do primeiro elemento na lista de revocações 
    (obtido pelo cálculo da precisão) que seja maior ou igual ao nível de revocação.
    - Caso encontre um índice que satisfaça essa condição, pega o valor de precisão correspondente e o adiciona à lista de precisões interpolação.
    - Caso não encontre um índice que satisfaça essa condição, adiciona à lista de precisões interpolação o valor 0.0 (a precisão é zero).
    - Retorna a lista de precisões interpolação e a lista de níveis de revocação padrão.
    """
    
    niveis_revocacao = np.arange(0, 1.1, 0.1)
    niveis_precisao = []
    for nivel_revoc in niveis_revocacao:
        # Procura o índice do primeiro elemento na lista de revocações que seja maior ou igual ao nível de revocação atual.
        try:
            # next() retorna o próximo elemento na iteração que satisfaz a condição.
            # Se não encontrar um elemento que satisfaça a condição, levanta StopIteration.
            index = next(i for i, r in enumerate(revocacao) if r >= nivel_revoc)
            # Pega o valor de precisão correspondente e adiciona à lista de precisões interpolação.
            niveis_precisao.append(max(precisao[index:]))
        # Caso não encontre um elemento que satisfaça a condição, adiciona 0.0 à lista de precisões interpolação.
        except StopIteration:
            niveis_precisao.append(0.0)
    return niveis_precisao, list(niveis_revocacao)

def plota_grafico(precisao, revocacao, consulta):
    """
    Plota um gráfico da precisão x revocação para um determinado conjunto de resultados de uma consulta.
    Os parâmetros precisão e revocação são listas que contêm os valores de precisão e revocação, respectivamente, para cada documento processado na consulta.
    O parâmetro consulta é o número da consulta que está sendo processada (para exibir na legenda do gráfico).
    """

    plt.plot(revocacao, precisao, label=f'Consulta {consulta}')
    plt.xlabel('Revocação')
    plt.ylabel('Precisão')
    plt.title('Precisão x Revocação')
    plt.legend()

def main():
    # O arquivo de referência é passado como argumento na linha de comando.
    # O programa abre o arquivo, lê suas linhas e faz a análise de precisão x revocação.
    referencia = sys.argv[1]
    with open(referencia, 'r') as f:
        # As linhas do arquivo são armazenadas em uma lista
        lines = f.readlines()

    # A primeira linha do arquivo contém o número de consultas (n_consultas)
    n_consultas = int(lines[0])

    # As próximas linhas contém as respostas esperadas de cada consulta (resposta_esperada) e as respostas obtidas pelo sistema (resposta_obtida)
    resposta_esperada = [list(map(int, line.split())) for line in lines[1:n_consultas+1]]
    resposta_obtida = [list(map(int, line.split())) for line in lines[n_consultas+1:]]

    # A precisão e a revocação são calculadas para cada consulta e armazenadas em uma lista (precisao, revocacao).
    # A lista media_precisao armazena a média dessas precisões para cada consulta.
    media_precisao = [0] * 11
    for i in range(n_consultas):
        precisao, revocacao = calcula_precisao_revocacao(resposta_esperada[i], resposta_obtida[i])
        precisao, revocacao = interpola_precisao(precisao, revocacao)
        plota_grafico(precisao, revocacao, i+1)
        media_precisao = [a + b for a, b in zip(media_precisao, precisao)]

    # A média das precisões é calculada e armazenada em uma lista
    media_precisao = [p / n_consultas for p in media_precisao]

    # Um novo gráfico é criado
    plt.figure()

    # É adicionado um único ponto no gráfico com os valores de média da precisão x revocação
    plt.plot(np.arange(0, 1.1, 0.1), media_precisao, label='Média')

    # Os rótulos dos eixos são definidos
    plt.xlabel('Revocação')
    plt.ylabel('Precisão')

    # O título do gráfico é definido
    plt.title('Média da precisão x revocação')

    # A legenda do gráfico é adicionada
    plt.legend()

    # O gráfico é exibido
    plt.show()

    # A lista de médias de precisão é escrita em um arquivo de texto
    with open('media.txt', 'w') as f:
        f.write(' '.join(map(str, media_precisao)))


if __name__ == "__main__":
    main()