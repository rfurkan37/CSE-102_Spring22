#include <stdio.h>

int romanToInt(char *s)
{
    int i = 0, res = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case 'I':
            res += 1;
            break;
        case 'V':
            if (s[i - 1] == 'I')
                res += 3;
            else
                res += 5;
            break;
        case 'X':
            if (i != 0 && s[i - 1] == 'I')
                res += 8;
            else
                res += 10;
            break;
        case 'L':
            if (i != 0 && s[i - 1] == 'X')
                res += 30;
            else
                res += 50;
            break;
        case 'C':
            if (i != 0 && s[i - 1] == 'X')
                res += 80;
            else
                res += 100;
            break;
        case 'D':
            if (i != 0 && s[i - 1] == 'C')
                res += 300;
            else
                res += 500;
            break;
        case 'M':
            if (i != 0 && s[i - 1] == 'C')
                res += 800;
            else
                res += 1000;
            break;
        default:
            break;
        }
        i++;
    }
    return (res);
}

int main()
{
    printf("\n%d", romanToInt("MCMXCIV"));
}