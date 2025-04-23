#include <stdio.h>

int main()
{

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for (int i = 0; i < 10; i++)
    {
        printf("%2c ", linha[i]);
    }
    printf("\n");

     // Preenche a matriz com a primeira coluna numerada e o restante com 0
    int tabela[10][10];

    for (int i = 0; i < 10; i++)
    {
        tabela[i][0] = i + 1;

        for (int j = 1; j < 10; j++)
        {
            tabela[i][j] = 0;
        }
    }

    //define manualmente onde os navios estarão alocados na tabela 
    tabela[1][3] = 3;
    tabela[1][4] = 3;
    tabela[1][5] = 3;

    tabela[5][5] = 3;
    tabela[6][5] = 3;
    tabela[7][5] = 3;


    //Imprime a matriz
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++){
            printf("%2d ", tabela[i][j]);
        }
        printf("\n");
    }

    return 0;
}
