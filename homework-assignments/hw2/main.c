#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"

int main()
{

    int select;
    int select2;

    printf("Please make a selection (1, 2, 3) :");
    scanf("%d", &select);

    if (select == 1)
    {
        char a1, b1;
        float pl, pw, sl, sw;

        printf("Please enter PL value:");
        scanf("%f", &pl);
        printf("Please enter PW value:");
        scanf("%f", &pw);
        printf("Please enter SL value:");
        scanf("%f", &sl);
        printf("Please enter SW value:");
        scanf("%f", &sw);

        a1 = dt1a(pl, pw, sl, sw);
        b1 = dt1b(pl, pw, sl, sw);

        if (a1 == b1)
            dt1p(a1);
        else
        {
            printf("a = ");
            dt1p(a1);
            printf("\nb = ");
            dt1p(b1);
        }
    }
    else if (select == 2)
    {

        double a2, b2;
        float x1, x2, x3;
        int x4, x5;

        printf("Please enter x1 value:");
        scanf("%f", &x1);
        printf("Please enter x2 value:");
        scanf("%f", &x2);
        printf("Please enter x3 value:");
        scanf("%f", &x3);
        printf("Please enter x4 (binary) value:");
        scanf("%d", &x4);
        printf("Please enter x5 (binary) value:");
        scanf("%d", &x5);

        a2 = dt2a(x1, x2, x3, x4, x5);
        b2 = dt2b(x1, x2, x3, x4, x5);

        if(fabs(a2 - b2) <= CLOSE_ENOUGH)
            printf("Result = %f", a2);
        else
            printf("a = %f\nb = %f", a2, b2);
    }
    else if (select == 3)
    {
        float intelligence;
        float strength;
        float stamina;
        float speed;
        int young_or_not;
        int gender;
        int res_a;
        int res_b;
        printf("Welcome to //Which Naruto character you are?\\\\ program.\n1) Please score your intelligence from 0 to 5 (as multiples of 0.5):");
        scanf("%f", &intelligence);
        printf("2) Please score your strength from 0 to 5 (as multiples of 0.5):");
        scanf("%f", &strength);
        printf("3) Please score your stamina from 0 to 5 (as multiples of 0.5):");
        scanf("%f", &stamina);
        printf("4) Please score your speed from 0 to 5 (as multiples of 0.5):");
        scanf("%f", &speed);
        printf("5) Please enter 1 for young and 0 for not:");
        scanf("%d", &young_or_not);
        printf("6) Please enter 1 for male and 0 for female:");
        scanf("%d", &gender);

        res_a = dt3a(intelligence, strength, stamina, speed,young_or_not, gender);
        res_b = dt3b(intelligence, strength, stamina, speed, young_or_not, gender);

        if (res_a == res_b)
        {
            printf("You are absolutely ==== ");
            dt3p(res_a);
            putchar('\n');
        }
        else
        {
            printf("You are a mysterious ninja. Here are the possibilities:\nA) ");
            dt3p(res_a);
            printf("\nB) ");
            dt3p(res_b);
            putchar('\n');
        }
    }
    return 0;
}
