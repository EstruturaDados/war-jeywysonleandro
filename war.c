#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_TERRITORIOS 5

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;


// inicializar territórios automaticamente
void inicializarTerritorios(Territorio *t) {

    strcpy(t[0].nome, "Brasil");
    strcpy(t[0].cor, "Azul");
    t[0].tropas = 10;

    strcpy(t[1].nome, "Argentina");
    strcpy(t[1].cor, "Vermelho");
    t[1].tropas = 8;

    strcpy(t[2].nome, "Chile");
    strcpy(t[2].cor, "Verde");
    t[2].tropas = 6;

    strcpy(t[3].nome, "Peru");
    strcpy(t[3].cor, "Amarelo");
    t[3].tropas = 7;

    strcpy(t[4].nome, "Colombia");
    strcpy(t[4].cor, "Verde");
    t[4].tropas = 5;
}


// mostrar mapa
void mostrarMapa(const Territorio *t) {

    printf("\n====== MAPA ======\n");

    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

        printf("\n[%d] %s\n", i + 1, t[i].nome);
        printf("Exército: %s\n", t[i].cor);
        printf("Tropas: %d\n", t[i].tropas);

    }

    printf("\n==================\n");
}


// sistema de ataque
void atacar(Territorio *t) {

    int atacante, defensor;

    printf("\nEscolha território ATACANTE: ");
    scanf("%d", &atacante);

    printf("Escolha território DEFENSOR: ");
    scanf("%d", &defensor);

    atacante--;
    defensor--;

    if(atacante == defensor) {
        printf("\nNão pode atacar o mesmo território!\n");
        return;
    }

    if(t[atacante].tropas <= 1) {
        printf("\nTropas insuficientes para atacar!\n");
        return;
    }

    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("\nDado atacante: %d\n", dadoAtaque);
    printf("Dado defensor: %d\n", dadoDefesa);

    if(dadoAtaque >= dadoDefesa) {

        printf("\nAtacante venceu!\n");

        t[defensor].tropas--;

        if(t[defensor].tropas <= 0) {

            printf("\nTerritório conquistado!\n");

            strcpy(t[defensor].cor, t[atacante].cor);
            t[defensor].tropas = 1;
        }

    } else {

        printf("\nDefensor venceu!\n");

        t[atacante].tropas--;

    }

}


// missão 1: destruir exército verde
int destruirVerde(const Territorio *t) {

    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

        if(strcmp(t[i].cor, "Verde") == 0) {
            return 0;
        }

    }

    return 1;
}


// missão 2: conquistar 3 territórios
int conquistarTres(const Territorio *t) {

    int contador = 0;

    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

        if(strcmp(t[i].cor, "Azul") == 0) {
            contador++;
        }

    }

    if(contador >= 3)
        return 1;

    return 0;
}


// verificar missão
int verificarMissao(const Territorio *t, int missao) {

    if(missao == 1)
        return destruirVerde(t);

    if(missao == 2)
        return conquistarTres(t);

    return 0;
}


// mostrar missão
void mostrarMissao(int missao) {

    printf("\n===== MISSÃO =====\n");

    if(missao == 1)
        printf("Destruir todo o exército VERDE\n");

    if(missao == 2)
        printf("Conquistar 3 territórios AZUIS\n");

}


// menu principal
void menu(Territorio *t, int missao) {

    int opcao;

    do {

        mostrarMapa(t);

        printf("\n1 - Atacar\n");
        printf("2 - Verificar Missão\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                atacar(t);
                break;

            case 2:

                if(verificarMissao(t, missao)) {
                    printf("\n🏆 MISSÃO COMPLETADA! VOCÊ VENCEU!\n");
                    return;
                } else {
                    printf("\nMissão ainda não concluída.\n");
                }

                break;

            case 0:
                printf("\nSaindo do jogo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");

        }

    } while(opcao != 0);

}


int main() {

    srand(time(NULL));

    Territorio *territorios = calloc(TOTAL_TERRITORIOS, sizeof(Territorio));

    if(territorios == NULL) {
        printf("Erro de memória!\n");
        return 1;
    }

    inicializarTerritorios(territorios);

    int missao = rand() % 2 + 1;

    mostrarMissao(missao);

    menu(territorios, missao);

    free(territorios);

    return 0;
}