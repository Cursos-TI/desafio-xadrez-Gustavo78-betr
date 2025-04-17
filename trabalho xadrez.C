nclude <stdio.h>
#include <string.h>

// Trabalho de Xadrez - Sistemas de Movimentação
//  Gustavo ribeiro
// Objetivo: Implementar as regras de movimentação das peças de xadrez, utilizando loops e estruturas básicas da linguagem C.

#define TAMANHO_TABULEIRO 8 // Define o tamanho do tabuleiro como 8x8

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Coloca zero em todas as posições
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Exibe cada posição
        }
        printf("\n");
    }
    printf("\n");
}

// Função para simular a movimentação do Bispo
void movimentarBispo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        // Movimento diagonal
        if (x + i < TAMANHO_TABULEIRO && y + i < TAMANHO_TABULEIRO) tabuleiro[x + i][y + i] = 1;
        if (x - i >= 0 && y - i >= 0) tabuleiro[x - i][y - i] = 1;
        if (x + i < TAMANHO_TABULEIRO && y - i >= 0) tabuleiro[x + i][y - i] = 1;
        if (x - i >= 0 && y + i < TAMANHO_TABULEIRO) tabuleiro[x - i][y + i] = 1;
    }
}

// Função para simular a movimentação da Torre
void movimentarTorre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[x][i] = 1; // Horizontal
        tabuleiro[i][y] = 1; // Vertical
    }
}

// Função para simular a movimentação da Rainha
void movimentarRainha(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    movimentarBispo(tabuleiro, x, y); // Rainha = Bispo +
    movimentarTorre(tabuleiro, x, y); // Torre
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int x = 4, y = 4; // Posição inicial da peça no tabuleiro

    // Movimentação do Bispo
    printf("Movimento do Bispo:\n");
    inicializarTabuleiro(tabuleiro);
    movimentarBispo(tabuleiro, x, y);
    exibirTabuleiro(tabuleiro);
//  - Bispo 
//    ░░██░░
//    ░████░
//    ██████
//    ░████░
//    ░████░
//    ░████░
// ██████████

    // Movimentação da Torre
    printf("Movimento da Torre:\n");
    inicializarTabuleiro(tabuleiro);
    movimentarTorre(tabuleiro, x, y);
    exibirTabuleiro(tabuleiro);
//  - Torre 
//    ██████
//    ██████
//    ██████
//    ░████░
//    ░████░
//    ░████░
// ██████████

    // Movimentação da Rainha
    printf("Movimento da Rainha:\n");
    inicializarTabuleiro(tabuleiro);
    movimentarRainha(tabuleiro, x, y);
    exibirTabuleiro(tabuleiro);
//  - Rainha 
//    █░░█░░█
//    ░░███░░
//    ███████
//    ░█████░
//    ░█████░
//    ░█████░
// ██████████

    return 0;
}

