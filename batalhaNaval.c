#include <stdio.h>
#define LINHA 10
#define COLUNA 11

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabela[LINHA][COLUNA];

    printf("  ");//espaco em branco pra alinhar as letras com os numeros

    //impressão das letras
    for (int i = 0; i < 10; i++)
    {
        printf("%2c", linha[i]);
    }
    printf("\n");

    //preenchendo a matriz com os numeros de 1 a 10
    for (int i = 0; i < LINHA; i++)
    {
       tabela[i][0] = i + 1;
        
        //preenchendo as colunas com 0
        for (int j = 1; j < COLUNA; j++)
        {
            tabela[i][j] = 0;
        }
    }


     //define manualmente onde os navios estarão alocados na tabela 

     //Cordenadas 2 - C, D, E
     tabela[1][3] = 3;
     tabela[1][4] = 3;
     tabela[1][5] = 3;
 
     //cordenada E - 6 ,7, 8
     tabela[5][5] = 3;
     tabela[6][5] = 3;
     tabela[7][5] = 3;
 
     //cordenada diagonal F, G, H - 4, 5, 6
     tabela[2][9] = 3;
     tabela[3][8] = 3;
     tabela[4][7] = 3;

    // cordenada diagonal A, B, C - 8, 9, 10
    tabela[7][1] = 3;
    tabela[8][2] = 3;
    tabela[9][3] = 3;

    //imprimindo a matriz com os numeros
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("%2d", tabela[i][j]);
        }
        printf("\n");
    }

    return 0;
}