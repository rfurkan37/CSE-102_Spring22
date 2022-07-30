#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_BLOCK_SIZE 10

typedef struct
{
    int *array;
    int currentSize;
    int maxSize;
} stack;

int doluMu(stack *steak)
{
    if (steak->currentSize == steak->maxSize) // doluysa 1 gönderiyoruz
        return 1;
    else
        return 0;
}

int bosMu(stack *steak)
{
    if (steak->currentSize == 0) // sizeı sıfırssa boştur
        return 1;
    else
        return 0;
}
int push(stack *s, int d)
{
    if (doluMu(s))
        return 0;

    s->array[(s->currentSize)] = d;// son entrysine aldığıız değeri koyuyoruz
    s->currentSize++; //  sizeı artırıyoruz

    return 1;
} /* the stack array will grow STACK_BLOCK_SIZE entries at
a time */

int pop(stack *s)
{
    if (bosMu(s)) // if its empty returning -1 means empty
        return -1;
    else
    {
        s->currentSize -= 1; // decreenting size
        return (s->array[s->currentSize]); // and taking last entry
    }
} /* the stack array will shrink STACK_BLOCK_SIZE entries at a
 time */

stack *init_return(int size)
{
    stack *stack1;

    stack1 = (stack *)malloc(sizeof(stack)); // initializing stack
    stack1->maxSize = size;
    stack1->array = (int *)malloc(sizeof(int) * size); // initializing array
    stack1->currentSize = 0;

    return stack1;
} /* initializes an empty stack */

int init(stack *s)
{
    if(s != NULL)
        return 1;
    else
        return 0;
} /* returns 1 if initialization is successful*/

void statusInfo(char den, char a, int diskNum)
{
    printf("Move disk %d from %c to %c\n", diskNum, den, a); // hareket ettirmemiz gereken diskleri ve nereye gideceğini yazıyoruz
}

void whereIsTheHareket(stack *kaldir, stack *indir, char kaldirdi, char indirdi)
{
    int popsource = pop(kaldir);
    int popdest = pop(indir);

    if (popsource == -1) // kaynak boşsa
    {
        push(kaldir, popdest); // kaynağa karşı taraftan çıkardığımızı koyuyoruz 
        statusInfo(indirdi, kaldirdi, popdest); // bunu yazıyoruz
    }
    else if (popdest == -1)
    {
        push(indir, popsource); // koycağımız yer boşsa direkt koyuyoruz
        statusInfo(kaldirdi, indirdi, popsource);
    }
    else if (popsource > popdest) // çıkardığımız disk karşı tarafınkinden büyükse çıkardıpımıı geri koyup karşıdan üstüne koyuyoruz
    {
        push(kaldir, popsource);
        push(kaldir, popdest);
        statusInfo(indirdi, kaldirdi, popdest);
    }
    else // çıkardığımız küçükse çıkardığımızı diğerinin üstüne koyuyoruz
    {
        push(indir, popdest);
        push(indir, popsource);
        statusInfo(kaldirdi, indirdi, popdest);
    }
}
void playGame(int diskNum, stack *start, stack *mid, stack *finish)
{
    int maxMove, fill = diskNum;
    char temp;
    char b, o, s;

    b = 'B'; // baş 
    o = 'O'; // orta
    s = 'S'; // son

    if (diskNum % 2 == 0)
    {
        temp = s;
        s = o;
        o = temp;
    }

    maxMove = pow(2, diskNum) - 1; // maksimum hareket kabiliyetimiz

    while (fill >= 1) // size dan geriye gelerek bas arrayimizi dolduruyoruz
    {
        push(start, fill);
        fill--;
    }

    for (int i = 1; i <= maxMove; i++)
    {
        switch (i % 3)
        {
        case 0:
            whereIsTheHareket(mid, finish, o, s); // sonra ortadan başa
            break;
        case 1:
            whereIsTheHareket(start, finish, b, s); // önce bu oluyo baştan sona hareket deniyoruz
            break;
        case 2:
            whereIsTheHareket(start, mid, b, o); // sonra baştan  ortaya
            break;
        default:
            break;
        }
    }
}

int main(void)
{
    int size;
    printf("Enter Tower size:");
    scanf("%d", &size); // sizeı alıyoruz

    stack *start, *finish, *mid;


    start = init_return(size);
    mid = init_return(size);
    finish = init_return(size);

    if(!init(start) || !init(mid) || !init(finish))
    {
        printf("Allocation is not successfull.");
        return 0;
    }
    playGame(size, start, mid, finish); // oyunu başlatıyoruz

    return 0;
}
