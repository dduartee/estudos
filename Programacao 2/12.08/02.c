#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Dado
{
    int codigo;
    float temp;
    float velocidadeVento;
    float umidadeAr;
    struct Dado *anterior;
    struct Dado *proximo;
};
void consultarRegistros(struct Dado *ultimo)
{
    struct Dado *atual;
    atual = ultimo;
    while (atual != NULL)
    {
        printf("\n Codigo: %d", atual->codigo);
        printf("\n Temperatura: %d", atual->temp);
        printf("\n Velocidade vento: %d", atual->velocidadeVento);
        printf("\n Umidade do ar: %d", atual->umidadeAr);
        atual = atual->anterior;
    }
    printf("\nFIM\n");
}
void main()
{
    struct Dado *primeiro = NULL;
    struct Dado *ultimo = NULL;
    bool finalizar = false;
    while (!finalizar)
    {
        printf("MENU DATALOGGER\n");
        printf("1.Novo registro\n");
        printf("2.Consultar registros\n");
        printf("3.Sair\n");
        int opcao = 0;
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            struct Dado *novo = malloc(sizeof(struct Dado));
            if (novo == NULL)
            {
                printf("ERRO AO ALOCAR");
            }
            int codigo, temp, velocidadeVento, umidadeAr;
            printf("Novo registro\n");
            printf("Codigo do equipamento: ");
            scanf("%d", &codigo);
            printf("Temperatura: ");
            scanf("%d", &temp);
            printf("Velocidade do vento: ");
            scanf("%d", &velocidadeVento);
            printf("Umidade relativa do ar: ");
            scanf("%d", &umidadeAr);
            novo->codigo = codigo;
            novo->temp = temp;
            novo->velocidadeVento = velocidadeVento;
            novo->umidadeAr = umidadeAr;
            novo->anterior = NULL;
            novo->proximo = NULL;
            if (primeiro == NULL)
            {
                primeiro = novo;
                ultimo = novo;
            }
            else
            {
                novo->anterior = ultimo;
                ultimo->proximo = novo;
                ultimo = novo;
            }
            break;
        case 2:
            consultarRegistros(ultimo);
            break;
        case 3:
            finalizar = true;
            break;
        default:
            break;
        }
    }
}
