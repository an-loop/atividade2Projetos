#ifndef MATRIZES_H_INCLUDED
#define MATRIZES_H_INCLUDED

typedef struct{
    int real;
    int imag;
} Complexo;

Complexo **aloca_matriz(int linhas, int colunas);

int geraNum(Complexo **matriz, int linhas, int colunas);
int imprime1(Complexo **matriz1, int linhas, int colunas);
int imprime2(Complexo **matriz1, Complexo **matriz2, int linhas, int colunas);
int imprimRes(Complexo **resultado, int linhas, int colunas);

Complexo **somaMatriz(int linhas, int colunas);
Complexo **subtraMatriz(int linhas, int colunas);
Complexo **transpostaMatriz(int linhas, int colunas);
Complexo **conjugMatriz(int linhas, int colunas);
Complexo **hermitMatriz(int linhas, int colunas);
Complexo **prodEscMatriz(int linhas, int colunas);
Complexo **prodMatMatriz(int linhas, int colunas);
Complexo **todosMatriz(int linhas, int colunas);

void todosMatriz();
void calc_svd(Complexo **matriz, int linhas, int colunas);
void teste_calc_svd();
#endif // MATRIZES_H_INCLUDED
