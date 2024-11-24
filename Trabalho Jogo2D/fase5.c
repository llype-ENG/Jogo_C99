#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fase3.h"

#define ALTURA 15
#define LARGURA 15

int main() {
    int altura = ALTURA, largura = LARGURA;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Criando o labirinto dinamicamente
    char **mapa = criarLabirinto(altura, largura);

    // Inicializando o labirinto com paredes (#), espaços ( ), objetos (O), buracos (X) e entrada/saída
    char temp[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', 'O', ' ', '#', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', '#', ' ', ' ', '#', 'X', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', 'O', ' ', '#'},
        {'#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', 'X', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', 'X', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', 'F', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
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

    // Criando o objeto que se moverá aleatoriamente
    Objeto *objeto = (Objeto *)malloc(sizeof(Objeto));
    if (objeto == NULL) {
        perror("Erro ao alocar memória para o objeto");
        exit(1);
    }
    objeto->x = 5; // Posição inicial do objeto
    objeto->y = 5;

    char entrada;

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

    while (1) {
        system("cls"); // Limpar tela (Windows)
        desenharLabirinto(mapa, altura, largura, jogador, objeto);

        // Verifica se o jogador chegou ao final
        if (mapa[jogador->y][jogador->x] == 'F') {
            printf("Parabéns! Você completou o labirinto!\n");
            break;
        }

        // Verifica se o jogador atingiu um objeto
        if (jogador->x == objeto->x && jogador->y == objeto->y) {
            printf("Você perdeu! Colidiu com o objeto!\n");
            break;
        }

        // Captura a entrada do jogador
        entrada = getch();
        switch (entrada) {
            case 'w': // Cima
                if (jogador->y > 0 && mapa[jogador->y - 1][jogador->x] != '#') {
                    jogador->y--;
                }
                break;
            case 's': // Baixo
                if (jogador->y < altura - 1 && mapa[jogador->y + 1][jogador->x] != '#') {
                    jogador->y++;
                }
                break;
            case 'a': // Esquerda
                if (jogador->x > 0 && mapa[jogador->y][jogador->x - 1] != '#') {
                    jogador->x--;
                }
                break;
            case 'd': // Direita
                if (jogador->x < largura - 1 && mapa[jogador->y][jogador->x + 1] != '#') {
                    jogador->x++;
                }
                break;
            default:
                break;
        }

        // Mover o objeto aleatoriamente
        moverObjetoAleatoriamente(mapa, altura, largura, objeto);
    }

    // Liberando memória
    free(jogador);
    free(objeto);
    liberarLabirinto(mapa, altura);

    return 0;
}
