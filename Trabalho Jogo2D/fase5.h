#ifndef FASE5_H
#define FASE5_H

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
    // Vetor de direções possíveis (cima, baixo, esquerda, direita)
    int direcoes[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // Cima, Baixo, Esquerda, Direita
    int direcaoEscolhida;
    int novoX, novoY;
    
    // Tenta mover o objeto aleatoriamente até que encontre um movimento válido
    for (int tentativas = 0; tentativas < 10; tentativas++) {
        direcaoEscolhida = rand() % 4;  // Escolhe uma direção aleatória
        novoX = objeto->x + direcoes[direcaoEscolhida][1];
        novoY = objeto->y + direcoes[direcaoEscolhida][0];
        
        // Verifica se a nova posição é válida (não é uma parede)
        if (novoX >= 0 && novoX < largura && novoY >= 0 && novoY < altura && mapa[novoY][novoX] != '#') {
            objeto->x = novoX;
            objeto->y = novoY;
            break;
        }
    }
}

#endif
