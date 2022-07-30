/* kerme eating recpes dick*/
#include <stdio.h>
#include <stdlib.h>

int countDigit(int num) // counting digit funciton
{
    int count = 0;

    while (num != 0)
    {
        num /= 10;
        count++;
    }

    return (count);
}

int countPower(int x, int power)// calculating power function
{
    if (power != 0)
        return (x * countPower(x, power - 1));
    else
        return 1;
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    int i = 0, c = 0;
    if (looplen < 2) // if smaller from 2 return 0
        return (0);
    while (i + looplen <= n)
    {
        if (arr[i] == arr[i + looplen])
        {
            c++; // counting 
            if (c == looplen)
            {
                *ls = n - 2 * c; // assigning first digit
                *le = n - c - 1; // assigning end digit
                return (1);
            }
        }
        else
            c = 0;
        i++;
    }
    return (0);
}

void hist_of_firstdigits(void (*generate)(int, int, int, int *), int xs, int seqlen, int *h, int digit)
{
    int *seq = (int *)malloc(sizeof(int) * seqlen);
    int currentlen = seqlen, numberOfDigit;
    generate(xs, currentlen, seqlen, seq);     
    if (digit <= 9)
    {
        h[digit - 1] = 0; 
        for (int a = 0; a < seqlen; a++)
        {
            numberOfDigit = countDigit(seq[a]);
            if (seq[a] / countPower(10, numberOfDigit - 1) == digit)
                h[digit - 1]++; 
        }
        free(seq);   
        hist_of_firstdigits(generate, xs, seqlen, h, digit + 1); // 
    }
    else
    {
        free(seq);
        return;
    }
}

void generate_sequence(int xs, int currentlen, int seqlen, int *seq)
{
    if (currentlen != 0)
    {
        seq[seqlen - currentlen] = xs;
        if (xs % 2 == 0)
            generate_sequence(xs / 2, currentlen - 1, seqlen, seq);
        else
            generate_sequence(3 * xs + 1, currentlen - 1, seqlen, seq);
    }
}

void check_loop_iterative(void (*generate)(int, int, int, int *), int xs, int seqlen, int *loop, int *looplen)
{
    int *seq, ls, le, i;

    seq = (int *)malloc(sizeof(int) * seqlen);
    (*generate)(xs, seqlen, seqlen, seq);

    while (i < seqlen) // printing sequence
    {
        printf("%d ", seq[i]);
        i++;
    }
    if (has_loop(seq, seqlen, (*looplen), &ls, &le) == 1)
    {
        for (i = 0; i < (*looplen); i++)
            loop[i] = seq[(ls) + i];

        printf("\nLoop detected with a length of %d.\n", *looplen);// whe loop found print

        loop = (int *)malloc(sizeof(int) * (*looplen)); // allocating for loop pointer.
        free(loop);

        printf("\nThe indexes of the loop's first occurance: %d (first digit), %d (last digit)\n", ls, le);
    }
    else
    {
        printf("Checking if there is a loop of length %d...\n", *looplen);
        (*looplen) -= 1;
        if (*looplen > 1)
            check_loop_iterative(generate_sequence, xs, seqlen, loop, looplen);
        else
            printf("No loop found.\n");
    }
    free(seq);
}

int main()
{
    int xs, seqlen, looplen = 0, *loop, h[9], digit = 1, c;
    void (*fp)(int, int, int, int *) = generate_sequence;

    printf("Please enter the first element of the sequence: ");
    scanf("%d", &xs);
    printf("Please enter the length of the sequence: ");
    scanf("%d", &seqlen); // taking seqlen
    looplen = seqlen / 2; // dividing to 2 
    loop = (int *)malloc(sizeof(int) * (looplen)); 

    check_loop_iterative(fp, xs, seqlen, loop, &looplen); // calling check function
    hist_of_firstdigits(generate_sequence, xs, seqlen, h, digit); // calling histof function
    printf("Loop: {");
    for (c = 0; c < looplen; c++) // printing loop in a loop
    {       
        if (c < looplen - 1)
            printf("%d, ", loop[c]);
        else
            printf("%d", loop[c]);
    }
    printf("}\n");
    for(c = 0; c<9; c++)// printing histogram in a loop
    {
        if(c == 0)
            printf("Histogram of sequence: {");
        if(c < 8)
            printf("%d, ",h[c]);
        else
        	printf("%d",h[c]);
        if( c == 8)
        	printf("}\n");
    }
    free(loop);// leaving loop alone
}