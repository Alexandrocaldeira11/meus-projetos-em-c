#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Constantes para melhor legibilidade do código
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Estrutura para representar uma habilidade especial
typedef struct {
    char nome[20];
    int matriz[TAM_HABILIDADE][TAM_HABILIDADE];
    int centro_linha;
    int centro_coluna;
    char simbolo;
} Habilidade;

// Função para verificar se uma posição está dentro do tabuleiro
bool dentro_do_tabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM_TABULEIRO && 
            coluna >= 0 && coluna < TAM_TABULEIRO);
}

// Função para verificar sobreposição entre navios
bool verificar_sobreposicao(int tabuleiro[][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int pos_linha = linha;
        int pos_coluna = coluna;
        
        switch (direcao) {
            case 'H': pos_coluna = coluna + i; break;
            case 'V': pos_linha = linha + i; break;
            case 'D': 
                pos_linha = linha + i;
                pos_coluna = coluna + i;
                break;
            case 'd':
                pos_linha = linha + i;
                pos_coluna = coluna - i;
                break;
        }
        
        if (dentro_do_tabuleiro(pos_linha, pos_coluna) && 
            tabuleiro[pos_linha][pos_coluna] == NAVIO) {
            return true;
        }
    }
    return false;
}

// Função para posicionar um navio no tabuleiro
bool posicionar_navio(int tabuleiro[][TAM_TABULEIRO], int linha, int coluna, char direcao, char* tipo_navio) {
    // Verifica se o navio cabe no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        int pos_linha = linha;
        int pos_coluna = coluna;
        
        switch (direcao) {
            case 'H': pos_coluna = coluna + i; break;
            case 'V': pos_linha = linha + i; break;
            case 'D': 
                pos_linha = linha + i;
                pos_coluna = coluna + i;
                break;
            case 'd':
                pos_linha = linha + i;
                pos_coluna = coluna - i;
                break;
        }
        
        if (!dentro_do_tabuleiro(pos_linha, pos_coluna)) {
            return false;
        }
    }
    
    // Verifica sobreposição
    if (verificar_sobreposicao(tabuleiro, linha, coluna, direcao)) {
        return false;
    }
    
    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        int pos_linha = linha;
        int pos_coluna = coluna;
        
        switch (direcao) {
            case 'H': pos_coluna = coluna + i; break;
            case 'V': pos_linha = linha + i; break;
            case 'D': 
                pos_linha = linha + i;
                pos_coluna = coluna + i;
                break;
            case 'd':
                pos_linha = linha + i;
                pos_coluna = coluna - i;
                break;
        }
        
        tabuleiro[pos_linha][pos_coluna] = NAVIO;
    }
    
    return true;
}

// Função para inicializar matriz de habilidade CONE
void inicializar_cone(int matriz[][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cone: formato triangular que se expande e depois contrai
            if ((i == 0 && j == 2) ||                    // Topo
                (i == 1 && j >= 1 && j <= 3) ||         // Expansão
                (i == 2) ||                             // Base larga
                (i == 3 && j >= 1 && j <= 3) ||         // Contração
                (i == 4 && j == 2)) {                   // Base
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para inicializar matriz de habilidade CRUZ
void inicializar_cruz(int matriz[][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cruz: linha central e coluna central
            if (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para inicializar matriz de habilidade OCTAEDRO
void inicializar_octaedro(int matriz[][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Octaedro: formato de losango usando distância do centro
            int distancia_centro = abs(i - TAM_HABILIDADE/2) + abs(j - TAM_HABILIDADE/2);
            if (distancia_centro <= TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para exibir uma matriz de habilidade
void exibir_matriz_habilidade(int matriz[][TAM_HABILIDADE], const char* nome) {
    printf("Matriz de Habilidade: %s\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[][TAM_TABULEIRO], Habilidade hab) {
    int centro_hab = TAM_HABILIDADE / 2;
    
    printf("Aplicando habilidade %s no centro (%d,%d):\n", 
           hab.nome, hab.centro_linha, hab.centro_coluna);
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (hab.matriz[i][j] == 1) {
                // Calcula posição no tabuleiro
                int tab_linha = hab.centro_linha + (i - centro_hab);
                int tab_coluna = hab.centro_coluna + (j - centro_hab);
                
                // Verifica se está dentro do tabuleiro
                if (dentro_do_tabuleiro(tab_linha, tab_coluna)) {
                    // Marca apenas se não for navio (para preservar os navios)
                    if (tabuleiro[tab_linha][tab_coluna] != NAVIO) {
                        tabuleiro[tab_linha][tab_coluna] = HABILIDADE;
                    }
                    printf("  (%d,%d) ", tab_linha, tab_coluna);
                }
            }
        }
    }
    printf("\n\n");
}

// Função para exibir o tabuleiro com cores simbólicas
void exibir_tabuleiro_colorido(int tabuleiro[][TAM_TABULEIRO]) {
    printf("\n=== BATALHA NAVAL - NIVEL MESTRE ===\n");
    printf("Tabuleiro 10x10 com Navios e Habilidades Especiais\n");
    printf("Legenda: 0 = Agua, 3 = Navio, 5 = Area de Habilidade\n\n");
    
    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Tabuleiro com índices de linha e cores simbólicas
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:
                    printf(" . ");  // Água
                    break;
                case NAVIO:
                    printf(" N ");  // Navio
                    break;
                case HABILIDADE:
                    printf(" H ");  // Habilidade
                    break;
                default:
                    printf(" ? ");
            }
        }
        printf("\n");
    }
}

// Função para exibir o tabuleiro numérico (alternativo)
void exibir_tabuleiro_numerico(int tabuleiro[][TAM_TABULEIRO]) {
    printf("\n=== VISUALIZACAO NUMERICA ===\n");
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular estatísticas do tabuleiro
void calcular_estatisticas(int tabuleiro[][TAM_TABULEIRO]) {
    int count_agua = 0, count_navios = 0, count_habilidade = 0;
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA: count_agua++; break;
                case NAVIO: count_navios++; break;
                case HABILIDADE: count_habilidade++; break;
            }
        }
    }
    
    printf("\n=== ESTATISTICAS DO TABULEIRO ===\n");
    printf("Posicoes com agua: %d\n", count_agua);
    printf("Posicoes com navios: %d\n", count_navios);
    printf("Posicoes com habilidades: %d\n", count_habilidade);
    printf("Total de posicoes: %d\n", TAM_TABULEIRO * TAM_TABULEIRO);
    printf("Taxa de ocupacao: %.1f%%\n", 
           ((count_navios + count_habilidade) * 100.0) / (TAM_TABULEIRO * TAM_TABULEIRO));
}

int main() {
    // Declaração e inicialização do tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa todas as posições com água (valor 0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    printf("=== FASE 1: POSICIONAMENTO DOS NAVIOS ===\n");
    
    // Posiciona 4 navios (2 retos + 2 diagonais)
    int navios_posicionados = 0;
    
    // Navio horizontal
    if (posicionar_navio(tabuleiro, 2, 1, 'H', "Horizontal")) {
        printf("Navio horizontal posicionado: linha 2, colunas 1-3\n");
        navios_posicionados++;
    }
    
    // Navio vertical
    if (posicionar_navio(tabuleiro, 5, 7, 'V', "Vertical")) {
        printf("Navio vertical posicionado: coluna 7, linhas 5-7\n");
        navios_posicionados++;
    }
    
    // Navio diagonal principal
    if (posicionar_navio(tabuleiro, 0, 2, 'D', "Diagonal Principal")) {
        printf("Navio diagonal principal posicionado\n");
        navios_posicionados++;
    }
    
    // Navio diagonal secundária
    if (posicionar_navio(tabuleiro, 1, 8, 'd', "Diagonal Secundaria")) {
        printf("Navio diagonal secundaria posicionado\n");
        navios_posicionados++;
    }
    
    printf("\nTotal de navios posicionados: %d/4\n\n", navios_posicionados);

    // Fase 2: Habilidades Especiais
    printf("=== FASE 2: HABILIDADES ESPECIAIS ===\n");
    
    // Cria e inicializa as habilidades especiais
    Habilidade habilidades[3];
    
    // Habilidade Cone
    strcpy(habilidades[0].nome, "CONE");
    inicializar_cone(habilidades[0].matriz);
    habilidades[0].centro_linha = 2;
    habilidades[0].centro_coluna = 2;
    habilidades[0].simbolo = 'C';
    
    // Habilidade Cruz
    strcpy(habilidades[1].nome, "CRUZ");
    inicializar_cruz(habilidades[1].matriz);
    habilidades[1].centro_linha = 5;
    habilidades[1].centro_coluna = 5;
    habilidades[1].simbolo = '+';
    
    // Habilidade Octaedro
    strcpy(habilidades[2].nome, "OCTAEDRO");
    inicializar_octaedro(habilidades[2].matriz);
    habilidades[2].centro_linha = 7;
    habilidades[2].centro_coluna = 7;
    habilidades[2].simbolo = 'O';

    // Exibe as matrizes de habilidade
    printf("\n=== MATRIZES DE HABILIDADE ===\n\n");
    for (int i = 0; i < 3; i++) {
        exibir_matriz_habilidade(habilidades[i].matriz, habilidades[i].nome);
    }

    // Aplica as habilidades ao tabuleiro
    printf("=== APLICANDO HABILIDADES AO TABULEIRO ===\n\n");
    for (int i = 0; i < 3; i++) {
        aplicar_habilidade(tabuleiro, habilidades[i]);
    }

    // Exibe os resultados finais
    printf("=== RESULTADO FINAL ===\n");
    exibir_tabuleiro_colorido(tabuleiro);
    exibir_tabuleiro_numerico(tabuleiro);
    calcular_estatisticas(tabuleiro);

    // Informações adicionais sobre as habilidades
    printf("\n=== CENTROS DAS HABILIDADES ===\n");
    for (int i = 0; i < 3; i++) {
        printf("Habilidade %s: Centro em (%d, %d)\n", 
               habilidades[i].nome, habilidades[i].centro_linha, habilidades[i].centro_coluna);
    }

    printf("\n=== DESAFIO CONCLUIDO - NIVEL MESTRE ===\n");
    printf("Implementacao completa de habilidades especiais com areas de efeito!\n");

    return 0;
}