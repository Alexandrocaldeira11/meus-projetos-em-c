# ♟️ Simulador de Movimentos de Xadrez em C

Este projeto foi desenvolvido como parte de um desafio de programação em C para demonstrar o uso de diferentes estruturas de repetição e lógica avançada. O programa simula os movimentos de várias peças de xadrez (Torre, Bispo, Rainha e Cavalo) imprimindo seus passos no console.

## 📈 Evolução do Desafio

O projeto foi construído em três níveis de complexidade:

* **Nível Novato:** Demonstra o uso de loops simples (`for`, `while`, `do-while`) para simular os movimentos da Torre, Bispo e Rainha.
* **Nível Aventureiro:** Introduz o uso de loops aninhados para criar o movimento em "L" do Cavalo.
* **Nível Mestre:** Refatora o código para usar **recursividade** (substituindo os loops da Torre, Bispo e Rainha) e **loops complexos** (com `break`, `continue` e múltiplas variáveis) para o Cavalo.

## 🚀 Como Compilar e Executar

Este programa foi escrito em C padrão e pode ser compilado com o GCC.

1.  Abra o terminal na pasta onde o arquivo `.c` está localizado.
2.  Compile o programa:
    ```bash
    gcc desafio_mestre.c -o xadrez
    ```
    *(**Nota:** Troque `desafio_mestre.c` pelo nome real do seu arquivo C)*

3.  Execute o programa:
    * No Windows (PowerShell):
        ```bash
        ./xadrez.exe
        ```
    * No Linux ou macOS:
        ```bash
        ./xadrez
        ```

## 🛠️ Tecnologias Utilizadas

* **Linguagem C**
* **Compilador GCC** (via MinGW no Windows)
* **VS Code** como editor de código