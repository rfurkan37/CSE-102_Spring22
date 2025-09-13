#include <stdio.h>             // defining the libraries.    
#include <stdlib.h>            // defining the libraries. 
#include <math.h>              // defining the libraries. 
#define PI 3.14                // defining PI as 3.14

enum shapes                    // defining enums
{
    triangle = 1,
    quadrilateral,
    circle,
    pyramid,
    cylinder
};
enum calculator                 // defining enums
{
    area = 1,
    perimeter,
    volume
};

void clean_stdin(void)           // here is my function that cleans stdin file...
{
    int r;
    do
    {
        r = getchar();   //  its getting char until stdin file ends.
    } while (r != '\n' && r != EOF);
}
int calc_triangle(int calc)
{
    float res;
    float a, b, c;
    int check = 0, scanret;
    float s;
    printf("Please enter three sides of Triangle :\n");
    while (check != 4)   // this is a levelized control loop
    {
        check = 0;
        scanret = scanf("%f", &a); // if scanf returns 0 that means it didnt take the wanted variable so ı used it.
        if (scanret == 0 || a <= 0)
        {
            clean_stdin(); // cleaning stdin for char situations
            printf("ERROR ! Please enter a valid entry.\n\n");
        }
        else
            check++; // if it is suitable continues

        if (check == 1)
        {
            scanret = scanf("%f", &b);
            if (scanret == 0 || b <= 0)
            {
                clean_stdin();
                printf("ERROR ! Please enter a valid entry.\n\n");
            }
            else
                check++;

            if (check == 2)
            {
                scanret = scanf("%f", &c);
                if (scanf == 0 || c <= 0)
                {
                    clean_stdin();
                    printf("ERROR ! Please enter a valid entry.\n\n");
                }
                else
                    check++;

                if (check == 3) // and at the end  program is checking triangle rule.
                {
                    s = (a + b + c) / 2;
                    if (s >= a && s >= b && s >= c)
                        check++;
                    else
                        printf("ERROR ! Please enter valid entries.\n\n");
                }
            }
        }
    }

    switch (calc) 
    {
    case area: // for each situation calculating result and printing it. 
        res = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("Area of TRIANGLE : %.2f", res);
        break;
    case perimeter:
        res = a + b + c;
        printf("Perimeter of TRIANGLE : %.2f", res);
        break;
    default:
        break;
    }
    return (1); // it is successfull so returning 1.
}
int calc_quadrilateral(int calc) // same system as triangle
{
    float a, b, c, d;
    int check = 0, scanret;
    float s, res;

    printf("Please enter four sides of Quadrilateral\n");

    while (check != 4) 
    {
        check = 0;
        scanret = scanf("%f", &a);
        if (scanret == 0 || a <= 0)
        {
            clean_stdin();
            printf("ERROR ! Please enter a valid entry.\n\n");
        }
        else
            check++;

        if (check == 1)
        {
            scanret = scanf("%f", &b);
            if (scanret == 0 || b <= 0)
            {
                clean_stdin();
                printf("ERROR ! Please enter a valid entry.\n\n");
            }
            else
                check++;

            if (check == 2)
            {
                scanret = scanf("%f", &c);
                if (scanret == 0 || c <= 0)
                {
                    clean_stdin();
                    printf("ERROR ! Please enter a valid entry.\n\n");
                }
                else
                    check++;

                if (check == 3)
                {
                    scanret = scanf("%f", &d);
                    if (scanret == 0 || c <= 0)
                    {
                        clean_stdin();
                        printf("ERROR ! Please enter a valid entry.\n\n");
                    }
                    else
                        check++;
                }
            }
        }
    }

    s = (a + b + c + d) / 2;

    switch (calc)
    {
    case area:
        res = sqrt((s - a) * (s - b) * (s - c) * (s - d));
        printf("\nArea of QUADLITERAL : %.2f", res);
        break;
    case perimeter:
        res = 2 * s;
        printf("\nPerimeter of QUADLITERAL : %.2f", res);
        break;
    default:
        break;
    }

    return (1);
}
int calc_circle(int calc) //same system as triangle
{
    int check = 0, scanret;
    float res, r;

    printf("Please enter the radius of Circle :\n");

    while (check != 1)
    {
        check = 0;
        scanret = scanf("%f", &r);
        if (scanret == 0 || r <= 0)
        {
            clean_stdin();
            printf("ERROR ! Please enter a valid entry.\n\n");
        }
        else
            check++;
    }

    switch (calc)
    {
    case area:
        res = PI * r * r;
        printf("\nArea of CIRCLE : %.2f", res);
        break;
    case perimeter:
        res = 2 * PI * r;
        printf("Perimeter of CIRCLE : %.2f", res);

    default:
        break;
    }

    return (1);
}
int calc_pyramid(int calc) // same system as triangle
{
    int check, scanret;
    float B, L, res, a, l;

    if (calc == area)
        printf("Please enter the base side and slant height of the Pyramid :\n");
    else if (calc == volume)
        printf("Please enter the base side and height of the Pyramid :\n");
    else if (calc == perimeter)
        printf("Please enter the base side and height of the Pyramid :\n");

    while (check != 2)
    {
        check = 0;
        scanret = scanf("%f", &a);
        if (scanret == 0 || a <= 0)
        {
            clean_stdin();
            printf("ERROR ! Please enter a valid entry.\n\n");
        }
        else
            check++;

        if (check == 1)
        {
            scanret = scanf("%f", &l);
            if (scanret == 0 || l <= 0)
            {
                clean_stdin();
                printf("ERROR ! Please enter a valid entry.\n\n");
            }
            else
                check++;
        }
    }

    switch (calc)
    {
    case volume:
        res = (a * a * l) / 3;
        printf("Volume of the PYRAMID : %.2f\n\n", res);
        break;
    case area:
        B = a * a;
        L = 2 * a * l;
        printf("Base Surface Area of the PYRAMID : %.2f\n\n", B);
        printf("Lateral Surface Area of the PYRAMID : %.2f\n\n", L);
        printf("Surface Area of the PYRAMID : %.2f\n\n", B + L);
        break;
    case perimeter:
        res = a * a;
        printf("Perimeter of the Base of PYRAMID : %.2f", res);
    default:
        break;
    }
    return (1);
}
int calc_cylinder(int calc) // same system as triangle
{
    int r, check = 0, h, scanret;
    float B, L, res;

    printf("Please enter the radius and height of the Cylinder :\n");

    while (check != 2)
    {
        check = 0;
        scanret = scanf("%d", &r);
        if (scanret == 0 || r <= 0)
        {
            clean_stdin();
            printf("ERROR ! Please enter a valid entry.\n\n");
        }
        else
            check++;

        if (check == 1)
        {
            scanret = scanf("%d", &h);
            if (scanret == 0 || h <= 0)
            {
                clean_stdin();
                printf("ERROR ! Please enter a valid entry.\n\n");
            }

            else
                check++;
        }
    }

    switch (calc)
    {
    case area:
        B = PI * r * r;
        L = 2 * PI * r * h;
        printf("Base Surface Area of the CYLINDER : %.2f\n\n", B);
        printf("Lateral Surface Area of the CYLINDER : %.2f\n\n", L);
        printf("Surface Area of the CYLINDER : %.2f\n\n", 2*B + L);
        break;
    case volume:
        res = PI * r * r * h;
        printf("Volume of the CYLINDER : %.2f\n\n", res);
        break;
    case perimeter:
        res = PI * r * 2;
        printf("Perimeter of the CYLINDER's Base Surface = %.2f", res);
        break;
    default:
        break;
    }

    return 1;
}

int select_shape(void)
{
    int a = 0, scanret = 0;

    while (scanret != 1)
    {
        printf("\nSelect a shape to calculate:\n----------------------------");
        printf("\n1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cyclinder\n0. Exit\n");
        printf("----------------------------\nInput : ");
        scanret = scanf("%d", &a); // using the same checking here.

        if (scanret == 0)
        {
            clean_stdin();
            printf("\nERROR ! Please enter a valid value.\n");
        }
    }
    return (a);
}
int select_calc(void)
{
    int a = 0, scanret = 0;

    while (scanret != 1)
    {
        printf("\nSelect calculator:\n----------------------------");
        printf("\n1. Area\n2. Perimeter\n3. Volume\n0. Exit\n");
        printf("----------------------------\nInput : ");
        scanret = scanf("%d", &a); // and the same here.

        if (scanret == 0)
        {
            clean_stdin();
            printf("\nERROR ! Please enter a valid value.\n");
        }
    }

    return (a);
}

int calculate(int select_shape(void), int select_calc(void))
{
    do // they  all in a while loop
    {
        int shape, calc;

        shape = select_shape();

        if (shape == 0) //  exit situation
            return 0;

        if (shape <= 5 && shape > 0)
            calc = select_calc();

        if (calc == 0)
            return 0;

        switch (shape)
        {
        case triangle:
            while (calc != area && calc != perimeter)
            {
                if (calc == 3)
                    printf("\nERROR!! You can't calculate triangle's volume. Please try again.\n");
                else if (calc == 0)
                    return 0;
                else
                    printf("\nERROR!! Not a valid value.");

                calc = select_calc();
            }
            calc_triangle(calc);
            break;
        case quadrilateral:
            while (calc != area && calc != perimeter)
            {
                if (calc == 3)
                    printf("\nERROR!! You can't calculate quadrilateral's volume. Please try again.\n");
                else if (calc == 0)
                    return 0;
                else
                    printf("\nERROR!! Not a valid value.");
                calc = select_calc();
            }
            calc_quadrilateral(calc);
            break;
        case circle:
            while (calc != area && calc != perimeter)
            {
                if (calc == 3)
                    printf("\nERROR!! You can't calculate circle's volume. Please try again.\n");
                else if (calc == 0)
                    return 0;
                else
                    printf("\nERROR!! Not a valid value.");

                calc = select_calc();
            }
            calc_circle(calc);
            break;
        case pyramid:
            while (calc != area && calc != perimeter && calc != volume)
            {
                if (calc == 0)
                    return 0;
                else
                    printf("\nERROR!! Not a valid value.");

                calc = select_calc();
            }
            calc_pyramid(calc);
            break;
        case cylinder:
            while (calc != area && calc != perimeter && calc != volume)
            {
                if (calc == 0)
                    return 0;
                else
                    printf("\nERROR!! Not a valid value.");

                calc = select_calc();
            }
            calc_cylinder(calc);
            break;
        default:
            printf("\nERROR ! Not a valid value.");
            break;
        }
    } while (1);

    return (1);
}

int main()
{
    printf("Welcome to the geometric calculator!\n\n"); 
    calculate(select_shape, select_calc); // starting calculation function.
    return 0;
}