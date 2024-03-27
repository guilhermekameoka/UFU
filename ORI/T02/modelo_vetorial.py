import spacy
import sys
import math

nlp = spacy.load("pt_core_news_lg")


def cria_indice_invertido(caminhos_arquivos):
    """
    Constrói um índice invertido a partir de uma lista contendo os caminhos para outros arquivos de texto
    e retorna um dicionário de termos com suas frequências em cada documento.
    Cada chave é um termo e seu valor é um dicionário no qual a chave é o número do documento e o valor é a
    frequência do termo no documento correspondente.
    """

    indice_invertido = {}

    # Para cada arquivo de texto na lista de caminhos
    for qtd, caminho_arquivo in enumerate(caminhos_arquivos, start=1):
        # Abre o arquivo de texto
        with open(caminho_arquivo, "r", encoding="utf-8") as file:
            # Le o texto do arquivo
            texto = file.read()
            # Processa o texto com o modelo linguístico SpaCy
            doc = nlp(texto)

            # Para cada token no modelo linguístico SpaCy
            for token in doc:
                # Se o token não for uma stopword e for uma palavra (letra) em português
                if not token.is_stop and token.is_alpha:
                    # Obtém a forma normalizada do termo
                    termo = token.lemma_.lower()

                    # Se o termo ainda não estiver no índice invertido
                    if termo not in indice_invertido:
                        # Cria um novo dicionário para o termo e adiciona o número
                        # do documento como chave e 1 como valor
                        indice_invertido[termo] = {qtd: 1}
                    else:
                        # Se o termo já estiver no índice invertido
                        if qtd not in indice_invertido[termo]:
                            # Adiciona o número do documento como chave e 1 como valor
                            indice_invertido[termo][qtd] = 1
                        else:
                            # Se o número do documento já estiver na frequência do termo
                            # no índice invertido, então incrementa seu valor em 1
                            indice_invertido[termo][qtd] += 1

    return indice_invertido


def escreve_indice_invertido(indice_invertido):
    """
    Escreve o índice invertido em um arquivo de texto chamado "indice.txt". O arquivo de texto terá a seguinte estrutura:
    termo: número do documento, frequência do termo no documento correspondente
    """

    with open("indice.txt", "w", encoding="utf-8") as file:
        for termo, frequencia in indice_invertido.items():
            file.write(
                f"{termo}: {', '.join([f'{doc},{freq}' for doc, freq in frequencia.items()])}\n"
            )


def calcula_pesos(documentos, indice_invertido):
    """
    Calcula os pesos TF-IDF para cada termo do índice invertido e escreve os resultados em um arquivo chamado "pesos.txt".
    Retorna um dicionário com os pesos calculados para cada termo.
    """

    # Calcula o número total de documentos na coleção
    N = len(documentos)

    # Dicionário para armazenar os pesos calculados para cada termo
    pesos = {}

    # Abre o arquivo para escrever os resultados
    with open("pesos.txt", "w", encoding="utf-8") as file:
        # Para cada termo no índice invertido
        for termo, documentos_com_termo in indice_invertido.items():
            # Calcula o número de documentos que contêm o termo
            ni = len(documentos_com_termo)

            # Para cada documento que contém o termo
            for doc, tf in documentos_com_termo.items():
                # Calcula o TF-IDF
                tfidf = (1 + math.log(tf, 10)) * math.log(N / ni)

                # Adiciona o TF-IDF ao dicionário de pesos
                if termo not in pesos:
                    pesos[termo] = {}
                pesos[termo][doc] = tfidf

                # Escreve o resultado no arquivo
                file.write(f"doc{doc}: {termo}, {tfidf:.4f}\n")

    return pesos


def busca(consulta, indice_invertido):
    """
    Realiza a busca dos documentos que contêm os termos da consulta e calcula a similaridade entre a consulta e cada documento.
    A similaridade é calculada somando os pesos dos termos que aparecem tanto na consulta quanto no documento.
    """

    # Processa a consulta com o modelo linguístico SpaCy
    consulta = " ".join(consulta)  # Convertendo a lista de palavras em uma única string
    doc = nlp(consulta)

    # Obtém os termos normalizados da consulta
    termos_consulta = [
        token.lemma_.lower() for token in doc if not token.is_stop and token.is_alpha
    ]

    # Inicializa um dicionário para armazenar a similaridade entre a consulta e cada documento
    similaridade = {}

    # Para cada termo na consulta
    for termo in termos_consulta:
        # Se o termo estiver no índice invertido
        if termo in indice_invertido:
            # Obtém os documentos que contêm o termo e as frequências desses termos
            documentos_com_termo = indice_invertido[termo]

            # Para cada documento que contém o termo
            for doc, freq in documentos_com_termo.items():
                # Calcula o peso do termo na consulta
                peso_termo_consulta = 1 + math.log(freq, 10)

                # Se o documento ainda não estiver no dicionário de similaridade, adiciona-o com o peso do termo
                if doc not in similaridade:
                    similaridade[doc] = peso_termo_consulta
                else:
                    # Se o documento já estiver no dicionário de similaridade, adiciona o peso do termo à similaridade existente
                    similaridade[doc] += peso_termo_consulta

    # Retorna os documentos que têm similaridade maior ou igual a 0.001
    return {doc: sim for doc, sim in similaridade.items() if sim >= 0.001}


def resposta_consulta(consulta, indice_invertido):
    """
    Gera uma resposta da consulta, escrevendo em um arquivo chamado "resposta.txt". O arquivo de resposta terá a seguinte estrutura:
    número de documentos relevantes
    documento relevante 1: similaridade
    documento relevante 2: similaridade
    ...
    etc.
    """

    # Busca os documentos relevantes com base na consulta e o índice invertido
    docs_relevantes = (
        (doc, sim)
        for doc, sim in busca(consulta, indice_invertido).items()
        if sim >= 0.001
    )

    # Ordena os documentos relevantes por similaridade em ordem decrescente
    docs_relevantes = sorted(docs_relevantes, key=lambda x: x[1], reverse=True)

    # Escreve a resposta no arquivo de resposta
    with open("resposta.txt", "w") as resp:
        resp.write(f"{len(docs_relevantes)}\n")
        for doc, sim in docs_relevantes:
            resp.write(f"doc{doc}.txt {sim:.4f}\n")


def main():
    # Verifica se o usuário passou os dois argumentos necessários (nome da base e nome do arquivo de consulta)
    if len(sys.argv) != 3:
        # Se não for o caso, exibe uma mensagem de erro
        print(
            "Use o comando: python3 modelo_vetorial.py <nome_da_sua_base>.txt <nome_arquivo_consulta>.txt"
        )
        return

    # Obtém os nomes dos arquivos passados como argumentos
    base = sys.argv[1]
    consulta = sys.argv[2]

    # Tenta abrir o arquivo de base (que contém os caminhos dos documentos)
    try:
        with open(base) as arquivo:
            # Lê o conteúdo do arquivo em uma lista, removendo o caractere de quebra de linha ao fim de cada linha
            caminhos_arquivos = [line.rstrip() for line in arquivo]
    except FileNotFoundError:
        # Se não for possível abrir o arquivo, exibe uma mensagem de erro e sai do programa
        print(f"Não foi possível abrir o arquivo '{base}'")
        return

    # Tenta abrir o arquivo de consulta (que contém a(s) palavra(s) que o usuário está procurando)
    try:
        with open(consulta) as arquivo:
            # Lê o conteúdo do arquivo em uma lista, removendo o caractere de quebra de linha ao fim de cada linha
            consulta = [line.rstrip() for line in arquivo]
    except FileNotFoundError:
        # Se não for possível abrir o arquivo, exibe uma mensagem de erro e sai do programa
        print(f"Não foi possível abrir o arquivo '{consulta}'")
        return

    # Cria o índice invertido a partir da lista de caminhos dos documentos
    indice_invertido = cria_indice_invertido(caminhos_arquivos)

    # Escreve o índice invertido em um arquivo chamado "indice_invertido.txt"
    escreve_indice_invertido(indice_invertido)

    # Calcula os pesos de cada documento com base no índice invertido
    calcula_pesos(caminhos_arquivos, indice_invertido)

    # Busca os documentos relevantes com base na consulta e o índice invertido
    resposta_consulta(consulta, indice_invertido)


if __name__ == "__main__":
    main()