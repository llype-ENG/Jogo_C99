#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "fase5.h"

#define ALTURA 14
#define LARGURA 15

int main() {
    int altura = ALTURA, largura = LARGURA;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    char novamente[10];

    do {
        // Criando o labirinto dinamicamente
        char **mapa = criarLabirinto(altura, largura);

        // Inicializando o labirinto
        char temp[ALTURA][LARGURA] = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'S', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
            {'#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '#', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', '#'},
            {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', 'F', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };



        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                mapa[i][j] = temp[i][j];
            }
        }

        // Criando dinamicamente o jogador
        Jogador *jogador = (Jogador *)malloc(sizeof(Jogador));
        if (!jogador) {
            perror("Erro ao alocar memória para o jogador");
            exit(1);
        }
        jogador->x = 1; // Posição inicial
        jogador->y = 1;

        // Criando o objeto que se moverá aleatoriamente
        Objeto *objeto = (Objeto *)malloc(sizeof(Objeto));
        if (!objeto) {
            perror("Erro ao alocar memória para o objeto");
            exit(1);
        }
        objeto->x = 5;
        objeto->y = 5;

        printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

        while (1) {
            system("cls"); // Limpar tela
            desenharLabirinto(mapa, altura, largura, jogador, objeto);

            // Verifica se o jogador chegou ao final
            if (mapa[jogador->y][jogador->x] == 'F') {
                printf("Parabéns! Você completou o labirinto!\n");
                break;
            }
            // Verifica se o jogador atingiu o objeto
            if (jogador->x == objeto->x && jogador->y == objeto->y || (mapa[jogador->y][jogador->x] == 'O' || mapa[jogador->y][jogador->x] == 'X') ) {
                printf("Você perdeu! Colidiu com o objeto!\n");
                break;
            }

            // Captura a entrada do jogador
            char entrada = getch();
            switch (entrada) {
                case 'w': // Cima
                    if (jogador->y > 0 && mapa[jogador->y - 1][jogador->x] != '#') jogador->y--;
                    break;
                case 's': // Baixo
                    if (jogador->y < altura - 1 && mapa[jogador->y + 1][jogador->x] != '#') jogador->y++;
                    break;
                case 'a': // Esquerda
                    if (jogador->x > 0 && mapa[jogador->y][jogador->x - 1] != '#') jogador->x--;
                    break;
                case 'd': // Direita
                    if (jogador->x < largura - 1 && mapa[jogador->y][jogador->x + 1] != '#') jogador->x++;
                    break;
                default:
                    break;
            }

            // Move o objeto aleatoriamente
            moverObjetoAleatoriamente(mapa, altura, largura, objeto);
        }

        // Liberando memória
        free(jogador);
        free(objeto);
        liberarLabirinto(mapa, altura);

        // Pergunta se o jogador deseja jogar novamente
        printf("Deseja jogar novamente? (sim/nao): ");
        fgets(novamente, sizeof(novamente), stdin);
        novamente[strcspn(novamente, "\n")] = '\0'; // Remove o '\n'

    } while (strcmp(novamente, "sim") == 0);

    printf("Obrigado por jogar! Até a próxima.\n");
    return 0;
}
