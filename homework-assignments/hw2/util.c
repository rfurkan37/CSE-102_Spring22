#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w)
{
    int r = 0;
    if (t > 35 && w != 3)
        r = 1;
    else if (t <= 35 && s == 0)
        r = 1;
    return r;
}

void dt1p(char a)
{
    if (a == 'm')
        printf("Setosa");
    else if (a == 't')
        printf("Virginica");
    else if (a == 'g')
        printf("Versicolor");
    putchar('\n');
}

void dt3p(int a)
{
    switch (a)
    {
    case 2:
        printf("HINATA");
        break;
    case 3:
        printf("INO");
        break;
    case 5:
        printf("ROCK LEE");
        break;
    case 6:
        printf("SHİKAMARU");
        break;
    case 8:
        printf("TENTEN");
        break;
    case 9:
        printf("NARUTO");
        break;
    case 10:
        printf("SAKURA");
        break;
    case 11:
        printf("IRUKA");
        break;
    case 12:
        printf("KAKASHI");
        break;
    case 13:
        printf("ASUMA");
        break;
    case 14:
        printf("KURENAI");
        break;
    case 15:
        printf("GAI SENSEI");
        break;
    case 17:
        printf("SHIZUNE");
        break;
    case 19:
        printf("TEMARI");
        break;
    case 21:
        printf("NEJI");
        break;
    case 22:
        printf("SASUKE");
        break;
    case 23:
        printf("ITACHI");
        break;
    case 24:
        printf("JIRAIYA");
        break;

    default:
        break;
    }
}

char dt1a(float pl, float pw, float sl, float sw)
{
    if (pl < 2.45)
        return ('m');
    else if (pw < 1.75)
    {
        if (pl < 4.95)
        {
            if (pw < 1.65)
                return ('y');
            else
                return ('t');
        }
        else
            return ('t');
    }
    else
        return ('t');
}

char dt1b(float pl, float pw, float sl, float sw)
{
    if (pl < 2.55)
        return ('m');
    else if (pw < 1.69)
    {
        if (pl < 4.85)
            return ('y');
        else
            return ('t');
    }
    else
        return ('t');
}

double dt2a(float x1, float x2, float x3, int x4, int x5)
{
    if (x1 < 31.5)
    {
        if (x2 > -2.5)
            return (5.0);
        else if (x2 - 0.1 <= x1 && x1 <= x2 + 0.1)
            return (2.1);
        else
            return (-1.1);
    }
    else if (x3 >= -1 && x3 <= 2)
        return (1.4);
    else if (x4 && x5)
        return (-2.23);
    else
        return (11.0);
}

double dt2b(float x1, float x2, float x3, int x4, int x5)
{
    if (x1 < 22 && x1 > 12)
    {
        if (x3 > (5 / 3))
            return (-2.0);
        else if (x1 - 0.1 <= x3 && x1 + 0.1 >= x3)
            return (1.01);
        else
            return (-8);
    }
    else if (x4 && x5)
        return (-1);
    else if (-1 <= x2 && x2 <= 2)
        return (-1 / 7);
    else
        return (sqrt(2) / 3);
}

int dt3a(float i, float str, float stamina, float speed, int y, int g)
{
    if (g == 1)
    {
        if (y == 1)
        {
            if (i >= 4.5)
                return (6);
            else if (str < 3)
                return (21);
            else if (i < 3)
                return (5);
            else if (stamina >= 4.5)
                return (9);
            else
                return (22);
        }
        else if (i == 5)
        {
            if (speed == 5)
                return (23);
            else
                return (12);
        }
        else if (str == 5)
            return (15);
        else if (stamina > 4.5)
            return (24);
        else if (str > 3)
            return (13);
        else
            return (11);
    }
    else if (y == 1)
    {
        if ((str + i + stamina + speed) / 4 < 3)
        {
            if (str >= 2.5)
                return (3);
            else if (speed >= 3)
                return (8);
            else
                return (2);
        }
        else if (stamina > 3)
            return (10);
        else
            return (19);
    }
    else
    {
        if ((str + i + stamina + speed) / 4 > 3.25)
            return (17);
        else
            return (14);
    }
}

int dt3b(float i, float str, float stamina, float speed, int y, int g)
{
    if(y==1)
    {
        if(g == 1)
        {
            if(str >= 4)
            {
                if(i >= 3)
                    return(6);
                else
                    return (5);
            }
            else if(stamina >= 4)
                return(9);
            else if(str > 3)
                return (22);
            else
                return (21);
        }
        else if (str >= 3)
        {
            if(stamina >= 3)
                return (19);
            else
                return (10);
        }
        else if(speed >= 3)
            return(8);
        else if(i >= 3)
            return (2);
        else
        return (3);
    }
    else
    {
        if(g == 1)
        {
        if(stamina >= 4)
        {
            if (speed == 5)
            {
                if(str > 4)
                    return (15);
                else
                    return (23);
            }
            else
                return (24);
        }
        else if (i == 5)
            return(12);
        else if(str > 3)
            return (13);
        else
            return (11);
        }
        else
        {
            if ((str + i + stamina + speed) / 4 > 3)
                return (17);
            else
                return (14);
        }
    }
}