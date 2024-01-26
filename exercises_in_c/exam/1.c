#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
    int recep = 31;
    return(a + b);
}

void basic(int topla(int, int))
{
    int n = 4;
printf("%3d", --n);
printf("%3d", n);
printf("%3d", n--);
printf("%3d\n", n);
int y = n * 4 + ++n;

int x = n++ * --n;

printf("%3d\n",y);
printf("\n%3d\n",n);
printf("%3d\n", x);
}

int main(void)
{
    basic(add);

}
