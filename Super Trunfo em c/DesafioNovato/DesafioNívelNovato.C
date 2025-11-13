#include <stdio.h>  // Para printf, scanf, fgets, getchar, EOF
#include <string.h> // Para strcspn

// Agora sim, todo o código está dentro da função principal
int main(void) {
    
    // --- Variáveis da Carta 1 ---
    float pib1, area1;
    char apelido1[50], nome1[50]; // Aumentei o tamanho para nomes de cidades
    int pontos_turisticos1, codigo1, populacao1;
    char estado1;

    // --- Variáveis da Carta 2 ---
    float pib2, area2;
    char apelido2[50], nome2[50];
    int pontos_turisticos2, codigo2, populacao2;
    char estado2;

    // ------------------------------------
    // --- COLETA DE DADOS DA CARTA 1 ---
    // ------------------------------------
    printf("--- CADASTRO CARTA 1 ---\n");

    printf("PIB (Bilhões): ");
    scanf("%f", &pib1);

    printf("Apelido: ");
    // CORREÇÃO: Limpa o buffer antes de ler a string com fgets
    // (Consome o '\n' deixado pelo scanf anterior)
    int c; // Variável temporária para limpar o buffer
    while ((c = getchar()) != '\n' && c != EOF); 
    
    fgets(apelido1, 50, stdin);
    apelido1[strcspn(apelido1, "\n")] = 0; // Remove o \n que o fgets deixa

    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("Estado (A-Z): ");
    // CORREÇÃO: Adicionado espaço antes do %c para ignorar o '\n'
    scanf(" %c", &estado1); 

    printf("Código (ex: 802): ");
    scanf("%d", &codigo1);

    // CORREÇÃO: Limpando o buffer novamente antes de ler o nome
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Nome da cidade: ");
    fgets(nome1, 50, stdin);
    nome1[strcspn(nome1, "\n")] = 0; // Remove o \n

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    // ------------------------------------
    // --- COLETA DE DADOS DA CARTA 2 ---
    // ------------------------------------
    printf("\n--- CADASTRO CARTA 2 ---\n");

    printf("PIB (Bilhões): ");
    scanf("%f", &pib2);

    printf("Apelido: ");
    while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer
    fgets(apelido2, 50, stdin);
    apelido2[strcspn(apelido2, "\n")] = 0;

    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    printf("Estado (A-Z): ");
    scanf(" %c", &estado2); // Adicionado espaço

    printf("Código (ex: 802): ");
    scanf("%d", &codigo2);

    while ((c = getchar()) != '\n' && c != EOF); // Limpa buffer
    printf("Nome da cidade: ");
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = 0;

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    // ------------------------------------
    // --- EXIBIÇÃO DOS RESULTADOS ---
    // ------------------------------------
    printf("\n\n--- CARTAS CADASTRADAS ---\n");

    // Carta 1
    printf("\n// Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Apelido: %s\n", apelido1);
    printf("Nome da Cidade: %s\n", nome1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1); // %.2f para formatar com 2 casas decimais
    printf("PIB: R$%.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);

    // Carta 2
    printf("\n// Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Apelido: %s\n", apelido2);
    printf("Código: %d\n", codigo2); // Você esqueceu de exibir o código
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: R$%.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);

    return 0; // Indica que o programa terminou com sucesso
}