// PREPROCESSORS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define MAX_INPUT 1000 // program crashes if user input exceeds this number of digits

// MAIN PROGRAM FUNCTIONS
// Part 1
void menu();
void software();
void web();
void mobile();

// Part 2
void salesOrder();
void input(int qty[]);
void process(int qty[], double priceBook[], double* subtotal, double* discount, double* total, int totalQty[]);
void output(int qty[], double priceBook[], double* subtotal, double* discount, double* total);
void report(int sales, int totalQty[]);

// Part 3
char quit();

// LAYOUT AND FEEDBACK
void error();
void box(int line);
void header();
void footer();
void prompt();

// INTRO AND SPECIAL EFFECTS
void intro();
void outro();
void delay(int lateRate);
void typing(char text[]);
void cursorMove(int move);
void slide(char text[]);

// GLOBAL DECLARATION (constant)
const double BOOK_PRICE[9] = { 69.00, 70.00, 55.50, 58.00, 65.00, 89.00, 73.50, 80.00, 50.00 };
const double DISCOUNT_RATE_200 = 0.05;
const double DISCOUNT_RATE_300 = 0.1;
const double DISCOUNT_RATE_500 = 0.15;

int main(void)
{
    // LOCAL DECLARATION & INITIALIZATION
    char option[MAX_INPUT] = { 0 };
    char ans = 'N';

    // LAYOUT
    intro();

    // LOOP
    do
    {
        for (int i = 0; i < MAX_INPUT; i++)
        {
            option[i] = 0;
        }

        header();
        prompt();
        box(1);
        printf("|                +               +                    |\n");
        printf("|                |   Main Menu   |                    |\n");
        printf("|                +               +                    |\n");
        box(1);
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

        // OUTPUT
        switch (option[0])
        {
        case 1:
            menu();
            break;
        case 2:
            salesOrder();
            break;
        case 3:
            ans = quit();
        }

        if (option[0] == 1 || option[0] == 2)
        {
            footer();
            system("pause");
            header();
        }
    } while (ans != 'Y');

    outro();
}

void intro()
{
    box(1);
    slide("UMT POS SYSTEM");
    box(1);
    typing("Welcome to UMT Programming Bookstore\n");
    printf("|        A simple console POS system.                 |\n");
    box(1);
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
    footer();
    exit(0);
}

char quit()
{
    // LOCAL DECLARATION & INITIALIZATION
    char ans[MAX_INPUT] = { 0 };

    // INPUT
    printf("| Continue to exit? (Y = Yes, N = No):             |");
    cursorMove(13);
    rewind(stdin);
    gets(ans);
    ans[0] = toupper(ans[0]);

    // VALIDATION
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

    // OUTPUT
    if (ans[0] == 'Y')
        printf("Exiting program.\n");

    return ans[0];
}

void salesOrder()
{
    // LOCAL DECLARATION & INITIALIZATION
    char choice[MAX_INPUT] = { 0 };
    int sales = 0;
    int totalQty[9] = { 0 };

    // LAYOUT
    footer();

    // LOOP
    do
    {
        // reset each order value whenever the order loops
        int qty[9] = { 0 };
        double priceBook[9] = { 0 };
        double subtotal = 0;
        double discount = 0;
        double total = 0;

        sales++;

        header();
        box(1);
        printf("|                  +              +                   |\n");
        printf("|                  |  Sales Order |                   |\n");
        printf("|                  +              +                   |\n");
        box(1);
        printf("|                  Sales Order No: %d                 |\n", sales);
        box(1);
        printf("|                                             Input   |\n");
        box(1);
        // INPUT
        input(qty);

        // PROCESS
        process(qty, priceBook, &subtotal, &discount, &total, totalQty);

        // OUTPUT
        output(qty, priceBook, &subtotal, &discount, &total);

        // INPUT
        box(1);
        printf("|           Next order? (Y = Yes, N = No):            |");
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

            box(1);
            printf("|           Next order? (Y = Yes, N = No):            |");
            cursorMove(11);
            rewind(stdin);
            gets(choice);
            choice[0] = toupper(choice[0]);
        }

        footer();
    } while (choice[0] == 'Y');

    // OUTPUT
    report(sales, totalQty);
}

// 1st argument is quantity for each book
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
            printf("|    Confirm the order? (Y = Yes, N = No):            |");
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

                printf("|    Confirm the order? (Y = Yes, N = No):            |");
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

        printf("| Quantity                            :             |");
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

                printf("| Quantity                            :             |");
                cursorMove(12);
                rewind(stdin);
                gets(qtyInput);
                i = 0;
            }
        }

        index[0] -= 65;
        qty[index[0]] += atoi(qtyInput);
    }
}

// 1st argument is quantity for each book, 2nd argument is total price for each book, 3rd argument is subtotal
// 4th argument is discount, 5th argument is total price in a transaction, 6th argument is total books sold
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

// 1st argument is quantity for each book, 2nd argument is total price for each book
// 3rd argument is subtotal, 4th argument is discount, 5th argument is total price in a transaction
void output(int qty[], double priceBook[], double* subtotal, double* discount, double* total)
{
    printf("\n|                       Receipt                       |\n");
    for (int i = 0; i < 9; i++)
    {
        if (priceBook[i] != 0)
            printf("| Book %c : %5d @ RM%5.2lf = RM%8.2lf |\n", i + 65, qty[i], BOOK_PRICE[i], priceBook[i]);
    }

    printf("|                                          ========== |\n");
    printf("| Subtotal                             = RM%8.2lf |\n", *subtotal);
    printf("| Discount                             = RM%8.2lf |\n", *discount);
    printf("| Total to pay                         = RM%8.2lf |\n", *total);
    printf("|             THANK YOU, HAVE A NICE DAY!!            |\n");
    footer();
}

// 1st argument is total sales orders, 2nd argument is total books sold
void report(int sales, int totalQty[])
{
    int totalBook = 0;
    double totalPrice = 0;

    header();
    box(1);
    printf("|          DAILY SALES ORDER SUMMARY REPORT           |\n");
    box(1);
    printf("| Total Number of Sales Orders = %d                   |\n", sales);
    box(1);
    printf("| Book |             Quantity Sold Sales |    Amount |\n");
    printf("| ---- | ------------------------------- | --------- |\n");

    for (int i = 0; i < 9; i++)
    {
        totalBook += totalQty[i];
        totalPrice += totalQty[i] * BOOK_PRICE[i];
        printf("|    %c |                           %5d |  %8.2lf |\n", i + 65, totalQty[i], totalQty[i] * BOOK_PRICE[i]);
    }

    printf("|                                   =====   ========= |\n");
    printf("| TOTAL                            %5d    %8.2lf |\n", totalBook, totalPrice);
    footer();
}

void menu()
{
    // LOCAL DECLARATION & INITIALIZATION
    char menuOpt[MAX_INPUT] = { 0 };

    // LAYOUT
    box(1);
    printf("|                +                 +                  |\n");
    printf("|                |    Menu Lists   |                  |\n");
    printf("|                +                 +                  |\n");
    box(1);
    prompt();
    printf("| 1. Software Development Programming                 |\n");
    printf("| 2. Web Programming                                  |\n");
    printf("| 3. Mobile Programming                               |\n");
    printf("| Input:                                             |");
    cursorMove(45);

    // INPUT
    rewind(stdin);
    gets(menuOpt);
    menuOpt[0] -= 48;

    // VALIDATION
    while (menuOpt[0] < 1 || menuOpt[0] > 3 || menuOpt[1] != 0)
    {
        error();

        for (int i = 0; i < MAX_INPUT; i++)
        {
            menuOpt[i] = 0;
        }

        box(1);
        printf("|                +                 +                  |\n");
        printf("|                |    Menu Lists   |                  |\n");
        printf("|                +                 +                  |\n");
        box(1);
        prompt();
        printf("| 1. Software Development Programming                 |\n");
        printf("| 2. Web Programming                                  |\n");
        printf("| 3. Mobile Programming                               |\n");
        printf("| Input:                                             |");
        cursorMove(45);

        // INPUT
        rewind(stdin);
        gets(menuOpt);
        menuOpt[0] -= 48;
    }

    // OUTPUT
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
    // OUTPUT
    printf("\nSoftware Development Programming\n");
    printf("| Type                                   Price(RM) |\n");
    printf("| A > Introduction to Java Programming      69.00 |\n");
    printf("| B > Learn to Program with C (2015)        70.00 |\n");
    printf("| C > Java For Dummies                      55.50 |\n");
}

void web()
{
    // OUTPUT
    printf("\nWeb Programming\n");
    printf("| Type                                   Price(RM) |\n");
    printf("| D > Introduction to Web Programming       58.00 |\n");
    printf("| E > Introduction HTML & CSS               65.00 |\n");
    printf("| F > Introduction to PHP                   89.00 |\n");
}

void mobile()
{
    // OUTPUT
    printf("\nMobile Programming\n");
    printf("| Type                                   Price(RM) |\n");
    printf("| G > Mobile Design and Programming         73.50 |\n");
    printf("| H > Start Building Mobile App             80.00 |\n");
    printf("| I > Android Programming                   50.00 |\n");
}

void error()
{
    printf("\a");
    box(1);
    printf("| Invalid input, please try it again                  |\n");
    box(1);
}

void header()
{
    box(1);
    printf("|              UMT Programming Bookstore              |\n");
    box(1);
}

void footer()
{
    box(1);
    printf("| Time: %s                                      |\n", __TIME__);
    printf("| Date: %s                     UMT POS SYSTEM |\n", __DATE__);
    box(1);
}

void prompt()
{
    box(1);
    printf("|                  Select an option                   |\n");
    box(1);
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
