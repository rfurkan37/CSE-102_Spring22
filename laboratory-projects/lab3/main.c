#include <stdio.h>

void x_star_display(int height)
{
    int i, j;


    for(i = 1; i <= height ; i++)
    {
        printf("\n");
        for(j = 1; j <= height; j++)
        {
            if(i == j)
                printf("*");
            else if (i + j == height + 1)
                printf("*");
            else
                printf(" ");   
         }
    }

    printf("\n");
}

void diamond_star_display(int height)
{
    int i, j;

    for(i = 1; i <= height ; i++)
    {
        printf("\n");
        for(j = 1; j <= height; j++)
        {
            if((i == 1 || i == height) && (j == (height + 1)/2))
                printf("*");
            else
                printf(" ");
        }
    }
}
void multiplication_table_display(int size)
{
    int i, j;

    printf("    ");
    for ( i = 1; i <= size; i++)
    {
        printf("%d  ", i);
    }
    
    printf("\n-----------------");


    for(i = 1 ; i <= size ; i++)
    {
        printf("\n%d*  ", i);
        for(j = 1; j <= size; j++)
        {
            printf("%d", i*j);
            if(i*j >= 10)
                printf(" ");
            else
                printf("  ");
        }
    }
}
void is_palindrome_integer(int n)
{
    int r ;
    int toplam = 0;
    int kaydet;

    kaydet = n;

    while(n > 0)
    {
        r = n % 10;
        toplam = (toplam * 10) + r;
        n = n / 10;
    }

    if(toplam == kaydet)
        printf("%d is a palindrome number.\n", kaydet);
    else
        printf("%d is not a palindrome number.\n",kaydet);
}








int main(void)
{
    int selection = 0;
    int variable;
    int ret;
    int other;

    do
    {
        printf("Enter option 1 to x_star_display\nEnter option 2 to diamond_star_display\nEnter option 3 to multiplication_table_display\nEnter option 4 to palindrome check number\nEnter option -1 to exit!\n");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            printf("Enter an odd integer as the height:");
            scanf("%d", &variable);
            x_star_display(variable);
            break;
        case 2:
            printf("Enter an odd integer as the height:");
            scanf("%d", &variable);
            diamond_star_display(variable);
            break;
        case 3:
            printf("Enter an integer as the size:");
            scanf("%d", &variable);
            multiplication_table_display(variable);
            break;
        case 4:
            printf("Enter an integer as the palindrome:");
            scanf("%d", &other);
            is_palindrome_integer(other);
            break;

        default:
            break;
        }
    } while (selection != -1);

    return 0;
}