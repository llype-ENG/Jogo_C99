#ifndef FASE3_H
#define FASE3_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Jogador;

typedef struct {
    int x, y;
} Objeto;

// Função para criar o labirinto dinamicamente
char **criarLabirinto(int altura, int largura) {
    char **labirinto = (char **)malloc(altura * sizeof(char *));
    if (labirinto == NULL) {
        perror("Erro ao alocar memória para o labirinto");
        exit(1);
    }
    for (int i = 0; i < altura; i++) {
        labirinto[i] = (char *)malloc(largura * sizeof(char));
        if (labirinto[i] == NULL) {
            perror("Erro ao alocar memória para uma linha do labirinto");
            exit(1);
        }
    }
    return labirinto;
}

// Função para liberar a memória do labirinto
void liberarLabirinto(char **labirinto, int altura) {
    for (int i = 0; i < altura; i++) {
        free(labirinto[i]);
    }
    free(labirinto);
}

// Função para desenhar o labirinto
void desenharLabirinto(char **mapa, int altura, int largura, Jogador *jogador, Objeto *objeto) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (i == jogador->y && j == jogador->x) {
                printf("P "); // Representa o jogador
            } else if (i == objeto->y && j == objeto->x) {
                printf("O "); // Representa o objeto
            } else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para mover o objeto aleatoriamente
void moverObjetoAleatoriamente(char **mapa, int altura, int largura, Objeto *objeto) {
    // Movimentos possíveis: cima (0,-1), baixo (0,1), esquerda (-1,0), direita (1,0)
    int movimentos[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int direcao = rand() % 4; // Seleciona um movimento aleatório

    int novaX = objeto->x + movimentos[direcao][0];
    int novaY = objeto->y + movimentos[direcao][1];

    // Verifica se a nova posição é válida (não ultrapassando as bordas e não sendo uma parede)
    if (novaX >= 0 && novaX < largura && novaY >= 0 && novaY < altura && mapa[novaY][novaX] != '#') {
        objeto->x = novaX;
        objeto->y = novaY;
    }
}

#endif
