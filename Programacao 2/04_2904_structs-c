#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Posicao
{
    int x;
    int y;
    int z;
};
struct Dados
{
    int somaX;
    int multiplicacaoY;
};

struct Dados handleDados(struct Posicao *diagonalPrincipal)
{
    struct Dados dados;
    dados.somaX = diagonalPrincipal[0].x + diagonalPrincipal[1].x;
    dados.multiplicacaoY = diagonalPrincipal[0].y * diagonalPrincipal[1].y;
    return dados;
}

void main()
{
    // matrix 2x2
    struct Posicao **matrix;
    int ordem = 2*2;
    matrix = malloc(ordem * sizeof(struct Posicao**)); // inicializa a matriz com 2 linhas
    int i = 0;
    for (i = 0; i < ordem; i++)
    {
        matrix[i] = malloc(ordem * sizeof(struct Posicao)); // inicializa as colunas
        int j = 0;
        for (j = 0; j< ordem; j++)
        {
            printf("Insira os valores para matrix[%d][%d]\n", i, j);
            printf("x: ");
            scanf("%d", &matrix[i][j].x);
            printf("y: ");
            scanf("%d", &matrix[i][j].y);
            printf("z: ");
            scanf("%d", &matrix[i][j].z);
        }
    }
    struct Posicao *diagonalPrincipal;
    diagonalPrincipal = malloc(ordem * sizeof(struct Posicao));
    for (i = 0; i < ordem; i++)
    {
        diagonalPrincipal[i] = matrix[i][i];
    }

    struct Dados dados = handleDados(diagonalPrincipal);
    
    for (i = 0; i < 2; i++)
    {
        printf("matrix[%d][0] = (%d, %d, %d)\n", i, matrix[i][0].x, matrix[i][0].y, matrix[i][0].z);
        printf("matrix[%d][1] = (%d, %d, %d)\n", i, matrix[i][1].x, matrix[i][1].y, matrix[i][1].z);
    }
    free(matrix);
}