#include <stdio.h>

int main(){
	struct aluno{
		char nome[30];
		char matricula[30];
		int idade;
	};

	struct aluno SI;

	scanf("%s", SI.nome);
	scanf("%s", SI.matricula);
	scanf("%d", &SI.idade);

	printf("nome: %s\n", SI.nome);
	printf("matricula: %s\n", SI.matricula);
	printf("idade: %d\n", SI.idade);
}

