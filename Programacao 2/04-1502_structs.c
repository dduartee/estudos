#include <stdio.h>
#include <stdlib.h>

struct Dados {
    int codigo;
    float temperatura;
    float velocidadeVento;
    float umidadeRelativa;
};

struct Dados *updateVetorSize(int novoTamanho, struct Dados *datalogger, int tamanhoAtual) {
    struct Dados *novoVetor;
    novoVetor = malloc(novoTamanho*sizeof(struct Dados));
    int i = 0;
    for (i = 0; i < tamanhoAtual; i++) {
        novoVetor[i] = datalogger[i];
    }
    free(datalogger);
    return novoVetor;
}

void main() {
    int tamanhoAtual = 10, i = 0;
    struct Dados *datalogger = malloc(tamanhoAtual*sizeof(struct Dados));
    do
    {
        printf("Digite as informações do datalogger %d:\n", i+1);
        printf("Código do equipamento: ");
        scanf("%d", &datalogger[i].codigo);
        printf("Temperatura: ");
        scanf("%d", &datalogger[i].temperatura);
        printf("Velocidade do vento: ");
        scanf("%d", &datalogger[i].velocidadeVento);
        printf("Umidade relativa do ar: ");
        scanf("%d", &datalogger[i].umidadeRelativa);
        i++;
        if(tamanhoAtual-i == 1) {
            datalogger = updateVetorSize(tamanhoAtual+10, datalogger, tamanhoAtual);
            tamanhoAtual += 10;
            printf("Vetor aumentado para %d", tamanhoAtual);
        }
    } while (datalogger[i-1].codigo > 0);
}