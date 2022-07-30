#include <stdio.h>
#include <string.h>

struct node
{
    char bookname[30];
    char author[30];
    int year;
    struct node *next;
};

struct node *read_file()
{
    FILE *file;
    struct node *head;

    char bookname[30];
    char author[30];
    int year;

    file = fopen("source.txt", "r");

    while (!feof(file))
    {
        fscanf(file, "%s %s %d", bookname, author, &year);
        head = insert_node(head, bookname, author, year);
    }
}

struct node *insert_node(struct node *root, char *bookname, char *author, int year)
{
    struct node *p, *put, *temp;
    put = (struct node *)malloc(sizeof(struct node));
    
    strcpy(put->bookname, bookname);
    strcpy(put->author, author);
    put->year = year;

    if (root == NULL)
    {
        return put;
    }
    else if (year < root->year)
    {
       put->next = root;
       return put;
    }
}

void print_nodes(struct node *root)
{
    struct node *p;

    p = root;

    while (p->next != NULL)
    {
        printf("%s %s %d", p->author, p->bookname, p->year); // printing
        p = p->next;                                         // going to other node
    }
}

int main()
{
    struct node *head;

    head = (struct node *)malloc(sizeof(struct node));
}