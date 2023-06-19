typedef struct no *Polinomio;

int lista_vazia(Polinomio p);
int cria_polinomio();
int insere_termo(Polinomio *p, int a, int pot);
int elimina_termo(Polinomio *p, int numero);
void imprime_polinomio(Polinomio p);
Polinomio reinicializar_polinomio(Polinomio p);
int calcula_polinomio(Polinomio *p, int numero);