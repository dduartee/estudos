#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Dado
{
    int codigo;
    int nSerie;
    struct Dado *anterior;
    struct Dado *proximo;
};
void main()
{
    struct Dado *primeiro = NULL;
    struct Dado *ultimo = NULL;
    bool finalizar = false;
    while (!finalizar)
    {
        struct Dado *novo = malloc(sizeof(struct Dado));
        if (novo == NULL)
        {
            printf("ERRO AO ALOCAR");
        }
        int codigo, nSerie, velocidadeVento, umidadeAr;
        printf("Codigo do equipamento: ");
        scanf("%d", &codigo);
        if (codigo != 0)
        {
            printf("Numero de série: ");
            scanf("%d", &nSerie);
            novo->codigo = codigo;
            novo->nSerie = nSerie;
            novo->anterior = NULL;
            novo->proximo = NULL;
            if (primeiro == NULL)
            {
                primeiro = novo;
            }
            else
            {
                novo->anterior = ultimo;
                ultimo->proximo = novo;
            }
            ultimo = novo;
        } else {
            finalizar = true;
        }
    }
    struct Dado *atual;
    atual = primeiro;
    printf("Primeiro -> Ultimo\n");
    printf("\n=====\n");
    while (atual != NULL)
    {
        printf("\n Codigo: %d", atual->codigo);
        printf("\n Numero de série: %d", atual->nSerie);
        printf("\n=====\n");
        atual = atual->proximo;
    }
    atual = ultimo;
    printf("Ultimo -> Primeiro\n");
    printf("\n=====");
    while (atual != NULL)
    {
        printf("\n Codigo: %d", atual->codigo);
        printf("\n Numero de série: %d", atual->nSerie);
        printf("\n=====\n");
        atual = atual->anterior;
    }
    free(primeiro);
    free(ultimo);
    free(atual);
}
