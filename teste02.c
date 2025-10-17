#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char nome[20];
    int idade;
};

int main() {
    int opcao, i, z;
    i = 0;

    struct Pessoa lista = {"Vinicius", 29};

    printf("%s\n%d\n", lista.nome, lista.idade);


    // Aloca memória para cada pessoa
    struct Pessoa *vetor_lista = malloc(10 * sizeof(struct Pessoa));

    do{
        printf("Digite\n01 - Cadastrar\n02 - Listar\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                printf("Nome: ");
                scanf("%19s", vetor_lista[i].nome);
                printf("Idade: ");
                scanf("%d", &vetor_lista[i].idade);
                i++;
                printf("Pessoa cadastrada com sucesso.\n");
                break;

            case 2:
                printf("\n--- Lista de Pessoas ---\n");
                for (z=0; z<10;z++){
                    printf("Posição %d | Nome: %s | Idade: %d\n",
                    z + 1, vetor_lista[z].nome, vetor_lista[z].idade);
                }
                break;

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 3);


    // Libera memória
    free(vetor_lista);

    return 0;
}