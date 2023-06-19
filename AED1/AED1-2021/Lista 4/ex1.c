/*
1) Faça um algoritmo utilizando o comando while que mostra uma contagem regressiva na tela, 
iniciando em 10 e terminando em 0. Mostrar uma mensagem “FIM!” após a contagem. 

Exemplo de saída:
<< Contagem regressiva >>
10.. 9.. 8.. 7.. 6.. 5.. 4.. 3.. 2.. 1.. 0.. FIM!
*/

#include <stdio.h>

int main()
{

    int contagem;

    printf("<< Contagem regressiva >>\n");
    contagem = 10;

    while (contagem >= 0)
    {

        printf("%d..", contagem);
        contagem--;
    }

    printf("FIM!");
}
