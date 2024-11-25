#ifndef FASE1_H
#define FASE1_H

// Definição da estrutura Jogador
typedef struct {
    int x, y; // Posição do jogador no labirinto
} Jogador;

// Funções para o labirinto e fases
void desenharLabirinto(char **mapa, int altura, int largura, Jogador *jogador);
char **criarLabirinto(int altura, int largura);
void liberarLabirinto(char **mapa, int altura);


// Funções específicas para as fases
void iniciarFase1();
void iniciarFase2();
void iniciarFase3();
void iniciarFase4();
void iniciarFase5();

#endif // FASE1_H
