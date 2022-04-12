#include <stdio.h>
// these functions are changing color for me.
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

int basamaksayaci(int n)
{
    int i = 0;    // taking n number and dividing it by 10 until it becomes 0 and counting to find digit number
    if (n < 0)
    {
        i++;
        n *= -1; // if it is negative i turn it to positive.
    }

    while (n > 0)
    {
        n = n / 10;
        i++;
    }

    return i;
}

void part1(void) // in first part
{
    FILE *file;  // ı define a file
    int a, b, c; // and integers for coefficients
    printf("\nPlease enter the coefficient for the following equation: x = a * (y * y) + b * y + c\n\n");
    printf("a: ");
    scanf("%d", &a); // taking a b and c to print them to file.
    printf("b: ");   // taking a b and c to print them to the file.
    scanf("%d", &b); // taking a b and c to print them to the file.
    printf("c: ");   // taking a b and c to print them to the file.
    scanf("%d", &c); // taking a b and c to print them to the file.

    file = fopen("coefficients.txt", "w"); // opening the file in write mode
    fprintf(file, "%d\n%d\n%d", a, b, c);  // and print the coefficients
    fclose(file);                          // closing the file after finishing my business here.

    printf("\ncoefficients.txt file has been created."); // informating user
}
void part2(void) // in second part
{
    FILE *file;                             // scanning the coefficients from .txt file
    int a, b, c, x, y, d, flag;             // scanning the coefficients from .txt file
    file = fopen("coefficients.txt", "r");  // scanning the coefficients from .txt file
    fscanf(file, "%d\n%d\n%d", &a, &b, &c); // scanning the coefficients from .txt file
    fclose(file);                           // scanning the coefficients from .txt file

    printf("Printing the graph of x = %d*(y*y) + %d*y + %d.\n", a, b, c);
    
    for (y = 16; y >= -16; y--) // my graphs y is starting from 16 because of arrows
    {
        flag = 0; // ı used flag because ı dont want the graph and the number concatenate each other.
        for (x = -56; x <= 56; x++) // x is is starring from -56 from the same reason.
        {

            if (x == 0 && y == 16)             // placing the ^ symbol at the top
            {                                  // placing the ^ symbol at the top
                green();                       // placing the ^ symbol at the top
                printf("^");                   // placing the ^ symbol at the top
                reset();                       // placing the ^ symbol at the top
            }
            else if (x == a * (y * y) + b * y + c)  //placing the ^ symbol at the top
            {
                red();
                printf("#");
                reset();

                if(x < 0)
                    flag = 3;
                else
                    flag = 2;
                 // and also making flag 3 because we have 3 digits number for negative. else it is 2 we shoul wait 2/3 digits until printing number

            }
            else if (x == -1 && y % 5 == 0 && y != 0 && flag == 0)
            {
                d = basamaksayaci(y); // ım printing back space in the amount of digit number because ım printing spaze after it.
                while (d != 0)
                {
                    printf("\b");
                    d--;
                }

                cyan();
                printf("%d ", y);
                reset();
            }
            else if (y == -1 && x % 10 == 0 && x != 0 && x != -1 && flag == 0)
            {
                d = basamaksayaci(x); // same think ım doing here.
                while (d != 0)
                {
                    printf("\b");
                    d--;
                }
                cyan();
                printf("%d ", x);
                reset();
            }
            else if (x == 56 && y == 0)                                             //placing the symbols again
            {                                       //placing the symbols again
                green();                                //placing the symbols again
                printf(">");                                //placing the symbols again
                reset();                                //placing the symbols again
            }                               //placing the symbols again
            else if (x == -56 && y == 0)                              //placing the symbols
            {                              //placing the symbols
                green();                              //placing the symbols
                printf("<");                              //placing the symbols
                reset();                              //placing the symbols
            }                              //placing the symbols
            else if (x == 0 && y == -16)                        // placing the symbols
            {                       // placing the symbols
                green();                        // placing the symbols
                printf("v");                        // placing the symbols
                reset();                        // placing the symbols
            }                       // placing the symbols
            else if (x == 0)                        // placing the symbols
            {                       // placing the symbols
                green();                        // placing the symbols
                printf("|");                        // placing the symbols
                reset();                        // placing the symbols
            }                       // placing the symbols
            else if (y == 0 && x != 0)                      // placing the symbols
            {                       // placing the symbols
                green();                        // placing the symbols
                printf("-");                        // placing the symbols
                reset();                        // placing the symbols
            }                       // placing the symbols
            else if (x == -1 && y == -1)                        // placing the symbols
            {                       // placing the symbols
                cyan();                     // placing the symbols
                printf("0");                        // placing the symbols
                reset();                        // placing the symbols
            }                       // placing the symbols
            else                        // placing the symbols
            {
                printf(" ");
                if (flag > 0) // while ım printing space ı  also decreasing flag 
                    flag--;
            }
        }
        printf("\n"); // ı go to next row.
    }
}
void part3()
{
    FILE *file; // in this part ım doing same things as the part 2 excluded of numbers and colors
    FILE *constant;
    int x, y, a, b, c;
    file = fopen("graph.txt", "w");
    constant = fopen("coefficients.txt", "r");
    fscanf(constant, "%d\n%d\n%d", &a, &b, &c);
    printf("Coefficients has been read from the coefficient file.\n");
    fclose(constant);

    for (y = 16; y >= -16; y--)
    {
        for (x = -56; x <= 56; x++)
        {

            if (x == 0 && y == 16)
                fprintf(file, "^");
            else if (x == a * (y * y) + b * y + c)
                fprintf(file, "#");
            else if (x == 56 && y == 0)
                fprintf(file, ">");
            else if (x == -56 && y == 0)
                fprintf(file, "<");
            else if (x == 0 && y == -16)
                fprintf(file, "v");
            else if (x == 0)
            {
                yellow();
                fprintf(file, "|");
                reset();
            }
            else if (y == 0 && x != 0)
            {
                yellow();
                fprintf(file, "-");
                reset();
            }
            else
                fprintf(file, " ");
        }
        fprintf(file, "\n");
    }
    printf("The graph of x = %d*(y*y) + %d*y + %d has been written to graph.txt file.\n\n", a, b, c);
    fclose(file);
}
int main(void)
{
    int selection;
    while (selection != 4) // this is an infinite loop until user tries to exit the program  user needs to press 4 to exit.
    {
        printf("Select an operation...\n1 -> Enter the coefficients.\n2 -> Draw the graph.\n3 -> Print the graph into a .txt file.\n4 -> Exit.\n\nChoice: ");
        scanf("%d", &selection);

        if (selection == 1) // due to selections parts of my program running.
            part1();
        else if (selection == 2)
            part2();
        else if (selection == 3)
            part3();
    }

    return 0;
}