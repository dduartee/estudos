#include <stdio.h>
#include <stdlib.h>

struct Produto {
    const char* nome;
    float preco;
    int quantidade;
};

void adicionarProdutos(struct Produto *produtos, int qtd) {
    int i = 0;
    for(i = 0; i<qtd; i++) {
        printf("=== Produto %d ===\n", i+1);
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        printf("Preço: ");
        scanf("%.2f", produtos[i].preco);
        printf("Quantidade de estoque: ");
        scanf("%d", produtos[i].quantidade);
        printf("\n");
    }
}
void main() {
    int qtdProdutos = 0;
    struct Produto *produtos;
    printf("Informe a quantidade de produtos que deseja cadastrar: ");
    scanf("%d", &qtdProdutos);
    produtos = malloc(qtdProdutos * sizeof(struct Produto));

    adicionarProdutos(produtos, qtdProdutos);
}
