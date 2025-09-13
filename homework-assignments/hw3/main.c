#include <stdio.h>
#include <math.h>

void sort_file(void)
{
    FILE *file;
    FILE *temp;
    temp = fopen("temp.txt", "a+");
    file = fopen("results.txt", "r+");
    int o_count = 0;
    int scan;
    int BOS = 2147483647;
    int prevmin3 = -2147483648;
    int count = 0;
    int same = 0;
    int sayma3 = 0;

    int min1 = BOS, min2 = BOS, min3 = BOS;
    while (!feof(file))
    {
        fscanf(file, "%d ", &scan); // here ım counting the number of integers.
        count++;
    }
    fseek(file, 0, SEEK_SET); // ı am setting cursor to head.
    while (o_count < count) // counting till max limit
    {
        fseek(file, 0, SEEK_SET); // ı am setting cursor to head again.
        same = 0;
        while (!feof(file))
        {
            fscanf(file, "%d ", &scan);
            if (scan > prevmin3) // here we have three conditions
            {
                if (min1 == BOS && min2 == BOS && min3 == BOS) // if we are at start we fill min3 first
                    min3 = scan;
                else if (min1 == BOS && min2 == BOS && min3 != BOS) // min3 is full we compare them
                {
                    if (scan > min3)
                    {
                        min2 = min3;
                        min3 = scan;
                    }
                    else
                        min2 = scan;
                }
                else if (min1 == BOS && min2 != BOS && min3 != BOS) // if min2 is full too we compare and shift if we need.
                {
                    if (scan > min3)
                    {
                        min1 = min2;
                        min2 = min3;
                        min3 = scan;
                    }
                    else if (scan > min2)
                    {
                        min1 = min2;
                        min2 = scan;
                    }
                    else
                        min1 = scan;
                }
                else if (min1 != BOS && min2 != BOS && min3 != BOS) // if all of them is full we check everyone and fins a place for our number.
                {
                    if (scan < min3)
                    {
                        if (scan > min2)
                            min3 = scan;
                        else if (scan < min1)
                        {
                            min3 = min2;
                            min2 = min1;
                            min1 = scan;
                        }
                        else
                        {
                            min3 = min2;
                            min2 = scan;
                        }
                    }
                }
            }
            else if (scan == prevmin3 && same == sayma3) // sayma3 means if in 3 minimum before we have a number ignore them below condition makes ignıring this condition finishes ignoring.
            {
                if (min1 == BOS && min2 == BOS && min3 == BOS)
                    min3 = scan;
                else if (min1 == BOS && min2 == BOS && min3 != BOS)
                {
                    if (scan > min3)
                    {
                        min2 = min3;
                        min3 = scan;
                    }
                    else
                        min2 = scan;
                }
                else if (min1 == BOS && min2 != BOS && min3 != BOS)
                {
                    if (scan > min3)
                    {
                        min1 = min2;
                        min2 = min3;
                        min3 = scan;
                    }
                    else if (scan > min2)
                    {
                        min1 = min2;
                        min2 = scan;
                    }
                    else
                        min1 = scan;
                }
                else if (min1 != BOS && min2 != BOS && min3 != BOS)
                {
                    if (scan < min3)
                    {
                        if (scan > min2)
                            min3 = scan;
                        else if (scan < min1)
                        {
                            min3 = min2;
                            min2 = min1;
                            min1 = scan;
                        }
                        else
                        {
                            min3 = min2;
                            min2 = scan;
                        }
                    }
                }
            }
            else if (scan == prevmin3 && same < sayma3) // same means ignore counter
                same++;
        }
        prevmin3 = min3; // we assign prevmin3 meaans previous
        if (min1 == BOS && min2 != BOS && min3 != BOS) // here we are sending them to temp file
        {
            fprintf(temp, "%d %d ", min2, min3);
            o_count += 2;
        }
        else if (min1 != BOS && min2 != BOS && min3 != BOS)
        {
            fprintf(temp, "%d %d %d ", min1, min2, min3);
            o_count += 3;
        }
        else if (min1 == BOS && min2 == BOS && min3 != BOS) // o_count is number counter
        {
            fprintf(temp, "%d ", min3);
            o_count += 1;
        }

        if (min3 == min2 && min3 == min1) // tihs means if it is like  a a a ignore 3
            sayma3 = 3;
        else if (min3 == min2) // if it is b a a ignore 2
            sayma3 = 2;
        else if (min3 != min2) // if it is b b a ignore 1
            sayma3 = 1;

        min1 = BOS; // we set them free now
        min2 = BOS;
        min3 = BOS;
    }
    rewind(file); // setting cursor to head
    rewind(temp);
    o_count = 0; // and counter to 0

    printf("Sorting is complete.\nResult: \n");

    while (!feof(temp) && o_count <= count)
    {
        fscanf(temp, "%d ", &scan);// taking from temp 
        fprintf(file, "%d ", scan);// writing to results.txt
        printf("%d ", scan); // also printing to screen.
        o_count++;
    }

    fclose(temp);/// closing files
    fclose(file);
}
void print_file(void)
{
    FILE *file;

    int a;
    file = fopen("results.txt", "r");

    printf("Result:\n");
    while (!feof(file))
    {
        fscanf(file, "%d ", &a);
        printf("%d ", a);
    }
    fclose(file);
}
void write_file(int a)
{
    FILE *file;

    file = fopen("results.txt", "a");
    fprintf(file, "%d ", a);
    fclose(file);
}
int isprime(int a)
{
    int i, j = 2, flag = 0;

    for (i = 2; i < a; i++)
    {
        for (j = 2; j <= sqrt(i); j++)
        {
            flag = 0;
            if (i % j == 0)
            {
                printf("%d is not a prime number, it is divisible by %d.\n", i, j);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d is a prime number.\n", i);
    }
}
int sum(int n1, int n2, int flag)
{
    int i, sum = 0;

    for (i = n1 + 1; i < n2; i++)
    {
        if (i % 2 == flag)
        {
            sum += i;
            printf("%d ", i);

            if (i + 2 < n2)
                printf("+ ");
        }
    }
    printf("= %d\n", sum);

    return (sum);
}
int multi(int n1, int n2, int flag)
{
    int i, multi = 1;

    for (i = n1 + 1; i < n2; i++)
    {
        if (i % 2 == flag)
        {
            multi *= i;
            printf("%d ", i);

            if (i + 2 < n2)
                printf("* ");
        }
    }
    printf("= %d\n", multi);

    return (multi);
}
void part2()
{
    int n;
    int ret;

    printf("Please enter an integer: ");
    scanf("%d", &n);

    isprime(n);
}
void part1()
{
    int temp, res;
    int sum_or_mul;
    int odd_or_even;
    int n1, n2;

    printf("Select operation\nPlease enter '0' for sum, '1' for multiplication.\n");
    scanf("%d", &sum_or_mul);
    if (sum_or_mul != 0 && sum_or_mul != 1)
    {
        printf("Wrong parameter!!!");
    }
    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
    scanf("%d", &odd_or_even);
    if (odd_or_even != 0 && odd_or_even != 1)
    {
        printf("Wrong parameter!!!");
    }
    printf("Number 1: ");
    scanf("%d", &n1);
    printf("Number 2: ");
    scanf("%d", &n2);

    if (n1 > n2)
    {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    printf("Result\n");

    switch (sum_or_mul)
    {
    case 0:
        res = sum(n1, n2, odd_or_even);
        break;
    case 1:
        res = multi(n1, n2, odd_or_even);
        break;
    }

    write_file(res);

    printf("The result is written to the results.txt file.");
}
int main(void)
{
    int selection;
    printf("Select operation\n 1. Calculate sum/multiplication between two numbers\n 2. Calculate prime numbers\n 3. Show number sequence in file\n 4. Sort number sequence in file");
    printf("\n-------------------------\n");
    scanf("%d", &selection);

    switch (selection)
    {
    case 1:
        part1();
        break;
    case 2:
        part2();
        break;
    case 3:
        print_file();
        break;
    case 4:
        sort_file();
        break;
    default:
        break;
    }

    return 0;
}