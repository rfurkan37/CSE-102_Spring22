#include <stdio.h>


int main()
{
    float yks_puan, mat, fen, ortalama;
    float res = 0;


    printf("YKS PUAN : ");
    scanf("%f", &yks_puan);
    printf("ORTALAMA : ");
    scanf("%f", &ortalama);
    printf("MAT ORTALAMA : ");
    scanf("%f", &mat);
    printf("FEN ORTALAMA : ");
    scanf("%f", &fen);


    res += (yks_puan / 100) * 49;
    res += ((ortalama * 25) / 100) * 31;
    res += (((mat * 7 + fen * 6) / 13) * 25) / 5; 


    printf("\n\n\n%f", res);
}