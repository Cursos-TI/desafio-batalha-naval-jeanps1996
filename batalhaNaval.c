#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializando o tabuleiro com 0 (água)
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Declarando navios com tamanho 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 2;  // posição inicial do navio horizontal
    int linha_vertical = 5, coluna_vertical = 7;      // posição inicial do navio vertical

    // Posicionando navio horizontal no tabuleiro
    for(i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posicionando navio vertical no tabuleiro
    for(i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Imprimindo o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

