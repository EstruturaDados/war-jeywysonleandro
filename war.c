#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===============================
   Estrutura do Territorio
   =============================== */
struct Territorio {
    char nome[20];
    char cor[20];
    int tropas;
};

/* ===============================
   Função de batalha
   =============================== */
void batalhar(struct Territorio *territorios, int atacante, int defensor) {

    int dadoAtaque = rand() % 6 + 1;   // Número de 1 a 6
    int dadoDefesa = rand() % 6 + 1;

    printf("\n--- BATALHA ---\n");
    printf("Atacante rolou: %d\n", dadoAtaque);
    printf("Defensor rolou: %d\n", dadoDefesa);

    if (dadoAtaque >= dadoDefesa) {
        printf("Atacante venceu a rodada!\n");
        territorios[defensor].tropas--;

        if (territorios[defensor].tropas <= 0) {
            printf("Territorio conquistado!\n");
            territorios[defensor].tropas = 1;
        }

    } else {
        printf("Defensor venceu a rodada!\n");
        territorios[atacante].tropas--;
    }
}

/* ===============================
   Função principal
   =============================== */
int main() {

    srand(time(NULL)); // Inicializa aleatoriedade

    struct Territorio *territorios;
    territorios = calloc(5, sizeof(struct Territorio));

    if (territorios == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    /* Cadastro */
    for (int i = 0; i < 5; i++) {

        printf("\nTerritorio %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", territorios[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", territorios[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    int atacante, defensor;

    /* Fase de batalha */
    printf("\n=== FASE DE ATAQUE ===\n");

    printf("Escolha territorio atacante (1-5): ");
    scanf("%d", &atacante);

    printf("Escolha territorio defensor (1-5): ");
    scanf("%d", &defensor);

    atacante--; // Ajuste para índice do vetor
    defensor--;

    batalhar(territorios, atacante, defensor);

    /* Exibir mapa atualizado */
    printf("\n=== MAPA ATUALIZADO ===\n");

    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    free(territorios); // Libera memória

    return 0;
}