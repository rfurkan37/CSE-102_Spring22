#include <stdio.h>
enum products
    {
        harddisk,
        monitor,
        keyboard,
        mouse,
    };

    enum products_prices
    {
        harddiskp = 2,
        monitorp = 5,
        keyboardp = 3,
        mousep = 10,
    };

    enum currencies
    {
        dolar = 4,
        euro = 5,
        pound = 9,
        peso = 10,
    };
int add_multiple(int sum, int a)
{
    

    if (a == harddisk)
        {
            sum += dolar * harddiskp;
        }
        else if (a == monitor)
        {
            sum += euro * monitorp;
        }
        else if (a == keyboard)
        {
            sum += pound * keyboardp;
        }
        else if (a == mouse)
        {
            sum += peso * mousep;
        }

        return sum;
}
void print_days(int day)
{
    enum days
    {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday
    };

    switch (day)
    {
    case sunday:
        printf("Sunday");
        break;
    case monday:
        printf("Monday");
        break;
    case tuesday:
        printf("Tuesday");
        break;
    case wednesday:
        printf("Wednesday");
        break;
    case thursday:
        printf("Thursday");
        break;
    case friday:
        printf("Friday");
        break;
    case saturday:
        printf("Saturday");
        break;

    default:
        break;
    }
}
void print_names(int a)
{
    enum products
    {
        harddisk,
        monitor,
        keyboard,
        mouse,
    };

    switch (a)
    {
    case harddisk:
        printf("Harddisk");
        break;
    case monitor:
        printf("Monitor");
        break;
    case keyboard:
        printf("Keyboard");
        break;
    case mouse:
        printf("Mouse");
        break;
    default:
        break;
    }
}
void all_orders_prices(int (*add_multiple)(int sum, int a))
{
    FILE *file;
    int a, b, sum = 0;
    file = fopen("orders.txt", "r");
    while (!feof(file))
    {
        fscanf(file, "%d %d ", &a, &b);
        sum = add_multiple(sum, a);
        printf("Product: ");
        print_names(a);
        printf(",Day: ");
        print_days(b);
        printf("\n");
    }

    printf("Total prices = %d TL\n", sum);
    fclose(file);
}


void readOrderFile(void print_days(int day))
{
    FILE *file;
    file = fopen("orders.txt", "r");
    int a, b;

    while (!feof(file))
    {
        fscanf(file, "%d %d ", &a, &b);
        printf("Product ID: %d,Day: ", a);
        print_days(b);
        printf("\n");
    }
    fclose(file);
}
void buy_product(void)
{
    int selection;
    FILE *file;
    file = fopen("orders.txt", "a");
    printf("Select your product:\n 0. Harddisk\n 1. Monitor \n 2. Keyboard\n 3. Mouse\n ------------------------\n");
    scanf("%d", &selection);
    fprintf(file, "%d ", selection);
    printf("Select your arrival day[0-6]:\n Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday\n------------------------\n");
    scanf("%d", &selection);
    fprintf(file, "%d ", selection);
    fclose(file);
}

int main()
{
    int selection;

    enum selections
    {
        buy = 1,
        orders,
        prices,
        exit
    };

    do
    {
        printf("\nWelcome to the TechMarket.\n 1. Buy Product\n 2. Orders\n 3. All Orders Prices\n 4. EXIT\n -----------------------\n");
        scanf("%d", &selection);

        switch (selection)
        {
        case buy:
            buy_product();
            break;
        case orders:
            readOrderFile(print_days);
            break;
        case prices:
            all_orders_prices(add_multiple);
            break;
        default:
            break;
        }

    } while (selection != 4);

    return 0;
}