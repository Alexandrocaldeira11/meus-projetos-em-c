#include <stdio.h>

int main() {
    printf("=== SIMULADOR DE XADREZ - NIVEL AVENTUREIRO ===\n\n");
    
    // Torre: 5 casas para a direita usando FOR
    printf("TORRE: 5 casas para a direita\n");
    printf("Movimento: ");
    for(int casa = 1; casa <= 5; casa++) {
        printf("Direita ");
    }
    printf("\n\n");
    
    // Bispo: 5 casas na diagonal (cima + direita) usando WHILE
    printf("BISPO: 5 casas na diagonal (cima + direita)\n");
    printf("Movimento: ");
    int casa_bispo = 1;
    while(casa_bispo <= 5) {
        printf("Cima, Direita ");
        casa_bispo++;
    }
    printf("\n\n");
    
    // Rainha: 8 casas para a esquerda usando DO-WHILE
    printf("RAINHA: 8 casas para a esquerda\n");
    printf("Movimento: ");
    int casa_rainha = 1;
    do {
        printf("Esquerda ");
        casa_rainha++;
    } while(casa_rainha <= 8);
    printf("\n\n");
    
    // CAVALO: Movimento em "L" - 2 casas para baixo + 1 casa para esquerda
    printf("CAVALO: Movimento em L (2 baixo + 1 esquerda)\n");
    printf("Movimento: ");
    
    // Loops aninhados: FOR (obrigatório) + DO-WHILE
    for(int movimento_vertical = 1; movimento_vertical <= 2; movimento_vertical++) {
        // Loop externo FOR controla as 2 casas verticais (baixo)
        int movimento_horizontal = 1;
        
        do {
            // Loop interno DO-WHILE controla as casas horizontais
            if(movimento_vertical <= 2) {
                printf("Baixo ");
            } else {
                printf("Esquerda ");
            }
            movimento_horizontal++;
        } while(movimento_horizontal <= 1 && movimento_vertical <= 2);
    }
    
    // Última casa horizontal (esquerda) após as duas verticais
    printf("Esquerda");
    
    printf("\n\n=== FIM DA SIMULACAO ===\n");
    return 0;
}