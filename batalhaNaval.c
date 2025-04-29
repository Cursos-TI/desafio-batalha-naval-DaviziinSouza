#include <stdio.h>
#define LINHA 10
#define COLUNA 11

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabela[LINHA][COLUNA];

    // Cabeçalho
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf("%2c", linha[i]);
    }
    printf("\n");

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < LINHA; i++) {
        tabela[i][0] = i + 1;
        for (int j = 1; j < COLUNA; j++) {
            tabela[i][j] = 0;
        }
    }

    // Navios (valor 3)
    tabela[1][3] = 3; tabela[1][4] = 3; tabela[1][5] = 3;
    tabela[5][5] = 3; tabela[6][5] = 3; tabela[7][5] = 3;
    tabela[2][9] = 3; tabela[3][8] = 3; tabela[4][7] = 3;
    tabela[7][1] = 3; tabela[8][2] = 3; tabela[9][3] = 3;

    // Matriz CONE 3x3
    int cone[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
    };

    // Matriz CRUZ 3x3
    int cruz[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // Matriz OCTAEDRO 3x3 (losango)
    int octaedro[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // Aplicar CONE (origem: 2,2)
    int origem_linha = 2, origem_coluna = 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int li = origem_linha - 1 + i;
            int co = origem_coluna - 1 + j;
            if (li >= 0 && li < LINHA && co >= 1 && co < COLUNA && cone[i][j] == 1 && tabela[li][co] == 0)
                tabela[li][co] = 7;
        }
    }

    // Aplicar CRUZ (origem: 6,8)
    origem_linha = 6;
    origem_coluna = 8;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int li = origem_linha - 1 + i;
            int co = origem_coluna - 1 + j;
            if (li >= 0 && li < LINHA && co >= 1 && co < COLUNA && cruz[i][j] == 1 && tabela[li][co] == 0)
                tabela[li][co] = 8;
        }
    }

    // Aplicar OCTAEDRO (origem: 4,7) - mais distante
    origem_linha = 4;
    origem_coluna = 7;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int li = origem_linha - 1 + i;
            int co = origem_coluna - 1 + j;
            if (li >= 0 && li < LINHA && co >= 1 && co < COLUNA && octaedro[i][j] == 1 && tabela[li][co] == 0)
                tabela[li][co] = 6;
        }
    }

    // Exibir tabuleiro final
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%2d", tabela[i][j]);
        }
        printf("\n");
    }

    return 0;
}
