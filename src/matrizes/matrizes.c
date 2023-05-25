#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

/*Função de alocação dinâmica*/
Complexo **aloca_matriz(int linhas, int colunas) {
    Complexo **matriz = malloc(linhas* sizeof(Complexo*)); // procura lugar na memoria para armazenar o vetor linhas
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas* sizeof(Complexo)); // procura lugar na memoria para armazenar o vetor colunas
    }
    return matriz;
}



/*Função gerar numero aleatorio*/
int geraNum(Complexo **matriz, int linhas, int colunas){
    //gera numero aleatorio
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            matriz[i][j].real = rand() % 10;
            matriz[i][j].imag = rand() % 10;
        }
    }
        return 0;
}

/*Função imprimir 1 operando*/
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


/*Função imprimir 2 operandos*/
int imprime2(Complexo **matriz1, Complexo **matriz2, int linhas, int colunas){
    //imprime na tela a primeira matriz
    printf("Operando: A=\n");
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("| %d %di |", matriz1[i][j].real, matriz1[i][j].imag);
        }
    printf("\n");
    }
        return 0;

    //imprime na tela a segunda matriz
    printf("\nOperando: B=\n");
    for(int i=0; i <linhas; i++){
        for(int j=0; j<colunas; j++){
            printf("| %d %di |", matriz2[i][j].real, matriz2[i][j].imag);
        }
    printf("\n");
    }
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
    //aloca na memoria as matrizes soma e resultado
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
    //aloca na memoria a matriz e a transposta
    Complexo **matriztrans = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numero aleatorio
    geraNum(matriztrans, linhas, colunas);

    //operação da matriz transposta
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matriztrans[j][i].real;
            resultado[i][j].imag= matriztrans[j][i].imag;
        }
    }
    //

    printf("\n======Teste da operacao transposta======\n");
    imprime1(matriztrans, linhas, colunas);
    imprimRes(resultado, linhas, colunas);

    return resultado;
}


/*Função de operação conjugada*/

Complexo **conjugMatriz(int linhas, int colunas){
    //aloca matrizes
    Complexo **matrizconj = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numero aleatorio
    geraNum(matrizconj, linhas, colunas);

    //operação da matriz conjugada
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matrizconj[i][j].real;
            resultado[i][j].imag= -matrizconj[i][j].imag;
        }
    }
    //

    printf("\n======Teste da operacao conjugada======\n");
    imprime1(matrizconj, linhas, colunas);
    imprimRes(resultado, linhas, colunas);


    return resultado;
}


/*Função de operação hermitiana*/
Complexo **hermitMatriz(int linhas, int colunas){
    //aloca matrizes
    Complexo **matrizhermit = aloca_matriz(linhas, colunas);
    Complexo **matriz = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numeros aleatorios
    geraNum(matrizhermit, linhas, colunas);

    //operação da matriz transposta
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            matriz[i][j].real= matrizhermit[j][i].real;
            matriz[i][j].imag= matrizhermit[j][i].imag;
        }
    }
    //operação da matriz conjugada
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real= matriz[i][j].real;
            resultado[i][j].imag= -matriz[i][j].imag;
        }
    }
    //
    //Operação Hermitiana
    printf("\n======Teste da operacao hermitiana======\n");
    //imprime matriz hermitiana
    imprime1(matrizhermit, linhas, colunas);
    printf("\nTransposta: \n");
    imprime1(matriz, linhas, colunas);
    printf("\nConjugada: ");
    imprime1(resultado, linhas, colunas);

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

     return resultado;
}


/*Função de operação produto escalar*/
Complexo **prodEscMatriz(int linhas, int colunas){
    //aloca matrizes
    Complexo **matrizprod1 = aloca_matriz(linhas, colunas);
    Complexo **matrizprod2 = aloca_matriz(linhas, colunas);
    Complexo **resultado = aloca_matriz(linhas, colunas);
    //gera numeros aleatorios
    geraNum(matrizprod1, linhas, colunas);
    geraNum(matrizprod2, linhas, colunas);

    //operação do produto escalar
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            resultado[i][j].real = 0;
            resultado[i][j].imag = 0;
            for(int k=0; k<colunas; k++){
                resultado[i][j].real = (matrizprod1[i][k].real * matrizprod2[k][j].real);
                resultado[i][j].real = (matrizprod1[i][k].real * matrizprod2[k][j].imag);
            }
        }
    }


    printf("\n======Teste da operacao produto escalar======\n");
    imprime2(matrizprod1, matrizprod2, linhas, colunas);
    imprimRes(matrizprod1, linhas, colunas);

    return resultado;
}


/*Função de operação produto matricial*/
Complexo **prodMatMatriz(int linhas, int colunas){
    //aloca matrizes
    Complexo **matrizmat1 = aloca_matriz(linhas, colunas);
    Complexo **matrizmat2 = aloca_matriz(linhas, colunas);
    Complexo **cont = aloca_matriz(linhas, colunas);
    int k;
    //gera numeors aleatorios
    geraNum(matrizmat1, linhas, colunas);
    geraNum(matrizmat2, linhas, colunas);

    //operação de produto matricial
    for (int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            for(k=0; k<colunas; k++){
                cont[i][j].real += matrizmat1[i][k].real * matrizmat2[k][j].real;
                cont[i][j].imag += matrizmat1[i][k].imag * matrizmat2[k][j].imag;
            }
        }
    }



    printf("\n======Teste da operacao produto matricial======\n");
    imprime2(matrizmat1, matrizmat2, linhas, colunas);
    imprimRes(cont, linhas, colunas);


    return cont;
}


/*Função teste todos*/
Complexo **todosMatriz(int linhas, int colunas){
    somaMatriz(linhas, colunas);
    subtraMatriz(linhas, colunas);
    transpostaMatriz(linhas, colunas);
    conjugMatriz(linhas, colunas);
    hermitMatriz(linhas, colunas);
    prodEscMatriz(linhas, colunas);
    prodMatMatriz(linhas, colunas);

    return 0;
}
