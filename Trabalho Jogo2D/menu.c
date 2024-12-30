#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "fase1.h"
#include "estatisticas.h"

int main() {
    int opcao;
    
    while(1){
    // Corrigindo as strings dentro do printf
    printf("Bem Vindo ao Labirinto em C99\n");
    printf("1 - Iniciar jogo.\n");
    printf("2 - Estatísticas.\n");
    printf("3 - Sair do Jogo.\n");
    
    // Corrigido o scanf, agora passa o endereço de 'opcao'
    scanf("%d", &opcao);
        
    switch(opcao) {
        case 1:
            printf("Iniciando Fase 1...\n");  // Exibe uma mensagem de confirmação
            iniciarFase1(); // Chama a função que inicia a fase 1
            printf("Iniciando Fase 2...\n");
            iniciarFase2();
            printf("Iniciando Fase 3...\n");
            iniciarFase3();
            printf("Iniciando Fase 4...\n");
            iniciarFase4();
            printf("Iniciando Fase 5...\n");
            iniciarFase5();
            break;

        case 2:
            printf("Exibindo estatísticas... \n");
            iniciarEstatisticas(); 
            break;

        case 3: 
            printf("Saindo do jogo...\n");
            exit(0);
            break;
        
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
    }

    return 0;
}
