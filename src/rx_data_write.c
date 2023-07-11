#include <stdio.h>
#include <stdlib.h>

void write_binary_file(char *filename, int *input, int n) {
    FILE *fp;
    fp = fopen("arquivo.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < n; i += 4) {
        char byte = (input[i] << 6) | (input[i + 1] << 4) | (input[i + 2] << 2) | input[i + 3];
        fwrite(&byte, sizeof(char), 1, fp);
    }
    fclose(fp);
}

int main() {
    char filename[] = "arquivo.bin";
    int input[] = {0, 1, 2, 3, 0, 1, 2, 3};
    int n = sizeof(input) / sizeof(int);
    write_binary_file(filename, input, n);
    return 0;
}
