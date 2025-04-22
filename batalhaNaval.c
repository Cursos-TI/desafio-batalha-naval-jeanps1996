#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0

// Função para verificar se é possível posicionar o navio sem ultrapassar os limites e sem sobreposição
int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha;
        int c = coluna;

        if (direcao == 'H') c += i;              // Horizontal
        else if (direcao == 'V') l += i;         // Vertical
        else if (direcao == 'D') { l += i; c += i; }     // Diagonal principal
        else if (direcao == 'O') { l += i; c -= i; }     // Diagonal oposta

        if (l >= TAM || c >= TAM || c < 0 || tabuleiro[l][c] != AGUA) {
            return 0;  // Fora do tabuleiro ou sobreposição
        }
    }
    return 1;
}

// Função para posicionar o navio após validar
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') tabuleiro[linha][coluna + i] = NAVIO;
        else if (direcao == 'V') tabuleiro[linha + i][coluna] = NAVIO;
        else if (direcao == 'D') tabuleiro[linha + i][coluna + i] = NAVIO;
        else if (direcao == 'O') tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro Batalha Naval 10x10:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Tentamos posicionar navios com tamanhos diferentes
    if (pode_posicionar(tabuleiro, 2, 1, 4, 'H'))  // Navio horizontal
        posicionar_navio(tabuleiro, 2, 1, 4, 'H');

    if (pode_posicionar(tabuleiro, 5, 5, 3, 'V'))  // Navio vertical
        posicionar_navio(tabuleiro, 5, 5, 3, 'V');

    if (pode_posicionar(tabuleiro, 0, 0, 4, 'D'))  // Diagonal principal
        posicionar_navio(tabuleiro, 0, 0, 4, 'D');

    if (pode_posicionar(tabuleiro, 0, 9, 4, 'O'))  // Diagonal oposta
        posicionar_navio(tabuleiro, 0, 9, 4, 'O');

    // Exibir o resultado
    exibir_tabuleiro(tabuleiro);

    return 0;
}
