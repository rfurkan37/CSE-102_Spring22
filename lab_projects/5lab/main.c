#include <stdio.h>

void create_1d_array(int oned_Array[10])
{
    int i;
    int a;
    printf("1D Array\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a);
        oned_Array[i] = a;
    }
}

void create_2d_array(int twod_Array[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &twod_Array[i][j]);
        }
    }
}

void print_1d_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}

void print_2d_array(int array[3][3], int flag)
{
    int i, j;

    if (flag == 0)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d\t", array[i][j]);
            }
            printf("\n");
        }
    }
    else if (flag == 1)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d\t", array[j][i]);
            }
            printf("\n");
        }
    }
}

void convolutional_filter()
{
    int i;
    int oned_array[10];
    create_1d_array(oned_array);
    int result[8];

    for (i = 0; i < 8; i++) // there is no segmentation fault because ım doing it until 8 
        result[i] = oned_array[i] * -1 + oned_array[i + 1] + oned_array[i + 2] * -1; // filter is -1 1 -1 so it is like that

    printf("Convolutional Filter Result:\n"); // printing result
    print_1d_array(result, 8);
}

void transpose(void)
{
    int i, j;
    int matris1[3][3];
    int matris2[3][3];
    int temp1, temp2;

    create_2d_array(matris1); //  creating the matrixes
    create_2d_array(matris2);

    printf("First Matrix:\n");
    print_2d_array(matris1, 0);
    printf("Second Matrix:\n");
    print_2d_array(matris2, 0);

    printf("\nTranspose of the first matrix:\n"); // sending them to print function with flag to display transpose
    print_2d_array(matris1, 1);
    printf("\nTranspose of the second matrix:\n");
    print_2d_array(matris2, 1);
}

void trace(void)
{
    int i, j;

    int matris1[3][3];
    int matris2[3][3];

    int trace1 = 0;
    int trace2 = 0;

    create_2d_array(matris1);
    create_2d_array(matris2);

    for (i = 0; i < 3; i++)
    {
        trace1 += matris1[i][i];// 
        trace2 += matris2[i][i];
    }

    printf("Trace of the first matrix:\n");
    print_2d_array(matris1, 0);
    printf("\nTrace of matrix is: %d", trace1);
    printf("\nTrace of the second matrix:\n");
    print_2d_array(matris2, 0);
    printf("\nTrace of matrix is: %d", trace2);
}

void multiplication()
{
    int i, j, a;

    int f_matrix[3][3], s_matrix[3][3], r_matrix[3][3];
    
    printf("Enter first matrix:\n");
    create_2d_array(f_matrix);
    printf("Enter second matrix:\n");
    create_2d_array(s_matrix);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            r_matrix[i][j] = 0;
            for (a = 0; a < 3; a++)
            {
                r_matrix[i][j] += f_matrix[i][a] * s_matrix[a][j];
            }
        }
    }

    printf("First matrix:\n");
    print_2d_array(f_matrix, 0);
    printf("\nSecond matrix:\n");
    print_2d_array(s_matrix, 0);
    printf("\nMultiplication of matrixs:\n");
    print_2d_array(r_matrix, 0);
}
int main()
{
    int selection;
    printf("Choose the matrix operation,\n"
           "----------------------------\n"
           "1. Convolutional Filter for 1D array\n"
           "2. Multiplication\n"
           "3. Trace\n"
           "4. Transpose\n"
           "5. Exit\n"
           "----------------------------\n"
           "Enter your choice: ");
    scanf("%d", &selection);

    switch (selection)
    {
    case 1:
        convolutional_filter();
        break;
    case 2:
        multiplication();
        break;

    case 3:
        trace();
        break;
    case 4:
        transpose();
        break;
    case 5:
        break;
    default:
        break;
    }

    return 0;
}
