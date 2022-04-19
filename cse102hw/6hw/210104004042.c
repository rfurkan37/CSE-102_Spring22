#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void red()     // color functions.
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

void blue()
{
    printf("\033[0;34m");
}

void white()
{
    printf("\033[0;37m");
}

void green()
{
    printf("\033[0;32m");
}

int dice(void) // random number generator
{
    int a = 0;
    srand(time(NULL)); // writing it to not give same number in different execution.

    while (a == 0)
    {
        a = (rand() % 6) + 1; // gives number between 1 and 6 included
    }

    return a;
}

void printMatrix(char table[][30])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (table[i][j] == '-' || table[i][j] == '|') // printing due color
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

void createMap(char gameTable[][30]) // starting situation of map creating here.
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

int move(char matrix[][30], int dice, int ara)
{
    int posi, posj , ret = 0;

    for (int i = 0; i < 15; i++)  // finding 1 or 2 due to flag
    {
        for (int j = 0; j < 30; j++)
        {
            if (matrix[i][j] == '0' + ara)
            {
                posi = i;
                posj = j;
                break;
            }
        }
    }

    matrix[posi][posj] = ' '; // deleting number
    
    if(ara == 1)
    {
        if(posi == 1)
        {
            if(posj + dice > 28) // changing direction
            {
                posi += dice - (28 - posj);
                posj = 28;
            }
            else if(matrix[posi][posj + dice] == 'X')
            { // penalty error
                posj = posj + dice - 2;
                yellow();
                printf("PENALTY FOR PLAYER 1.\n");
                reset();
            }
            else
            {
                posj += dice; // normal increment
            }
        }
        else if(posj == 28) // same things
        {
            if(posi + dice > 13)
            {
                posj = posj - (dice - (13 - posi));
                posi = 13; 
            }
            else if(matrix[posi + dice][posj] == 'X')
            {
                posi = posi + dice - 2;
                yellow();
                printf("PENALTY FOR PLAYER 1.\n");
                reset();
            }
            else
                posi += dice;
        }
        else if(posi == 13) // same things above but different number due to direction
        {
            if(posj - dice < 1)
            {
               posi -= dice - (posj - 1);
               posj = 1;
            }
            else if(matrix[posi][posj - dice] == 'X')
            {
                posj = posj - dice + 2;
                yellow();
                printf("PENALTY FOR PLAYER 1.\n");
                reset();
            }
            else
                posj -= dice;
        }
        else if(posj == 1)
        {
            if(posi - dice < 4)
            {
                while(dice>0){ // changing direction at the end

                    if(posi >1) posi--;
                    else posj++;

                    dice--;
                }
                ret = 3; // returning 3 to winning
                //KAZANMIŞ
            }
            else
                posi -= dice;
        }

        matrix[posi][posj] = '1'; // changing place of 1 
    }
    else if(ara == 2) // same codes for 2 
    {
        if(posi == 3)
        {
            if(posj + dice > 26)
            {
                posi += dice - (26 - posj);
                posj = 26;
            }
            else if(matrix[posi][posj + dice] == 'X')
            {
                posj = posj + dice - 2;
                blue();
                printf("PENALTY FOR PLAYER 2.\n");
                reset();
                //PENALTy
            }
            else
                posj += dice;
            
        }
        else if(posj == 26)
        {
            if(posi + dice > 11)
            {
                posj = posj - (dice - (11 - posi));
                posi = 11; 
            }
            else if(matrix[posi + dice][posj] == 'X')
            {
                posi = posi + dice - 2;
                blue();
                printf("PENALTY FOR PLAYER 2.\n");
                reset();
                //PENALTy
            }
            else
                posi += dice;
        }
        else if(posi == 11)
        {
            if(posj - dice < 3)
            {
               posi -= dice - (posj - 3);
               posj = 3;
            }
            else if(matrix[posi][posj - dice] == 'X')
            {
                posj = posj - dice + 2;
                blue();
                printf("PENALTY FOR PLAYER 2.\n");
                reset();
                //PENALTy
            }
            else
                posj -= dice;
        }
        else if(posj == 3)
        {
            if(posi - dice < 4)
            {
                while(dice>0){

                    if(posi >3) posi--;
                    else posj++;

                    dice--;
                }
                ret = 3;
                //KAZANMIŞ
            }
            else
                posi -= dice;
        }
        matrix[posi][posj] = '2';
    }

    return ret;
}

int startGame()
{
    int dice1, dice2; // starting of gamee choosing first starter
    printf("\n\nTo start the game, players should dice and decide who is going to start first according to it...\n");
    while (1)
    {
        yellow();
        printf("PLAYER 1... Please press ENTER to dice.\n");
        getchar();
        dice1 = dice();
        printf("DICE : %d\n", dice1);
        blue();
        printf("PLAYER 2... Please press ENTER to dice.\n");
        getchar();
        dice2 = dice();
        printf("DICE : %d\n", dice2);

        if (dice1 > dice2)
            return 1;
        else if (dice2 > dice1)
            return 2;
        else
        {
            white();
            printf("Same dice value... Please try again.\n");
            reset();
        }
    }
}
void game(char table[15][30])
{
    int win1 = 0, win2 = 0, dice1 = 0, dice2 = 0, ret = 0, moveret;

    createMap(table); // creating
    printMatrix(table); // printing
    ret = startGame();

    if (ret == 1) // first starter
    {
        printf("\n*** PLAYER 1 will start the game... ***\n");
        while (1)
        {
            yellow();
            printf("PLAYER 1... Please press ENTER to dice.");
            getchar(); // getting char
            dice1 = dice(); // dicing
            printf("DICE : %d\n", dice1); //printing dice
            moveret = move(table, dice1, 1); // moving
            if(moveret == 3)
            {
                printMatrix(table);
                win1++; //  winning situation
                break;
            }

            blue();
            printf("PLAYER 2... Please press ENTER to dice.\n");
            getchar();
            dice2 = dice();
            printf("DICE : %d\n", dice2);
            moveret = move(table, dice2, 2);
            if(moveret == 3)
            {
                printMatrix(table);
                win2++;
                break;
            }
            printMatrix(table);
        }
    }
    else if (ret == 2) // 2 starts first 
    {
        printf("*** PLAYER 2 will start the game... ***\n");
        while (1)
        {
            blue();
            printf("PLAYER 2... Please press ENTER to dice.\n");
            getchar();
            dice2 = dice();
            printf("DICE : %d\n", dice2);
            moveret = move(table, dice2, 2);
            if(moveret == 3)
            {
                printMatrix(table);
                win2++;
                break;
            }
            yellow();
            printf("PLAYER 1... Please press ENTER to dice.\n");
            getchar();
            dice1 = dice();
            printf("DICE : %d\n", dice1);
            moveret = move(table, dice1, 1);
            if(moveret == 3)
            {
                printMatrix(table);
                win1++;
                break;
            }
            printMatrix(table);
        }
    }

    if(win2 == 1)
    {
        blue();
        printf("\n\n\n*** PLAYER 2 WON THE GAME ***\n"); // giving message winner
        reset();
    }
    else if(win1 == 1)
    {
        yellow();
        printf("\n\n\n*** PLAYER 1 WON THE GAME ***\n");
        reset();
    }
}

int main()
{
    char gameTable[15][30];
    game(gameTable);
    return 0;
}