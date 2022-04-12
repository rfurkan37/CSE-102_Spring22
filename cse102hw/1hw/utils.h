#ifndef recpe
#define recpe

int find_divisible(int x, int y, int z);

int find_nth_divisible(int n, int f_I, int z);

int validate_identity_number(char identity_number[]);

int create_customer(char identity_number[], int password);

int check_login(char identity_number[], int password);

int withdrawable_amount(float cash_amount);

void part1recep();

void part2recep();

void part3recep();

#endif