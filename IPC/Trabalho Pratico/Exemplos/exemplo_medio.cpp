#include <stdio.h>

struct aluno{
	char nome[30];
	char matricula[30];
	int idade;
};

void cadastra(struct aluno *X, struct aluno Y){
	scanf("%s", X->nome);
	scanf("%s", X->matricula);
	scanf("%d", &X->idade);

	scanf("%s", Y.nome);
	scanf("%s", Y.matricula);
	scanf("%d", &Y.idade);
}

int main(){
	struct aluno A, B;

	cadastra(&A, B);

	printf("nome: %s\n", A.nome);
	printf("nome: %s\n", A.matricula);
	printf("idade: %d\n", A.idade);


   // os printf abaixo darão erro, pois, não foi levado o ponteiro (endereço) da estrutura B para a função cadastra.
   // com isso, os valores digitados para a estrutura B não foram armazenados na posição correta da memória
	printf("nome: %s\n", B.nome);
	printf("nome: %s\n", B.matricula);
	printf("idade: %d\n", B.idade);
}

