#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define MAX_INPUT 1000

const double BOOK_PRICE[9] = { 69.00, 70.00, 55.50, 58.00, 65.00, 89.00, 73.50, 80.00, 50.00 };
const double DISCOUNT_RATE_200 = 0.05;
const double DISCOUNT_RATE_300 = 0.1;
const double DISCOUNT_RATE_500 = 0.15;

void menu();
void software();
void web();
void mobile();
void salesOrder();
void report(int sales, int totalQty[]);
void input(int qty[]);
void process(int qty[], double priceBook[], double* subtotal, double* discount, double* total, int totalQty[]);
void output(int qty[], double priceBook[], double* subtotal, double* discount, double* total);
char quit();
void error();
void box(int line);
void header();
void footer();
void prompt();
void intro();
void outro();
void delay(int lateRate);
void typing(char text[]);
void cursorMove(int move);
void slide(char text[]);

int main(void)
{
    char option[MAX_INPUT] = { 0 };
    char ans[MAX_INPUT] = { 0 };

    intro();

    do
    {
        for (int i = 0; i < MAX_INPUT; i++)
        {
            option[i] = 0;
            ans[i] = 0;
        }

        header();
        prompt();
        printf("\n");
        printf("| 1. View Menu                                         |\n");
        printf("| 2. Sales Order                                       |\n");
        printf("| 3. Exit                                              |\n");
        printf("| Choose an option:                                    |");
        cursorMove(36);
        rewind(stdin);
        gets(option);
        option[0] -= 48;

        while (option[0] < 1 || option[0] > 3 || option[1] != 0)
        {
            error();

            for (int i = 0; i < MAX_INPUT; i++)
            {
                option[i] = 0;
            }

            printf("| Choose an option:                                    |");
            cursorMove(36);
            rewind(stdin);
            gets(option);
            option[0] -= 48;
        }

        if (option[0] == 1)
        {
            menu();
        }
        else if (option[0] == 2)
        {
            salesOrder();
        }
        else if (option[0] == 3)
        {
            ans[0] = quit();

            if (ans[0] == 'N')
                option[0] = 0;
        }

        if (option[0] == 1 || option[0] == 2)
        {
            footer();
            system("pause");
            header();
        }
    } while (option[0] != 3);

    outro();
    return 0;
}

void intro()
{
    box(1);
    slide("UMT POS SYSTEM");
    box(1);
    printf("A simple console POS system.\n");
}

void outro()
{
    typing("Shutting down...\n");
    for (int i = 3; i > 0; i--)
    {
        printf("%d\n", i);
        delay(300);
    }

    printf("Shut down successfully!!\n");
}

char quit()
{
    char ans[MAX_INPUT] = { 0 };

    printf("| Continue to exit? (Y = Yes, N = No):             |");
    cursorMove(13);
    rewind(stdin);
    gets(ans);
    ans[0] = toupper(ans[0]);

    while (ans[0] != 'Y' && ans[0] != 'N' || ans[1] != 0)
    {
        error();

        for (int i = 0; i < MAX_INPUT; i++)
        {
            ans[i] = 0;
        }

        printf("| Continue to exit? (Y = Yes, N = No):             |");
        cursorMove(13);
        rewind(stdin);
        gets(ans);
        ans[0] = toupper(ans[0]);
    }

    if (ans[0] == 'Y')
        printf("Exiting program.\n");

    return ans[0];
}

void salesOrder()
{
    char choice[MAX_INPUT] = { 0 };
    int sales = 0;
    int totalQty[9] = { 0 };

    do
    {
        int qty[9] = { 0 };
        double priceBook[9] = { 0 };
        double subtotal = 0;
        double discount = 0;
        double total = 0;

        sales++;

        header();
        printf("\nSales Order\n");
        printf("Sales Order No: %d\n", sales);
        input(qty);

        process(qty, priceBook, &subtotal, &discount, &total, totalQty);
        output(qty, priceBook, &subtotal, &discount, &total);
        printf("| Next order? (Y = Yes, N = No):                  |");
        cursorMove(11);
        rewind(stdin);
        gets(choice);
        choice[0] = toupper(choice[0]);

        while (choice[0] != 'Y' && choice[0] != 'N' || choice[1] != 0)
        {
            error();

            for (int i = 0; i < MAX_INPUT; i++)
            {
                choice[i] = 0;
            }

            printf("| Next order? (Y = Yes, N = No):                  |");
            cursorMove(11);
            rewind(stdin);
            gets(choice);
            choice[0] = toupper(choice[0]);
        }
    } while (choice[0] == 'Y');

    report(sales, totalQty);
}

void input(int qty[])
{
    char index[MAX_INPUT] = { 0 };
    char qtyInput[MAX_INPUT] = { 0 };
    char ans[MAX_INPUT] = { 0 };

    while (1)
    {
        for (int i = 0; i < MAX_INPUT; i++)
        {
            index[i] = 0;
            qtyInput[i] = 0;
        }

        printf("| A, B, C, D, E, F, G, H, I (X - Exit):            |");
        cursorMove(12);
        rewind(stdin);
        gets(index);
        index[0] = toupper(index[0]);

        while (index[0] != 'A' && index[0] != 'B' && index[0] != 'C' && index[0] != 'D' && index[0] != 'E' && index[0] != 'F' && index[0] != 'G' && index[0] != 'H' && index[0] != 'I' && index[0] != 'X' || index[1] != 0)
        {
            error();

            for (int i = 0; i < MAX_INPUT; i++)
            {
                index[i] = 0;
            }

            printf("| A, B, C, D, E, F, G, H, I (X - Exit):            |");
            cursorMove(12);
            rewind(stdin);
            gets(index);
            index[0] = toupper(index[0]);
        }

        if (index[0] == 'X')
        {
            printf("| Confirm the order? (Y = Yes, N = No):            |");
            cursorMove(12);
            rewind(stdin);
            gets(ans);
            ans[0] = toupper(ans[0]);

            while (ans[0] != 'Y' && ans[0] != 'N' || ans[1] != 0)
            {
                error();

                for (int i = 0; i < MAX_INPUT; i++)
                {
                    ans[i] = 0;
                }

                printf("| Confirm the order? (Y = Yes, N = No):            |");
                cursorMove(12);
                rewind(stdin);
                gets(ans);
                ans[0] = toupper(ans[0]);
            }

            if (ans[0] == 'Y')
                break;
            else
                continue;
        }

        printf("| Quantity:                                          |");
        cursorMove(12);
        rewind(stdin);
        gets(qtyInput);

        for (int i = 0; i < strlen(qtyInput) || !(isdigit(qtyInput[0])); i++)
        {
            while (!(isdigit(qtyInput[i])) || qtyInput[0] < 0)
            {
                error();

                for (int j = 0; j < MAX_INPUT; j++)
                {
                    qtyInput[j] = 0;
                }

                printf("| Quantity:                                          |");
                cursorMove(12);
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

void process(int qty[], double priceBook[], double* subtotal, double* discount, double* total, int totalQty[])
{
    for (int i = 0; i < 9; i++)
    {
        priceBook[i] = qty[i] * BOOK_PRICE[i];
        *subtotal += priceBook[i];
        totalQty[i] += qty[i];
    }

    if (*subtotal > 500)
        *discount = *subtotal * DISCOUNT_RATE_500;
    else if (*subtotal > 300)
        *discount = *subtotal * DISCOUNT_RATE_300;
    else if (*subtotal > 200)
        *discount = *subtotal * DISCOUNT_RATE_200;
    else
        *discount = 0.0;

    *total = *subtotal - *discount;
}

void output(int qty[], double priceBook[], double* subtotal, double* discount, double* total)
{
    printf("Order complete. Subtotal: RM%.2lf\n", *subtotal);

    printf("\nReceipt\n");
    for (int i = 0; i < 9; i++)
    {
        if (priceBook[i] != 0)
            printf("| Book %c : %d @ RM%.2lf = RM%.2lf |\n", i + 65, qty[i], BOOK_PRICE[i], priceBook[i]);
    }

    printf("| Subtotal: RM%.2lf |\n", *subtotal);
    printf("| Discount: RM%.2lf |\n", *discount);
    printf("| Total to pay: RM%.2lf |\n", *total);
    footer();
}

void report(int sales, int totalQty[])
{
    int totalBook = 0;
    double totalPrice = 0;

    printf("\nDaily Sales Order Summary Report\n");
    printf("Total Number of Sales Orders = %d\n", sales);
    printf("Book | Quantity Sold | Amount\n");

    for (int i = 0; i < 9; i++)
    {
        totalBook += totalQty[i];
        totalPrice += totalQty[i] * BOOK_PRICE[i];
        printf("%c | %d | %.2lf\n", i + 65, totalQty[i], totalQty[i] * BOOK_PRICE[i]);
    }

    printf("TOTAL | %d | %.2lf\n", totalBook, totalPrice);
    footer();
}

void menu()
{
    char menuOpt[MAX_INPUT] = { 0 };

    printf("\nMenu Lists\n");
    prompt();
    printf("| 1. Software Development Programming                 |\n");
    printf("| 2. Web Programming                                  |\n");
    printf("| 3. Mobile Programming                               |\n");
    printf("| Input:                                             |");
    cursorMove(45);
    rewind(stdin);
    gets(menuOpt);
    menuOpt[0] -= 48;

    while (menuOpt[0] < 1 || menuOpt[0] > 3 || menuOpt[1] != 0)
    {
        error();

        for (int i = 0; i < MAX_INPUT; i++)
        {
            menuOpt[i] = 0;
        }

        printf("\nMenu Lists\n");
        prompt();
        printf("| 1. Software Development Programming                 |\n");
        printf("| 2. Web Programming                                  |\n");
        printf("| 3. Mobile Programming                               |\n");
        printf("| Input:                                             |");
        cursorMove(45);
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

    footer();
}

void software()
{
    printf("\nSoftware Development Programming\n");
    printf("| Type                                   Price(RM) |\n");
    printf("| A > Introduction to Java Programming      69.00 |\n");
    printf("| B > Learn to Program with C (2015)        70.00 |\n");
    printf("| C > Java For Dummies                      55.50 |\n");
}

void web()
{
    printf("\nWeb Programming\n");
    printf("| Type                                   Price(RM) |\n");
    printf("| D > Introduction to Web Programming       58.00 |\n");
    printf("| E > Introduction HTML & CSS               65.00 |\n");
    printf("| F > Introduction to PHP                   89.00 |\n");
}

void mobile()
{
    printf("\nMobile Programming\n");
    printf("| Type                                   Price(RM) |\n");
    printf("| G > Mobile Design and Programming         73.50 |\n");
    printf("| H > Start Building Mobile App             80.00 |\n");
    printf("| I > Android Programming                   50.00 |\n");
}

void error()
{
    printf("Invalid input, please try it again\n");
}

void header()
{
    box(1);
    printf("|              UMT Programming Bookstore              |\n");
    printf("| Time: %s                                      |\n", __TIME__);
    printf("| Date: %s                     UMT POS SYSTEM |\n", __DATE__);
    box(1);
}

void footer()
{
    box(1);
}

void prompt()
{
    printf("Select an option\n");
}

void box(int line)
{
    for (int i = 0; i < line; i++)
    {
        printf("+------------------------------------------------------+\n");
    }
}

void delay(int lateRate)
{
    int start = clock();

    while (clock() < start + lateRate)
    {
    }
}

void typing(char text[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c", text[i]);
        delay(20);
    }
}

void slide(char text[])
{
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c", text[i]);
        delay(15);
    }

    printf("\n");
}

void cursorMove(int move)
{
    for (int i = 0; i < move; i++)
    {
        printf("\b");
    }
}
