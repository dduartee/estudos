#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

struct EstadoComodo
{
    int codigo;
    int tempArCondicionado;
    int fechamentoCortina;
};
struct EstadoComodo *remalloc(int novoTamanho, struct EstadoComodo *estadoComodos, int tamanhoAtual)
{
    struct EstadoComodo *novoVetor;
    novoVetor = malloc(novoTamanho * sizeof(struct EstadoComodo));
    int i = 0;
    for (i = 0; i < tamanhoAtual; i++)
    {
        novoVetor[i] = estadoComodos[i];
    }
    free(estadoComodos);
    return novoVetor;
}
void mostrarAlteracoes(struct EstadoComodo *estadoComodos, int entradas)
{
    printf("\n\n");
    if(entradas == 0) {
        printf("[!] Nenhuma alteração realizada\n");
        return;
    }
    printf("Suas alterações: \n");
    for (int i = 0; i < entradas; i++)
    {
        printf("%d [Cômodo %d]\n", i, estadoComodos[i].codigo);
        printf("  Temperatura do ar condicionado: %d\n", estadoComodos[i].tempArCondicionado);
        printf("  Fechamento da cortina: %d\n", estadoComodos[i].fechamentoCortina);
        printf("\n");
    }
}
struct EstadoComodo atualizarEstadoComodo(int codigo, int tempArCondicionado, int porcentagemCortina)
{
    struct EstadoComodo comodo;
    comodo.codigo = codigo;
    comodo.tempArCondicionado = tempArCondicionado;
    comodo.fechamentoCortina = porcentagemCortina;
    return comodo;
}
int main()
{
    struct EstadoComodo *estadoComodos;
    int tamanhoAtual = 3;
    int i = 0;
    estadoComodos = malloc(tamanhoAtual * sizeof(struct EstadoComodo));
    bool finalizar = false;
    printf("=== Sistema automação residencial ===\n");
    while (finalizar == false)
    {
        printf("Atualizar estado do comodo: \n");
        printf(" 1. Quarto\n 2. Suite \n 3. Sala \n 0. Sair\n");
        printf("[?] Digite o código do cômodo: ");
        int codigo;
        scanf("%d", &codigo);
        if (codigo == 0)
        {
            finalizar = true;
            mostrarAlteracoes(estadoComodos, i);
            printf("[!] Finalizando...\n");
            break;
        }
        if (codigo < 1 || codigo > 3)
        {
            printf("[x] Valor inválido!\n");
            continue;
        }
        int tempArCondicionado;
        printf("[?] Digite a temperatura do ar condicionado: ");
        scanf("%d", &tempArCondicionado);

        int porcentagemCortina;
        printf("[?] Porcentagem da fechamento da cortina: ");
        scanf("%d", &porcentagemCortina);
        if (porcentagemCortina < 0 || porcentagemCortina > 100)
        {
            printf("[x] Valor inválido!\n");
            continue;
        }
        struct EstadoComodo estadoComodoAtualizado = atualizarEstadoComodo(codigo, tempArCondicionado, porcentagemCortina);
        if (tamanhoAtual % 3 == 0)
        {
            estadoComodos = remalloc(tamanhoAtual + 3, estadoComodos, tamanhoAtual);
            tamanhoAtual += 3;
        }
        estadoComodos[i] = estadoComodoAtualizado;
        i++;
    }
    free(estadoComodos);
    return 0;
}