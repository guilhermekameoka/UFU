/*
Faça um programa que seja semelhante ao jogo de forca, mas com uma única letra. A letra que o 
usuário deve adivinhar deve ser definida no código do programa. O usuário tem 5 chances de acertar 
a letra. O programa finaliza sua execução quando o usuário acerta a letra ou quando acabam suas 
chances

Exemplo de saída:
<<Forca de uma letra só>>
Qual a letra? o
Errado! Você tem mais 4 chances
Qual a letra? d
Errado! Você tem mais 3 chances
Qual a letra? w
Errado! Você tem mais 2 chances
Qual a letra? q
ACERTOU!

Exemplo de saída 2:
<<Forca de uma letra só>>
Qual a letra? d
Errado! Você tem mais 4 chances
Qual a letra? g
Errado! Você tem mais 3 chances
Qual a letra? k
Errado! Você tem mais 2 chances
Qual a letra? r
Última chance!!!
Qual a letra? o
Acabaram suas chances. A letra correta é 'q'
*/

#include <stdio.h>

int main()
{
    char letra, resposta='q';
    int chances;

    printf("<<Forca de uma Letra so>>\n");

    for (chances = 4; chances >= 0; chances--)
    {
        printf("Qual a Letra?: ");
        setbuf(stdin, NULL);
        scanf("%c", &letra);

        if (letra == resposta)
        {
            printf("ACERTOU!");
            break;
        }
        if ((letra != resposta) && (chances > 0))
        {
            printf("Errado! Voce tem mais %d chances.\n", chances);
        }
        if (chances == 1)
        {
            printf("Ultima chance!!!\n");
        }
    }
    if (chances < 0)
    {
        printf("Acabaram suas chances. A letra correta e '%c'", resposta);
    }

}