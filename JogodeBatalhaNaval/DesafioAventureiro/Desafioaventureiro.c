#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Constantes para melhor legibilidade do código
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

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
        
        // Calcula a posição baseada na direção
        switch (direcao) {
            case 'H': // Horizontal
                pos_coluna = coluna + i;
                break;
            case 'V': // Vertical
                pos_linha = linha + i;
                break;
            case 'D': // Diagonal principal (sudeste)
                pos_linha = linha + i;
                pos_coluna = coluna + i;
                break;
            case 'd': // Diagonal secundária (sudoeste)
                pos_linha = linha + i;
                pos_coluna = coluna - i;
                break;
        }
        
        // Verifica se a posição já está ocupada
        if (dentro_do_tabuleiro(pos_linha, pos_coluna) && 
            tabuleiro[pos_linha][pos_coluna] == NAVIO) {
            return true; // Há sobreposição
        }
    }
    return false; // Não há sobreposição
}

// Função para posicionar um navio no tabuleiro
bool posicionar_navio(int tabuleiro[][TAM_TABULEIRO], int linha, int coluna, char direcao, char* tipo_navio) {
    // Verifica se o navio cabe no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        int pos_linha = linha;
        int pos_coluna = coluna;
        
        switch (direcao) {
            case 'H': // Horizontal
                pos_coluna = coluna + i;
                break;
            case 'V': // Vertical
                pos_linha = linha + i;
                break;
            case 'D': // Diagonal principal
                pos_linha = linha + i;
                pos_coluna = coluna + i;
                break;
            case 'd': // Diagonal secundária
                pos_linha = linha + i;
                pos_coluna = coluna - i;
                break;
        }
        
        if (!dentro_do_tabuleiro(pos_linha, pos_coluna)) {
            printf("Erro: %s fora dos limites do tabuleiro!\n", tipo_navio);
            return false; // Navio não cabe
        }
    }
    
    // Verifica sobreposição
    if (verificar_sobreposicao(tabuleiro, linha, coluna, direcao)) {
        printf("Erro: %s sobrepõe outro navio!\n", tipo_navio);
        return false; // Há sobreposição
    }
    
    // Posiciona o navio
    printf("Posicionando navio %s: ", tipo_navio);
    for (int i = 0; i < TAM_NAVIO; i++) {
        int pos_linha = linha;
        int pos_coluna = coluna;
        
        switch (direcao) {
            case 'H':
                pos_coluna = coluna + i;
                break;
            case 'V':
                pos_linha = linha + i;
                break;
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
        printf("(%d,%d) ", pos_linha, pos_coluna);
    }
    printf("\n");
    
    return true;
}

// Função para exibir o tabuleiro de forma organizada
void exibir_tabuleiro(int tabuleiro[][TAM_TABULEIRO]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL - NIVEL AVENTUREIRO ===\n");
    printf("Tabuleiro 10x10 com 4 navios (2 retos + 2 diagonais)\n");
    printf("Legenda: 0 = Agua, 3 = Navio\n\n");
    
    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Tabuleiro com índices de linha
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para exibir informações detalhadas dos navios
void exibir_informacoes_navios(int navios[][4], char direcoes[], char* tipos[]) {
    printf("\n=== INFORMAÇÕES DETALHADAS DOS NAVIOS ===\n");
    for (int i = 0; i < 4; i++) {
        printf("Navio %d (%s):\n", i + 1, tipos[i]);
        printf("  Posição inicial: (%d, %d)\n", navios[i][0], navios[i][1]);
        printf("  Direção: %c\n", direcoes[i]);
        printf("  Coordenadas: ");
        
        for (int j = 0; j < TAM_NAVIO; j++) {
            int linha = navios[i][0];
            int coluna = navios[i][1];
            
            switch (direcoes[i]) {
                case 'H':
                    coluna = navios[i][1] + j;
                    break;
                case 'V':
                    linha = navios[i][0] + j;
                    break;
                case 'D':
                    linha = navios[i][0] + j;
                    coluna = navios[i][1] + j;
                    break;
                case 'd':
                    linha = navios[i][0] + j;
                    coluna = navios[i][1] - j;
                    break;
            }
            printf("(%d,%d) ", linha, coluna);
        }
        printf("\n\n");
    }
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

    // Definição dos quatro navios [linha, coluna, direção, tipo]
    int navios[4][4] = {
        // Dois navios retos (horizontal/vertical)
        {2, 1, 'H', 0},  // Horizontal
        {5, 7, 'V', 1},  // Vertical
        // Dois navios diagonais
        {0, 2, 'D', 2},  // Diagonal principal
        {1, 8, 'd', 3}   // Diagonal secundária
    };
    
    char direcoes[] = {'H', 'V', 'D', 'd'};
    char* tipos_navios[] = {
        "Horizontal", 
        "Vertical", 
        "Diagonal Principal", 
        "Diagonal Secundária"
    };

    printf("=== INICIANDO POSICIONAMENTO DOS NAVIOS ===\n");
    
    // Posiciona todos os navios
    bool sucesso = true;
    for (int i = 0; i < 4; i++) {
        if (!posicionar_navio(tabuleiro, navios[i][0], navios[i][1], 
                             direcoes[i], tipos_navios[i])) {
            sucesso = false;
            break;
        }
    }

    // Exibe resultados
    if (sucesso) {
        exibir_tabuleiro(tabuleiro);
        exibir_informacoes_navios(navios, direcoes, tipos_navios);
        
        // Estatísticas do tabuleiro
        int count_navios = 0;
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            for (int j = 0; j < TAM_TABULEIRO; j++) {
                if (tabuleiro[i][j] == NAVIO) {
                    count_navios++;
                }
            }
        }
        
        printf("=== ESTATÍSTICAS ===\n");
        printf("Total de posições com navios: %d/%d\n", 
               count_navios, TAM_TABULEIRO * TAM_TABULEIRO);
        printf("Posições ocupadas: %.1f%% do tabuleiro\n", 
               (count_navios * 100.0) / (TAM_TABULEIRO * TAM_TABULEIRO));
        
    } else {
        printf("\nFalha no posicionamento dos navios!\n");
        printf("Verifique as coordenadas e tente novamente.\n");
    }

    return 0;
}