#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>
#include "matrizes.h"

/*Função de alocação dinâmica*/
Complexo **aloca_matriz(int linhas, int colunas) {
     // Aloca memoria para o vetor de ponteiros 'matriz'
    Complexo **matriz = malloc(linhas* sizeof(Complexo*));  // Cada elemento do vetor 'matriz' será um ponteiro para uma linha da matriz
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas* sizeof(Complexo)); // Para cada linha, aloca memoria para um vetor de 'colunas' elementos do tipo Complexo
    }

    // Retorna o ponteiro para a matriz alocada
    return matriz;
}



/* Função gerar numero aleatorio */
int geraNum(Complexo **matriz, int linhas, int colunas){
    //gera numero aleatorio  para preencher a matriz
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            matriz[i][j].real = rand() % 10; // Atribui um valor aleatorio entre 0 e 9 para a parte real
            matriz[i][j].imag = rand() % 10; // Atribui um valor aleatorio entre 0 e 9 para a parte imaginaria
        }
    }
        return 0;
}

/* Função imprimir uma matriz */
int imprime1(Complexo **matriz1, int linhas, int colunas){
    //imprime na tela a primeira matriz
    printf("Operando: A=\n");
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("| %d %di |", matriz1[i][j].real, matriz1[i][j].imag);
        }
    printf("\n");
    }
            return 0;
}


/* Função imprimir duas matrizes */
int imprime2(Complexo **matriz1, Complexo **matriz2, int linhas, int colunas){
    //imprime na tela a primeira matriz
    printf("Operando: A=\n");
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("| %d %di |", matriz1[i][j].real, matriz1[i][j].imag);
        }
    printf("\n");
    }


    //imprime na tela a segunda matriz
    printf("\nOperando: B=\n");
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("| %d %di |", matriz2[i][j].real, matriz2[i][j].imag);
        }
    printf("\n");
    }
        return 0;
}


/*Imprime resultado*/
int imprimRes(Complexo **resultado,int linhas,int colunas){
    //imprime na tela o resultado da operação
    printf("\nResultado : R=\n");
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("| %d %di |", resultado[i][j].real, resultado[i][j].imag);
        }
    printf("\n");
    }
            return 0;

}

/*Função de operação soma*/

Complexo **somaMatriz(int linhas, int colunas){
    // somaMatriz recebe como parametro tipos inteiros linha e colunas
    Complexo **matriz1 = aloca_matriz(linhas, colunas);
    Complexo **matriz2 = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas,colunas);
    //gera numeros aleatorios para a matriz
    geraNum(matriz1, linhas, colunas);
    geraNum(matriz2, linhas, colunas);

    //operação soma
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matriz1[i][j].real + matriz2[i][j].real;
            resultado[i][j].imag= matriz1[i][j].imag + matriz2[i][j].imag;
        }
    }

    printf("\n======Teste da operacao soma======\n");
    imprime2(matriz1, matriz2, linhas, colunas);
    imprimRes(resultado, linhas, colunas);


    return resultado;


}


/*Função de Operação Subtração*/
Complexo **subtraMatriz(int linhas, int colunas){
    //aloca na memoria as matrizes subtração e resultado
    Complexo **matrizA = aloca_matriz(linhas, colunas);
    Complexo **matrizB = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas,colunas);
    //gera numeros aleatorios
    geraNum(matrizA, linhas, colunas);
    geraNum(matrizB, linhas, colunas);

    // operação subtração
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real = matrizA[i][j].real - matrizB[i][j].real;
            resultado[i][j].imag = matrizA[i][j].imag - matrizB[i][j].imag;
        }
    }
    //

    printf("\n======Teste da operacao subtracao======\n");
    imprime2(matrizA, matrizB, linhas, colunas);
    imprimRes(resultado, linhas, colunas);

    return resultado;

}

/*Função de Operação Transposta*/
Complexo **transpostaMatriz(int linhas, int colunas){
    // aloca na memória a matriz transposta e o resultado
    Complexo **matriztrans = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numero aleatorio para a matriz transposta
    geraNum(matriztrans, linhas, colunas);

    // realiza a operação da matriz transposta
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matriztrans[j][i].real;
            resultado[i][j].imag= matriztrans[j][i].imag;
        }
    }
    // Imprime a matriz transposta e o resultado da operação

    printf("\n======Teste da operacao transposta======\n");
    imprime1(matriztrans, linhas, colunas);
    imprimRes(resultado, linhas, colunas);

   //retorna o resultado da operação
    return resultado;
}


/*Função de operação conjugada*/

Complexo **conjugMatriz(int linhas, int colunas){
    //aloca matrizes matrizconj (matriz original) e resultado (matriz conjugada)
    Complexo **matrizconj = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numeros aleatorios para a matriz matrizconj
    geraNum(matrizconj, linhas, colunas);

    // realiza a operação da matriz conjugada
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matrizconj[i][j].real;
            resultado[i][j].imag= -matrizconj[i][j].imag;
        }
    }
    //Imprime a matriz matrizconj e o resultado da operação

    printf("\n======Teste da operacao conjugada======\n");
    imprime1(matrizconj, linhas, colunas);
    imprimRes(resultado, linhas, colunas);

 // Retorna o resultado da operação
    return resultado;
}


/* Função de operação hermitiana */
Complexo **hermitMatriz(int linhas, int colunas){
    // aloca as matrizes matrizhermit (matriz original), matriz (matriz transposta) e resultado (matriz conjugada)
    Complexo **matrizhermit = aloca_matriz(linhas, colunas);
    Complexo **matriz = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numeros aleatorios para a matriz matrizhermit
    geraNum(matrizhermit, linhas, colunas);

    // realiza a operação da matriz transposta
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            matriz[i][j].real= matrizhermit[j][i].real;
            matriz[i][j].imag= matrizhermit[j][i].imag;
        }
    }
    // realiza a operação da matriz conjugada
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matriz[i][j].real;
            resultado[i][j].imag= -matriz[i][j].imag;
        }
    }
    // imprime a matriz matrizhermit, a matriz transposta e a matriz conjugada
    //Operação Hermitiana
    printf("\n======Teste da operacao hermitiana======\n");
    //imprime matriz hermitiana
    imprime1(matrizhermit, linhas, colunas);
    printf("\nTransposta: \n");
    imprime1(matriz, linhas, colunas);
    printf("\nConjugada: ");
    imprime1(resultado, linhas, colunas);

    // Verifica se a matriz e hermitiana comparando a matriz original e a matriz conjugada
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(matrizhermit[i][j].real == resultado[i][j].real && matrizhermit[i][j].imag == resultado[i][j].imag){
                printf("\nMatriz e Hermitiana\n");
                return 0;
            } else{
                printf("\nMatriz nao e Hermitiana\n");
                return 0;
            }
        }
    }

    // Retorna a matriz resultado
    return resultado;
}


Complexo **prodEscMatriz(int linhas,int colunas){
    //aloca as matrizes matrizprod1, matrizprod2 (matrizes de entrada) e resultado (matriz resultante)
    Complexo **matriz1 = aloca_matriz(linhas, colunas);
    Complexo **matriz2 = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numeros aleatorios  para as matrizes matrizprod1 e matrizprod2
    geraNum(matriz1, linhas, colunas);
    geraNum(matriz2, linhas, colunas);

    // realiza a operação do produto escalar
    for (int i = 0; i < linhas; i++) {
        for(int j=0; j< colunas; j++){
            resultado[i][j].real = matriz1[i][j].real * matriz2[i][j].real - matriz1[i][j].imag * matriz2[i][j].imag;
            resultado[i][j].imag = matriz1[i][j].real * matriz2[i][j].imag - matriz1[i][j].imag * matriz2[i][j].real;
        }
    }


    // imprime as matrizes matrizprod1, matrizprod2 e o resultado da operação
    printf("\n======Teste da operacao produto escalar======\n");
    imprime2(matriz1, matriz2, linhas, colunas);
    imprimRes(resultado, linhas, colunas);

    // retorna o resultado da operação
    return resultado;
}


/*Função de operação produto matricial*/
Complexo **prodMatMatriz(int linhas, int colunas){
    //aloca matrizes matrizmat1, matrizmat2 (matrizes de entrada), resultado (matriz resultante) e cont (matriz auxiliar para cálculos intermediários)
    Complexo **matrizmat1 = aloca_matriz(linhas, colunas);
    Complexo **matrizmat2 = aloca_matriz(linhas, colunas);
    Complexo **cont = aloca_matriz(linhas, colunas);
    int k;
    //gera numeors aleatorios  para as matrizes matrizmat1 e matrizmat2
    geraNum(matrizmat1, linhas, colunas);
    geraNum(matrizmat2, linhas, colunas);

    //realiza a operação de produto matricial
    for (int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            for(k=0; k<colunas; k++){
                cont[i][j].real += matrizmat1[i][k].real * matrizmat2[k][j].real;
                cont[i][j].imag += matrizmat1[i][k].imag * matrizmat2[k][j].imag;
            }
        }
    }


    // imprime as matrizes matrizmat1, matrizmat2 e o resultado da operação
    printf("\n======Teste da operacao produto matricial======\n");
    imprime2(matrizmat1, matrizmat2, linhas, colunas);
    imprimRes(cont, linhas, colunas);

    // retorna o cont(resultado) da operação
    return cont;
}

void calc_svd(Complexo **matriz, int linhas, int colunas){
    int i,j;
    gsl_matrix * A = gsl_matrix_alloc(linhas, colunas);
    gsl_matrix * V = gsl_matrix_alloc(colunas, colunas);
    gsl_vector * S = gsl_vector_alloc(colunas);
    gsl_vector * work = gsl_vector_alloc(colunas);

    //checando matriz complexa
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            if(matriz[i][j].imag != 0){
                printf("\n");
                imprime1(matriz, linhas, colunas);
                printf("\n\nALerta: Essa matrix é complexa. Será realizado o cálculo utilizando apenas a parte Real da matriz!\n\n");
            } else{
                printf("\n\nEssa matriz é real!\n\n");
            }
            break;
        }
        break;
    }

    //imprime parte real da matriz
    printf("Matriz %dx%d\n", linhas, colunas);
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            gsl_matrix_set(A, i, j, matriz[i][j].real);
            printf("| %f |", gsl_matrix_get(A, i, j));
        }
        printf("\n");
    }

    //realiza o calculo SVD
    gsl_linalg_SV_decomp(A, V, S, work);

    //imprime matriz V
    printf("\n\nMatriz V\n");
    for(i=0; i<colunas; i++){
        for(j=0; j<colunas; j++){
            printf("| %f |", gsl_matrix_get(V, i, j));
        }
    printf("\n");
    }

    //imprime vetor U
    printf("\n\nMatriz U\n");
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf("| %f |", gsl_matrix_get(A, i, j));
        }
    printf("\n");
    }

    //imprime vetor S
    printf("\n\nVetor S\n");
    for(i=0; i<colunas; i++)
        printf("| %f |", gsl_vector_get(S, i));
    printf("\n\n");

}

void teste_calc_svd(){
    Complexo **matrizR;
    int linhas[4] = {3, 4, 6, 6};
    int colunas[4] = {2, 4, 5 , 5}; 
    int i, j, t;

    printf("\n======Teste da operacao SVD======\n");

    Complexo **matrizC = aloca_matriz(3, 3);
    geraNum(matrizC, 3, 3);
    calc_svd(matrizC, 3, 3);


    for(t=0; t<4; t++){
        linhas[t];
        colunas[t];

    matrizR = aloca_matriz(linhas[t], colunas[t]);
    for(int i=0; i <linhas[t]; i++){
        for(int j=0; j<colunas[t]; j++){
            matrizR[i][j].real = rand() % 10; // Atribui um valor aleatorio entre 0 e 9 para a parte real
            matrizR[i][j].imag = 0;
        }
    }
    
    calc_svd(matrizR, linhas[t], colunas[t]);

    }


}



/*Função teste todos*/
void todosMatriz(){
     // Chamando as funções de teste para cada operação
    somaMatriz(3, 3);
    subtraMatriz(3, 3);
    transpostaMatriz(3, 3);
    conjugMatriz(3, 3);
    hermitMatriz(3, 3);
    prodEscMatriz(3, 3);
    prodMatMatriz(3, 3);
    teste_calc_svd();

    
}
