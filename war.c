/* ============================================================
   PROJETO WAR - CADASTRO DE TERRITORIOS
   Objetivo: Cadastrar e exibir 5 territórios usando struct e vetor
   ============================================================ */

#include <stdio.h> // Biblioteca padrão para entrada e saída (printf e scanf)

/* ============================================================
   Estrutura Territorio
   Serve para agrupar informações sobre cada território
   ============================================================ */
struct Territorio {

    char nome[20];   // Armazena o nome do território (texto)
    char cor[20];    // Armazena a cor do exército dominante
    int tropas;      // Armazena o número de tropas presentes
};

int main() { // Função principal do programa

    /* Criação de um vetor estático para armazenar 5 territórios */
    struct Territorio territorios[5];

    /* ============================================================
       Loop para cadastro dos territórios
       ============================================================ */
    for (int i = 0; i < 5; i++) {

        printf("Territorio %d\n", i + 1); // Mostra qual território está sendo cadastrado

        printf("Nome: "); // Solicita o nome do território
        scanf("%s", territorios[i].nome); // Lê o nome e armazena na struct

        printf("Cor do exercito: "); // Solicita a cor do exército
        scanf("%s", territorios[i].cor); // Lê a cor

        printf("Numero de tropas: "); // Solicita número de tropas
        scanf("%d", &territorios[i].tropas); // & indica o endereço de memória para armazenar o valor
    }

    /* ============================================================
       Exibição dos territórios cadastrados
       ============================================================ */

    printf("\nTerritorios cadastrados:\n");

    for (int i = 0; i < 5; i++) {

        printf("Territorio %d\n", i + 1); // Mostra o número do território

        printf("Nome: %s\n", territorios[i].nome); // Mostra o nome salvo
        printf("Cor do exercito: %s\n", territorios[i].cor); // Mostra a cor salva
        printf("Numero de tropas: %d\n", territorios[i].tropas); // Mostra tropas

        printf("\n"); // Pula linha para melhor visualização
    }

    return 0; // Finaliza o programa
}