#include <stdio.h>
#include <conio.h> // Para capturar teclas (no Windows)

#define LARGURA 10
#define ALTURA 5

void desenharLabirinto(char labirinto[ALTURA][LARGURA], int jogadorX, int jogadorY) {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (i == jogadorY && j == jogadorX) {
                printf("P "); // Jogador
            } else {
                printf("%c ", labirinto[i][j]);
            }
        }
        printf("\n");
    }
     char labirinto[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', 'F', '#'}
    };
}

int main() {
    
    char labirinto[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', 'F', '#'}
    };
    
    int jogadorX = 2, jogadorY = 2; // Posição inicial do jogador
    char entrada;

    desenharLabirinto(labirinto, jogadorX, jogadorY);

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");
    while (1) {
        system("cls"); // Limpar tela (no Windows)
        desenharLabirinto(labirinto, jogadorX, jogadorY);

        if (labirinto[jogadorY][jogadorX] == 'F') {
            printf("Parabéns! Você completou o labirinto!\n");
            break;
        }

        entrada = getch(); // Capturar tecla
        switch (entrada) {
            case 'w': // Cima
                if (labirinto[jogadorY - 1][jogadorX] != '#') jogadorY--;
                break;
            case 'a': // Esquerda
                if (labirinto[jogadorY][jogadorX - 1] != '#') jogadorX--;
                break;
            case 's': // Baixo
                if (labirinto[jogadorY + 1][jogadorX] != '#') jogadorY++;
                break;
            case 'd': // Direita
                if (labirinto[jogadorY][jogadorX + 1] != '#') jogadorX++;
                break;
        }
    }

    return 0;
}
