#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_INPUT 1000

void menu();
void software();
void web();
void mobile();

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
        char index[MAX_INPUT] = { 0 };
        char qtyInput[MAX_INPUT] = { 0 };
        int qty[9] = { 0 };

        printf("\nSales Order\n");
        printf("Sales Order No: 1\n");
        printf("A, B, C, D, E, F, G, H, I (X - Exit): ");
        rewind(stdin);
        gets(index);
        index[0] = toupper(index[0]);

        while (index[0] != 'A' && index[0] != 'B' && index[0] != 'C' && index[0] != 'D' && index[0] != 'E' && index[0] != 'F' && index[0] != 'G' && index[0] != 'H' && index[0] != 'I' && index[0] != 'X' || index[1] != 0)
        {
            printf("Invalid book code.\n");

            for (int i = 0; i < MAX_INPUT; i++)
            {
                index[i] = 0;
            }

            printf("A, B, C, D, E, F, G, H, I (X - Exit): ");
            rewind(stdin);
            gets(index);
            index[0] = toupper(index[0]);
        }

        if (index[0] == 'X')
        {
            printf("Order cancelled.\n");
        }
        else
        {
            printf("Quantity: ");
            rewind(stdin);
            gets(qtyInput);

            for (int i = 0; i < strlen(qtyInput) || !(isdigit(qtyInput[0])); i++)
            {
                while (!(isdigit(qtyInput[i])) || qtyInput[0] < 0)
                {
                    printf("Invalid quantity.\n");

                    for (int j = 0; j < MAX_INPUT; j++)
                    {
                        qtyInput[j] = 0;
                    }

                    printf("Quantity: ");
                    rewind(stdin);
                    gets(qtyInput);
                    i = 0;
                }
            }

            index[0] -= 65;
            qty[index[0]] += atoi(qtyInput);

            printf("Book %c quantity: %d\n", index[0] + 65, qty[index[0]]);
        }
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
        web();
        break;
    case 3:
        mobile();
    }
}

void software()
{
    printf("\nSoftware Development Programming\n");
    printf("Type                                   Price(RM)\n");
    printf("A > Introduction to Java Programming      69.00\n");
    printf("B > Learn to Program with C (2015)        70.00\n");
    printf("C > Java For Dummies                      55.50\n");
}

void web()
{
    printf("\nWeb Programming\n");
    printf("Type                                   Price(RM)\n");
    printf("D > Introduction to Web Programming       58.00\n");
    printf("E > Introduction HTML & CSS               65.00\n");
    printf("F > Introduction to PHP                   89.00\n");
}

void mobile()
{
    printf("\nMobile Programming\n");
    printf("Type                                   Price(RM)\n");
    printf("G > Mobile Design and Programming         73.50\n");
    printf("H > Start Building Mobile App             80.00\n");
    printf("I > Android Programming                   50.00\n");
}
