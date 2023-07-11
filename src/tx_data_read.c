#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int *vetor;

    fp = fopen("arquivo.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    vetor = (int *)malloc(sizeof(int));

    while ((ch = fgetc(fp)) != EOF)
    {
        vetor[i] = ch & 3;
        i++;
        vetor = (int *)realloc(vetor, (i + 1) * sizeof(int));
        vetor[i] = (ch >> 2) & 3;
        i++;
        vetor = (int *)realloc(vetor, (i + 1) * sizeof(int));
        vetor[i] = (ch >> 4) & 3;
        i++;
        vetor = (int *)realloc(vetor, (i + 1) * sizeof(int));
        vetor[i] = (ch >> 6) & 3;
        i++;
        vetor = (int *)realloc(vetor, (i + 1) * sizeof(int));
    }

    fclose(fp);

    for (j = 0; j < i; j++)
    {
        printf("%d ", vetor[j]);
    }

    free(vetor);

    return 0;
}
