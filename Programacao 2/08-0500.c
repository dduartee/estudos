#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct celula
{
    struct celula *proximo;
    int informacao;
};
int main(void)
{
    int info, cont = 0;
    struct celula *primeiro = NULL;
    struct celula *ultimo = NULL;
    do
    {
        printf("Informe o cod do equip:");
        scanf("%d", &info);
        if (info != 0)
        {
            struct celula *novaCelula = (struct celula *)malloc(sizeof(struct celula));
            novaCelula->informacao = info;
            novaCelula->proximo = NULL;
            if (primeiro == NULL)
            {
                primeiro = novaCelula;
                ultimo = novaCelula;
            }
            else
            {
                ultimo->proximo = novaCelula;
                ultimo = novaCelula;
            }
        }
    } while (info != 0);
    // mostrando os itens da lista
    struct celula *atual = primeiro;
    while (atual != NULL)
    {
        printf("%d, ", atual->informacao);
        atual = atual->proximo;
    }
}