#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nomep[50];
    char nomec[50];
    char cpf[11];
    char tel[10];
    float preço;
}Pizzaria;

Pizzaria pizzarias[10];
int numPizzas = 0;

void CadastrarPizza();
void CadastrarCliente();
void ListarPizzas();
void ListarClientes();
void FinalizarCompra();

int main() {
    int opcao;

    do {
        printf("-- Bem vindo a Pizzaria Nostra Pizza --\n");
        printf("O que você deseja fazer?\n");
        printf("1. Cadastrar Pizza\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Listar Pizzas\n");
        printf("4. Listar Clientes\n");
        printf("5. Finalizar compra\n");
        printf("0. Sair \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            CadastrarPizza();
            break;
            case 2:
            CadastrarCliente();
            break;
            case 3:
            ListarPizzas();
            break;
            case 4:
            ListarClientes();
            break;
            case 5:
            FinalizarCompra();
            break;
            case 0:
            printf("Saindo..\n");
            break;
            default:
            printf("Opção Invalida!!\n");
            break;
        }
        printf("Pressione enter para continuar");
        getchar(); 
        getchar();
        system("clear");

    } while (opcao != 0);

    return 0;
}

void CadastrarPizza(){
    
    printf("-- Cadastre a pizza --\n");
    printf("Informe o nome da pizza: ");
    scanf(" %[^\n]", pizzarias[numPizzas].nomep);
    printf("Informe o preço da pizza: R$");
    scanf("%f", &pizzarias[numPizzas].preço);
    numPizzas++; 
}

void CadastrarCliente(){
    
    printf("-- Cadastre o cliente --\n");
    printf("Informe seu nome completo: ");
    scanf(" %[^\n]", pizzarias[numPizzas].nomec);
    printf("Informe seu CPF: ");
    scanf(" %[^\n]", pizzarias[numPizzas].cpf);
    printf("Informe seu número para contato: ");
    scanf(" %[^\n]", pizzarias[numPizzas].tel);
    numPizzas++;
}

void ListarPizzas(){
    
    printf("-- Pizzas Cadastradas --\n");
    for (int i = 0; i < numPizzas; i++) {
        printf("Nome: %s\n", pizzarias[i].nomep);
        printf("Preço: %.2f\n", pizzarias[i].preço);
        printf("--------------------------\n");
    }
}

void ListarClientes(){
    
    printf("-- Clientes Cadastradas --\n");
    for (int i = 0; i < numPizzas; i++) {
        printf("Nome: %s\n", pizzarias[i].nomec);
        printf("CPF: %s\n", pizzarias[i].cpf);
        printf("Telefone: %s\n", pizzarias[i].tel);
        printf("--------------------------\n");
    }
}

void FinalizarCompra(){
    char verificacpf[20];
    int casa, opcaop;
    float valortotal;

    printf("Informe seu CPF novamente: ");
    scanf(" %[^\n]", verificacpf);
    for (int i = 0; i < numPizzas; i++) {
        int iguais = 1;
        int j = 0;
        while(verificacpf[j] == pizzarias[i].cpf[j] && verificacpf[j] != 0) {
            j++;
        }
        if(verificacpf[j] != pizzarias[i].cpf[j]) {
            iguais = 0;
        }
        if(iguais) {
            
            printf("Seja bem vindo, %s!\n", pizzarias[i].nomec);
            printf("Escolha os sabores desejados dentre esses:\n");
            for (int k = 0; k < numPizzas; k++) {
                printf("%d -- Nome: %s, Preço: %.2f\n", k + 1, pizzarias[k].nomep, pizzarias[k].preço);
            }
            printf("Informe a quantidade de pizzas que você deseja: ");
            scanf("%d", &opcaop);
            printf("Informe o numero de sua casa/apartamento: ");
            scanf("%d", &casa);
            valortotal = pizzarias[opcaop - 1].preço;
            printf("Sua pizza escolhida é: %s\n", pizzarias[opcaop - 1].nomep);
            printf("Sua compra deu: R$ %.2f\n", valortotal);
            printf("Numero da casa/apartamento: %d\n", casa);
            return;
        }
    }

    printf("Você não tem cadastro então não pode comprar!!\n");
}