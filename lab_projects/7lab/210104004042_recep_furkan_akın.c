#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void concatAlphabeticReverseSort(char arr[][MAX_LEN], int n, char catStr[]);
/*
 * Function concatAlphabeticReverseSort
 * It sorts the string array from z to a.
 * n : len of array helps us not to lead to segmentation fault
 * MAX_LEN : we defined at the top as 100.
 * arr : the array we want to sort
 *
 * returns nothing just modifying arr.
 */
void generateTagParserCustomized(char temp[], char arr[]);
/*
 * Function generateTagParserCustomized
 * It delete first and the last letter and wtich it with another characters
 *
 * temp: temporary array.
 * arr: array will be tagged.
 *
 * returns nothing just modifies arr
 */
void concatAlphabeticReverseSort(char arr[][MAX_LEN], int n, char catStr[])
{
    char temp[100];
    printf("enter the strings:\n");
    for (int i = 0; i < n; i++) // scan strings
    {
        scanf("%s", arr[i]);
    }

    printf("\nGiven array is:\n");
    for (int l = 0; l < n; l++) // print given
    {
        printf("%d: %s\n", l, arr[l]);
    }
    for (int j = 0; j < n - 1; j++) // bubble sort
    {
        if (strcmp(arr[j], arr[j + 1]) < 0)
        {
            strcpy(temp, arr[j]);
            strcpy(arr[j], arr[j + 1]);
            strcpy(arr[j + 1], temp);
            j = -1;
        }
        printf("%d. array is:\n", j);
        for (int k = 0; k < n; k++) // print sorted
        {
            printf("%d: %s\n", k, arr[k]);
        }
    }
    printf("Sorted array is:\n");
    for (int k = 0; k < n; k++) // print sorted
    {
        printf("%d: %s\n", k, arr[k]);
    }

    for (int a = 0; a < n; a++) // concaterating
    {
        strcat(catStr, arr[a]);
    }

    printf("\n%s\n", catStr);
}

void generateTagParserCustomized(char temp[], char arr[])
{
    int len;
    len = strlen(arr); // taking length

    if (len < 5) //
    {
        temp[0] = '<';
        temp[1] = '<';
        temp[2] = '\0';
        strcat(temp, &arr[1]);
    }
    else if (len > 10)
    {
        temp[0] = '/';
        temp[1] = '+';
        temp[2] = '\0';
        strcat(temp, &arr[1]);
    }
    else
        strcpy(temp, arr);

    if (len < 5)
    {
        temp[len + 1] = '>';
        temp[len] = '>';
        temp[len + 2] = '\0';
    }
    else if (len >= 5 && len <= 10)
    {
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                temp[i] = '*';
            }
            else if (i == len - 1)
            {
                temp[i] = '*';
            }
        }
    }
    else if (len > 10)
    {
        temp[len] = '+';
        temp[len + 1] = '/';
        temp[len + 2] = '\0';
    }
    strcpy(arr, temp);
    printf("\n%s\n", arr);
}

int main()
{
    int stringNum, selection;
    char catStr[100] = "Result is:\n";
    char temp[MAX_LEN];
    char arr2[MAX_LEN];
    printf("Select part(1 or 2): ");
    scanf("%d", &selection); // selection taking
    if (selection == 1)
    {
        printf("enter the count of how many strings you will enter...\n"); // asking
        scanf("%d", &stringNum);
    }
    else if (selection == 2)
    {
        printf("enter a  string: "); // asking
        scanf("%s", arr2);
    }
    char arr[stringNum][MAX_LEN]; // defining

    switch (selection)
    {
    case 1:
        concatAlphabeticReverseSort(arr, stringNum, catStr); // executing function
        break;
    case 2:
        generateTagParserCustomized(temp, arr2); // executing function
    default:
        break;
    }
}
