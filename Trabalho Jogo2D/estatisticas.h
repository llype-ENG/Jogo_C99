#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

typedef struct {
    int fases_completadas;
    float tempo_total;
    float tempo_fases[5];  // Supondo que o jogo tenha 5 fases
} Estatisticas;

void salvarEstatisticas(const char *nome_arquivo, Estatisticas *est);
Estatisticas* lerEstatisticas(const char *nome_arquivo);
void atualizarEstatisticas(Estatisticas *est, float tempo_fase);
void mostrarEstatisticas();
void iniciarJogo();

#endif
