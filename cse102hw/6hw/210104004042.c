#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void reset()
{
    printf("\033[0m");
}
void green()
{
    printf("\033[0;32m");
}
void blue()
{
    printf("\033[0;34m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[0;36m");
}
void white()
{
    printf("\033[0;37m");
}

int dice(void)
{
    int a = 0;
    srand(time(NULL));

    while (a == 0)
    {
        a = (rand() % 6) + 1;
    }

    return a;
}
void printMatrix(char table[][30])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (table[i][j] == '-' || table[i][j] == '|')
                white();
            else if (table[i][j] == '_')
                green();
            else if (table[i][j] == 'X')
                red();
            else if (table[i][j] == '1')
                yellow();
            else if (table[i][j] == '2')
                blue();
            printf("%c", table[i][j]);
            reset();
        }
        printf("\n");
    }
}
void createMap(char gameTable[][30])
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
    gameTable[2][1] = '_';
    gameTable[4][3] = '_';
    gameTable[1][1] = '1';
    gameTable[3][3] = '2';
}

int move(char matrix[][30], int dice, int flag)
{
    int ix, jy;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (matrix[i][j] == 48 + flag)
            {
                ix = i;
                jy = j;
                break;
            }
        }
    }

    
}

int startGame()
{
    int dice1, dice2;
    printf("\n\nTo start the game, players should dice and decide who is going to start first according to it...\n");
    while (1)
    {
        printf("PLAYER 1... Please press ENTER to dice.\n");
        getchar();
        dice1 = dice();
        printf("DICE : %d\n", dice1);
        printf("PLAYER 2... Please press ENTER to dice.\n");
        getchar();
        dice2 = dice();
        printf("DICE : %d\n", dice2);

        if (dice1 > dice2)
            return 1;
        else if (dice2 > dice1)
            return 2;
        else
            printf("Same dice value... Please try again.\n");
    }
}
void game(char table[15][30])
{
    int win1 = 0, win2 = 0, dice1 = 0, dice2 = 0, ret = 0, moveret;

    createMap(table);
    printMatrix(table);
    ret = startGame();

    if (ret == 1)
    {
        printf("\n*** PLAYER 1 will start the game... ***\n");
        while (win1 == 0 && win2 == 0)
        {
            printf("PLAYER 1... Please press ENTER to dice.");
            getchar();
            dice1 = dice();
            printf("DICE : %d\n", dice1);
            /*moveret = move(table, dice1, 1);
            if (moveret == 0)
                printf("Penalty for player 1...\n");
            else if (moveret == 2)
            {
                win1 = 1;
                break;
            }
            */
            printf("PLAYER 2... Please press ENTER to dice.\n");
            getchar();
            dice2 = dice();
            printf("DICE : %d\n", dice2);
            /*moveret = move(table, dice2, 2);
            if (moveret == 0)
                printf("Penalty for player 2...\n");
            else if (moveret == 2)
            {
                win2 = 1;
                break;
            }
            */
            printMatrix(table);
        }
    }
    else if (ret == 2)
    {
        printf("*** PLAYER 2 will start the game... ***\n");
        while (win1 == 0 && win2 == 0)
        {
            printf("PLAYER 2... Please press ENTER to dice.\n");
            getchar();
            dice2 = dice();
            printf("DICE : %d\n", dice2);
            /*moveret = move(table, dice2, 2);
            if (moveret == 0)
                printf("Penalty for player 2...\n");
            else if (moveret == 2)
            {
                win2 = 1;
                break;
            }
            */
            printf("PLAYER 1... Please press ENTER to dice.\n");
            getchar();
            dice1 = dice();
            printf("DICE : %d\n", dice1);
            /*moveret = move(table, dice1, 1);
            if (moveret == 0)
                printf("Penalty for player 1...\n");
            else if (moveret == 2)
            {
                win1 = 1;
                break;
            }
            */
            printMatrix(table);
        }
    }
}

int main()
{
    char gameTable[15][30];

    game(gameTable);

    return 0;
}