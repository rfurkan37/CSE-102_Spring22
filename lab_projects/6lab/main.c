#include <stdio.h>

void print_table(char table[26][26])
{
    int i, j;
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            printf("%c ", table[i][j]); // printing the table
        }
        printf("\n");
    }
}

void generate_matrix(char table[26][26])// generating the matrix
{
    char c;
    for (int i = 0; i < 26; i++)
    {
        c = 'A' + i;
        for (int j = 0; j < 26; j++)
        {
            if (c + j <= 'Z')
                table[i][j] = c + j; // increasing the letters
            else if (c + j > 'A')
                table[i][j] = c + j - ('Z' - 'A') - 1; // decreasing the letters
        }
    }
}

void encryption(char table[26][26])
{
    char plain_text[10], key[3], keystream[10], ciphertext[10];
    char c ;
    int i = 0;

    printf("*** ENCRYPTION ***\n\n");

    printf("Plaintext:");

    while(i < 10)    // taking until 10 characters for plain text.
    {
        c = getchar();
        plain_text[i] = c;
        i++;
    }

    plain_text[i] = 0;     
    printf("Key:");
    c = '0';

    for(i = 0; i < 3; i++) // taking until 3 characters for plain text.
    {
        c = getchar();
        key[i] = c;
    }
    key[i] = 0;

    for(i = 0; plain_text[i]; i++) // genrating keystream
    {
        keystream[i] = key[i%3];
    }

     for(i = 0; keystream[i]; i++) // printing keystream
    {
        printf("%c",keystream[i]);
    }
}

int main()
{
    char table[26][26];
    int selection;

    generate_matrix(table); // geenrating table
    do 
    { // infinite loop section
        printf("\nWelcome to Vigenere Cipher Program\n"
               "1. Print Table\n2. Encryption\n3. Decryption\n4. Exit");
        printf("\n--------------------------------------\nINPUT : ");
        scanf("%d", &selection);

        switch (selection) // selection section 
        {
        case 1:
            print_table(table);
            break;
        case 2:
            encryption(table);
            break;
            // case 3:
            //   decryption();
            // break;
        default:
            break;
        }

    } while (selection != 4);

    return 0;
}