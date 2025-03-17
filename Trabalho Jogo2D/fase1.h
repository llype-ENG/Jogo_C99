#ifndef FASE1_H
#define FASE1_H
#define ALTURA 10   // Defina conforme necessário
#define LARGURA 10  // Defina conforme necessário
// Definição da estrutura Jogador
typedef struct {
    int x, y; // Posição do jogador no labirinto
} Jogador;

typedef struct {
    int x, y;
} Objeto;

typedef struct {
    char nome[50];
    int fase;
    float tempo;  // Tempo gasto na fase
    int tentativas;  // Quantidade de tentativas
} Estatisticas;

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

// Função para criar o labirinto dinamicamente
char **criarLabirinto(int altura, int largura) {
    char **mapa = (char **)malloc(altura * sizeof(char *));
    for (int i = 0; i < altura; i++) {
        mapa[i] = (char *)malloc(largura * sizeof(char));
    }
    return mapa;
}

// Função para liberar o labirinto
void liberarLabirinto(char **mapa, int altura) {
    for (int i = 0; i < altura; i++) {
        free(mapa[i]);
    }
    free(mapa);
}

// Função para iniciar a fase 1
void iniciarFase1() {

    int altura = ALTURA, largura = LARGURA;

    // Criando o labirinto dinamicamente
    char **mapa = criarLabirinto(altura, largura);

    // Inicializando o labirinto
    char temp[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', ' ', ' ', '#', '#', ' ', '#'},
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


 // Fase 2 



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


// Fase 3


void iniciarFase3() {
    Estatisticas estat;
    estat.tentativas = 0;

    int altura = ALTURA, largura = LARGURA;
    // Criando o labirinto dinamicamente
    char **mapa = criarLabirinto(altura, largura);

    // Inicializando o labirinto com paredes (#), espaços ( ) e objetivos (O)
    char temp[ALTURA][LARGURA] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', 'O', '#'},
        {'#', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', 'O', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', '#'},
        {'#', '#', '#', ' ', 'O', ' ', '#', '#', '#', '#'},
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

    char entrada, nextFase = 'N'; // Variável para controlar a transição entre fases

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

   do {
    // Reinicia a posição do jogador para o início se o jogador escolher 'N'
    if (nextFase == 'N' || nextFase == 'n') {
        jogador->x = 1;
        jogador->y = 1;
    }

    while (1) {
        system("cls"); // Limpar tela (Windows)
        desenharLabirinto(mapa, altura, largura, jogador);

        // Captura a entrada do jogador
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
            scanf(" %c", &nextFase); // Corrige o scanf para capturar a resposta do jogador
            if (nextFase == 'S' || nextFase == 's') {
                break; // Sai do loop interno e vai para a próxima fase
            } else {
                nextFase = 'N'; // Garante que a fase seja reiniciada se o jogador escolher 'N'
                break; // Sai do loop e reinicia a fase
            }
        }

        // Verifica se o jogador colidiu com um objeto
        if (mapa[jogador->y][jogador->x] == 'O') {
            // Exibe a mensagem de colisão
            printf("Você perdeu! Colidiu com um objeto!\n");
            estat.tentativas += 1;


            // Pergunta ao jogador se ele quer tentar novamente
            printf("Deseja tentar novamente? (S/N): ");
            char tentativa;
            scanf(" %c", &tentativa); // Captura a resposta

            if (tentativa == 'S' || tentativa == 's') {
                // Se o jogador escolher tentar novamente, reinicia a posição do jogador
                jogador->x = 1;
                jogador->y = 1;
            } else {
                // Caso contrário, sai do loop e termina a fase
                nextFase = 'N'; // Garante que a fase seja reiniciada se o jogador escolher 'N'
                break; // Sai do loop
            }
        }
    }
} while (nextFase == 'N' || nextFase == 'n'); // Repete a fase se o jogador quiser

// Liberando a memória alocada
liberarLabirinto(mapa, altura);
free(jogador);

}


// Fase 4


void iniciarFase4() {
    int altura = 15, largura = 15;
    char nextFase = 'N'; // Garantir que a fase inicie com 'N'
    Estatisticas estat;
    estat.tentativas = 0;

    // Criando o labirinto dinamicamente
    char **mapa = criarLabirinto(altura, largura);

    // Inicializando o labirinto com paredes (#), espaços ( ), objetos (O), buracos (X) e entrada/saída
    char temp[15][15] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#'},
        {'#', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', 'O', ' ', '#', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', '#', ' ', ' ', '#', 'X', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', 'O', ' ', '#'},
        {'#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', 'X', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', 'X', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', 'F', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
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

    char entrada;

    printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

    do {
        // Reinicia a posição do jogador para o início se o jogador escolher 'N'
        if (nextFase == 'N' || nextFase == 'n') {
            jogador->x = 1;
            jogador->y = 1;
        }

        while (1) {
            system("cls"); // Limpar tela (Windows)
            desenharLabirinto(mapa, altura, largura, jogador);

            // Captura a entrada do jogador
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
                scanf(" %c", &nextFase); // Corrige o scanf para capturar a resposta do jogador
                if (nextFase == 'S' || nextFase == 's') {
                    break; // Sai do loop interno e vai para a próxima fase
                } else {
                    nextFase = 'N'; // Garante que a fase seja reiniciada se o jogador escolher 'N'
                    break; // Sai do loop e reinicia a fase
                }
            }

            // Verifica se o jogador colidiu com um objeto
            if (mapa[jogador->y][jogador->x] == 'O') {
                // Exibe a mensagem de colisão
                printf("Você perdeu! Colidiu com um objeto!\n");
                estat.tentativas += 1;


                // Pergunta ao jogador se ele quer tentar novamente
                printf("Deseja tentar novamente? (S/N): ");
                char tentativa;
                scanf(" %c", &tentativa); // Captura a resposta

                if (tentativa == 'S' || tentativa == 's') {
                    // Se o jogador escolher tentar novamente, reinicia a posição do jogador
                    jogador->x = 1;
                    jogador->y = 1;
                } else {
                    // Caso contrário, sai do loop e termina a fase
                    nextFase = 'N'; // Garante que a fase seja reiniciada se o jogador escolher 'N'
                    break; // Sai do loop
                }
            }
        }
    } while (nextFase == 'N' || nextFase == 'n'); // Repete a fase se o jogador quiser

    // Liberando a memória alocada
    liberarLabirinto(mapa, altura);
    free(jogador);
}

void desenharLabirinto2(char **mapa, int altura, int largura, Jogador *jogador, Objeto *objeto) {
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


// Fase 5


void iniciarFase5() {
    int altura = 15, largura = 15;
    Estatisticas estat;
    estat.tentativas = 0;


    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    char novamente[10];

    do {
        // Criando o labirinto dinamicamente
        char **mapa = criarLabirinto(altura, largura);

        // Inicializando o labirinto
        char temp[15][15] = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'S', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
            {'#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '#', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', '#'},
            {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', 'F', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };



        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                mapa[i][j] = temp[i][j];
            }
        }

        // Criando dinamicamente o jogador
        Jogador *jogador = (Jogador *)malloc(sizeof(Jogador));
        if (!jogador) {
            perror("Erro ao alocar memória para o jogador");
            exit(1);
        }
        jogador->x = 1; // Posição inicial
        jogador->y = 1;

        // Criando o objeto que se moverá aleatoriamente
        Objeto *objeto = (Objeto *)malloc(sizeof(Objeto));
        if (!objeto) {
            perror("Erro ao alocar memória para o objeto");
            exit(1);
        }
        objeto->x = 5;
        objeto->y = 5;

        printf("Bem-vindo ao jogo de labirinto! Use W (cima), A (esquerda), S (baixo), D (direita) para mover-se.\n");

        while (1) {
            system("cls"); // Limpar tela
            desenharLabirinto2(mapa, altura, largura, jogador, objeto);

            // Verifica se o jogador chegou ao final
            if (mapa[jogador->y][jogador->x] == 'F') {
                printf("Parabéns! Você completou o labirinto!\n");
                break;
            }
            // Verifica se o jogador atingiu o objeto
            if (jogador->x == objeto->x && jogador->y == objeto->y || (mapa[jogador->y][jogador->x] == 'O' || mapa[jogador->y][jogador->x] == 'X') ) {
                printf("Você perdeu! Colidiu com o objeto!\n");
                estat.tentativas += 1;

                break;
            }

            // Captura a entrada do jogador
            char entrada = getch();
            switch (entrada) {
                case 'w': // Cima
                    if (jogador->y > 0 && mapa[jogador->y - 1][jogador->x] != '#') jogador->y--;
                    break;
                case 's': // Baixo
                    if (jogador->y < altura - 1 && mapa[jogador->y + 1][jogador->x] != '#') jogador->y++;
                    break;
                case 'a': // Esquerda
                    if (jogador->x > 0 && mapa[jogador->y][jogador->x - 1] != '#') jogador->x--;
                    break;
                case 'd': // Direita
                    if (jogador->x < largura - 1 && mapa[jogador->y][jogador->x + 1] != '#') jogador->x++;
                    break;
                default:
                    break;
            }

            // Move o objeto aleatoriamente
            moverObjetoAleatoriamente(mapa, altura, largura, objeto);
        }

        // Liberando memória
        free(jogador);
        free(objeto);
        liberarLabirinto(mapa, altura);

        // Pergunta se o jogador deseja jogar novamente
        printf("Deseja jogar novamente? (sim/nao): ");
        fgets(novamente, sizeof(novamente), stdin);
        novamente[strcspn(novamente, "\n")] = '\0'; // Remove o '\n'

    } while (strcmp(novamente, "sim") == 0);

    printf("Obrigado por jogar! Até a próxima.\n");

}

void salvarEstatisticas(const char *arquivo, Estatisticas estat) {
    FILE *fp = fopen(arquivo, "ab"); // "ab" para adicionar em modo binário
    if (!fp) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    fwrite(&estat, sizeof(Estatisticas), 1, fp);
    fclose(fp);
}

void exibirEstatisticas(const char *arquivo) {
    FILE *fp = fopen(arquivo, "rb"); // "rb" para leitura binária
    if (!fp) {
        printf("Nenhum dado encontrado!\n");
        return;
    }

    Estatisticas estat;
    printf("\n=== Estatísticas dos Jogadores ===\n");
    while (fread(&estat, sizeof(Estatisticas), 1, fp)) {
        printf("Nome: %s | Fase: %d | Tempo: %.2f segundos | Tentativas: %d\n", 
               estat.nome, estat.fase, estat.tempo, estat.tentativas);
    }
    
    fclose(fp);
}

#endif // FASE1_H
