#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib; // Em Milhões de R$
    int pontos_turisticos;
    float densidade; // Será calculada
    float pib_per_capita; // Será calculada
} Carta;
 
// Array para controlar atributos disponíveis no menu dinâmico
int atributos_disponiveis[6] = {1, 1, 1, 1, 1, 1}; // 1 = disponível, 0 = indisponível
 
// Nomes dos atributos para exibição
const char *nomes_atributos[] = {
    "Populacao", "Area", "PIB", "Pontos Turisticos", 
    "Densidade Demografica", "PIB per Capita"
};
 
// Função para calcular métricas
void calcular_metricas(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade = carta->populacao / carta->area;
    } else {
        carta->densidade = 0;
    }
    
    if (carta->populacao > 0) {
        // (PIB em Milhões * 1.000.000) / População = PIB per capita em R$
        carta->pib_per_capita = (carta->pib * 1000000) / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}
 
// Função para exibir menu dinâmico
void exibir_menu_dinamico(const char *titulo) {
    printf("\n=== %s ===\n", titulo);
    
    for (int i = 0; i < 6; i++) {
        if (atributos_disponiveis[i]) {
            printf("%d. %s\n", i + 1, nomes_atributos[i]);
        }
    }
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
}
 
// Função para obter valor do atributo de uma carta
float obter_valor_atributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade;
        case 6: return carta.pib_per_capita;
        default: return 0;
    }
}
 
// Função para comparar dois valores baseado no tipo de atributo
int comparar_valores(float valor1, float valor2, int atributo) {
    // Operador ternário para determinar regra de comparação
    int resultado = (atributo == 5) ? 
                    (valor1 < valor2 ? 1 : (valor2 < valor1 ? -1 : 0)) : // Densidade: menor vence
                    (valor1 > valor2 ? 1 : (valor2 > valor1 ? -1 : 0));  // Outros: maior vence
    
    return resultado;
}
 
// Função principal de comparação com múltiplos atributos
void comparar_multiplos_atributos(Carta c1, Carta c2, int attr1, int attr2) {
    printf("\n=== COMPARACAO AVANCADA ===\n");
    printf("Carta 1: %s (%s)\n", c1.cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.cidade, c2.estado);
    printf("Atributos: %s e %s\n", nomes_atributos[attr1-1], nomes_atributos[attr2-1]);
    
    float valor1_attr1 = obter_valor_atributo(c1, attr1);
    float valor2_attr1 = obter_valor_atributo(c2, attr1);
    float valor1_attr2 = obter_valor_atributo(c1, attr2);
    float valor2_attr2 = obter_valor_atributo(c2, attr2);
    
    // Comparação individual dos atributos
    int resultado_attr1 = comparar_valores(valor1_attr1, valor2_attr1, attr1);
    int resultado_attr2 = comparar_valores(valor1_attr2, valor2_attr2, attr2);
    
    printf("\n--- COMPARACAO INDIVIDUAL ---\n");
    
    // Atributo 1
    printf("%s:\n", nomes_atributos[attr1-1]);
    printf("  %s: ", c1.cidade);
    (attr1 == 1 || attr1 == 4) ? printf("%.0f\n", valor1_attr1) : printf("%.2f\n", valor1_attr1);
    printf("  %s: ", c2.cidade);
    (attr1 == 1 || attr1 == 4) ? printf("%.0f\n", valor2_attr1) : printf("%.2f\n", valor2_attr1);
    
    // Operador ternário para resultado do primeiro atributo
    const char *vencedor_attr1 = (resultado_attr1 == 1) ? c1.cidade : 
                                 (resultado_attr1 == -1) ? c2.cidade : "Empate";
    printf("  Vencedor: %s\n", vencedor_attr1);
    
    // Atributo 2
    printf("%s:\n", nomes_atributos[attr2-1]);
    printf("  %s: ", c1.cidade);
    (attr2 == 1 || attr2 == 4) ? printf("%.0f\n", valor1_attr2) : printf("%.2f\n", valor1_attr2);
    printf("  %s: ", c2.cidade);
    (attr2 == 1 || attr2 == 4) ? printf("%.0f\n", valor2_attr2) : printf("%.2f\n", valor2_attr2);
    
    // Operador ternário para resultado do segundo atributo
    const char *vencedor_attr2 = (resultado_attr2 == 1) ? c1.cidade : 
                                 (resultado_attr2 == -1) ? c2.cidade : "Empate";
    printf("  Vencedor: %s\n", vencedor_attr2);
    
    // Soma dos atributos (Regra do Nível Mestre)
    // Nota: Esta soma pode misturar grandezas (ex: População + PIB), 
    // o que é parte da lógica do jogo, não um erro.
    float soma_c1 = valor1_attr1 + valor1_attr2;
    float soma_c2 = valor2_attr1 + valor2_attr2;
    
    printf("\n--- SOMA DOS ATRIBUTOS ---\n");
    printf("%s: %.2f\n", c1.cidade, soma_c1);
    printf("%s: %.2f\n", c2.cidade, soma_c2);
    
    // Resultado final com operador ternário
    printf("\n=== RESULTADO FINAL ===\n");
    if (soma_c1 > soma_c2) {
        printf("VENCEDOR: %s!\n", c1.cidade);
    } else if (soma_c2 > soma_c1) {
        printf("VENCEDOR: %s!\n", c2.cidade);
    } else {
        printf("EMPATE!\n");
    }
}
 
// Função para exibir carta
void exibir_carta(Carta c) {
    printf("\n--- CARTA ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f (Milhoes R$)\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: R$ %.2f\n", c.pib_per_capita);
}
 
// Função para resetar atributos disponíveis
void resetar_atributos() {
    for (int i = 0; i < 6; i++) {
        atributos_disponiveis[i] = 1;
    }
}
 
// Função para validar entrada do usuário (robusta)
int validar_entrada(int min, int max) {
    int opcao;
    char buffer[100];
    
    while (1) {
        // Tenta ler a linha inteira
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tenta converter o buffer para um inteiro
            if (sscanf(buffer, "%d", &opcao) == 1) {
                // Verifica se o inteiro está no intervalo válido
                if (opcao >= min && opcao <= max) {
                    return opcao; // Retorna o número válido
                }
            }
        }
        // Se falhar em qualquer etapa, pede novamente
        printf("Entrada invalida! Digite um numero entre %d e %d: ", min, max);
    }
}
 
int main() {
    
    // --- DADOS FIXOS (Hardcoded) ---
    // Cartas pré-cadastradas (Exemplos: Curitiba e Manaus)
    
    // Carta 1: Curitiba (PR)
    Carta carta1 = {
        "PR", "C003", "Curitiba", 
        1960000, 435.0, 98000.0, 30
    };
    
    // Carta 2: Manaus (AM)
    Carta carta2 = {
        "AM", "C004", "Manaus", 
        2250000, 11401.0, 103000.0, 25
    };
    
    // ---------------------------------
    
    // Calcular métricas
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);
    
    int opcao_principal;
    int atributo1 = 0, atributo2 = 0;
    
    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("Comparacao Avancada com Multiplos Atributos\n");
    
    // Exibir cartas
    printf("\nCARTAS DISPONIVEIS:\n");
    exibir_carta(carta1);
    exibir_carta(carta2);
    
    do {
        resetar_atributos(); // Resetar menu para nova comparação
        
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Iniciar Comparacao com 2 Atributos\n");
        printf("2. Ver Cartas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        
        // Limpa o buffer de entrada antes de validar
        // (Necessário após o 'getchar' da pausa)
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        opcao_principal = validar_entrada(0, 2);
        
        // Estrutura switch para menu principal
        switch(opcao_principal) {
            case 1: {
                // Escolha do primeiro atributo
                printf("\n");
                exibir_menu_dinamico("ESCOLHA O PRIMEIRO ATRIBUTO");
                atributo1 = validar_entrada(0, 6);
                
                if (atributo1 == 0) break;
                
                // Marcar primeiro atributo como indisponível
                atributos_disponiveis[atributo1 - 1] = 0;
                
                // Escolha do segundo atributo
                printf("\n");
                exibir_menu_dinamico("ESCOLHA O SEGUNDO ATRIBUTO");
                
                // Validação para garantir que o segundo atributo seja válido e diferente
                while (1) {
                    atributo2 = validar_entrada(0, 6);
                    if (atributo2 == 0) {
                        break; // Permite voltar
                    }
                    if (atributo1 == atributo2 || atributos_disponiveis[atributo2 - 1] == 0) {
                        printf("ERRO: Voce escolheu um atributo invalido ou repetido!\n");
                        printf("Por favor, escolha um atributo disponivel: ");
                    } else {
                        break; // Atributo 2 é válido
                    }
                }
                
                if (atributo2 == 0) {
                    // Se voltar, reabilitar primeiro atributo
                    atributos_disponiveis[atributo1 - 1] = 1;
                    break;
                }
                
                // Executar comparação avançada
                comparar_multiplos_atributos(carta1, carta2, atributo1, atributo2);
                
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguardar Enter
                break;
            }
            
            case 2:
                // Exibir cartas novamente
                exibir_carta(carta1);
                exibir_carta(carta2);
                break;
                
            case 0:
                printf("Saindo do Super Trunfo...\n");
                break;
                
            default:
                // Esta parte não será alcançada devido à validação
                printf("Opcao invalida!\n");
                break;
        }
        
    } while (opcao_principal != 0);
    
    return 0;
}