#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIVROS 50
#define TAM_STRING 100

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    bool disponivel;
};

int menu(void);
void cadastrar_livro(struct Livro *biblioteca, int *qtd_livros, int capacidade);
void listar_livros(const struct Livro *biblioteca, int qtd_livros);

void limparBufferEntrada(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(void){
    int opcao;
    int qtd_livros = 0;         // contador de livros cadastrados
    const int capacidade = MAX_LIVROS;

    struct Livro *biblioteca = malloc(capacidade * sizeof(struct Livro));
    if (!biblioteca){
        fprintf(stderr, "Falha ao alocar memória.\n");
        return 1;
    }

    do {
        opcao = menu();
        switch (opcao){
            case 1:
                cadastrar_livro(biblioteca, &qtd_livros, capacidade);
                break;

            case 2:
                listar_livros(biblioteca, qtd_livros);
                break;

            case 3:
                printf("Funcionalidade de empréstimo (a implementar).\n");
                break;

            case 4:
                printf("Listagem de empréstimos (a implementar).\n");
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 5);

    free(biblioteca);
    return 0;
}

int menu(void){
    int opcao;
    printf("\n---> MENU DO USUÁRIO <---\n");
    printf("1. Cadastrar livro\n");
    printf("2. Listar livros\n");
    printf("3. Pegar livro emprestado\n");
    printf("4. Listar livros emprestados\n");
    printf("5. Sair\n");
    printf("Escolha: ");
    if (scanf("%d", &opcao) != 1){
        opcao = 0; // força inválido
    }
    limparBufferEntrada();
    return opcao;
}

void cadastrar_livro(struct Livro *biblioteca, int *qtd_livros, int capacidade){
    if (*qtd_livros >= capacidade){
        printf("Capacidade máxima (%d) atingida. Não é possível cadastrar mais livros.\n", capacidade);
        return;
    }

    int idx = *qtd_livros;

    printf("Digite o nome do livro: ");
    if (fgets(biblioteca[idx].nome, TAM_STRING, stdin) == NULL) return;
    biblioteca[idx].nome[strcspn(biblioteca[idx].nome, "\n")] = '\0';

    printf("Digite o nome do autor: ");
    if (fgets(biblioteca[idx].autor, TAM_STRING, stdin) == NULL) return;
    biblioteca[idx].autor[strcspn(biblioteca[idx].autor, "\n")] = '\0';

    printf("Digite o nome da editora: ");
    if (fgets(biblioteca[idx].editora, TAM_STRING, stdin) == NULL) return;
    biblioteca[idx].editora[strcspn(biblioteca[idx].editora, "\n")] = '\0';

    printf("Digite o ano de edição: ");
    if (scanf("%d", &biblioteca[idx].edicao) != 1){
        printf("Entrada inválida para edição.\n");
        limparBufferEntrada();
        return;
    }
    limparBufferEntrada();

    biblioteca[idx].disponivel = true;

    (*qtd_livros)++;
    printf("Cadastro realizado com sucesso! (Total: %d)\n", *qtd_livros);
}

void listar_livros(const struct Livro *biblioteca, int qtd_livros) {
    if (qtd_livros == 0){
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Livros (%d) ---\n", qtd_livros);
    for (int i = 0; i < qtd_livros; i++) {
        printf("#%d\n", i + 1);
        printf("  Título:     %s\n", biblioteca[i].nome);
        printf("  Autor:      %s\n", biblioteca[i].autor);
        printf("  Editora:    %s\n", biblioteca[i].editora);
        printf("  Edição:     %d\n", biblioteca[i].edicao);
        printf("  Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
    }
}