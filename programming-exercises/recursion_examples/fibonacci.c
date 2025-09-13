#include <stdio.h>


int fibo(int n)
{
    int ret;
    if(n == 0)
        ret = 0;
    else if(n == 1)
        ret = 1;
    else
        ret = fibo(n - 1) + fibo(n - 2);
    
    return ret;
}

int main()
{
    for (int i = 0 ; i< 62; i++)
    {
        printf("%d, ", fibo(i));
    }

    printf("\noha");

    return 0;
}