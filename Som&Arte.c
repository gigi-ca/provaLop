#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char banda[40];
    int ano, comp, id, gênero;
}CD;

CD cds[30];
int numCd = 0;
int quant = 30;
void CadastrarumCD();
void PesquisarCDporgenero();
void ConsultarseoCDexiste();
void ComprarCD();

int main(){
    int opcao;
    
    do{
        printf("\033[36m");
        printf("-- Bem vindo a loja Som & Arte --\n");
        printf("\033[0m");
        printf("O que você deseja?\n");
        printf("1. Cadastrar um CD\n");
        printf("2. Pesquisar um CD por gênero\n");
        printf("3. Consutar se o CD existe e se ha unidade disponiveis\n");
        printf("4. Comprar um CD\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
            CadastrarumCD();
            break;
            case 2:
            PesquisarCDporgenero();
            break;
            case 3:
            ConsultarseoCDexiste(); 
            break;
            case 4:
            ComprarCD();
            break;
            case 0:
            printf("Saindo..");
            break;
            default:
            printf("Opcao Invalida!\n");
            break;
        }
        printf("Pressione enter para continuar");
        getchar();
        getchar();
        system("clear");
    }while(opcao != 0);
    
    return 0;
}

void CadastrarumCD(){
    
    printf("\033[36m");
    printf("-- Cadastre seu CD --\n");
    printf("\033[0m");
    cds[numCd].id = numCd;
    printf("Id do CD: %d\n", cds[numCd].id);
    printf("Informe a banda: ");
    scanf(" %[^\n]", cds[numCd].banda);
    printf("Informe o ano em que o CD foi lançado: ");
    scanf("%d", &cds[numCd].ano);
    printf("Informe o genêro musical do CD: \n");
    printf("1. Rock\n");
    printf("2. Pop\n");
    printf("3. Hip-Hop\n");
    printf("4. Blues\n");
    printf("5. Funk\n");
    printf("6. Country\n");
    printf("7. Musica classica\n");
    printf("8. Musica eletronica\n");
    printf("9. Rap\n");
    printf("10. Reggae\n");
    printf("11. MPB\n");
    scanf("%d", &cds[numCd].gênero);
    printf("Temos %d quantidades desse CD no estoque \n", quant);
    numCd++;
}

void PesquisarCDporgenero(){
    int pesquisa, encontrar = 0;
    
    printf("\033[36m");
    printf("Informe o gênero musical que deseja pesquisar: \n");
    printf("\033[0m");
    printf("1. Rock\n");
    printf("2. Pop\n");
    printf("3. Hip-Hop\n");
    printf("4. Blues\n");
    printf("5. Funk\n");
    printf("6. Country\n");
    printf("7. Musica classica\n");
    printf("8. Musica eletronica\n");
    printf("9. Rap\n");
    printf("10. Reggae\n");
    printf("11. MPB\n");
    scanf("%d", &pesquisa);
        for(int i = 0; i < numCd; i++){
            if(pesquisa == cds[i].gênero){
            printf("Id: %d\n", cds[i].id);
            printf("Banda: %s\n", cds[i].banda);
            printf("Ano de lançamento: %d\n", cds[i].ano);
            printf("Gênero: %d\n", cds[i].gênero);
            printf("Quantidade em estoque: %d\n", quant);
            printf("\033[35m");
            printf("---------------------------\n");
            printf("\033[0m");
            encontrar = 1;
            }
    else if(encontrar == 0){
        printf("Nenhum CD foi encontrado!!\n");
              }
        }
}
void ConsultarseoCDexiste(){
    
    printf("\033[36m");
    printf("-- Consulte os CDs --\n");
    printf("\033[0m");
    for(int i = 0; i < numCd; i++){
    printf("Id: %d\n", cds[i].id);
    printf("Banda: %s\n", cds[i].banda);
    printf("Ano de lançamento: %d\n", cds[i].ano);
    printf("Gênero: %d\n", cds[i].gênero);
    printf("Quantidade em estoque: %d\n", quant);
    printf("\033[35m");
    printf("---------------------------\n");
    printf("\033[0m");
    }
}

void ComprarCD(){
    int quantfinal;
    float valorf;
    
    printf("\033[36m");
    printf("-- Nova compra --\n");
    printf("\033[0m");
    printf("O valor de cada CD é de R$2.50\n");
    printf("Informe a quantidade de CD que você deseja comprar: ");
    scanf("%d", &cds[numCd].comp);
    valorf = (cds[numCd].comp * 2.50);
    quantfinal = (quant - cds[numCd].comp);
    printf("O valor total da sua compra é de: R$%.2f \n", valorf);
    printf("A quantidade atual do estoque %d\n", quantfinal);
}