#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

struct Comodo
{
    int codigo;
    int tempArCondicionado;
    bool luzAcesa;
    int fechamentoCortina;
};
void consultar(struct Comodo comodo)
{
    printf("- Cômodo %d\n", (comodo.codigo) + 1);
    printf("- Temperatura do ar condicionado: %d\n", comodo.tempArCondicionado);
    printf("- Luz acesa: %s\n", comodo.luzAcesa ? "SIM" : "NÃO");
    printf("- Fechamento da cortina: %d\n", comodo.fechamentoCortina);
}
void mostrarAlteracoes(struct Comodo *comodos)
{
    printf("\n\n");
    printf("Suas alterações: \n");
    for (int i = 0; i < 5; i++)
    {
        if (comodos[i].codigo == i + 1)
        {
            printf("Cômodo %d\n", i + 1);
            consultar(comodos[i]);
        }
    }
}
void modificar(int codigo, struct Comodo *comodos)
{
    printf("\n\n");
    int indice = codigo - 1;
    if (comodos[indice].codigo == codigo)
    {
        printf("[!] Cômodo já preenchido\n");
        printf("[?] Deseja modifica-lo? [1] Sim [2] Não  \n");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 2)
            return;
    }
    printf("[!] Modificando comodo %d\n", codigo);
    int tempArCondicionado;
    printf("[?] Digite a temperatura do ar condicionado: ");
    scanf("%d", &tempArCondicionado);
    int estadoLuz;
    printf("[?] A luz está acesa? [1] Sim [2] Não");
    scanf("%d", &estadoLuz);
    if (estadoLuz < 1 && estadoLuz > 2)
    {
        printf("[x] Valor inválido!\n");
        return;
    }

    int porcentagemCortina;
    printf("[?] Porcentagem da fechamento da cortina: ");
    scanf("%d", &porcentagemCortina);
    if(porcentagemCortina < 0 || porcentagemCortina > 100)
    {
        printf("[x] Valor inválido!\n");
        return;
    }

    printf("\n[?] Deseja modificar o comodo %d para as informações abaixo? \n", codigo);
    struct Comodo comodo;
    comodo.codigo = codigo;
    comodo.tempArCondicionado = tempArCondicionado;
    comodo.luzAcesa = estadoLuz == 1;
    comodo.fechamentoCortina = porcentagemCortina;
    consultar(comodo);

    printf("[1] Sim [2] Não\n");
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        comodos[indice].codigo = codigo;
        comodos[indice].tempArCondicionado = tempArCondicionado;
        comodos[indice].luzAcesa = estadoLuz == 1;
        comodos[indice].fechamentoCortina = porcentagemCortina;
        printf("[!] Modificado com sucesso!\n");
    }
    else
    {
        printf("[x] Modificação cancelada!\n");
    }
}
bool menuOperacoes(struct Comodo *comodos, int codigo)
{
    printf(" 1. Consultar as configurações atuais\n 2. Alterar as configurações\n 0. Voltar\n");
    int operacao;
    printf("\n[?] Digite a operação: ");
    scanf("%d", &operacao);
    switch (operacao)
    {
    case 0:
        return false;
    case 1:
        if (comodos[codigo - 1].codigo != codigo)
        {
            printf("\n[x] Cômodo %d não preenchido\n", codigo);
            return true;
        }
        consultar(comodos[codigo-1]);
        printf("\n[?] Pressione qualquer tecla para continuar...\n");
        scanf("%s");
        break;
    case 2:
        modificar(codigo, comodos);
        break;
    default:
        printf("[x] Operação inválida\n");
        break;
    }
    return false;
}
int main()
{
    struct Comodo *comodos;
    comodos = malloc(5 * sizeof(struct Comodo));
    bool finalizar = false;
    while (finalizar == false)
    {
        printf("=== Sistema Domótica ===\n");
        printf(" 1. Suite\n 2. Quarto \n 3. Suite MASTER\n 4. Sala \n 5. Sala de jantar \n 0. Sair\n");
        printf("- Digite o código do cômodo: ");
        int codigo;
        scanf("%d", &codigo);
        if (codigo == 0)
        {
            finalizar = true;
            mostrarAlteracoes(comodos);

            printf("[!] Finalizando...\n");
            return 0;
        }
        if (codigo < 1 && codigo > 5)
        {
            printf("[x] Valor inválido!\n");
            return 0;
        }
        printf("\n[!] Cômodo selecionado: [%d]\n", codigo);
        bool emOperacao = true;
        do{
            emOperacao = menuOperacoes(comodos, codigo);
        } while (emOperacao);
    }
    free(comodos);
    return 0;
}