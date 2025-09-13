#include <stdio.h>

void findMaximumDistance(int distanceOfCities[5], int start, int end, int result[2])
{
    int min = distanceOfCities[start]; // assigninn minimum to first
    int temp;                          // for swapping
    int i = start;                     // assigning i to start
    if (start != end)
    {
        while (i <= end) // searching for minimum
        {
            if (distanceOfCities[i] < min)
                min = distanceOfCities[i];
            i++;
        }
        i = 0;
        while (i <= end) // and searching for ists place
        {
            if (distanceOfCities[i] == min)
                break;
            i++;
        }
        temp = distanceOfCities[start]; // swapping to first place
        distanceOfCities[start] = distanceOfCities[i];
        distanceOfCities[i] = temp;
        findMaximumDistance(distanceOfCities, start + 1, end, result); // and searching start + 1 because we modfiyed first place
    }
    result[0] = distanceOfCities[start]; // at the end assignig result array
    result[1] = distanceOfCities[end];
}

int recursiveMinStrDiff(char str1[50], char str2[50], int m, int n)
{

    printf("%c, %c\n", str1[m - 1], str2[n - 1]);
    if (str1[0] == '\0') // if empty
        return n;
    else if (str2[0] == '\0') // if empty
        return m;
    else if(m - 1 == 0 || n - 1 == 0)  // finish
        {
            if (m > n)
                return 0;
            else 
                return 0;
        }
    else if (str1[m - 1] == str2[n - 1])
        return recursiveMinStrDiff(str1, str2, m - 1, n - 1);
    else if (str1[m - 1] != str2[n - 1] && m == n)
    {
        return (1 + recursiveMinStrDiff(str1, str2, m - 1, n - 1));
    }
    else if (str1[m - 1] != str2[n - 1] && m != n)
    {
        if (m > n)
            return (1 + recursiveMinStrDiff(str1, str2, m  , n - 1));
        else
            return  (1 + recursiveMinStrDiff(str1, str2, m - 1, n ));
    }
}

int main()
{
    int distanceOfCities[] = {120, 200, 500, 300, 295};
    int result[2];
    char str1[50] = "intention";
    char str2[50] = "execution";

    findMaximumDistance(distanceOfCities, 0, 4, result);
    printf("\n%d, %d\n", result[0], result[1]);

    printf("\n%d\n", recursiveMinStrDiff(str1, str2,9, 9));
}