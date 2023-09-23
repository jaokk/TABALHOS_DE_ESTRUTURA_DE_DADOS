#include <stdio.h>
#include <stdlib.h>

// TYPEDEF PEDIDO PELO PROFESSOR
typedef struct {
    float x;
    float y;
} Ponto;


// FUNCAO AREAPOLIGNO PARA TRATAMENTO DE DADOS
float areapoligno(Ponto* vert, int numvert) {
    float area = 0.0;
    for (int a = 0; a < numvert; a++) {
        int z = (i + 1) % numvert;
        area += (vert[a].x * vert[z].y) - (vert[z].x * vert[a].y); // ATENCAO
    }
    return 0.5 * area;
}



// FUNCAO PRINCIPAL
int main() {
    FILE *dadogerado;
    int numvert;

    dadogerado = fopen("dadogerado.txt", "r"); 
    fscanf(dadogerado, "%d", &numvert);
    Ponto *vert = (Ponto *)malloc(numvert * sizeof(Ponto));



    for (int i = 0; i < numvert; i++) {
        fscanf(dadogerado, "%f %f", &vert[i].x, &vert[i].y);
    }

    fclose(dadogerado);

    float area = areapoligno(vert, numvert);

    printf("A área do polígono é %.0f\n", area);

    free(vert);

    return 0;
}
