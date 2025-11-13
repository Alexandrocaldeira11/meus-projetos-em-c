#include <stdio.h>

// =============================================
// FUNÇÕES RECURSIVAS (Torre, Bispo, Rainha)
// =============================================

// Função recursiva para movimento da TORRE (direita)
void moverTorre(int casas) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    printf("Direita ");
    
    // Chamada recursiva: move uma casa a menos
    moverTorre(casas - 1);
}

// Função recursiva para movimento do BISPO (diagonal: cima + direita)
void moverBispo(int casas) {
    // Caso base
    if (casas <= 0) {
        return;
    }
    
    printf("Cima, Direita ");
    
    // Chamada recursiva
    moverBispo(casas - 1);
}

// Função recursiva para movimento da RAINHA (esquerda)
void moverRainha(int casas) {
    // Caso base
    if (casas <= 0) {
        return;
    }
    
    printf("Esquerda ");
    
    // Chamada recursiva
    moverRainha(casas - 1);
}

// =============================================
// MOVIMENTO COMPLEXO DO CAVALO
// =============================================

void moverCavaloComplexo() {
    printf("CAVALO: Movimento complexo em L (2 cima + 1 direita)\n");
    printf("Movimento: ");
    
    // Loops aninhados com múltiplas variáveis e condições
    int vertical_completo = 0;
    int horizontal_completo = 0;
    
    for (int etapa = 1, direcao = 1; etapa <= 3 && !(vertical_completo && horizontal_completo); etapa++) {
        // Loop while com condição múltipla
        int passos_vert = 0;
        while (passos_vert < 2 && !vertical_completo) {
            if (etapa > 2) {
                // Usando continue para pular em condições específicas
                continue;
            }
            
            printf("Cima ");
            passos_vert++;
            
            // Condição complexa para controle de fluxo
            if (passos_vert == 2 && etapa == 2) {
                vertical_completo = 1;
            }
        }
        
        // Controle de break baseado em múltiplas condições
        int passos_horiz = 0;
        do {
            if (vertical_completo && passos_horiz == 0 && etapa >= 2) {
                printf("Direita");
                horizontal_completo = 1;
                
                // Break para sair quando movimento completo
                if (vertical_completo && horizontal_completo) {
                    break;
                }
            }
            passos_horiz++;
        } while (passos_horiz < 1 && !horizontal_completo);
    }
}

// =============================================
// BISPO COM LOOPS ANINHADOS (Requisito adicional)
// =============================================

void moverBispoLoopsAninhados() {
    printf("BISPO (Loops Aninhados): 3 casas na diagonal\n");
    printf("Movimento: ");
    
    // Loop externo: movimento vertical (cima)
    for (int vertical = 1; vertical <= 3; vertical++) {
        // Loop interno: movimento horizontal (direita)
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Cima, Direita ");
        }
    }
}

// =============================================
// FUNÇÃO PRINCIPAL
// =============================================

int main() {
    printf("=== SIMULADOR DE XADREZ - NIVEL MESTRE ===\n\n");
    
    // TORRE com recursividade (5 casas direita)
    printf("TORRE (Recursiva): 5 casas para a direita\n");
    printf("Movimento: ");
    moverTorre(5);
    printf("\n\n");
    
    // BISPO com recursividade (5 casas diagonal)
    printf("BISPO (Recursivo): 5 casas na diagonal\n");
    printf("Movimento: ");
    moverBispo(5);
    printf("\n\n");
    
    // RAINHA com recursividade (8 casas esquerda)
    printf("RAINHA (Recursiva): 8 casas para a esquerda\n");
    printf("Movimento: ");
    moverRainha(8);
    printf("\n\n");
    
    // BISPO com loops aninhados (requisito adicional)
    moverBispoLoopsAninhados();
    printf("\n\n");
    
    // CAVALO com loops complexos
    moverCavaloComplexo();
    printf("\n\n");
    
    printf("=== FIM DA SIMULACAO MESTRE ===\n");
    return 0;
}