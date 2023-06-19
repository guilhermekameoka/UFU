/* 
Escreva um programa que leia as coordenadas x e y de pontos no R2 
e calcule sua distância da origem (0,0).  
Obs: faça #include <math.h> e use a função sqrt() para calcular a raiz de um número

Exemplo de saída
<< Distância >>
Entre com a coordenada x: 3
Entre com a coordenada y: 4
A distância entre os pontos (3,4) e (0,0)  eh 5.0 
*/

#include<stdio.h>
#include<math.h>

int main(){

    int x,y;
    float dist;

    printf("<< Distancia >>\n");

    printf("Entre com a coordenada x: ");
    scanf("%d", &x);
    printf("Entre com a coordenada y: ");
    scanf("%d", &y);

    dist = sqrt(pow((0-x),2) + pow((0-y),2));

    printf("A distancia entre os pontos (%d,%d) e (0,0) eh %.1f", x,y,dist);
    
}