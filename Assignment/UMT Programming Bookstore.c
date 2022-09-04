#include <stdio.h>
#define MAX_INPUT 1000

void menu();
void software();

int main(void)
{
    char option[MAX_INPUT] = { 0 };

    printf("========================================\n");
    printf("       UMT Programming Bookstore\n");
    printf("========================================\n");
    printf("A simple console POS system.\n");
    printf("\n");
    printf("1. View Menu\n");
    printf("2. Sales Order\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    rewind(stdin);
    gets(option);
    option[0] -= 48;

    if (option[0] == 1)
    {
        menu();
    }
    else if (option[0] == 2)
    {
        printf("Sales order will be added later.\n");
    }
    else if (option[0] == 3)
    {
        printf("Exiting program.\n");
    }
    else
    {
        printf("Invalid option.\n");
    }

    return 0;
}

void menu()
{
    char menuOpt[MAX_INPUT] = { 0 };

    printf("\nMenu Lists\n");
    printf("1. Software Development Programming\n");
    printf("2. Web Programming\n");
    printf("3. Mobile Programming\n");
    printf("Input: ");
    rewind(stdin);
    gets(menuOpt);
    menuOpt[0] -= 48;

    while (menuOpt[0] < 1 || menuOpt[0] > 3 || menuOpt[1] != 0)
    {
        printf("Invalid menu category.\n");

        for (int i = 0; i < MAX_INPUT; i++)
        {
            menuOpt[i] = 0;
        }

        printf("\nMenu Lists\n");
        printf("1. Software Development Programming\n");
        printf("2. Web Programming\n");
        printf("3. Mobile Programming\n");
        printf("Input: ");
        rewind(stdin);
        gets(menuOpt);
        menuOpt[0] -= 48;
    }

    switch (menuOpt[0])
    {
    case 1:
        software();
        break;
    case 2:
        printf("\nWeb Programming\n");
        printf("D. Introduction to Web Programming - RM58.00\n");
        printf("E. Introduction HTML & CSS - RM65.00\n");
        printf("F. Introduction to PHP - RM89.00\n");
        break;
    case 3:
        printf("\nMobile Programming\n");
        printf("G. Mobile Design and Programming - RM73.50\n");
        printf("H. Start Building Mobile App - RM80.00\n");
        printf("I. Android Programming - RM50.00\n");
    }
}

void software()
{
    printf("\nSoftware Development Programming\n");
    printf("A. Introduction to Java Programming - RM69.00\n");
    printf("B. Learn to Program with C (2015) - RM70.00\n");
    printf("C. Java For Dummies - RM55.50\n");
}
