#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct table
{
    char **field;
    char **type;
    char **value;
    bool *isNull;
    bool *isKey;
    int numOfEntries; // to know amount of entries.
    char *nameOfTable;
} table;

typedef struct tables
{
    struct tables *next;
    table *t;
} tables;

typedef struct database
{
    tables *tList; /*to be implemented as a linked list*/
    int n;         /* num of entries */
    char *name;    /* table name */
    struct database *next;
} database;


database *databaseNameControl(database *dList, char *name)
{
    database *search = dList;

    while (search != NULL)
    {
        if (strcmp(search->name, name) == 0)// until finding
            return search;// when found returning
        search = search->next;// incrementing
    }

    return NULL;
}
tables *tableNameControl(database *d, tables *tList, char *name)
{
    tables *search = d->tList;

    while (search != NULL)
    {
        if (strcmp(search->t->nameOfTable, name) == 0) // until finding
            return search; // when found returning
        search = search->next; // incrementing
    }

    return NULL;
}

void create_database(database *dList, char *name)
{
    database *last = dList;
    database *database1 = (database *)malloc(sizeof(database)); // allocating memory for new database
    database1->name = (char *)malloc(sizeof(char)*30); // allocating memory for its name
    strcpy(database1->name, name);  // giving name
    dList->n = 0;
    database1->tList = (tables *)malloc(sizeof(tables) * 2);
    database1->tList->t = NULL;
    database1->tList->next = NULL;

    while (last->next != NULL) // searching for last
        last = last->next;

    last->next = database1;// putting new databse to last
}

void show_table(database *d)
{
    tables *currentNode = d->tList;
    printf("+---------+-------------+------+-----+\n");
    printf("| tables in database %-16s|\n", d->name);
    printf("+---------+-------------+------+-----+\n");

    for (int i = 0; i < d->n; i++)
    {
        printf("| %-35s|\n", currentNode->t->nameOfTable); // printing name of tables -35 for centrelazing string
        currentNode = currentNode->next; // incrementing
    }
    printf("+---------+-------------+------+-----+\n");
}

void desc_table(database *d, table *t)
{
    char yesSign[] = "YES";
    char noSign[] = "NO";

    printf("+---------+-------------+------+-------------+-----+\n");
    printf("| Field   | Type        | Null | Value       | Key |\n");
    printf("+---------+-------------+------+-------------+-----+\n");
    for (int i = 0; i < t->numOfEntries; i++)
    {
        // printf("| %-8s| %-12s| %-5s| %-4s", t->field[i], t->type[i], t->isNull[i], );
        printf("| %-8s| %-12s| ", t->field[i], t->type[i]); // printing values
        if (t->isNull[i] == true)
            printf("%-5s| ", yesSign); // yes sign to arrange string
        else
            printf("%-5s| ", noSign);

        printf("%-12s| ", t->value[i]);

        if (t->isKey[i] == true)
            printf("%-4s|\n", yesSign);
        else
            printf("%-4s|\n", noSign);
    }
    printf("+---------+-------------+------+-------------+-----+\n");
}

void insert_table(database *d, table *t)
{
    int size ,temp;
    tables *last = d->tList;
    t = (table *)malloc(sizeof(table));
    t->field = (char **)malloc(sizeof(char *) * size);
    t->type = (char **)malloc(sizeof(char *) * size);
    t->value = (char **)malloc(sizeof(char *) * size); // allocating memory
    t->nameOfTable = (char *)malloc(sizeof(char) * 20);// allocating memory
    t->isKey = (bool *)malloc(sizeof(bool) * size);// allocating memory
    t->isNull = (bool *)malloc(sizeof(bool) * size);// allocating memory

    printf("Please enter the name of table: ");
    scanf("%s", t->nameOfTable);
    printf("Please enter the number of fields: ");
    scanf("%d", &size); // taking size and name

    t->numOfEntries = size;

    for (int i = 0; i < size; i++)
    {
        t->field[i] = (char *)malloc(sizeof(char) * 20); // allocating and filling it
        t->type[i] = (char *)malloc(sizeof(char) * 20);
        t->value[i] = (char *)malloc(sizeof(char) * 20);
        printf("Please enter name of field %d: ", i + 1);
        scanf("%s", t->field[i]);
        printf("Please enter type %d:", i + 1);
        scanf("%s", t->type[i]);
        printf("Please enter the value %d:", i + 1);
        scanf("%s", t->value[i]);
        t->isNull[i] = false;
        printf("Please enter 1 if its a key value 0 for not:");
        scanf("%d", &temp);
        if(temp == 1)
            t->isKey[i] = true;
        else
            t->isKey[i] = false; // istisna for bool
    }

    while (last->next != NULL)
        last = last->next;

    last->next->t = t;
}

void remove_table(database *d, char *name)
{
    tables *removing = d->tList;
    tables *preremoving;

    if (removing != NULL && strcmp(removing->t->nameOfTable, name) == 0) // if the head is what we searching
    {
        d->tList = removing->next; // removing
        free(removing); // freeing
        return;
    }

    while (removing != NULL && strcmp(removing->t->nameOfTable, name) != 0) // else searhing
    {
        preremoving = removing;
        removing = removing->next;
    }

    if (removing == NULL) // if we couldnt found
        return;

    preremoving->next = removing->next;

    free(removing);
}

void remove_database(database *d, char *name) // same as tabeles
{
    database *removing = d;
    database *preremoving;

    if (removing != NULL && strcmp(removing->name, name) == 0)
    {
        d = removing->next;
        free(removing);
        return;
    }

    while (removing != NULL && strcmp(removing->name, name) != 0)
    {
        preremoving = removing;
        removing = removing->next;
    }

    if (removing == NULL)
        return;

    preremoving->next = removing->next;

    free(removing);
}

void insert_key(database *d, table *t, bool key);

int main()
{
    int selection;
    char name1[30], name2[30];
    database *dList;
    dList = (database *)malloc(sizeof(database) * 10);
    dList->next = NULL;
    dList->name = (char *)malloc(sizeof(char)*30);
    strcpy(dList->name, "head");
    database *temp = NULL; 
    tables *temp2 = NULL;
   

    
    dList->n = 0;
    dList->tList = (tables *)malloc(sizeof(tables) * 10);
    dList->tList->next = NULL;
    

    while (selection != 7)
    {
        printf("\t\t\tRecepSQL System\n"
               "1. Create a database.\n"
               "2. Add and fill a table to from a database.\n" // menu
               "3. Remove a table from database.\n"
               "4. Remove a database.\n"
               "5. Show tables.\n"
               "6. Describe tables.\n"
               "7. EXIT\n\n");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            printf("Please enter a name for your database: ");
            scanf("%s", name1);
            create_database(dList, name1); // calling func
            printf("Your database \"%s\" has been created.\n", name1);
            break;
        case 2:
            printf("Please enter the name of database you want to add table into: ");
            scanf("%s", name1);
            temp = databaseNameControl(dList, name1); // taking pointet of what we saerch
            if (temp == NULL)
            {
                printf("There isn't any database name like \"%s\" .Please try again.\n", name1);
                break;
            }
            else
            {
                printf("Please enter the name of table you wanna add: ");
                scanf("%s", name2);
                printf("xd");
                //temp2 = tableNameControl(temp, temp->tList, name2);

                //insert_table(temp, temp2->t); // this thigns cao-used me segmentaiton

                printf("Table \"%s\" has been successfully created.\n", name2);
            }
            break;
        case 4:
            printf("Please enter the name of database you want to remove:");
            scanf("%s", name1);
            remove_database(dList, name1); // rwmovning
            break;
        case 3:
            printf("Please enter the name of database you want to remove table into: ");
            scanf("%s", name1);
            temp = databaseNameControl(dList, name1);
            if (temp == NULL)
            {
                printf("There isn't any database name like \"%s\" .Please try again.\n", name1);
                break;
            }
            else
            {
                printf("Please enter the name of table you wanna add: ");
                scanf("%s", name2);

                remove_table(temp, name2);

                printf("Table \"%s\" has been successfully created.\n", name2);
            }
            break;
        case 5:
            printf("Please enter the name of database you want to show:");
            scanf("%s", name1);

            temp = databaseNameControl(dList, name1);

            if (temp == NULL)
            {
                printf("Try again.");
                break;
            }
            else
                show_table(temp);
            break;
        case 6:
            printf("Please enter the name of database you want to describe from:");
            scanf("%s", name1);
            temp = databaseNameControl(dList, name1);
            if (temp == NULL)
            {
                printf("Try again.");
                break;
            }
            else
            {
                printf("Please enter the name of table you want to describe:");
                scanf("%s", name2);
                temp2 = tableNameControl(temp, dList->tList, name2);
                desc_table(temp, temp2->t);
            }
            break;
        case 7:
            break;

        default:
            break;
        }
    }

    return 0;
}