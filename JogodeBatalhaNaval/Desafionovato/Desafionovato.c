#include <stdio.h>

// Constantes para facilitar a leitura do código
#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3 // Valor que representa o navio, como pedido no desafio

int main() {
    // 1. Criar uma matriz (tabuleiro) 10x10
    int tabuleiro[LINHAS][COLUNAS];
    int i, j; // Variáveis de controle para os loops

    // 2. Inicializar todo o tabuleiro com AGUA (0)
    // Usamos loops aninhados (um 'for' dentro do outro)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    printf("=== BATALHA NAVAL - NIVEL NOVATO ===\n");
    printf("Tabuleiro 10x10 inicializado com agua (0):\n\n");

    // 3. Exibir o tabuleiro (ainda vazio, só com água)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            // Imprime o valor da posição e um espaço
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha ao final de cada linha da matriz
        printf("\n"); 
    }

    /*
    
    // --- Próximo Passo: Posicionar os Navios ---
    // (O código para adicionar os navios viria aqui)
    // Ex: tabuleiro[2][3] = NAVIO;
    
    */

    return 0;
}