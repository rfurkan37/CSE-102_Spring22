#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Books
{
    char title[50], author[50], subject[50]; // struct declaring 
    int publicDate;
} *ptr, temp;

void sortStructs(int size)
{
    int i = 0;

    while(i < size - 1)
    {
        if(ptr[i].publicDate < ptr[i + 1].publicDate)
        {
            strcpy(temp.author, ptr[i].author);           // swapping between them.
            strcpy(ptr[i].author, ptr[i + 1].author); // swapping between them.
            strcpy(ptr[i + 1].author, temp.author); // swapping between them.
            strcpy(temp.title, ptr[i].title); // swapping between them.
            strcpy(ptr[i].title, ptr[i + 1].title); // swapping between them.
            strcpy(ptr[i + 1].title, temp.title); // swapping between them.
            strcpy(temp.subject, ptr[i].subject); // swapping between them.
            strcpy(ptr[i].subject, ptr[i + 1].subject); // swapping between them.
            strcpy(ptr[i + 1].subject, temp.subject); // swapping between them.
            temp.publicDate=ptr[i].publicDate; // swapping between them.
            ptr[i].publicDate = ptr[i + 1].publicDate; // swapping between them.
            ptr[i + 1].publicDate = temp.publicDate; // swapping between them.
            i = 0; // makin i zero for bubble zort
        }
        i++;
    }
}
int searchStructs(char buff[50], int flag, int size) // used flag for identying what to search
{
    switch (flag)
    {
    case 1:
        for(int i = 0; i < size;  i++)
        {
            if(strcmp(buff, ptr[i].title) == 0) // if found print found and print book
            {
                printf("\nBook Found.\n");
                printf("Title  -> %s\nAuthor -> %s\n Subject -> %s\n Year -> %d", ptr[i].title, ptr[i].author, ptr[i].subject, ptr[i].publicDate);
                break;
            }
        }
        break;
    case 2:
        for(int i = 0; i < size; i++)
        {
            if(strcmp(buff, ptr[i].author) == 0)
            {
                printf("\nBook Found.\n");
                printf("Title  -> %s\nAuthor -> %s\n Subject -> %s\n Year -> %d", ptr[i].title, ptr[i].author, ptr[i].subject, ptr[i].publicDate);
                break;
            }
        }
        break;
    case 3:
        for(int i = 0; i < size; i++)
        {
            if(strcmp(buff, ptr[i].subject) == 0)
            {
                printf("\nBook Found.\n");
                printf("Title  -> %s\nAuthor -> %s\n Subject -> %s\n Year -> %d", ptr[i].title, ptr[i].author, ptr[i].subject, ptr[i].publicDate);
                break;
            }
        }
        break;    
    default:
        break;
    }
}
void printStructs(int size)
{
    for(int i = 0; i < size; i++) // printing until end
    {
        printf("************************************************\n%d. Book:\nTitle  -> %s\nAuthor -> %s\n Subject -> %s\n Year -> %d\n", i + 1, ptr[i].title, ptr[i].author, ptr[i].subject, ptr[i].publicDate);
    }
}

int main()
{
    int selection = 0, subSelection = 0, s = 0;
    char buffer[50];

    ptr = (struct Books *)malloc(sizeof(struct Books *) * 100);

    while (selection != 3)
    {
        printf("MENU\n"
               "\t1. Add New Book\n"
               "\t2. List Books\n"
               "\t3. EXIT\n\n"

               "Choose = ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 2:
            while (subSelection != 6)
            {
                printf("*********************************\n"
                       "SUBMENU\n"
                       "\t1. Get by Title\n"
                       "\t2. Get by Author\n"
                       "\t3. Get by Subject\n"
                       "\t4. Sorted List by Year (DESC)\n"
                       "\t5. List All Books\n"
                       "\t6. EXIT SUBMENU\n\n"
                       "Choose = ");
                scanf("%d", &subSelection);
                switch (subSelection)
                {
                case 5:
                    printStructs(s);
                    break;
                case 1:
                    printf("Enter a book title = ");
                    scanf("%s", buffer);
                    searchStructs(buffer, 1, s);
                    break;
                case 2:
                    printf("Enter a book author = ");
                    scanf("%s", buffer);
                    searchStructs(buffer, 2, s);
                    break;
                case 3:
                    printf("Enter a book subject = ");
                    scanf("%s", buffer);
                    searchStructs(buffer, 3, s);
                    break;
                case 4:
                sortStructs(s);
                printStructs(s);
                case 6:
                    break;
                default:
                    printf("\nEnter normal value.\n");
                    break;
                }
            }

            break;
        case 1:
            printf("*********************************\n\nPlease enter book title = ");
            fflush(stdin);
            scanf(" %[^\n]%*c", ptr[s].title);
            printf("Please enter book author = ");
            fflush(stdin);
            scanf(" %[^\n]%*c", ptr[s].author);
            printf("Please enter book subject = ");
            fflush(stdin);
            scanf(" %[^\n]%*c", ptr[s].subject);
            printf("Please enter book year = ");
            fflush(stdin);
            scanf("%d", &ptr[s].publicDate);
            s++;
            break;
        case 3:
            break;
        default:
            printf("\nEnter normal value.\n");
            break;
        }
    }
}