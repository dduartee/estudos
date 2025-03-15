#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct DadosPesquisa
{
    int idade;
    int escolaridade;
    int aprovacaoGov;
};
struct EstatisticaVotos
{
    int ruim;
    int satisfatorio;
    int bom;
    int otimo;
    int semOpiniao;
};
struct PorcentagemVotos
{
    float ruim;
    float satisfatorio;
    float bom;
    float otimo;
    float semOpiniao;
};
struct DadosPesquisa *atualizarTamanhoVetor(struct DadosPesquisa *pesquisas, int tamanhoAtual, int tamanhoNovo)
{
    struct DadosPesquisa *novoVetor;
    novoVetor = malloc(tamanhoNovo * sizeof(struct DadosPesquisa));
    int i = 0;
    for (i = 0; i < tamanhoAtual; i++)
    {
        novoVetor[i] = pesquisas[i];
    }
    printf("\nTamanho vetor atualizado\n");
    free(pesquisas);
    return novoVetor;
}
void mostrarResultado(struct PorcentagemVotos *porcentagemVotos, int entradas)
{
    printf("Porcentagem de votos: \n");
    printf("Ruim: %.2f%%\n", porcentagemVotos->ruim);
    printf("Satisfatório: %.2f%%\n", porcentagemVotos->satisfatorio);
    printf("Bom: %.2f%%\n", porcentagemVotos->bom);
    printf("Ótimo: %.2f%%\n", porcentagemVotos->otimo);
    printf("Sem opinião: %.2f%%\n", porcentagemVotos->semOpiniao);
}

struct PorcentagemVotos *calcularPorcentagem(struct EstatisticaVotos *votos, int entradas)
{
    struct PorcentagemVotos *porcentagem;
    porcentagem = malloc(sizeof(struct PorcentagemVotos));
    porcentagem->ruim = ((float)votos->ruim / entradas) * 100;
    porcentagem->satisfatorio = ((float)votos->satisfatorio / entradas) * 100;
    porcentagem->bom = ((float)votos->bom / entradas) * 100;
    porcentagem->otimo = ((float)votos->otimo / entradas) * 100;
    porcentagem->semOpiniao = ((float)votos->semOpiniao / entradas) * 100;
    return porcentagem;
}
struct PorcentagemVotos *armazenar(struct EstatisticaVotos *votos, struct DadosPesquisa *pesquisas, struct DadosPesquisa *pesquisa, int entradas)
{
    pesquisas[entradas] = *pesquisa;
    printf("Armazenado!");
    switch (pesquisa->aprovacaoGov)
    {
    case 1:
        votos->ruim++;
        break;
    case 2:
        votos->satisfatorio++;
        break;
    case 3:
        votos->bom++;
        break;
    case 4:
        votos->otimo++;
        break;
    case 5:
        votos->semOpiniao++;
        break;
    }
    return calcularPorcentagem(votos, entradas+1);
}
void main()
{
    struct EstatisticaVotos *votos;
    struct PorcentagemVotos *porcentagemVotos;
    votos = malloc(sizeof(struct EstatisticaVotos));

    struct DadosPesquisa *pesquisas;
    int tamanhoAtual = 10;
    pesquisas = malloc(tamanhoAtual * sizeof(struct DadosPesquisa));
    int entradas = 0;

    bool finalizar = false;
    while (finalizar == false)
    {
        if (entradas == tamanhoAtual - 1)
        {
            pesquisas = atualizarTamanhoVetor(pesquisas, tamanhoAtual, tamanhoAtual + 10);
            tamanhoAtual += 10;
        }

        printf("Digite a idade: ");
        int idade;
        scanf("%d", &idade);
        if (idade == 0)
        {
            finalizar = true;
            mostrarResultado(porcentagemVotos, entradas);
            break;
        }
        printf("Digite o nível de escolaridade: ");
        int escolaridade;
        scanf("%d", &escolaridade);

        printf("Digite o nível aprovação do governo: ");
        int aprovacaoGov;
        scanf("%d", &aprovacaoGov);

        struct DadosPesquisa *pesquisaAtual;
        pesquisaAtual = malloc(1 * sizeof(struct DadosPesquisa));
        pesquisaAtual->idade = idade;
        pesquisaAtual->escolaridade = escolaridade;
        pesquisaAtual->aprovacaoGov = aprovacaoGov;
        porcentagemVotos = armazenar(votos, pesquisas, pesquisaAtual, entradas);

        entradas++;
    }
}