#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(void)
{
    int a = 0;
    srand(time(NULL));

    while (a == 0)
    {
        a = rand() % 7;
    }
    
    return a;
}

void printMatrix(char table[15][30])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            printf("%c", table[i][j]);
        }
        printf("\n");
    }
}

void printMap(char gameTable[15][30], int x1, int y1, int x2, int y2)
{

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == 0 || i == 14)
                gameTable[i][j] = '-';
            else if (j == 0 || j == 29)
                gameTable[i][j] = '|';
            else if (j >= 2 && j <= 27 && (i == 2 || i == 12))
                gameTable[i][j] = '-';
            else if (i > 2 && i < 12 && (j == 2 || j == 27))
                gameTable[i][j] = '|';
            else if (j >= 4 && j <= 25 && (i == 4 || i == 10))
                gameTable[i][j] = '-';
            else if (i > 4 && i < 10 && (j == 4 || j == 25))
                gameTable[i][j] = '|';
            else if (i == y1 && j == x1)
                gameTable[i][j] = '1';
            else if (i == y2 && j == x2)
                gameTable[i][j] = '2';
            else
                gameTable[i][j] = ' ';
        }
    }

    gameTable[1][14] = 'X';
    gameTable[7][28] = 'X';
    gameTable[13][14] = 'X';
    gameTable[3][10] = 'X';
    gameTable[3][18] = 'X';
    gameTable[5][26] = 'X';
    gameTable[10][26] = 'X';
    gameTable[11][10] = 'X';
    gameTable[11][18] = 'X';

    printMatrix(gameTable);
}

int main()
{
    char gameTable[15][30];
    int pos1x = 1, pos1y = 1, pos2x = 3, pos2y = 3;

    printMap(gameTable, pos1x, pos1y, pos2x, pos2y);
    printf("What's going on here?");

    return 0;
}