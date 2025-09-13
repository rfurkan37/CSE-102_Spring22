#include <stdio.h>
#include <string.h>

union Person
{
    char name[50];
    char address[50];
    int phone;
};

union Loan
{
    float arr[3];
};

struct BankAccount
{
    union Person Customer;
    union Loan Loans[3];
};

struct BankAccount customers[50];

float artificialPower(float base, int power)
{
    if (power != 0)
        return base * artificialPower(base, power - 1);
    else
        return 1;
}

float calculateLoan(float amount, int period, float interestRate)
{
    if (period == 0)
        return amount;
    else
    {
        amount *= (1 + interestRate);
        return calculateLoan(amount, period - 1, interestRate);
    }
}

void addCustomer(int *counter)
{
    union Person kisi;
    FILE *file;
    char buffer[100], buf1[10], buf2[10], buf3[10];
    int number;

    file = fopen("results.txt", "a+");
    while(!feof(file))
    {
        fscanf(file, "%s", buffer);
        sscanf(buffer,"%d,%s,%s", &number, buf1, buf2);
    }
    file = fopen("results.txt", "a+");

    *counter = number;
    fprintf(file,"ID : %d", *counter);
    printf("Please enter customer's name:");
    scanf("%s", kisi.name);
    fprintf(file, "%s,", kisi.name);
    strcpy(customers[*counter].Customer.name, kisi.name);

    printf("Please enter phone number:");
    scanf("%d", &kisi.phone);
    fprintf(file, "%d,", kisi.phone);

    printf("Please enter customer's address:");
    scanf("%s", kisi.address);
    fprintf(file, "%s\n", kisi.address);

    fclose(file);

    *counter++;
}

int newLoan(int ID)
{
    int loanAmount;
    float loan;
    FILE *fp;

    fp = fopen("loans.txt", "a+");
    printf("Please enter how many loan you want to add:");
    scanf("%d", &loanAmount);
    fprintf(fp, "Customer ID : %d\n", ID);

    for (int i = 0; i < loanAmount; i++)
    {
        printf("Please enter amount:");
        scanf("%f", &customers[ID].Loans[i].arr[0]);
        printf("Please enter interest rate:");
        scanf("%f", &customers[ID].Loans[i].arr[1]);
        printf("Please enter period:");
        scanf("%f", &customers[ID].Loans[i].arr[2]);
        loan = calculateLoan(customers[ID].Loans[i].arr[0], customers[ID].Loans[i].arr[2], customers[ID].Loans[i].arr[1]);
        fprintf(fp, "%f ", loan);
    }

    fclose(fp);
}

int main(void)
{
    int select = 0;
    int count = 0;
    int customerID;

    while (select != 5)
    {
        printf("=====================================\n"
               "Welcome to the Bank Management System\n"
               "=====================================\n"
               "\t1. List All Customers\n"
               "\t2. Add New Customer\n"
               "\t3. New Loan Application\n"
               "\t4. Report Menu\n"
               "\t5. Exit System\n");

        scanf("%d", &select);

        switch (select)
        {
        case 1:
            //listCustomers(&count);
            break;
        case 2:
            addCustomer(&count);
            break;
        case 3:
            printf("Please enter the customer ID that you want to add loan into:");
            scanf("%d", &customerID);
            newLoan(customerID);
        default:
            break;
        }
    }
}
