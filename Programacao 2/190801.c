#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Componente {
    struct Componente *prev;
    struct Componente *next;
    int id;
    int nSerie;
};

void main() {
    struct Componente *first = NULL;
    struct Componente *last = NULL;
    int id, i = 0;
    do
    {
        printf("Componente %d\n", i+1);
        printf("ID: ");
        scanf("%d", &id);
        if(id > 0) {
            struct Componente *novoComponente = malloc(sizeof(struct Componente));
            if(novoComponente == NULL) {
                printf("Erro ao alocar para novoComponente");
            }
            novoComponente->id = id;
            printf("nSerie: ");
            scanf("%d", &novoComponente->nSerie);
            novoComponente->prev = NULL;
            novoComponente->next = NULL;
            if(first == NULL) {
                first = novoComponente;
                last = novoComponente;
            } else {
                novoComponente->prev = last;
                last->next = novoComponente;
                last = novoComponente;
            }
            i++;
        }
    } while (id > 0);

    struct Componente *current;
    current = first;
    while (current != NULL)
    {
        printf("[%d] -> ID:", current->id);
        printf("[%d] -> nSerie:", current->nSerie);
        current = current->next;
    }
    printf("FIM\n");
    
    current = last;
    while (current != NULL)
    {
        printf("[%d] -> ID:", current->id);
        printf("[%d] -> nSerie:", current->nSerie);
        current = current->prev;
    }
    free(first);

    
}