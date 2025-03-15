#include <stdio.h>
#include <stdlib.h>

struct Grupo {
    int * pares;
    int qtdPares;
    int * impares;
    int qtdImpares;
};
void imprimirVetor(int *v, int tamanho) {
    int i = 0;
    printf("{ ");
    for (i = 0; i<tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("}\n");
}

struct Grupo agrupar(int *v, int tamanho) {
    int i;
    int tamanhoPares =0, tamanhoImpares = 0;
    for(i = 0; i<tamanho; i++) {
        if(v[i] % 2 == 0) tamanhoPares++;
        else tamanhoImpares++;
    }
    printf("Tamanho pares: %d\n", tamanhoPares);
    printf("Tamanho impares: %d\n", tamanhoImpares);
    int *vPares, *vImpares;
    vPares = malloc(sizeof(int)*tamanhoPares);
    vImpares = malloc(sizeof(int)*tamanhoImpares);
    int contagemPar = 0, contagemImpar = 0;
    for(i = 0; i<tamanho; i++) {
        if(v[i] % 2 == 0) {
            vPares[contagemPar] = v[i];
            contagemPar++;
        } else {
            vImpares[contagemImpar] = v[i];
            contagemImpar++;
        }
    }
    struct Grupo grupo;
    grupo.pares = vPares;
    grupo.impares = vImpares;
    grupo.qtdPares = tamanhoPares;
    grupo.qtdImpares = tamanhoImpares;

    return grupo;
}
void main() {
    int i, tamanho, *v;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    v = malloc(tamanho*sizeof(int));
    for(i = 0; i<tamanho; i++) {
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &v[i]);
    }

    struct Grupo grupo = agrupar(v, tamanho);

    printf("vetor original: ");
    imprimirVetor(v, tamanho); 
    printf("vetor pares: ");
    imprimirVetor(grupo.pares, grupo.qtdPares);
    printf("vetor impares: ");
    imprimirVetor(grupo.impares, grupo.qtdImpares);

} 