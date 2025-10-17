#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 10

struct Pessoa {
    char nome[50];
    int idade;
};

int menu();

struct Pessoa cadastrar(struct Pessoa *lista);


int main(){
    int opcao, i;

    struct Pessoa *lista = malloc(MAX_PESSOAS * sizeof(struct Pessoa));

    do{
        opcao = menu();
        switch(opcao){
            case 1:
                cadastrar(lista);
                break;
            case 2:
                i = 0;
                while (lista[i].nome[0] != '\0') { // Para quando encontrar nome vazio
                    printf("Nome: %s\n", lista[i].nome);
                    i++;
                }
                break;
            case 3:
                break;
        }
    } while(opcao != 3);
}

int menu(){
    int opcao;
    printf("Digite \n01 para cadastrar\n02 para listar\n03 para sair\n");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

struct Pessoa cadastrar(struct Pessoa *lista){
    int qtd;
    printf("Digite a quantidade de pessoas na lista: ");
    scanf("%d", &qtd);
    getchar();
    for (int i = 0; i < qtd; i++){
    printf("Digite nome: ");
    scanf("%s", &lista[i].nome);
    getchar();
    printf("Digite idade: ");
    scanf("%d", &lista[i].idade);
    getchar();
    }
    return *lista;
}