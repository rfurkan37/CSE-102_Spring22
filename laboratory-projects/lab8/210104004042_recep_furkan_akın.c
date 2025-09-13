#include <stdio.h>
#include <string.h>

void merge(int arr[], int p, int q, int r);
/*
 * This function merges little subarrays in order.
 * p means first index q means middle index anr r means right index
 */

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1; // Creating L  A[p...q] and m B[q + 1 .. r]
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) // until we reach either en
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    int orta;

    if (r > l) // r - l > 0 means if the array doesnt have one element.
    {
        orta = (r + l) / 2;
        mergeSort(arr, l, orta);     // dividing to left part.
        mergeSort(arr, orta + 1, r); // dividing to right.
        merge(arr, l, orta, r);      // sorting little parts.
    }
}
void reverse(char str[], char reversed[], int i)
{
    int len;
    len = strlen(str);

    reversed[i] = str[len - i - 1]; // resing from end copying it to reversed array
    if (str[i + 1] != '\0')         // i + 1 not finish doing it again with i + 1
    {
        i++;
        reverse(str, reversed, i);
    }
}

int main()
{
    int select, arr[] = {
                    30,
                    31,
                    45,
                    78,
                    89,
                    50,
                    49,
                    1,
                    4,
                    5,
                };
    char str[100] = "alala";
    char tersi[100];
    printf("select 1 or 2:");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        reverse(str, tersi, 0); // copying reverse to tersi array
        printf("String  : %s \nReverse : %s\n", str, tersi);
        if (strcmp(str, tersi) == 0)         // if they are equal
            printf("This is palindrome.\n"); // palindrome
        else
            printf("This is not a palindrome.\n"); // not
        break;
    case 2:
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]); // printing sorted array
        }
        mergeSort(arr, 0, 9); // giving with indexes
        putchar('\n');
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]); // printing sorted array
        }
        printf("\n");
    default:
        break;
    }

    return 0;
}