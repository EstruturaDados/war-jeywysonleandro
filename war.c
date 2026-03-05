#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_TERRITORIOS 4

// Estrutura do território
typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

// ------------------- FUNÇÃO MOSTRAR MAPA -------------------
void mostrarMapa(const Territorio t[]) {
    printf("\n===== MAPA =====\n");

    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", t[i].nome);
        printf("Cor: %s\n", t[i].cor);
        printf("Tropas: %d\n\n", t[i].tropas);
    }
}

// ------------------- FUNÇÃO ATACAR -------------------
void atacar(Territorio t[]) {
    int origem, destino;

    printf("Escolha o territorio de ataque (1-4): ");
    scanf("%d", &origem);

    printf("Escolha o territorio a ser atacado (1-4): ");
    scanf("%d", &destino);

    origem--;
    destino--;

    if(t[origem].tropas > t[destino].tropas) {
        printf("Vitoria!\n");
        t[destino].tropas = t[origem].tropas - 1;
        t[destino].cor[0] = '\0';
        strcpy(t[destino].cor, t[origem].cor);
    } else {
        printf("Derrota!\n");
        t[origem].tropas = 1;
    }
}

// ------------------- FUNÇÃO VERIFICAR MISSÃO -------------------
void verificarMissao(const Territorio t[], int missao) {

    int contador = 0;

    if(missao == 1) {
        for(int i = 0; i < TOTAL_TERRITORIOS; i++) {
            if(strcmp(t[i].cor, "Verde") != 0) {
                contador++;
            }
        }

        if(contador == TOTAL_TERRITORIOS) {
            printf("Missao cumprida! Exército Verde destruido!\n");
        } else {
            printf("Missao ainda nao concluida.\n");
        }

    } else {
        for(int i = 0; i < TOTAL_TERRITORIOS; i++) {
            if(strcmp(t[i].cor, "Azul") == 0) {
                contador++;
            }
        }

        if(contador >= 3) {
            printf("Missao cumprida! 3 territorios conquistados!\n");
        } else {
            printf("Missao ainda nao concluida.\n");
        }
    }
}

// ------------------- MAIN -------------------
int main() {

    srand(time(NULL));

    Territorio territorios[TOTAL_TERRITORIOS] = {
        {"Brasil", "Azul", 10},
        {"Argentina", "Verde", 8},
        {"Chile", "Verde", 6},
        {"Uruguai", "Azul", 5}
    };

    int missao = rand() % 2 + 1;
    int opcao;

    do {
        mostrarMapa(territorios);

        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                atacar(territorios);
                break;
            case 2:
                verificarMissao(territorios, missao);
                break;
        }

    } while(opcao != 0);

    printf("Jogo encerrado.\n");

    return 0;
}