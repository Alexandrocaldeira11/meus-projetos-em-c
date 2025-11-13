# 🚢 Jogo de Batalha Naval em C

Este projeto é uma simulação em C do clássico jogo Batalha Naval. O desafio foi dividido em três níveis, demonstrando uma progressão desde o uso básico de matrizes até conceitos avançados como `structs` e mapeamento de matrizes.

## 📈 Evolução do Desafio

O projeto foi construído em três etapas incrementais:

### Nível Novato: Posicionamento Básico
O ponto de partida focou na criação e manipulação de matrizes.

* **Matriz 10x10:** Implementação de um tabuleiro 10x10.
* **Inicialização:** Todo o tabuleiro é preenchido com `0` (Água).
* **Navios Retos:** Posicionamento "hardcoded" (fixo) de **dois navios** de tamanho 3 (um horizontal e um vertical), marcados com o valor `3`.
* **Exibição:** O tabuleiro é impresso no console usando loops aninhados.

### Nível Aventureiro: Navios Diagonais e Validação
O segundo nível introduziu lógicas mais complexas e um código mais robusto.

* **Navios Diagonais:** A lógica foi expandida para posicionar **quatro navios** no total (dois retos e dois diagonais).
* **Modularização:** O código foi refatorado em funções (`posicionar_navio`, `exibir_tabuleiro`, etc.) para melhor organização.
* **Validação de Sobreposição:** Implementada a função `verificar_sobreposicao` para garantir que navios não sejam colocados uns sobre os outros, um requisito chave do desafio.
* **Exibição Melhorada:** A saída do console foi melhorada para incluir índices de linha e coluna, facilitando a leitura do tabuleiro.

### Nível Mestre: Habilidades Especiais e `structs`
O nível final transformou o projeto num simulador tático, introduzindo conceitos avançados.

* **Estruturas (`struct`):** Foi criada uma `struct Habilidade` para agrupar dados complexos (nome, uma matriz de área de efeito 5x5 e coordenadas centrais).
* **Mapeamento de Matrizes:** Implementação de uma lógica avançada (`aplicar_habilidade`) que "mapeia" a matriz 5x5 da habilidade sobre o tabuleiro 10x10, usando a posição central como um "offset" (deslocamento).
* **Design Orientado a Dados:** Habilidades como o "Octaedro" foram criadas usando fórmulas matemáticas (`abs(i - centro) + abs(j - centro)`) em vez de valores fixos, demonstrando uma técnica de programação mais eficiente.
* **Exibição Simbólica:** A exibição final foi aprimorada para mostrar símbolos (`.`, `N`, `H`) em vez de números, melhorando a experiência do utilizador.

## 🚀 Como Compilar e Executar

Este programa foi escrito em C padrão e pode ser compilado com o GCC.

1.  Abra o terminal na pasta onde o ficheiro `.c` do Nível Mestre está localizado.
2.  Compile o programa:
    ```bash
    gcc DesafioBatalhaNavalMestre.c -o BatalhaNaval
    ```
    *(**Nota:** Troque `DesafioBatalhaNavalMestre.c` pelo nome real do seu ficheiro C)*

3.  Execute o programa:
    * No Windows (PowerShell):
        ```bash
        ./BatalhaNaval.exe
        ```
    * No Linux ou macOS:
        ```bash
        ./BatalhaNaval
        ```

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem C**
* **Matrizes (Arrays Bidimensionais)** (incluindo mapeamento de matrizes)
* **Estruturas de Dados (`struct`)**
* **Modularização** (separação de código em funções)
* **Loops Aninhados (for)**
* **Booleanos (`stdbool.h`)**
* **Constantes (`#define`)**
* **Compilador GCC**