#include <stdio.h>
#include <stdlib.h>

struct cliente{
	int nro;
	int qto;
};

void cadastro(struct cliente T[]){
	for(int i=0; i<1; i++){
		printf("\nDigite o numero do quarto %d: ", i+1);
		scanf("%d", &T[i].nro);
		printf("\nDigite o numero do cliente %d: ", i+1);
		scanf("%d", &T[i].qto);
	}
}

void mostra(struct cliente T[]){
	for(int i=0; i<3; i++){
		printf("Quarto      : %d\n", T[i].nro);
		printf("Nro Cliente : %d\n", T[i].qto);
	}
}

void mostra1(struct cliente T[]){
		printf("Quarto      : %d\n", T->nro);
		printf("Nro Cliente : %d\n", T->qto);
}


void menu(){
	int opcao=0;
	struct cliente P[30];

	while(1){
		printf("\nBem vindo ao Hotel de SI! ");
		printf("\n1- Cadastrar ");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar Primeiro");
		printf("\n9- Sair ");
		printf("\nDigite opção: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 3) mostra1(&P[0]);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}

