import spacy
import sys

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
        with open(caminho_arquivo, 'r', encoding='utf-8') as file:
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
    
    with open('indice.txt', 'w', encoding='utf-8') as file:
        for termo, frequencia in indice_invertido.items():
            file.write(f"{termo}: {', '.join([f'{doc},{freq}' for doc, freq in frequencia.items()])}\n")
            
def main():
    """
    Verifica se o número de argumentos passados na linha de comando é igual a 2. Caso contrário, exibe uma mensagem de uso.
    Caso o número de argumentos seja igual a 2, obtém o nome do arquivo de base na posição 1 dos argumentos passados na linha de comando (sys.argv[1])
    e tenta abrir o arquivo. Caso não consiga abrir o arquivo, exibe uma mensagem de erro.
    Caso consiga abrir o arquivo, obtém todas as linhas do arquivo, removendo eventuais quebras de linha e espaços em branco à direita (rstrip()).
    Cada linha do arquivo deve conter o nome de um arquivo de texto que será utilizado para construir o índice invertido.
    Por fim, constroi o índice invertido utilizando a função cria_indice_invertido() passando como argumento a lista de nomes de arquivos de texto gerada acima 
    e chama a função escreve_indice_invertido() para escrever o índice invertido em um arquivo de texto chamado "indice.txt".
    """
    
    if len(sys.argv) != 2:
        print("Use o comando: python3 indice.py <nome_da_sua_base>.txt")
        return

    base = sys.argv[1]
    
    try:
        with open(base, 'r') as arquivo:
            caminhos_arquivos = [line.strip().rstrip() for line in arquivo]
    except FileNotFoundError:
        print(f"Não foi possível abrir o arquivo '{base}'")
        return

    indice_invertido = cria_indice_invertido(caminhos_arquivos)
    escreve_indice_invertido(indice_invertido)

if __name__ == "__main__":
    main()