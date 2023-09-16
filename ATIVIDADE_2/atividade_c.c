#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reordenarpalavras(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void consertarvertor(char *palavras[], int size, int *trocar, int *comparisons) {
    for (int i = 0; i < size - 1; i++) {
        for (int k = 0; k < size - i - 1; k++) {
            (*comparisons)++;
            if (strcmp(palavras[k], palavras[k + 1]) > 0) {
                (*trocar)++;
                reordenarpalavras(&palavras[k], &palavras[k + 1]);
            }
        }
    }
}

int main() {
    char *palavras[] = {"arroz", "carro", "lebre", "tijolo", "albino"};

    int size = sizeof(palavras) / sizeof(palavras[0]);
    int trocar = 0;
    int comparisons = 0;

    consertarvertor(palavras, size, &trocar, &comparisons);

    char *mediana;
    if (size % 2 == 0) {
        mediana = palavras[size / 2 - 1];
    } else {
        mediana = palavras[size / 2];
    }

    printf("Vetor organizado:\n");
    for (int i = 0; i < size; i++) {
        printf("(%d) %s\n", i + 1, palavras[i]);
    }

    printf("Número de mudanças: %d\n", trocar);
    printf("Número de comparações: %d\n", comparisons);

    printf("Media de tudo: %s\n", mediana);

    FILE *arquivo;
    arquivo = fopen("final.txt", "w");

    fprintf(arquivo, "Número de mudanças: %d\n", trocar);
    fprintf(arquivo, "Número de comparações: %d\n", comparisons);
    fprintf(arquivo, "Vetor ordenado:\n");
    for (int i = 0; i < size; i++) {
        fprintf(arquivo, "(%d) %s\n", i + 1, palavras[i]);
    }
    fprintf(arquivo, "Media de tudo: %s\n", mediana);

    fclose(arquivo);

    return 0;
}
