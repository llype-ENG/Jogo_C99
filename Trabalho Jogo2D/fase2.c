#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fase2.h"

#define ALTURA 10
#define LARGURA 10

int main() {
    int altura = ALTURA, largura = LARGURA;

    // Criando o labirinto dinamicamente
    char **mapa = criarLabirinto(altura, largura);

    // Inicializando o labirinto
    char temp[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', ' ', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'F', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            mapa[i][j] = temp[i][j];
        }
    }

    // Criando dinamicamente o jogador
    Jogador *jogador = (Jogador *)malloc(sizeof(Jogador));
    if (jogador == NULL) {
        perror("Erro ao alocar memória para o jogador");
        exit(1);
    }
    jogador->x = 1; // Posição inicial
    jogador->y = 1;

    char entrada;

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

    while (1) {
        system("cls"); // Limpar tela (Windows)
        desenharLabirinto(mapa, altura, largura, jogador);

        // Verifica se o jogador chegou ao final
        if (mapa[jogador->y][jogador->x] == 'F') {
            printf("Parabéns! Você completou o labirinto!\n");
            break;
        }

        // Captura a entrada do jogador
        entrada = getch();
        switch (entrada) {
            case 'w': // Cima
                if (jogador->y > 0 && mapa[jogador->y - 1][jogador->x] != '#') jogador->y--;
                break;
            case 'a': // Esquerda
                if (jogador->x > 0 && mapa[jogador->y][jogador->x - 1] != '#') jogador->x--;
                break;
            case 's': // Baixo
                if (jogador->y < altura - 1 && mapa[jogador->y + 1][jogador->x] != '#') jogador->y++;
                break;
            case 'd': // Direita
                if (jogador->x < largura - 1 && mapa[jogador->y][jogador->x + 1] != '#') jogador->x++;
                break;
        }
    }

    // Liberando a memória alocada
    liberarLabirinto(mapa, altura);
    free(jogador);

    return 0;
}
