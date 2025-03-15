#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Ponto {
    int x;
    int y;
};
struct PontoEncadeado
{
    struct Ponto ponto;
    struct PontoEncadeado *anterior;
    struct PontoEncadeado *proximo;
};
struct Grupo
{
    struct Ponto *xPares;
    int qtd_xPares;
    struct Ponto *yPares;
    int qtd_yPares;
};

struct Grupo *agruparPares(struct PontoEncadeado *primeiro)
{
    struct Grupo *agrupados = malloc(sizeof(struct Grupo));
    agrupados->xPares = malloc(sizeof(struct Ponto)*10);
    agrupados->yPares = malloc(sizeof(struct Ponto)*10);
    agrupados->qtd_xPares = 0;
    agrupados->qtd_yPares = 0;
    int qtd_yPares = 0;
    struct PontoEncadeado *atual = primeiro;
    while (atual != NULL)
    {
        struct Ponto novo = atual->ponto;
        if (atual->ponto.x % 2 == 0)
        {
            agrupados->xPares[agrupados->qtd_xPares] = novo;
            agrupados->qtd_xPares++;
        }
        if (atual->ponto.y % 2 == 0)
        {
            agrupados->yPares[agrupados->qtd_yPares] = novo;
            agrupados->qtd_yPares++;
        }
        atual = atual->proximo;
    }
    return agrupados;
}
void main()
{
    struct PontoEncadeado *primeiro = NULL;
    struct PontoEncadeado *ultimo = NULL;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        struct PontoEncadeado *novo = malloc(sizeof(struct PontoEncadeado));
        printf("Ponto %d:\n", i+1);
        int x = 0;
        printf("x: ");
        scanf("%d", &x);
        int y = 0;
        printf("y: ");
        scanf("%d", &y);
        novo->ponto.x = x;
        novo->ponto.y = y;
        novo->proximo = NULL;
        novo->anterior = NULL;
        if (primeiro == NULL)
        {
            primeiro = novo;
        }
        else
        {
            ultimo->proximo = novo;
            novo->anterior = ultimo;
        }
        ultimo = novo;
    }
    struct Grupo *grupo = agruparPares(primeiro);
    printf("\n-> Pontos xPares\n");
    for (i = 0; i < grupo->qtd_xPares; i++)
    {
        printf("(%d, %d)\n", grupo->xPares[i].x, grupo->xPares[i].y);
    }
    printf("-> Pontos yPares\n");
    for (i = 0; i < grupo->qtd_yPares; i++)
    {
        printf("(%d, %d)\n", grupo->yPares[i].x, grupo->yPares[i].y);
    }

}