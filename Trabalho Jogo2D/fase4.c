#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fase1.h"

#define ALTURA 15
#define LARGURA 15

void iniciarFase4() {
    int altura = ALTURA, largura = LARGURA;
    char nextFase = 'N'; // Garantir que a fase inicie com 'N'

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
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', 'F', '#', '#'},
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

    char entrada;

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

    do {
        // Reinicia a posição do jogador para o início se o jogador escolher 'N'
        if (nextFase == 'N' || nextFase == 'n') {
            jogador->x = 1;
            jogador->y = 1;
        }

        while (1) {
            system("cls"); // Limpar tela (Windows)
            desenharLabirinto(mapa, altura, largura, jogador);

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

            // Verifica se o jogador chegou ao final
            if (mapa[jogador->y][jogador->x] == 'F') {
                printf("Parabéns! Você completou o labirinto!\n");
                printf("Deseja ir para a próxima fase? (S/N): ");
                scanf(" %c", &nextFase); // Corrige o scanf para capturar a resposta do jogador
                if (nextFase == 'S' || nextFase == 's') {
                    break; // Sai do loop interno e vai para a próxima fase
                } else {
                    nextFase = 'N'; // Garante que a fase seja reiniciada se o jogador escolher 'N'
                    break; // Sai do loop e reinicia a fase
                }
            }

            // Verifica se o jogador colidiu com um objeto
            if (mapa[jogador->y][jogador->x] == 'O') {
                // Exibe a mensagem de colisão
                printf("Você perdeu! Colidiu com um objeto!\n");

                // Pergunta ao jogador se ele quer tentar novamente
                printf("Deseja tentar novamente? (S/N): ");
                char tentativa;
                scanf(" %c", &tentativa); // Captura a resposta

                if (tentativa == 'S' || tentativa == 's') {
                    // Se o jogador escolher tentar novamente, reinicia a posição do jogador
                    jogador->x = 1;
                    jogador->y = 1;
                } else {
                    // Caso contrário, sai do loop e termina a fase
                    nextFase = 'N'; // Garante que a fase seja reiniciada se o jogador escolher 'N'
                    break; // Sai do loop
                }
            }
        }
    } while (nextFase == 'N' || nextFase == 'n'); // Repete a fase se o jogador quiser

    // Liberando a memória alocada
    liberarLabirinto(mapa, altura);
    free(jogador);
}
