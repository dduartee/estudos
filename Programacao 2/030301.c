#include <stdio.h>

void somarValores(int *v, int* somaPares, int* somaImpares) {
    int i;
    int tamanho = sizeof(v) / sizeof(v[0]);
    int pares, impares;
    for(i = 0; i < tamanho; i++) {
        if(i%2 == 0) {
            pares = pares + v[i];
        } else {
            impares = impares + v[i];
        }
    }
    *somaPares = pares;
    *somaImpares = impares;
}

void main() {
    int v[8];
    int tamanho = sizeof(v) / sizeof(v[0]);

    int i;
    for(i = 0; i < tamanho; i++){
        printf("Insira o %d numero: ", i+1);
        scanf("%d", &v[i]);
    }
    int somaPares, somaImpares;
    somarValores(v, &somaPares, &somaImpares);
    printf("Soma pares: %d", somaPares);
    printf("Soma impares: %d", somaImpares);
}