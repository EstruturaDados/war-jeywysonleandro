#include <stdio.h>

struct Territorio {
    char nome[20];
    char cor[20];
    int tropas;
};

int main() {

    struct Territorio territorios[5];

    for (int i = 0; i < 5; i++) {

        printf("Território %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", territorios[i].nome);

        printf("Cor do exército: ");
        scanf("%s", territorios[i].cor);

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
    
    }

    // Exibir os territórios cadastrados
    printf("\nTerritórios cadastrados:\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Número de tropas: %d\n", territorios[i].tropas);

    }

    return 0;
}