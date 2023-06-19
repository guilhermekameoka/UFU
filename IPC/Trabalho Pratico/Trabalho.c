#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct
{
   char nome_professor[50];
   char nome_disciplina[50];
   char codigo_disciplina[50];
} Struct_professor_disciplina;
 
typedef FILE * Arq_professor_disciplina;
 
void cadastro_professor_disciplina(Struct_professor_disciplina professor_disciplina, FILE *arquivo_professor_disciplina)
{
    char nome_professor[50];
    char nome_disciplina[50];
    char codigo_disciplina[15];
 
    printf("\n Digite o nome do professor: ");
    scanf("%s", nome_professor);
    strcpy(professor_disciplina.nome_professor, nome_professor);
 
    printf("\n Digite o nome da disciplina: ");
    scanf("%s", nome_disciplina);
    strcpy(professor_disciplina.nome_disciplina, nome_disciplina);
 
    printf("\n Digite o codigo da disciplina: ");
    scanf("%s", codigo_disciplina);
    strcpy(professor_disciplina.codigo_disciplina, codigo_disciplina);
 
    arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat","ab");
 
    fwrite(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
    printf("\n\n Cadastro realizado com sucesso!\n\n");
 
    fclose(arquivo_professor_disciplina);
    getch();
}
 
void leitura_geral(FILE *arquivo_professor_disciplina)
{
  Struct_professor_disciplina professor_disciplina;
 
  arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat","rb");
 
  if (arquivo_professor_disciplina == NULL)
  {
      system("cls");
      printf("Arquivo nao encontrado!");
      getch();
      system("cls");
      return;
  }
 
  fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
    while(! feof(arquivo_professor_disciplina))
    {
      printf("Professor: %s\n", professor_disciplina.nome_professor);
      printf("Disciplina: %s\n", professor_disciplina.nome_disciplina);
      printf("Codigo: %s\n\n", professor_disciplina.codigo_disciplina);
 
      fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
    }
    fclose(arquivo_professor_disciplina);
    getch();
}
 
void busca_professor(char professor_nome[], FILE *arquivo_professor_disciplina)
{
    Struct_professor_disciplina professor_disciplina;
 
    arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat","rb");
    if (arquivo_professor_disciplina == NULL)
    {
        printf("\nArquivo nao encontrado!");
    }
    else
    {
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
        while(! feof(arquivo_professor_disciplina))
        {
            if (strcmp(professor_disciplina.nome_professor, professor_nome) == 0)
            {
                printf("\nProfessor <%s> encontrado em nossa base de dados!", professor_nome);
                return;
            }
            fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
        }
        printf("\nProfessor <%s> nao encontrado!", professor_nome);
    }
    fclose(arquivo_professor_disciplina);
    getch();
}
 
void busca_disciplina(char nome_disciplina[], FILE *arquivo_professor_disciplina)
{
    Struct_professor_disciplina professor_disciplina;
 
    arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat", "rb");
    if (arquivo_professor_disciplina == NULL)
    {
        system("cls");
        printf("\n\nArquivo nao encontrado!");
    }
    else
    {
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
        while(! feof(arquivo_professor_disciplina))
        {
            if (strcmp(professor_disciplina.nome_disciplina, nome_disciplina) == 0)
            {
                printf("\nDisciplina <%s> encontrada em nossa base de dados!", nome_disciplina);
                return;
            }
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
        }
        system("cls");
        printf("Disciplina <%s> nao encontrada!", nome_disciplina);
 
    }
    fclose(arquivo_professor_disciplina);
    getch();
}
 
void busca_codigo_disciplina(char codigo_disciplina[], FILE *arquivo_professor_disciplina)
{
    Struct_professor_disciplina professor_disciplina;
 
    arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat", "rb");
    if (arquivo_professor_disciplina == NULL)
    {
        printf("\n\nArquivo nao encontrado!");
    }
    else
    {
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
        while(! feof(arquivo_professor_disciplina))
        {
            if (strcmp(professor_disciplina.codigo_disciplina, codigo_disciplina) == 0)
            {
                printf("\nCodigo de disciplina <%s> encontrada em nossa base de dados!", codigo_disciplina);
                return;
            }
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
        }
        system("cls");
        printf("Codigo <%s> nao encontrado!", codigo_disciplina);
 
    }
    fclose(arquivo_professor_disciplina);
    getch();
}
 
void busca_disciplina_atribuida_professores(char nome_disciplina[], FILE *arquivo_professor_disciplina)
{
    Struct_professor_disciplina professor_disciplina;
 
    arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat","rb");
    if (arquivo_professor_disciplina == NULL)
    {
        printf("\nArquivo nao encontrado!");
    }
    else
    {
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
        while(! feof(arquivo_professor_disciplina))
        {
            if (strcmp(professor_disciplina.nome_disciplina, nome_disciplina) == 0)
            {
                printf("\nProfessor: %s ", professor_disciplina.nome_professor);
                printf("\nCodigo: %s\n\n", professor_disciplina.codigo_disciplina);
            }
            fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
        }
    }
    fclose(arquivo_professor_disciplina);
    getch();
}

void busca_professor_atribuido_a_disciplina (char nome_professor[], FILE *arquivo_professor_disciplina)
{
    Struct_professor_disciplina professor_disciplina;
 
    arquivo_professor_disciplina = fopen("sistemasdeinformacao.dat","rb");
    if (arquivo_professor_disciplina == NULL)
    {
        printf("\nArquivo nao encontrado!");
    }
    else
    {
         fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
 
        while(! feof(arquivo_professor_disciplina))
        {
            if (strcmp(professor_disciplina.nome_professor, nome_professor) == 0)
            {
                printf("\nDisciplina: %s ", professor_disciplina.nome_disciplina);
                printf("\nCodigo: %s\n\n", professor_disciplina.codigo_disciplina);
            }
            fread(&professor_disciplina, sizeof(Struct_professor_disciplina), 1, arquivo_professor_disciplina);
        }
    }
    fclose(arquivo_professor_disciplina);
    getch();
}
 
void excluir()
{
    remove("sistemasdeinformacao.dat");
    system("cls");
    printf("\nArquivo excluido com sucesso!");
    getch();
}
 
void menu()
{
    int opcao;
    char busca_professor_arquivo[50];
    char busca_disciplina_arquivo[15];
    char busca_codigo_disciplina_arquivo[15];
 
    Struct_professor_disciplina professor_disciplina;
    Arq_professor_disciplina arquivo_professor_disciplina;
 
    while(1)
    {
        printf("\nBem vindo ao Sistema de distribuicao de disciplinas para professores da UFU.\n");
        printf("\nSelecione uma das opcoes:\n");
        printf("\n1- Atribuir disciplina para um professor.");
        printf("\n2- Leitura de cadastros.");
        printf("\n3- Buscar por professor.");
        printf("\n4- Buscar por disciplina.");
        printf("\n5- Buscar por codigo de disciplina.");
        printf("\n6- Buscar professores atribuidos por disciplina.");
        printf("\n7- Buscar disciplinas atribuidas por professor");
        printf("\n8- Excluir data.");
        printf("\n9- Sair.\n ");
        printf("\nDigite opcao: ");
        scanf("%d", &opcao);
 
        if(opcao == 1)
        {
            system("cls");
            cadastro_professor_disciplina(professor_disciplina, arquivo_professor_disciplina);
            system("cls");
        }
        if(opcao == 2)
        { 
            system("cls");
            leitura_geral(arquivo_professor_disciplina);
            system("cls");
        }
        if(opcao == 3)
        {   system("cls");
            printf("Digite o nome do professor a ser buscado: ");
            scanf("%s", &busca_professor_arquivo);
            busca_professor(busca_professor_arquivo, arquivo_professor_disciplina);
            getch();
            system("cls");
        }
        if(opcao == 4)
        {
            system("cls");
            printf("Digite o nome da disciplina a ser buscada: ");
            scanf("%s", &busca_disciplina_arquivo);
            busca_disciplina(busca_disciplina_arquivo, arquivo_professor_disciplina);
            getch();
            system("cls");
        }   
        if(opcao == 5)
        {
            system("cls");
            printf("Digite o codigo da disciplina a ser buscado: ");
            scanf("%s", &busca_codigo_disciplina_arquivo);
            busca_codigo_disciplina(busca_codigo_disciplina_arquivo, arquivo_professor_disciplina);
            getch();
            system("cls");
        }
        if(opcao == 6)
        {
            system("cls");
            printf("\nDescobrir os professores atribuidos por disciplina:\n");
            printf("Digite o nome da disciplina a ser buscada: ");
            scanf("%s", &busca_codigo_disciplina_arquivo);
            busca_disciplina_atribuida_professores(busca_codigo_disciplina_arquivo, arquivo_professor_disciplina);
            system("cls");
        }
        if(opcao == 7)
        {
            system("cls");
            printf("\nDescobrir disciplinas atribuidas por professor\n");
            printf("Digite o nome do professor a ser buscado: ");
            scanf("%s", &busca_codigo_disciplina_arquivo);
            busca_professor_atribuido_a_disciplina(busca_codigo_disciplina_arquivo, arquivo_professor_disciplina);
            system("cls");

        }

        if(opcao == 8)
        {
            excluir();
        }
        if(opcao == 9) return;
    }
}
 
int main()
{
    menu();
}