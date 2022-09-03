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
        printf("Book menu will be added later.\n");
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
