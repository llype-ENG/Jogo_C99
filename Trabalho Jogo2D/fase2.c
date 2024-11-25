#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fase1.h"  // Inclua a fase1.h para compartilhar as funções

#define ALTURA 10
#define LARGURA 10

// Função para iniciar a fase 2
void iniciarFase2() {
    int altura = ALTURA, largura = LARGURA;

    // Criando o labirinto dinamicamente
    char **mapa = criarLabirinto(altura, largura);

    // Inicializando o labirinto para a fase 2
    char temp[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
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

    char entrada, nextFase;

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

    do {
    // Reinicia o labirinto e a posição do jogador se o jogador escolher "N"
    if (nextFase == 'N' || nextFase == 'n') {
        // Reinicia a posição do jogador para o início
        jogador->x = 1;
        jogador->y = 1;
    }

    while (1) {
        system("cls"); // Limpar tela (Windows)
        desenharLabirinto(mapa, altura, largura, jogador);
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
            scanf(" %c", &nextFase); // Corrigido o scanf
            if (nextFase == 'S' || nextFase == 's') {
                break; // Sai do loop e vai para a próxima fase
            } else {
                // Se escolher 'N', reinicia a fase
                nextFase = 'N';  // Garante que a condição do do-while seja verdadeira
                break; // Sai do loop interno
            }
        }
    }
} while (nextFase == 'N' || nextFase == 'n');

    // Liberando a memória alocada
    liberarLabirinto(mapa, altura);
    free(jogador);
}
