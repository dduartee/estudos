#include <stdio.h>
#include <stdlib.h>

struct Dado
{
    struct Dado *anterior;
    struct Dado *proximo;
    int numero;
};
struct Dados {
    struct Dado *pares;
    struct Dado *impares;
};

struct Dados *encadear(int *numeros) {
    struct Dado *primeiroPar = NULL;
    struct Dado *ultimoPar = NULL;
    struct Dado *primeiroImpar = NULL;
    struct Dado *ultimoImpar = NULL;

    int i = 0;
    for (i = 0; i<10; i++) {
        struct Dado *novo = malloc(sizeof(struct Dado));
        novo->numero = numeros[i];
        novo->anterior = NULL;
        novo->proximo = NULL;
        if(numeros[i] % 2 == 0) {
            if(primeiroPar == NULL) {
                primeiroPar = novo;
            } else {
                ultimoPar->proximo = novo;
                novo->anterior = ultimoPar;
            }
            ultimoPar = novo;
        } else {
            if(primeiroImpar == NULL) {
                primeiroImpar = novo;
            } else {
                ultimoImpar->proximo = novo;
                novo->anterior = ultimoImpar;
            }
            ultimoImpar = novo;
        }
    }
    struct Dados *dados = malloc(sizeof(struct Dados*));
    dados->pares = primeiroPar;
    dados->impares = primeiroImpar;
    return dados;
}
void consultarRegistros(struct Dado *primeiro)
{
    struct Dado *atual;
    atual = primeiro;
    while (atual != NULL)
    {
        printf("numero: %d\n", atual->numero);
        atual = atual->proximo;
    }
    printf("\nFIM\n");
}
void main() {
    int *numeros;
    numeros = malloc(10 * sizeof(int));
    int i = 0;
    for(i = 0; i<10; i++) {
        int numero = 0;
        printf("Insira o %d° valor: ", i+1);
        scanf("%d", &numero);
        if(numero > 0) {
            numeros[i] = numero;
        } else {
            printf("Numero negativo\n");
            i--;
        }
    }
    struct Dados *dados = encadear(numeros);
    printf("\nPARES\n");
    consultarRegistros(dados->pares);
    printf("\nIMPARES\n");
    consultarRegistros(dados->impares);

}