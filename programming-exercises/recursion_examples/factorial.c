#include <stdio.h>

long long fact(int n)
{
    long long ret;

    if(n == 0 || n == 1)
        ret = 1;
    else
    {
        ret = fact(n - 1) * n;
    }
    
    return ret;
}

int main()
{
      printf("%lld, ", fact(60));
    return 0;
}