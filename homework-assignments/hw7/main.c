#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 6  // max letter
#define MAX_T 15 // max table size
#define MAX_W 50 // max word amount

enum types // enumerating to see it effectively.
{
    horizontal = 1,
    rhorizontal,
    vertical,
    rvertical,
    torightdiagonal, /* / */
    rtorightdiagonal,
    toleftdiagonal, /* \ */
    rtoleftdiagonal
};
struct putWords // building struct to make thing easier and to collect all data in one type
{
    int index, jitter, length, type;
};

struct putWords words[7]; // making them in array to use it with other array

void printMatrix(char matrix[MAX_T][MAX_T]) // printing 2d array
{
    for (int i = 0; i < MAX_T; i++)
    {
        for (int j = 0; j < MAX_T; j++)
        {
            if (matrix[i][j] == 'X') // printing the X letter in red color
            {
                printf("\033[1;31m");
            }
            printf("%c ", matrix[i][j]);
            printf("\033[0m");
        }
        printf("\n");
    }
}
void transferWordstoArray(char fill[MAX_W][MAX_L]) // transferring words to array
{
    int i = 0;
    FILE *file;
    file = fopen("wordlist.txt", "r"); // opening file in read mode.

    while (!feof(file) && i < 50) // until the end and 50 word
    {
        fscanf(file, "%s", fill[i]); // scanning into array
        i++;
    }
    fclose(file); // closing file
}

void chooseRandomWords(char words[][MAX_L], char choosenWords[][MAX_L]) // choosing randomly from array
{
    int randoms[7] = {-1, -1, -1, -1, -1, -1, -1}; // declaring random array
    int random, flag, i = 0;

    while (i < 7) // 7 words
    {
        flag = 0;
        random = rand() % 50; // 0 to 49

        for (int j = 0; j < i; j++) // searching old randoms to check double same
        {
            if (randoms[j] == random) // if its like that  making flag 1 and quitting
            {
                flag = 1;
                break; 
            }
        }

        if (flag == 0) // if its not double
        {
            strcpy(choosenWords[i], words[random]); // taking into words array
            randoms[i] = random;// recording random
            i++; // incrementing i
        }
    }
}

int checkValidity(int i, int j, int length, int type, char board[][MAX_T])
{
    int holyFlag = 0, c = 0;
    switch (type)
    {
    case horizontal:
        if (j + (length - 1) >= MAX_T) // if it goes out of table return 0
            return 0;
        else // else searching for X
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }
                j++; // searching horizontal
                c++;
            }

            if (holyFlag == 1) // if there is  x on the road return 0 else 1
                return 0;
            else
                return 1;
        }
        break;
    case rhorizontal: // reverse horizontal but same
        if (j - (length - 1) < 0)
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }
                j--;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    case vertical: // vertical version
        if (i + (length - 1) >= MAX_T)
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }
                i++;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    case rvertical: // reverse vertical
        if (i - (length - 1) < 0)
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }
                i--;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    case toleftdiagonal: /* \ */
        if (i + (length - 1) >= MAX_T || j + (length - 1) >= MAX_T)
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }

                i++;
                j++;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    case rtoleftdiagonal: /*reverse \ */
        if ((i - (length - 1) < 0) || (j - (length - 1) < 0))
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }

                i--;
                j--;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    case torightdiagonal:/* / */
        if (i - (length - 1) < 0 || j + (length - 1) >= MAX_T)
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }

                i--;
                j++;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    case rtorightdiagonal:/* / */
        if (i + (length - 1) >= MAX_T || j - (length - 1) < 0)
            return 0;
        else
        {
            while (c < length)
            {
                if (board[i][j] == 'X')
                {
                    holyFlag = 1;
                    break;
                }

                i++;
                j--;
                c++;
            }

            if (holyFlag == 1)
                return 0;
            else
                return 1;
        }
        break;
    default:
        break;
    }
}

void modifyTable(int i, int j, int length, int type, char board[][MAX_T], char word[MAX_L], int flag)
{
    int count = 0;

    switch (type)
    {
    case horizontal: // flag 1 means cover with X 0 means make it letter
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            j++;
            count++;
        }
        break;
    case rhorizontal:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            j--;
            count++;
        }
        break;
    case vertical:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            i++;
            count++;
        }
        break;
    case rvertical:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            i--;
            count++;
        }
        break;
    case torightdiagonal:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            i--;
            j++;
            count++;
        }
        break;
    case rtorightdiagonal:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            i++;
            j--;
            count++;
        }
        break;
    case toleftdiagonal:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            i++;
            j++;
            count++;
        }
        break;
    case rtoleftdiagonal:
        while (count < length)
        {
            if (flag == 1)
                board[i][j] = 'X';
            else
                board[i][j] = word[count];

            i--;
            j--;
            count++;
        }
        break;
    default:
        break;
    }
}
void putWordsintoBoard(char choosenWords[][MAX_L], char board[][MAX_T])
{
    int i = 0, j = 0, length, type, ret = -1;
    int c = 0;

    while (c < 7)
    {
        ret = -1;
        length = strlen(choosenWords[c]); // taking length

        while (ret != 1) // finding suitable random
        {
            i = rand() % MAX_T;
            j = rand() % MAX_T;
            type = (rand() % 8) + 1;
            ret = checkValidity(i, j, length, type, board);
        }
        modifyTable(i, j, length, type, board, choosenWords[c], 1); // modifying with X

        words[c].index = i; // saving into struct
        words[c].jitter = j;
        words[c].length = length;
        words[c].type = type;

        c++;
    }

    for (int a = 0; a < 7; a++)
    {
        modifyTable(words[a].index, words[a].jitter, words[a].length, words[a].type, board, choosenWords[a], 0); // making them all letters
    }
}

void generateMatrix(char board[][MAX_T]) // generating random charater table
{
    for (int i = 0; i < MAX_T; i++)
    {
        for (int j = 0; j < MAX_T; j++)
            board[i][j] = 'a' + (rand() % 26); 
    }
}

void game(char table[][MAX_T], char word[][MAX_L])
{
    int hp = 3, point = 0, i, j, holyFlag;
    int buf1, buf2;
    char strbuf[10];
    char buffer[100];

    printf("Welcome to game!!\n"
           "Here is your table.\n"
           "Please type coordinates of first letter you found and the word after that.\n"
           "You have 3 HP 's and each word worth 5 points.\n"
           "Good luck!\n");
    for (int i = 0; i < 7; i++)
    {
        printf("Position : [%d][%d]\n Type: %d\n Word: %s\n Lenght: %d\n\n", words[i].index, words[i].jitter, words[i].type, word[i], words[i].length); // printing for hint
    }

    while (hp > 0 && point != 14)
    {
        holyFlag = 0;
        printMatrix(table);
        printf("\nEnter the coordinates and the word: ");
        scanf("%[^\n]%*c", buffer); // until the enter scan

        if (buffer[0] == ':' && buffer[1] == 'q')
            break; // stop at :q
        else
        {
            sscanf(buffer, "%d %d %s", &buf1, &buf2, strbuf); // separating string into different variables

            i = buf1;// taing them to i and j which are coordinates
            j = buf2;

            for (int k = 0; k < 7; k++) // searching for answer
            {
                if (words[k].index == i && words[k].jitter == j && strcmp(word[k], strbuf) == 0)
                {
                    modifyTable(i, j, words[k].length, words[k].type, table, word[k], 1); // if true making them XX
                    strcpy(word[k], "founded"); // changing in array 
                    holyFlag = 1;
                    break;
                }
            }

            if (holyFlag == 1) // if corrent incrementing point and priniting result
            {
                point += 2;
                printf("\nFounded! You got 2 points. Your total point is %d\n", point);
            }
            else
            { // else decrementing hp and printing lefts
                hp--;
                printf("Wrong choice! You have %d lefts. Please try again!\n", hp);
            }
        }
    }
    printf("Game finished!. You got %d points. Thanks for playing.\n", point); // at the end printing point
}

int main(void)
{
    srand(time(NULL)); // setting seed
    char board[MAX_T][MAX_T];
    char wordArray[50][MAX_L];
    char choosenWords[7][MAX_L];
    generateMatrix(board); // running functions in order
    transferWordstoArray(wordArray);
    chooseRandomWords(wordArray, choosenWords);
    putWordsintoBoard(choosenWords, board);
    game(board, choosenWords);

    return 0;
}