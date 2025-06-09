#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int quant;
    float preço;
} Produto;

Produto produtos;
int produtoCadastrado = 0;
void cadastrarProduto();
void visualizarEstoque();
void realizarCompra();

int main() {
    int opcao;

    do {
        printf("\033[36m");
        printf("-- Bem vindo ao SuperMais --\n");
        printf("\033[0m");
        printf("Escolha o que você deseja: \n");
        printf("1. Cadastrar produto\n");
        printf("2. Ver estoque\n");
        printf("3. Realizar compra\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            cadastrarProduto();
            break;
            case 2:
            visualizarEstoque();
            break;
            case 3:
            realizarCompra();
            break;
            case 0:
            printf("Saindo..\n");
            break;
            default:
            printf("Opção inválida!!\n");
        }
        printf("Pressione enter para continuar");
        getchar();
        getchar();
        system("clear");
    } while (opcao != 0);

    return 0;
}

void cadastrarProduto(){
    
    printf("\033[36m");
    printf("-- Cadastro do Produto --\n");
    printf("\033[0m");
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", produtos.nome);
    printf("Quantidade que temos em estoque: ");
    scanf("%d", &produtos.quant);
    printf("Preço da unidade: R$");
    scanf("%f", &produtos.preço);
    produtoCadastrado = 1;
    printf("O produto foi cadastrado!!\n");
}

void visualizarEstoque() {
    
    if(produtoCadastrado) {
        printf("\033[36m");
        printf("-- Informações do Produto --\n");
        printf("\033[0m");
        printf("Nome: %s\n", produtos.nome);
        printf("Quantidade em estoque: %d\n", produtos.quant);
        printf("Preço da unidade: R$%.2f\n", produtos.preço);
    } else {
        printf("O produto não foi encontrado.\n");
    }
}

void realizarCompra() {
    
    if (!produtoCadastrado) {
        printf("Nenhum produto foi encontrado para continuar a comprar!");
        return;
    }

    int quantCompra;
    printf("\033[36m");
    printf("-- Realizar Compra --\n");
    printf("\033[0m");
    printf("Quantidade que você deseja comprar: ");
    scanf("%d", &quantCompra);
    if (quantCompra <= 0) {
        printf("Quantidade inválida.\n");
        return;
    }
    if (quantCompra > produtos.quant){
        printf("A quantidade que você deseja ultrapssada o estoque atual: %d\n", produtos.quant);
    } else {
        produtos.quant -= quantCompra;
        printf("Compra realizada com sucesso!\n");
        printf("Quantidade restante em estoque: %d\n", produtos.quant);
    }
}