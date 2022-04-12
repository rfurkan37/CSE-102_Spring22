#include <stdio.h>
#include <math.h>

void    write_file(int value)
{
    FILE *file;

    file = fopen("result.txt", "a");
    fprintf(file,"%d ", value);
    fclose(file);
    printf("\nThe result is written to the results.txt file.");
}

int calculate_mean(void)
{
    int mean = 0;
    int index = 0;
    int num;
    FILE *file;

    file = fopen("result.txt", "r");

    while(! feof(file))
    {
        fscanf(file, "%d ", &num);
        mean += num;
        index++;
    }
    
    fclose(file);

    mean = mean / index;
    return mean;
}


int gcd_calculator(int n1, int n2)
{
    int i = 1;
    int result = 0;

    while(i != n1 && i != n2)
    {
        if(n1 % i == 0 && n2 % i == 0)
            result = i;
        i++;
    }
    return result;
}

int lcm_calculator(int n1, int n2)
{
    int result;
 
    result = (n1 * n2) / gcd_calculator(n1, n2);

    return result;
}

double standard_deviation_calculator(void)
{  
    FILE *file;
    int num;
    double result;
    int sum = 0;
    int mean;

    mean = calculate_mean();

    int index = 0;

    file = fopen("result.txt", "r");

    while (!feof(file))
    {
        fscanf(file, "%d ", &num);
        printf("%d. Number = %d\n", index + 1, num);
        sum += (num - mean)*(num - mean);
        index++;
    }
    printf("Mean: %d\n", mean);
    printf("Total Count: %d", index);
    result = (sum / index);
    result = sqrt(result);

    return result;

}

int main(void)
{
    int selection;
    int n1, n2;
    printf("Enter the calculator type\n 1. GCD Calculator\n 2. LCM Calculator via GCD\n 3. Standart Deviation Calculator\n -------------------------\n");
    scanf("%d", &selection);

    if (selection == 1)
    {
        printf("Please enter two different number:\nNumber 1: ");
        scanf("%d", &n1);
        printf("Number 2: ");
        scanf("%d", &n2);
        printf("GCD of these two numbers: %d", gcd_calculator(n1, n2));
        write_file(gcd_calculator(n1, n2));
    }
    else if (selection == 2)
    {
        printf("Please enter two different number:\nNumber 1: ");
        scanf("%d", &n1);
        printf("Number 2: ");
        scanf("%d", &n2);
        printf("LCM of these two numbers: %d", lcm_calculator(n1, n2));
        write_file(lcm_calculator(n1, n2));
    }
    else if (selection == 3)
    {
        double result = standard_deviation_calculator();
        printf("\nStandard Deviation : %.2f\n", result);
        
    }

    return 0;
}