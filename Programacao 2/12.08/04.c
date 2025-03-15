#include <stdio.h>
#include <stdlib.h>

struct Dado
{
    struct Dado *anterior;
    struct Dado *proximo;
    int codigo;
    int nSerie;
};
void consultarRegistros(struct Dado *ultimo)
{
    struct Dado *atual;
    atual = ultimo;
    while (atual != NULL)
    {
        printf("numero: %d\n", atual->numeroPar);
        atual = atual->anterior;
    }
    printf("\nFIM\n");
}
struct Dado *encadear(int *numeros) {
    struct Dado *primeiro = NULL;
    struct Dado *ultimo = NULL;
    
    int i = 0;
    for(i = 0; i<10; i++) {
        if (numeros[i] % 2 == 0)
        {
            struct Dado *novo = malloc(sizeof(struct Dado));
            if (novo == NULL)
            {
                printf("Erro ao alocar");
            }
            novo->numeroPar = numeros[i];
            novo->anterior = NULL;
            novo->proximo = NULL;
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
    }
}
void main()
{
    int *numeros;
    numeros = malloc(10 * sizeof(int));
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        int numero = 0;
        printf("Insira o %d° valor: ", i + 1);
        scanf("%d", &numero);
        numeros[i] = numero;
    }
    struct Dado *encadeado = encadear(numeros);
    consultarRegistros(encadeado);
}