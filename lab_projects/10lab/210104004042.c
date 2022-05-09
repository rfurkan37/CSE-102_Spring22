#include <stdio.h>
struct number
{
    char inting[20];
    int integer;
};
struct number one, two;

int parse_to_int(char *number_of_str, int length_of_str)
{
    if (length_of_str != 0) // if not finished
    {
        if (length_of_str == 1) // if at the finish
            return number_of_str[0] - 48; // retrun int value
        else
            return (number_of_str[length_of_str - 1] - 48) + (parse_to_int(number_of_str, length_of_str - 1) * 10);
    }
    else
        return 1;//if at the finish
}
struct combination
{
    struct number one ;
    struct number two ;
    int result;
};
int recursive_factorial(int n)
{
    if (n == 0 || n == 1) // one or zero return 1 
        return 1;
    else
        return n * recursive_factorial(n - 1); // else number * number - 1 factorial
}

int is_number(char *number_as_str, int length_of_str)
{
    int i = 0, holyFlag = 0;
    while (i < length_of_str) // until the end 
    {
        if (number_as_str[i] < 48 && number_as_str[i] > '9') // search for non-number
            holyFlag = 1; //
        i++;
    }

    if (holyFlag == 1) // if there 0 
        return 0;
    else
        return 1; // if not 1
}

int ft_strlen(char *str) // until the end call the funtion again with one step away
{

    if (*str == '\0')
        return 0;
    else
    {
        str++;
        return 1 + ft_strlen(str);
    }
}



int main()
{
    int a, b, c , d, e;
    int combi;
    char one1[100], two1[100];
    while (a == 0 && b == 0)
    {
        printf("Please enter n:");
        scanf("%s", one.inting);
        printf("Please enter r:");
        scanf("%s", two.inting);
        a = is_number(one.inting, ft_strlen(one.inting));
        b = is_number(two.inting, ft_strlen(two.inting));
        if (a == 1 && b == 1)
        {
            one.integer = parse_to_int(one.inting, ft_strlen(one.inting));
            two.integer = parse_to_int(two.inting, ft_strlen(two.inting));
            if (one.integer < two.integer)
            {
                printf("n should be smaller than r.\n");
                a = 0;
                b = 0;
            }
        }
        else if (a == 0 || b == 0)
            printf("\nNOT VALID TRY AGAIN\n");
    }

    one.integer = parse_to_int(one.inting, ft_strlen(one.inting));
    two.integer = parse_to_int(two.inting, ft_strlen(two.inting));
   
    c =recursive_factorial(one.integer);
    d =recursive_factorial(two.integer);
    e = recursive_factorial(one.integer - two.integer);

    combi = (c /(d * e)); 
   // combination.number.one = one.integer;
    //combination.number.two= two.integer;
   // combination.result = combi;

    printf("n:%d\nr:%d\ncombination:%d\n", one.integer, two.integer, combi);
}