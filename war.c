// ================= BIBLIOTECAS =================

// Biblioteca para usar printf e scanf
#include <stdio.h>

// Biblioteca para usar rand() e srand()
#include <stdlib.h>

// Biblioteca para usar time()
#include <time.h>

// Biblioteca para usar strcmp() e strcpy()
#include <string.h>


// ================= CONSTANTE =================

// Define uma constante chamada TOTAL_TERRITORIOS com valor 4
// Isso evita usar número "solto" no código
#define TOTAL_TERRITORIOS 4


// ================= STRUCT =================

// Criamos um novo tipo chamado Territorio
// Ele funciona como um molde
typedef struct {

    char nome[30];   // Guarda o nome do território (texto)
    char cor[20];    // Guarda a cor do exército (texto)
    int tropas;      // Guarda a quantidade de tropas (número inteiro)

} Territorio; // Finalizamos a struct


// ================= FUNÇÃO MOSTRAR MAPA =================

// const significa que essa função NÃO pode alterar os dados
void mostrarMapa(const Territorio t[]) {

    printf("\n===== MAPA =====\n"); // Mostra título

    // Laço for para percorrer todos os territórios
    for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

        printf("Territorio %d\n", i + 1); // Mostra número do território

        printf("Nome: %s\n", t[i].nome); // %s é usado para texto

        printf("Cor: %s\n", t[i].cor);   // Mostra a cor

        printf("Tropas: %d\n\n", t[i].tropas); // %d é usado para número inteiro
    }
}


// ================= FUNÇÃO ATACAR =================

// Aqui NÃO usamos const porque vamos alterar os dados
void atacar(Territorio t[]) {

    int origem;   // Variável para guardar território atacante
    int destino;  // Variável para guardar território atacado

    printf("Escolha o territorio de ataque (1-4): ");
    scanf("%d", &origem); // Lê número digitado

    printf("Escolha o territorio a ser atacado (1-4): ");
    scanf("%d", &destino); // Lê número digitado

    origem--;  // Ajusta para índice do vetor (vetor começa em 0)
    destino--; // Ajusta para índice do vetor

    // Verifica se o atacante tem mais tropas
    if(t[origem].tropas > t[destino].tropas) {

        printf("Vitoria!\n");

        // O território conquistado recebe as tropas
        t[destino].tropas = t[origem].tropas - 1;

        // Copia a cor do atacante para o conquistado
        strcpy(t[destino].cor, t[origem].cor);

    } else {

        printf("Derrota!\n");

        // Se perder, o território atacante fica com 1 tropa
        t[origem].tropas = 1;
    }
}


// ================= FUNÇÃO VERIFICAR MISSÃO =================

// Recebe os territórios e o número da missão
void verificarMissao(const Territorio t[], int missao) {

    int contador = 0; // Conta territórios conquistados

    // Se a missão for 1
    if(missao == 1) {

        // Percorre todos os territórios
        for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

            // strcmp compara textos
            // Se for diferente de Verde
            if(strcmp(t[i].cor, "Verde") != 0) {

                contador++; // Soma 1
            }
        }

        // Se nenhum território for Verde
        if(contador == TOTAL_TERRITORIOS) {

            printf("Missao cumprida! Exército Verde destruido!\n");

        } else {

            printf("Missao ainda nao concluida.\n");
        }

    } 
    else { // Missão 2

        for(int i = 0; i < TOTAL_TERRITORIOS; i++) {

            // Se a cor for Azul
            if(strcmp(t[i].cor, "Azul") == 0) {

                contador++; // Soma 1
            }
        }

        // Se tiver 3 ou mais territórios Azuis
        if(contador >= 3) {

            printf("Missao cumprida! 3 territorios conquistados!\n");

        } else {

            printf("Missao ainda nao concluida.\n");
        }
    }
}


// ================= FUNÇÃO PRINCIPAL =================

int main() {

    srand(time(NULL)); // Inicializa números aleatórios

    // Criando vetor de territórios já preenchido
    Territorio territorios[TOTAL_TERRITORIOS] = {

        {"Brasil", "Azul", 10},
        {"Argentina", "Verde", 8},
        {"Chile", "Verde", 6},
        {"Uruguai", "Azul", 5}
    };

    int missao = rand() % 2 + 1; // Gera missão 1 ou 2

    int opcao; // Guarda escolha do menu

    // Loop do menu
    do {

        mostrarMapa(territorios); // Mostra mapa

        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao); // Lê opção

        switch(opcao) {

            case 1:
                atacar(territorios); // Chama função atacar
                break;

            case 2:
                verificarMissao(territorios, missao); // Verifica missão
                break;
        }

    } while(opcao != 0); // Repete até digitar 0

    printf("Jogo encerrado.\n");

    return 0; // Finaliza programa
}