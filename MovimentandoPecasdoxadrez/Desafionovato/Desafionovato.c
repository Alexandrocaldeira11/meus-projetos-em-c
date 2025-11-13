#include <stdio.h>

int main() {
    int i;
    int casas_torre = 5; // Número de casas que a Torre vai andar

    // --- 1. Movimento da Torre (usando FOR) ---
    printf("--- Movimento da Torre (usando FOR) ---\n");
    
    // O loop 'for' é ótimo pois sabemos o número exato de repetições (5)
    for (i = 1; i <= casas_torre; i++) {
        // Imprime a direção a cada casa percorrida
        printf("Torre moveu 1 casa para a Direita (Passo %d de %d)\n", i, casas_torre);
    }

    /*
    
    // --- 2. Movimento do Bispo (usando WHILE) ---
    // (O código do Bispo viria aqui)
    
    // --- 3. Movimento da Rainha (usando DO-WHILE) ---
    // (O código da Rainha viria aqui)
    
    */

    return 0;
}