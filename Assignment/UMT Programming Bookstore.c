#include <stdio.h>
#define MAX_INPUT 1000

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
        char menuOpt[MAX_INPUT] = { 0 };

        printf("\nMenu Lists\n");
        printf("1. Software Development Programming\n");
        printf("2. Web Programming\n");
        printf("3. Mobile Programming\n");
        printf("Input: ");
        rewind(stdin);
        gets(menuOpt);
        menuOpt[0] -= 48;

        if (menuOpt[0] == 1)
        {
            printf("\nSoftware Development Programming\n");
            printf("A. Introduction to Java Programming - RM69.00\n");
            printf("B. Learn to Program with C (2015) - RM70.00\n");
            printf("C. Java For Dummies - RM55.50\n");
        }
        else if (menuOpt[0] == 2)
        {
            printf("Web programming books will be listed later.\n");
        }
        else if (menuOpt[0] == 3)
        {
            printf("Mobile programming books will be listed later.\n");
        }
        else
        {
            printf("Invalid menu category.\n");
        }
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
