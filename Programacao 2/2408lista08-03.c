#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Dado
{
    int codigo;
    int nSerie;
    int potencia;
    struct Dado *anterior;
    struct Dado *proximo;
};
struct Lista {
    struct Dado *primeiro;
    struct Dado *ultimo;
};

struct Lista inserir(struct Lista lista) {
    struct Dado *novo = malloc(sizeof(struct Dado));
    if (novo == NULL)
    {
        printf("ERRO AO ALOCAR");
    }
    int codigo, potencia, nSerie;
    printf("Novo registro\n");
    printf("Codigo: ");
    scanf("%d", &codigo);
    printf("Numero de serie: ");
    scanf("%d", &nSerie);
    printf("Potencia: : ");
    scanf("%d", &potencia);
    novo->codigo = codigo;
    novo->nSerie = nSerie;
    novo->potencia = potencia;
    novo->anterior = NULL;
    novo->proximo = NULL;
    if (lista.primeiro == NULL)
    {
        lista.primeiro = novo;
    }
    else
    {
        lista.ultimo->proximo = novo;
        novo->anterior = lista.ultimo;
    }
    lista.ultimo = novo;
    return lista;
}

void consultar(struct Dado *primeiro) {
    int nSerie;
    printf("Insira o numero de serie para a consulta: ");
    scanf("%d", &nSerie);
    if(primeiro == NULL) {
        printf("Lista vazia.\n");
    }
    struct Dado *atual = primeiro;
    int i=0;
    while (atual != NULL)
    {
        if(atual->nSerie == nSerie) {
            printf("Posição: %d\n", i);
            printf("Codigo: %d\n", atual->codigo);
            printf("Numero de serie: %d\n", atual->nSerie);
            printf("Potencia: %d\n", atual->potencia);
            atual = NULL;
        } else {
            atual = atual->proximo;
            if(atual == NULL) {
                printf("Numero de serie nao encontrado!!!!\n");
            }
        }
        i++;
    }
}

void editar(struct Dado *primeiro) {
    int nSerie, novoNSerie;
    printf("Insira o numero de serie para a editar: ");
    if(primeiro == NULL) {
        printf("Lista vazia.\n");
    }
    scanf("%d", &nSerie);
    struct Dado *atual = primeiro;
    int i=0;
    while (atual != NULL)
    {
        if(atual->nSerie == nSerie) {
            printf("Posição: %d\n", i);
            printf("Codigo: %d\n", atual->codigo);
            printf("Numero de serie: %d\n", atual->nSerie);
            printf("Potencia: %d\n", atual->potencia);
            printf("Digite o NOVO numero de serie: ");
            scanf("%d", &novoNSerie);
            atual->nSerie = novoNSerie;
            printf("Numero de serie atualizado!\n");
            atual = NULL;
        } else {
            atual = atual->proximo;
            if(atual == NULL) {
                printf("Numero de serie nao encontrado!!!!\n");
            }
        }
        i++;
    }
}

void excluir(struct Dado *primeiro) {
    int nSerie;
    printf("Insira o numero de serie para a remover: ");
    scanf("%d", &nSerie);
    if(primeiro == NULL) {
        printf("Lista vazia.\n");
    }
    struct Dado *atual = primeiro;
    while (atual != NULL)
    {
        if(atual->nSerie == nSerie) {
            if(atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            }
            if(atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            }
            printf("Numero de serie %d removido\n", nSerie);
            atual = NULL;
        } else {
            atual = atual->proximo;
            if(atual == NULL) {
                printf("Numero de serie nao encontrado!!!!\n");
            }
        }
    }
}

void main()
{
    struct Lista lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;
    bool finalizar = false;
    int i = 0;
    while (!finalizar)
    {
        printf("MENU Controle Dispositivos\n");
        printf("1.Inserir\n");
        printf("2.Consultar\n");
        printf("3.Editar\n");
        printf("4.Excluir\n");
        printf("5.Sair\n");
        int opcao;
        printf("Digite uma opção:   ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            lista = inserir(lista);
            break;
        case 2:
            consultar(lista.primeiro);
            break;
        case 3:
            editar(lista.primeiro);
            break;
        case 4:
            excluir(lista.primeiro);
            break;
        case 5:
            finalizar = true;
            break;
        default:
            break;
        }
    }
}