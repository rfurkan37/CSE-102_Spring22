#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMOFITEMS 2
#define FILENAME "Lab11_data.bin"

typedef struct
{
    int ID;
    char name[30];
    int price;

} item_t;

typedef struct
{
    int number;
    char mail[50];

} contactInfo_t;

typedef struct
{
    item_t item;
    contactInfo_t contact;

} itemWithCont_t;

typedef struct 
{
    int ID;
    char name[30];
    int price;
} temp;

temp temp1;

void printItem(item_t item)
{
    printf("ID -> %d\n", item.ID);
    printf("Name -> %s\n", item.name);
    printf("Price -> %d\n", item.price);
}



void flushInputBuffer()
{
    char tmp;
    do
    {
        scanf("%c", &tmp);
    } while (tmp != '\n');
}
int writeItems(char filename[], item_t *items, int size)
{
    FILE *fp;

    fp = fopen(filename, "ab");

    for (int i = 0; i < 2; i++)
    {
        fwrite(&items[size - 2 + i],sizeof(item_t),1,fp);
    }

    fclose(fp);
}

item_t *getItems(item_t *items, int *size)
{
    for (int i = 0; i < 2; i++)
    {
        printf("ID -> %d\n", *size + 1);
        items[*size].ID = *size + 1;
        printf("Name -> ");
        scanf("%s", items[*size].name);
        flushInputBuffer();
        printf("Price -> ");
        scanf("%d", &items[*size].price);
        flushInputBuffer();
        *size += 1;
    }

    printf("Printing...\n");

    for (int i = 0; i < 2; i++)
    {
        printItem(items[*size - 2 + i]);
    }

    writeItems(FILENAME, items, *size);
    printf("Successfully wrote to file.");

    return items;
}

void readFromFile(int size)
{
    FILE *fp;

    fp = fopen(FILENAME, "rb");

    for(int i = 0; i < size; i++)
    {
        fread(&temp1,sizeof(item_t),1,fp);
        printf("ID -> %d \n Name -> %s \n Price -> %d\n", temp1.ID,temp1.name, temp1.price);
    }
    fclose(fp);
}

void contactInfoAdder(item_t *items, int size, itemWithCont_t *contacts)
{
    for (int i = 0; i < size; i++)
    {
        contacts[i].item.ID = items[i].ID;
        strcpy(contacts[i].item.name,items[i].name);
        contacts[i].item.price = items[i].price;
        printf("Enter the phone for %s => ", items[i].name);
        scanf("%d", &contacts[i].contact.number);
        flushInputBuffer();
        printf("Enter the mail for %s => ", items[i].name);
        scanf("%s", contacts[i].contact.mail);
    }

    for (int k = 0; k < size; k++)
    {
        printf("ID: %d\nName: %s\nPrice: %d\nNumber: %d\nMail: %s\n", contacts[k].item.ID, contacts[k].item.name, contacts[k].item.price, contacts[k].contact.number, contacts[k].contact.mail);
    }
}  
void printItemWithContactInfo(itemWithCont_t itemsWithCont);

int main()
{
    item_t *items;
    itemWithCont_t *contacts;
    int count = 0, size = 10;
    int selection;

    items = (item_t *)malloc(sizeof(item_t) * 100);
    contacts = (itemWithCont_t*)malloc(sizeof(itemWithCont_t)* 100);

    while (selection != 4)
    {
        printf("Select:\n 1. Write data to file.\n 2. Read data from file\n 3.Add and print with contact info \n4.EXIT\n");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            items = getItems(items, &count);
            break;
        case 2:
        printf("Reading from file...\n");
            readFromFile(count);
            break;
        case 3:
           contactInfoAdder(items, count, contacts);
            break;

        default:
            break;
        }
    }
}
