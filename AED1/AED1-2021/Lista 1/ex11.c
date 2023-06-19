/*Faça um programa que faça operações simples de números complexos:
•Crie e leia dois números complexos z e w, compostos por parte real e parte imaginária.
•Apresente a soma, subtração e produto entre z e w, nessa ordem, bem como o módulo de ambos.
•Obs: faça #include <math.h> e use a função sqrt() para calcular a raiz de um número

<<Numero complexo>>
Informe a parte real de z: 2
Informe a parte imaginária de z:3
Informe a parte real de w: 5
Informe a parte imaginária de w:2
z + w =  7.0 + 5.0i
z - w = -3.0 + 1.0i
z * w = 4.0+19i
|z| = 3.6056 
|w| = 5.3852 */

#include <stdio.h>
#include <math.h>

int main(){

    float z, w, zi, wi, multzw1, multzw2;

    printf("<<Numero complexo>>\n");

    printf("Informe a parte real de z: ");
    scanf("%f",&z);

    printf("Informe a parte imaginaria de z: ");
    scanf("%f",&zi);

    printf("Informe a parte real de w: ");
    scanf("%f",&w);

    printf("Informe a parte imaginaria de w: ");
    scanf("%f",&wi);

    multzw1 = (z*w - zi*wi);
    multzw2 = (z*wi + w*zi);

    printf("z + w = %.1f + %.1fi\n",z+w, zi+wi);
    printf("z - w = %.1f + %.1fi\n",z-w, zi-wi);
    printf("z * w = %.1f + %.1fi\n", multzw1, multzw2);
    printf("|z| = %.4f", sqrt(pow(z,2) + pow(zi,2)));
    printf("\n|w| = %.4f", sqrt(pow(w,2) + pow(wi,2)));
}