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
        printf("\nBook Menu\n");
        printf("Software Development Programming\n");
        printf("A. Introduction to Java Programming - RM69.00\n");
        printf("B. Learn to Program with C (2015) - RM70.00\n");
        printf("C. Java For Dummies - RM55.50\n");
        printf("\nWeb Programming\n");
        printf("D. Introduction to Web Programming - RM58.00\n");
        printf("E. Introduction HTML & CSS - RM65.00\n");
        printf("F. Introduction to PHP - RM89.00\n");
        printf("\nMobile Programming\n");
        printf("G. Mobile Design and Programming - RM73.50\n");
        printf("H. Start Building Mobile App - RM80.00\n");
        printf("I. Android Programming - RM50.00\n");
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
