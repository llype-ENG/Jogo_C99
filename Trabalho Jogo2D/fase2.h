#ifndef FASE2_H
#define FASE2_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Jogador;

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
void desenharLabirinto(char **mapa, int altura, int largura, Jogador *jogador) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (i == jogador->y && j == jogador->x) {
                printf("P "); // Representa o jogador
            } else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

#endif
