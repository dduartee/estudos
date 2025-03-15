#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node *prev;
    struct Node *next;
    int numero;
};

void main() {
    struct Node *first = NULL;
    struct Node *last = NULL;
    int numero, i = 0;
    do
    {
        printf("Insira o valor para o nó %d:", i);
        scanf("%d", &numero);
        if(numero>0) {
            struct Node *newNode = malloc(sizeof(struct Node));
            if(newNode == NULL) {
                printf("newNode NAO ALOCADO!!");
            }
            newNode->numero = numero;
            newNode->prev = NULL;
            newNode->next = NULL;
            if(first != NULL) {
                last->next = newNode;
                newNode->prev = last;

                last = newNode;
            } else { // primeira iteração
                first = newNode;
                last = newNode;
            }
            i++;
        }
    } while (numero>0);

    struct Node *current;
    current = first;
    while(current != NULL) {
        printf("[%d] -> ", current->numero);
        current = current->next;
    }
    printf("FIM\n");

    numero = 0;
    bool removido = false;
    printf("Digite o numero do nó para remover: ");
    scanf("%d", &numero);
    current = first;
    i = 0;
    while(current != NULL) {
        if (i == numero) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                first = current->next; // Removing the first node
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                last = current->prev; // Removing the last node
            }
            free(current);
            removido = true;
            break; // Exit after removing the node
        }
        current = current->next;
        i++;
    }
    current = first;
    while(current != NULL) {
        printf("[%d] -> ", current->numero);
        current = current->next;
    }
    printf("FIM\n");
}