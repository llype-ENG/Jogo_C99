#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estatisticas.h"

// Função para salvar as estatísticas no arquivo binário
void salvarEstatisticas(const char *nome_arquivo, Estatisticas *est) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo para escrita");
        exit(1);
    }
    fwrite(est, sizeof(Estatisticas), 1, arquivo);
    fclose(arquivo);
    printf("Estatísticas salvas com sucesso!\n");  // Mensagem para depuração
}

// Função para ler as estatísticas do arquivo binário
Estatisticas* lerEstatisticas(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Arquivo de estatísticas não encontrado. Criando um novo.\n");  // Mensagem para depuração
        return NULL; // Retorna NULL se não encontrar o arquivo
    }

    Estatisticas *est = (Estatisticas *)malloc(sizeof(Estatisticas));
    if (est == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        exit(1);
    }

    fread(est, sizeof(Estatisticas), 1, arquivo);
    fclose(arquivo);
    return est;
}

// Função para atualizar as estatísticas após cada fase
void atualizarEstatisticas(Estatisticas *est, float tempo_fase) {
    est->tempo_total += tempo_fase;
    est->tempo_fases[est->fases_completadas] = tempo_fase;
    est->fases_completadas++;
}

// Função para exibir as estatísticas
void mostrarEstatisticas() {
    Estatisticas *est = lerEstatisticas("estatisticas.bin");
    if (est != NULL) {
        printf("Estatísticas do Jogador:\n");
        printf("Fases Completadas: %d\n", est->fases_completadas);
        printf("Tempo Total Jogando: %.2f segundos\n", est->tempo_total);
        for (int i = 0; i < est->fases_completadas; i++) {
            printf("Tempo da Fase %d: %.2f segundos\n", i + 1, est->tempo_fases[i]);
        }
        free(est); // Liberar memória após exibição
    } else {
        printf("Nenhuma estatística encontrada. Jogue algumas fases primeiro!\n");
    }
}

// Função para iniciar o jogo
void iniciarJogo() {
    Estatisticas *est = lerEstatisticas("estatisticas.bin");
    if (est == NULL) {
        est = (Estatisticas *)malloc(sizeof(Estatisticas));
        if (est == NULL) {
            perror("Erro ao alocar memória para estatísticas");
            exit(1);
        }
        est->fases_completadas = 0;
        est->tempo_total = 0.0;
        memset(est->tempo_fases, 0, sizeof(est->tempo_fases));  // Inicializa os tempos das fases
    }

    // Simula o jogo, jogando várias fases (apenas 5 fases)
    for (int fase = 0; fase < 5; fase++) { // Limita o número de fases a 5
        clock_t inicio_fase = clock(); // Começa o tempo da fase

        // Simulação de uma fase... O código da fase ficaria aqui.
        // Lógica de movimentação do jogador, detecção de vitória/colisão, etc.

        clock_t fim_fase = clock(); // Fim do tempo
        float tempo_fase = (float)(fim_fase - inicio_fase) / CLOCKS_PER_SEC;

        // Atualiza as estatísticas
        atualizarEstatisticas(est, tempo_fase);
        printf("Tempo da Fase %d: %.2f segundos\n", fase + 1, tempo_fase);  // Mensagem para depuração
    }

    // Exibe as estatísticas ao final
    mostrarEstatisticas();

    // Salva as estatísticas após o fim do jogo
    salvarEstatisticas("estatisticas.bin", est);

    // Liberar memória
    free(est);
}
