// Arquivo Ponto.h = Documentacao

typedef struct ponto Ponto;

// Funcao gera_pto()
Ponto *gera_pto(); // cria uma instância de um ponto sem valores

// Entrada: Nenhuma
// Pre-condicao: Nenhuma
// Processo: Alocacao de memoria
// Saida: Ponteiro para struct ponto
// Pos-condicao: Nenhuma


// Funcao set_pto()
int set_pto(Ponto *p, float x, float y); // atribui os valores das coordenadas x e y de um ponto

// Entrada: Ponteiro para struct ponto e valores float para x e y
// Pre-condicao: Ter alocado memoria anteriormente
// Processo: atribui valores para x e y
// Saida: 0 se a alocação falhar, caso contrario atribui valores para x e y
// Pos-condicao: Inclusao dos dados de Ponto


// Funcao get_pto()
int get_pto(Ponto *p, float *x, float *y); // retorna os valores das coordenadas x e y de um ponto

// Entrada: ponteiro para Ponto e dois ponteiros para float
// Pre-condicao: Existir valores para Ponto
// Processo: leitura dos valores do ponto
// Saida: nehuma
// Pos-condicao: nenhuma


// Funcao libera_pto()
void libera_pto(Ponto **p); // operação que elimina um ponto criado

// Entrada: endereço do endereco de um ponteiro para Ponto
// Pre-condicao: nenhuma
// Processo: liberar a memória e limpar o ponteiro
// Saida: nenhuma
// Pos-condicao: ponteiro liberado


// Funcao distancia_pto()
float distancia_pto(Ponto *p1, Ponto *p2); // calcula a distância entre dois pontos

// Entrada: 2 ponteiros para Ponto
// Pre-condicao: Existir dois pontos
// Processo: Cacula a distancia entre dois pontos
// Saida: Retorna a distancia entre os pontos
// Pos-condicao: nenhuma
