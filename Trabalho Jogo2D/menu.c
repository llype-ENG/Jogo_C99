#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "fase1.h"
#include "fase5.h"  // Incluindo o arquivo da fase1 para poder chamar a função iniciarFase1
#include "estatisticas.h"

void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[3][40]);
void textColor(int letras, int fundo);

enum {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE};
enum {_BLACK=0, _BLUE=16, _GREEN=32, _CYAN=48, _RED=64, _MAGENTA=80, _BROWN=96, _LIGHTGRAY=112, _DARKGRAY=128, _LIGHTBLUE=144, _LIGHTGREEN=160, _LIGHTCYAN=176, _LIGHTRED=192, _LIGHTMAGENTA=208, _YELLOW=224, _WHITE=240};

void textColor(int letra, int fundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
}

void linhaCol(int lin, int col) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){col - 1, lin - 1});
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void box(int lin1, int col1, int lin2, int col2) {
    int i, j, tamlin, tamcol;
    tamlin = lin2 - lin1;
    tamcol = col2 - col1;

    for (i = col1; i <= col2; i++) { 
        linhaCol(lin1, i);
        printf("%c", 196);
        linhaCol(lin2, i);
        printf("%c", 196);
    }

    for (i = lin1; i <= lin2; i++) { 
        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);
    }

    for (i = lin1 + 1; i < lin2; i++) {
        for (j = col1 + 1; j < col2; j++) {
            linhaCol(i, j);
            printf(" ");
        }
    }

    linhaCol(lin1, col1);
    printf("%c", 218);
    linhaCol(lin1, col2);
    printf("%c", 191);
    linhaCol(lin2, col1);
    printf("%c", 192);
    linhaCol(lin2, col2);
    printf("%c", 217);
}

int menu(int lin1, int col1, int qtd, char lista[3][40]) {
    int opc = 1, lin2, col2, linha, i, tamMaxItem, tecla;
    tamMaxItem = strlen(lista[0]);
    for (i = 1; i < qtd; i++) {
        if (strlen(lista[i]) > tamMaxItem) {
            tamMaxItem = strlen(lista[i]);
        }
    }
    lin2 = lin1 + (qtd * 2 + 2);
    col2 = col1 + tamMaxItem + 4;

    textColor(WHITE, _MAGENTA);
    setlocale(LC_ALL, "C");
    box(lin1, col1, lin2, col2);
    setlocale(LC_ALL, "");
    
    while (1) {
        linha = lin1 + 2;
        for (i = 0; i < qtd; i++) {           
            if (i + 1 == opc) {
                textColor(BLACK, _LIGHTBLUE); 
            }
            else {
                textColor(WHITE, _MAGENTA);
            }
            linhaCol(linha, col1 + 2);
            printf("%s", lista[i]);
            linha += 2;
        }

        linhaCol(1, 1);
        tecla = getch();
        linhaCol(22, 1);

        if (tecla == 27) { // Se pressionar ESC, sai do menu
            opc = 0; break;
        }
        else if (tecla == 13) { // Se pressionar ENTER, seleciona a opção
            break;
        }
        else if (tecla == 72) { // Se pressionar a seta para cima, vai para a opção anterior
            if (opc > 1) opc--; 
        }
        else if (tecla == 80) { // Se pressionar a seta para baixo, vai para a próxima opção
            if (opc < qtd) opc++; 
        }
    }

    return opc;
}

int main() {
    int opc;
    char lista[3][40] = {"Iniciar Jogo", "Estatísticas", "Sair do jogo"}; 
    char nomeJogo[] = "Labirinto C99"; 
    char playerName[50];

    setlocale(LC_ALL, "");

    int larguraTela = 80; 
    int posicaoCentral = (larguraTela / 2) - (strlen(nomeJogo) / 2);

    textColor(WHITE, _BLACK);
    linhaCol(1, posicaoCentral);
    printf("%s\n", nomeJogo);

    while (true) {
        opc = menu(10, 10, 3, lista);
        if (opc == 0) { 
            break;  // Se for 0, sai do jogo
        }

        if (opc == 1) {
            printf("Iniciando Fase 1...\n");  // Exibe uma mensagem de confirmação
            iniciarFase1(); // Chama a função que inicia a fase 1
            printf("Iniciando Fase 2...\n");
            iniciarFase2();
            printf("Iniciando Fase 3...\n");
            iniciarFase3();
            printf("Iniciando Fase 4...\n");
            iniciarFase4();
            printf("Iniciando Fase 5...\n");
            iniciarFase5();;
        } else if (opc == 2) {
            printf("Exibindo estatísticas... \n");
            mostrarEstatisticas();
            // Aqui você pode adicionar a lógica para exibir as estatísticas, caso necessário
        }
    }

    textColor(WHITE, _BLACK);
    linhaCol(24, 1);
    printf("Obrigado por jogar!\n");

    return 0;
}
