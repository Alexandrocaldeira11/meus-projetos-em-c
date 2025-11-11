#include <stdio.h>
#include <string.h>
 
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
 
// Função para calcular densidade populacional e PIB per capita
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
 
// Função para exibir menu interativo
void exibir_menu() {
    printf("\n=== SUPER TRUNFO - MENU DE ATRIBUTOS ===\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("6. PIB per Capita\n");
    printf("0. Sair\n");
    printf("Escolha o atributo para comparacao: ");
}
 
// Função para comparar duas cartas baseado no atributo escolhido
void comparar_cartas(Carta c1, Carta c2, int atributo) {
    printf("\n=== COMPARACAO DE CARTAS ===\n");
    printf("Carta 1: %s (%s)\n", c1.cidade, c1.estado);
    printf("Carta 2: %s (%s)\n", c2.cidade, c2.estado);
    printf("Atributo escolhido: ");
    
    float valor1, valor2;
    
    // CORREÇÃO: Declarar como 'const char *' (remove os avisos)
    const char *nome_atributo; 
    
    // Estrutura switch para determinar qual atributo comparar
    switch(atributo) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            nome_atributo = "Populacao";
            printf("Populacao\n");
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            nome_atributo = "Area";
            printf("Area\n");
            break;
        case 3:
            valor1 = c1.pib;
            valor2 = c2.pib;
            nome_atributo = "PIB (em Milhoes R$)";
            printf("PIB\n");
            break;
        case 4:
            valor1 = c1.pontos_turisticos;
            valor2 = c2.pontos_turisticos;
            nome_atributo = "Pontos Turisticos";
            printf("Pontos Turisticos\n");
            break;
        case 5:
            valor1 = c1.densidade;
            valor2 = c2.densidade;
            nome_atributo = "Densidade Demografica";
            // CORREÇÃO: Adicionar o printf e o break que faltavam
            printf("Densidade Demografica\n"); 
            break;
        case 6:
            valor1 = c1.pib_per_capita;
            valor2 = c2.pib_per_capita;
            nome_atributo = "PIB per Capita (R$)";
            printf("PIB per Capita\n");
            break;
        default:
            printf("Atributo invalido!\n");
            return;
    }
    
    printf("\nVALORES:\n");
    
    // Exibir valores formatados conforme o tipo
    if (atributo == 1 || atributo == 4) { // Inteiros (População, Pontos)
        // CORREÇÃO: Completar os 'printf'
        printf("%s - %s: %.0f\n", c1.cidade, nome_atributo, valor1);
        printf("%s - %s: %.0f\n", c2.cidade, nome_atributo, valor2);
    } else { // Floats (Área, PIB, Densidade, Per Capita)
        // CORREÇÃO: Completar os 'printf'
        printf("%s - %s: %.2f\n", c1.cidade, nome_atributo, valor1);
        printf("%s - %s: %.2f\n", c2.cidade, nome_atributo, valor2);
    }
    
    printf("\nRESULTADO: ");
    
    // Lógica de comparação (Regra especial para Densidade)
    if (atributo == 5) {
        if (valor1 < valor2) {
            printf("Carta 1 (%s) VENCEU! (menor densidade)\n", c1.cidade);
        } else if (valor2 < valor1) {
            printf("Carta 2 (%s) VENCEU! (menor densidade)\n", c2.cidade);
        } else {
            printf("EMPATE!\n");
        }
    } else {
        // Regra Padrão (maior vence)
        if (valor1 > valor2) {
            printf("Carta 1 (%s) VENCEU!\n", c1.cidade);
        } else if (valor2 > valor1) {
            printf("Carta 2 (%s) VENCEU!\n", c2.cidade);
        } else {
            printf("EMPATE!\n");
        }
    }
}
 
// Função para exibir detalhes de uma carta
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
 
// CORREÇÃO: Usar 'int main()' em vez de 'void main()'
int main() {
    // Cartas pré-cadastradas (Brasília e Salvador)
    Carta carta1 = {
        "DF", "C001", "Brasilia", 
        3094000, 5760.78, 286943.0, 15
    };
    
    Carta carta2 = {
        "BA", "C002", "Salvador", 
        2900000, 693.80, 63681.0, 20
    };
    
    // Calcular métricas
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);
    
    int opcao; // Variável 'opcao' declarada
    
    printf("=== SUPER TRUNFO - NIVEL AVENTUREIRO ===\n");
    
    printf("\nCARTAS DISPONIVEIS PARA COMPARACAO:\n");
    exibir_carta(carta1);
    exibir_carta(carta2);
    
    // Loop principal do menu
    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                comparar_cartas(carta1, carta2, opcao);
                break;
            case 0:
                printf("Saindo do Super Trunfo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Limpar buffer do scanf
            getchar(); // Aguardar Enter
        }
        
    // CORREÇÃO: Corrigir o typo de 'opcap' para 'opcao'
    } while (opcao != 0);
    
    return 0; // Necessário para 'int main()'

// CORREÇÃO: Adicionar o '}' que falta no final do arquivo
}