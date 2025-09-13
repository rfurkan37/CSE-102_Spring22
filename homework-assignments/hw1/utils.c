#include <stdio.h>
#include "utils.h"
#include <string.h>

int find_divisible(int x, int y, int z)
{
	int i = 1;

	if (x >= y) // if our x greater or equal to due this is a wrong situation we return -1.
		return (-1);
	else
	{
		while (x + i <= y) // now our program is searching all number BETWEEN x and y excluded
		{
			if ((x + i) % z == 0 && (x + i) != y) // if our program finds a number divided by z cause we want fisrt it immediately returns it.
				return (x + i);
			i++;
		}
		return (-1); // if we can't find any number we return -1.
	}
}

int find_nth_divisible(int n, int f_I, int z)
{
	int ret;

	ret = f_I + n * z; // to find nth divisible we add n timez divisor to first integer.

	return (ret); // and we return it.
}

int validate_identity_number(char identity_number[])
{
	int odd_number_sum = 0;
	int even_number_sum = 0;
	int ten_number_sum = 0;
	int sayac = 0;
	int i = 0;
	int flag = 0;
	while (identity_number[sayac] != '\0') // in this loop we are validating that every digit is a digit.
	{
		if (!(identity_number[sayac] >= '0' && identity_number[sayac] <= '9')) // in this statement we're checking if it's not digit.
			flag = 1;
		sayac++; // also we're counting number of digit.
	}

	if (sayac != 11 || identity_number[0] == '0' || flag == 1) // and if it's not 11 or if first digit is 0 if any of digits is not digit we return 0
		return 0;

	while (i <= 9)
	{
		ten_number_sum += identity_number[i] - '0'; // here we are counting first 10 digits sum
		if (i <= 8)
		{
			if (i % 2 == 0)
				odd_number_sum += identity_number[i] - '0'; // counting odd numbers sum
			else
				even_number_sum += identity_number[i] - '0';// counting even numbers sum
		}
		i++;
	}

	if ((odd_number_sum * 7 - even_number_sum) % 10 == (identity_number[9] - '0') && ten_number_sum % 10 == (identity_number[10] - '0')) // here we are checking ID numbers requirements
		return 1;
	else
		return 0;
}

int create_customer(char identity_number[], int password) 
{
	FILE *file;

	file = fopen("customeraccount.txt", "w"); // we are opening a file on write mod
	fprintf(file, "%s,%d", identity_number, password); // and we write our ID and password on it.
	fclose(file);

	return 0;
}

int check_login(char identity_number[], int password)
{
	FILE *file;
	char iceri[30];
	int pass;

	file = fopen("customeraccount.txt", "r");
	fscanf(file, "%[^,]%*c %d", iceri, &pass); // here we scanning it first until camma and after it we take password this is the meaing of interesting type.
	fclose(file);

	if (strcmp(iceri, identity_number) == 0 && password == pass) // we are checking if ID and password is correct
		return 1;
	else
		return 0;
}

int withdrawable_amount(float cash_amount)
{
	int wd_amount;

	wd_amount = cash_amount;// first we convert float to int to get away after point numbers

	wd_amount -= wd_amount % 10; // after delete minus mod 10 to make it counts of 10

	return (wd_amount); // and we return it
}

void part1recep(void)
{
	int fres = 0;
	int f_I;
	int sres = 0;
	int limsay = -1;
	int x, y, z, n, a;

	printf("PART I\n\n");

	printf("Please enter the first integer:");
	scanf("%d", &x);
	printf("Please enter the second integer:");
	scanf("%d", &y);
	printf("Please enter the divisor:");
	scanf("%d", &z);

	fres = find_divisible(x, y, z);

	f_I = fres;

	while (f_I < y) // we are counting limits here to find max n
	{
		limsay++;
		f_I += z;
	}

	if (fres == -1)
		printf("\nThere is not any integer between %d and %d can be divided by %d.", x, y, z);
	else
	{
		printf("\nThe first integer between %d and %d divided by %d is %d.", x, y, z, fres);
		printf("\nEnter the number how many next:");
		scanf("%d", &n);
		if (n <= limsay)// if n is less than limit it is okay but else we print a error message
		{
			sres = find_nth_divisible(n, fres, z);
			printf("The %d. integer between %d and %d divided by %d is %d.\n", n + 1, x, y, z, sres);
		}
		else
			printf("No possible to find %d. divisible between %d and %d divided by %d.\n", n + 1, x, y, z);
	}
}

void part2recep(void)
{
	char tckimlik[30];
	int pass;
	printf("\nPART II\n\n");
	printf("Please enter your identity number:");
	scanf("%s", tckimlik);
	if (validate_identity_number(tckimlik) == 1)
	{
		printf("Your ID is valid.\nPlease enter a password:");
		scanf("%d", &pass);
		create_customer(tckimlik, pass);
		printf("\nCustomer account created.");
		part3recep();
	}
	else
	{
		printf("Your ID is not valid.\nPlease restart the program.\n");
	}
}

void part3recep(void)
{
	char tckimlik[30];
	int pass;
	float para;
	int cekilen;
	printf("\n\nPART III\n\n");
	printf("Please enter your identity number:");
	scanf("%s", tckimlik);
	printf("Please enter your password:");
	scanf("%d", &pass);

	if (check_login(tckimlik, pass) == 1)
	{
		printf("\nLogin successfull.");
		printf("\nPlease enter your withdraw amount:");
		scanf("%f", &para);
		cekilen = withdrawable_amount(para);
		printf("\nWithdrawable amount is: %d\n", cekilen);
	}
	else
		printf("\nInvalid identity number or password.\n");
}