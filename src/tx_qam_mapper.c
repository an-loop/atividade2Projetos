#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void QAMmapper(int *indices, int n, double complex *output) {
    int i;
    for (i = 0; i < n; i++) {
        switch (indices[i]) {
            case 0:
                output[i] = -1 + I;
                break;
            case 1:
                output[i] = -1 - I;
                break;
            case 2:
                output[i] = 1 + I;
                break;
            case 3:
                output[i] = 1 - I;
                break;
            default:
                printf("Índice inválido.\n");
                exit(1);
        }
    }
}

int main() {
    int indices[] = {0, 1, 2, 3};
    int n = sizeof(indices) / sizeof(int);
    double complex output[n];
    QAMmapper(indices, n, output);
    int i;
    for (i = 0; i < n; i++) {
        printf("%f + %fi\n", creal(output[i]), cimag(output[i]));
    }
    return 0;
}
