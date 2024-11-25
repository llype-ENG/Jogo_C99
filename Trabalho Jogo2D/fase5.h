#ifndef FASE5_H
#define FASE5_H
#include "fase1.h"

// Definição da estrutura Jogador


typedef struct {
    int x, y;
} Objeto;

// Funções para o labirinto e fases

void desenharLabirinto2(char **mapa, int altura, int largura, Jogador *jogador, Objeto *objeto);
void moverObjetoAleatoriamente(char **mapa, int altura, int largura, Objeto *objeto);

// Funções específicas para as fases
void iniciarFase5();

#endif // FASE5_H