#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Aluno
{
    int matricula;
    int conhecimentoProgC;
};
struct CandidatosGrupo
{
    struct Aluno *iniciantes;
    struct Aluno *avancados;
    int *qtdIniciantes;
    int *tamanhoVetIniciantes;
    int *qtdAvancados;
    int *tamanhoVetAvancados;
};

struct Aluno *handleTamanhoVetor(int *qtd, int *tamanhoVet, struct Aluno *candidatos)
{
    printf("handleTamanhoVetor(%d, %d)\n", *qtd, *tamanhoVet);
    if (*tamanhoVet - *qtd <= 1)
    { 
        *tamanhoVet += 3;
        printf("Redimensionando vetor para %d\n", *tamanhoVet);
        printf("Tentando redimensionar para %d", *tamanhoVet);
        struct Aluno *novoVetCandidatos;
        novoVetCandidatos = malloc(*tamanhoVet * sizeof(struct Aluno));
        int i = 0;
        for (i = 0; i < (*tamanhoVet)-3; i++)
        {
            novoVetCandidatos[i] = candidatos[i];
        }
        //free(candidatos);
        *candidatos = *novoVetCandidatos;
    }
    return candidatos;

}
// (1 - iniciante ou 2 - avançado)
struct CandidatosGrupo armazenar(struct Aluno candidato, struct CandidatosGrupo candidatosGrupo)
{
    if (candidato.conhecimentoProgC == 1)
    {
        candidatosGrupo.iniciantes = handleTamanhoVetor(candidatosGrupo.qtdIniciantes, candidatosGrupo.tamanhoVetIniciantes, candidatosGrupo.iniciantes);
        candidatosGrupo.iniciantes[*candidatosGrupo.qtdIniciantes] = candidato;
        *candidatosGrupo.qtdIniciantes += 1;
    }
    else if (candidato.conhecimentoProgC == 2)
    {
        candidatosGrupo.avancados = handleTamanhoVetor(candidatosGrupo.qtdAvancados, candidatosGrupo.tamanhoVetAvancados, candidatosGrupo.avancados);
        candidatosGrupo.avancados[*candidatosGrupo.qtdAvancados] = candidato;
        *candidatosGrupo.qtdAvancados += 1;
    }
    else
    {
    }
    printf("Candidato Armazenado!\n");
    printf("\ntamanhoVetIniciantes %d\n tamanhoVetAvancados %d\n\n", *candidatosGrupo.tamanhoVetIniciantes, *candidatosGrupo.tamanhoVetAvancados);
    return candidatosGrupo;
}
void printCandidatos(struct Aluno* candidatos, int *qtdCandidatos) {
    for (int i = 0; i < *qtdCandidatos; i++)
    {
        printf("\n");
        printf("Matricula: %d\n", candidatos[i].matricula);
        printf("Conhecimento de programacao em C: ");
        if(candidatos[i].conhecimentoProgC == 1) {
            printf("Iniciante");
        } else {
            printf("Avançado");
        }
        printf("\n");
    }
}
void main()
{
    int i = 0;
    struct CandidatosGrupo candidatosGrupo;

    candidatosGrupo.iniciantes = malloc(3 * sizeof(struct Aluno));
    candidatosGrupo.avancados = malloc(3 * sizeof(struct Aluno));
    candidatosGrupo.tamanhoVetIniciantes = malloc(sizeof(int));
    candidatosGrupo.tamanhoVetAvancados = malloc(sizeof(int));
    candidatosGrupo.qtdIniciantes = malloc(sizeof(int));
    candidatosGrupo.qtdAvancados = malloc(sizeof(int));

    *candidatosGrupo.qtdIniciantes = 0;
    *candidatosGrupo.tamanhoVetIniciantes = 3;
    *candidatosGrupo.qtdAvancados = 0;
    *candidatosGrupo.tamanhoVetAvancados = 3;

    bool finalizar = false;
    while (finalizar == false)
    {
        struct Aluno candidato;
        printf("Digite as informações do candidato %d\n", i + 1);
        printf("Matricula . ");
        scanf("%d", &candidato.matricula);
        if(candidato.matricula == 0){
            finalizar = true;
            break;
        }
        printf("Nivel de conhecimento em programação C (1 - iniciante ou 2 - avançado) . ");
        scanf("%d", &candidato.conhecimentoProgC);
        if (candidato.matricula > 0)
        {
            armazenar(candidato, candidatosGrupo);
        }
        else
        {
            finalizar = true;
        }
        // printf("qtdIniciantes main() %d\n", *candidatosGrupo.qtdIniciantes);
        i++;
    }
    printf("Candidatos: \n");
    printCandidatos(candidatosGrupo.iniciantes, candidatosGrupo.qtdIniciantes);
    printCandidatos(candidatosGrupo.avancados, candidatosGrupo.qtdAvancados);
    free(candidatosGrupo.iniciantes);
    free(candidatosGrupo.avancados);
}