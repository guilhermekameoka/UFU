#include <stdio.h>

int main()
{

    float massa, altura, imc;

    printf("Digite sua massa em Kg: ");
    scanf("%f", &massa);

    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);

    imc = massa / (altura * altura);

    if (imc < 18.5)
    {
        printf("Sua classificacao eh: Magreza");
    }
    else if (imc > 18.5 && imc <= 24.9)
    {
        printf("Sua classificacao eh: Saudavel");
    }
    else if (imc >= 25.0 && imc <= 29.9)
    {
        printf("Sua classificacao eh: Sobrepeso");
    }
    else if (imc >= 30.0 && imc <= 34.9)
    {
        printf("Sua classificacao eh: Obesidade Grau I");
    }
    else if (imc >= 35.0 && imc <= 39.9)
    {
        printf("Sua classificacao eh: Obesidade Grau II (severa)");
    }
    else
    {
        printf("Sua classificacao eh: Obesidade Grau III (morbida)");
    }
}