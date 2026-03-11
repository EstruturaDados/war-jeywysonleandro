#include <stdio.h>
#include <string.h>

#define TOTAL_TERRITORIOS 5

// Criando a struct
struct Territorio {
    char nome[50];
    char cor[20];
    int tropas;
};

int main() {

    struct Territorio territorios[TOTAL_TERRITORIOS];

    // Cadastro dos territórios
    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Nome do território: ");
        fgets(territorios[i].nome, 50, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(territorios[i].cor, 20, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o enter do buffer
    }

    // Exibição do mapa
    printf("\n====== MAPA ATUAL ======\n");

    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);

    }

    return 0;
}