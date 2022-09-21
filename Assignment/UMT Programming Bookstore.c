/*
Author: LOW NAM LEE
Program: UMT Programming Bookstore
Date Modified: 22 Sept 2022
*/

// PREPROCESSORS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define MAX_INPUT 1000 // replace the keyword with 1000 (program crashes if user input exceeds this number of digits)

// DECORATIONS (ignore them if you see them in the source code ^-^)
// INTRO & OUTRO
void intro();
void outro();

// LAYOUT
void header();
void footer();
void prompt();
void box(int line);
void cursorMove(int move);

// ALGORITHMS FOR SPECIAL EFFECTS
void slide(char text[]);
void typing(char text[]);
void delay(int lateRate);
void error();

// MAIN PROGRAM FUNCTIONS (IMPORTANT)
// Part1
void menu();
void software();
void web();
void mobile();

// Part2
void salesOrder();
void input(int qty[]);
void process(int qty[], double priceBook[], double* subtotal, double* discount, double* total, int totalQty[]);
void output(int qty[], double priceBook[], double* subtotal, double* discount, double* total);
void report(int sales, int totalQty[]);

// Part3
char quit();

// GLOBAL DECLARATION (constant)
const double BOOK_PRICE[9] = { 69.00, 70.00, 55.50, 58.00, 65.00, 89.00, 73.50, 80.00, 50.00 };
const double DISCOUNT_RATE_200 = 0.05;
const double DISCOUNT_RATE_300 = 0.1;
const double DISCOUNT_RATE_500 = 0.15;

int main()
{
    // LOCAL DECLARATION & INITIALIZATION
    char opt[MAX_INPUT] = { 0 };
    char ans = 'N';

    // LAYOUT
    intro();
    header();

    // LOOP
    do
    {
        // LAYOUT
        prompt();
        printf("|     (1 = View Menu, 2 = Sales Order, 3 = Exit):     |");
        cursorMove(5);

        // clear buffer then read the input
        rewind(stdin);
        gets(opt);

        // convert the user input from ASCII value to digit
        opt[0] -= 48;

        // VALIDATION
        while (opt[0] < 1 || opt[0] > 3 || opt[1] != 0)
        {
            // error message to alert user
            error();

            // reset the value of all index
            for (int i = 0; i < MAX_INPUT; i++)
            {
                opt[i] = 0;
            }

            // LAYOUT
            prompt();
            printf("|     (1 = View Menu, 2 = Sales Order, 3 = Exit):     |");
            cursorMove(5);

            // clear buffer then read the input
            rewind(stdin);
            gets(opt);

            // convert the user input from ASCII value to digit
            opt[0] -= 48;
        }

        // OUTPUT
        switch (opt[0])
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

        if (opt[0] == 1 || opt[0] == 2)
        {
            // LAYOUT
            footer();

            // pause for user to read
            system("pause");

            // LAYOUT
            header();
        }
    } while (ans != 'Y');

    // LAYOUT
    outro();
}

// PART1
void menu()
{
    // LOCAL DECLARATION & INITIALIZATION
    char opt[MAX_INPUT] = { 0 };

    // LAYOUT
    box(2);
    printf("|                +                 +                  |\n");
    printf("|                |    Menu Lists   |                  |\n");
    printf("|                +                 +                  |\n");
    box(2);
    prompt();
    box(1);
    printf("|         1. Software Development Programming         |\n");
    printf("|         2. Web Programming                          |\n");
    printf("|         3. Mobile Programming                       |\n");
    box(1);
    printf("|         Input:                                      |");
    cursorMove(38);

    // INPUT
    rewind(stdin);
    gets(opt);
    opt[0] -= 48;

    // VALIDATION
    while (opt[0] < 1 || opt[0] > 3 || opt[1] != 0)
    {
        error();

        for (int i = 0; i < MAX_INPUT; i++)
        {
            opt[i] = 0;
        }

        box(2);
        printf("|                +                 +                  |\n");
        printf("|                |    Menu Lists   |                  |\n");
        printf("|                +                 +                  |\n");
        box(2);
        prompt();
        box(1);
        printf("|         1. Software Development Programming         |\n");
        printf("|         2. Web Programming                          |\n");
        printf("|         3. Mobile Programming                       |\n");
        box(1);
        printf("|         Input:                                      |");
        cursorMove(38);

        // INPUT
        rewind(stdin);
        gets(opt);
        opt[0] -= 48;
    }

    box(2);

    // OUTPUT
    switch (opt[0])
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

// OUTPUT
void software()
{
    // OUTPUT
    printf("| Type                                   Price(RM) |\n");
    box(1);
    printf("| A > Introduction to Java Programming      69.00 |\n");
    box(1);
    printf("| B > Learn to Program with C (2015)        70.00 |\n");
    box(1);
    printf("| C > Java For Dummies                      55.50 |\n");
}

// OUTPUT
void web()
{
    // OUTPUT
    printf("| Type                                   Price(RM) |\n");
    box(1);
    printf("| D > Introduction to Web Programming       58.00 |\n");
    box(1);
    printf("| E > Introduction HTML & CSS               65.00 |\n");
    box(1);
    printf("| F > Introduction to PHP                   89.00 |\n");
}

// OUTPUT
void mobile()
{
    // OUTPUT
    printf("| Type                                   Price(RM) |\n");
    box(1);
    printf("| G > Mobile Design and Programming         73.50 |\n");
    box(1);
    printf("| H > Start Building Mobile App             80.00 |\n");
    box(1);
    printf("| I > Android Programming                   50.00 |\n");
}

// PART2
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
        // LOCAL DECLARATION & INITIALIZATION
        // reset each order value whenever the order loops
        int qty[9] = { 0 };
        double priceBook[9] = { 0 };
        double subtotal = 0;
        double discount = 0;
        double total = 0;

        // add the total sales order by 1 whenever it loops
        sales++;

        // LAYOUT
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
        // LAYOUT
        printf("+-----------------------------------------------------+\n");
        box(1);
        printf("|           Next order? (Y = Yes, N = No):            |");
        cursorMove(11);

        // clear the buffer then read the input
        rewind(stdin);
        gets(choice);

        // convert the user input into uppercase
        choice[0] = toupper(choice[0]);

        // VALIDATION
        while (choice[0] != 'Y' && choice[0] != 'N' || choice[1] != 0)
        {
            // error message to alert user
            error();

            // reset the value of all index
            for (int i = 0; i < MAX_INPUT; i++)
            {
                choice[i] = 0;
            }

            // LAYOUT
            box(1);
            printf("|           Next order? (Y = Yes, N = No):            |");
            cursorMove(11);

            // clear the buffer then read the input
            rewind(stdin);
            gets(choice);

            // convert the user input into uppercase
            choice[0] = toupper(choice[0]);
        }

        // LAYOUT
        footer();
    } while (choice[0] == 'Y');

    // OUTPUT
    report(sales, totalQty);
}

// 1st argument is quantity for each book
void input(int qty[])
{
    // LOCAL DECLARATION & INITIALIZATION
    char index[MAX_INPUT] = { 0 };
    char qtyInput[MAX_INPUT] = { 0 };
    char ans[MAX_INPUT] = { 0 };

    // LOOP
    while (1)
    {
        // reset the input buffers before the next book entry
        for (int i = 0; i < MAX_INPUT; i++)
        {
            index[i] = 0;
            qtyInput[i] = 0;
        }

        // LAYOUT
        printf("| A, B, C, D, E, F, G, H, I (X - Exit):            |");
        cursorMove(12);

        // INPUT
        rewind(stdin);
        gets(index);

        // convert the user input into uppercase
        index[0] = toupper(index[0]);

        // VALIDATION
        while (index[0] != 'A' && index[0] != 'B' && index[0] != 'C' && index[0] != 'D' && index[0] != 'E' && index[0] != 'F' && index[0] != 'G' && index[0] != 'H' && index[0] != 'I' && index[0] != 'X' || index[1] != 0)
        {
            // error message to alert user
            error();

            // reset the value of all index
            for (int i = 0; i < MAX_INPUT; i++)
            {
                index[i] = 0;
            }

            // LAYOUT
            printf("| A, B, C, D, E, F, G, H, I (X - Exit):            |");
            cursorMove(12);

            // clear the buffer then read the input
            rewind(stdin);
            gets(index);

            // convert the user input into uppercase
            index[0] = toupper(index[0]);
        }

        if (index[0] == 'X')
        {
            // LAYOUT
            printf("|    Confirm the order? (Y = Yes, N = No):            |");
            cursorMove(12);

            // INPUT
            rewind(stdin);
            gets(ans);

            // convert the user input into uppercase
            ans[0] = toupper(ans[0]);

            // VALIDATION
            while (ans[0] != 'Y' && ans[0] != 'N' || ans[1] != 0)
            {
                // error message to alert user
                error();

                // reset the value of all index
                for (int i = 0; i < MAX_INPUT; i++)
                {
                    ans[i] = 0;
                }

                // LAYOUT
                printf("|    Confirm the order? (Y = Yes, N = No):            |");
                cursorMove(12);

                // clear the buffer then read the input
                rewind(stdin);
                gets(ans);

                // convert the user input into uppercase
                ans[0] = toupper(ans[0]);
            }

            if (ans[0] == 'Y')
                break;
            else
                continue;
        }

        // LAYOUT
        printf("| Quantity                            :             |");
        cursorMove(12);

        // INPUT
        rewind(stdin);
        gets(qtyInput);

        // VALIDATION
        for (int i = 0; i < strlen(qtyInput) || !(isdigit(qtyInput[0])); i++)
        {
            while (!(isdigit(qtyInput[i])) || qtyInput[0] < 0)
            {
                // error message to alert user
                error();

                // reset the value of all index
                for (int j = 0; j < MAX_INPUT; j++)
                {
                    qtyInput[j] = 0;
                }

                // LAYOUT
                printf("| Quantity                            :             |");
                cursorMove(12);

                // clear the buffer then read the input
                rewind(stdin);
                gets(qtyInput);

                // reset loop counter to validate from first index again
                i = 0;
            }
        }

        // PROCESS
        index[0] -= 65;
        qty[index[0]] += atoi(qtyInput);
    }
}

// 1st argument is quantity for each book, 2nd argument is total price for each book, 3rd argument is subtotal
// 4th argument is discount, 5th argument is total price in a transaction, 6th argument is total books sold
void process(int qty[], double priceBook[], double* subtotal, double* discount, double* total, int totalQty[])
{
    // PROCESS
    for (int i = 0; i < 9; i++)
    {
        // calculate total price of each book type
        priceBook[i] = qty[i] * BOOK_PRICE[i];

        // add each book total into subtotal
        *subtotal += priceBook[i];

        // add this order quantity into the daily total quantity
        totalQty[i] += qty[i];
    }

    // calculate discount based on subtotal amount
    if (*subtotal > 500)
        *discount = *subtotal * DISCOUNT_RATE_500;
    else if (*subtotal > 300)
        *discount = *subtotal * DISCOUNT_RATE_300;
    else if (*subtotal > 200)
        *discount = *subtotal * DISCOUNT_RATE_200;
    else
        *discount = 0.0;

    // calculate final price after discount
    *total = *subtotal - *discount;
}

// 1st argument is quantity for each book, 2nd argument is total price for each book
// 3rd argument is subtotal, 4th argument is discount, 5th argument is total price in a transaction
void output(int qty[], double priceBook[], double* subtotal, double* discount, double* total)
{
    // OUTPUT
    printf("\n|                       Receipt                       |\n");

    for (int i = 0; i < 9; i++)
    {
        // display only the books included in this order
        if (priceBook[i] != 0)
            printf("| Book %c : %5d @ RM%5.2lf = RM%8.2lf |\n", i + 65, qty[i], BOOK_PRICE[i], priceBook[i]);
    }

    // display payment summary
    printf("|                                          ========== |\n");
    printf("| Subtotal                             = RM%8.2lf |\n", *subtotal);
    printf("| Discount                             = RM%8.2lf |\n", *discount);
    printf("| Total to pay                         = RM%8.2lf |\n", *total);
    printf("|             THANK YOU, HAVE A NICE DAY!!            |\n");

    // LAYOUT
    footer();
}

// 1st argument is total sales orders, 2nd argument is total books sold
void report(int sales, int totalQty[])
{
    // LOCAL DECLARATION & INITIALIZATION
    int totalBook = 0;
    double totalPrice = 0;

    // LAYOUT
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
        // add all the number of books that have been sold
        totalBook += totalQty[i];

        // calculate the total price for all the purchase
        totalPrice += totalQty[i] * BOOK_PRICE[i];

        // display the quantity sold and total price for each book type
        printf("|    %c |                           %5d |  %8.2lf |\n", i + 65, totalQty[i], totalQty[i] * BOOK_PRICE[i]);
    }

    // LAYOUT
    printf("|                                   =====   ========= |\n");

    // display total quantity of all types of books sold and total sales price
    printf("| TOTAL                            %5d    %8.2lf |\n", totalBook, totalPrice);

    // LAYOUT
    footer();
}

// Part3
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

void intro()
{
    // LAYOUT
    slide("   ----------------------------------------------------- ");
    slide("  |         ....  ....  ...       ...   .........       |");
    slide("  | _|_    $$$!: $$$!: $$!:      $$!: $$$$$$$$$!:       |");
    slide("  |  |     $$$!: $$$!: $$$!:    $$$!: $$$$$$$$$!        |");
    slide("  |        $$$!: $$$!: $$$$!:  $$$$!:    $$$!:          |");
    slide("  |        $$$!: $$$!: $$$$$$$$$$$$!:    $$$!:          |");
    slide("  |        $$$!: $$$!: $$$!$$$$!$$$!:    $$$!:          |");
    slide("  |        $$$$$$$$$!: $$$!:$$! $$$!:    $$$!:    _|_   |");
    slide("  |         $$$$$$$!:  $$$:     $$$!     $$$!      |    |");
    slide("  |                                                     |");
    slide("  |            TAR UMT PROGRAMMING BOOKSTORE            |");
    slide("  |                                                     |");
    slide("  |           ____________________                      |");
    slide("  |          / / / / / / / / / / /|                     |");
    slide("  |   _|_   / / / / / / / / / / / |            __       |");
    slide("  |    |   / / / / / / / / / / /  |           / /       |");
    slide("  |       / / / / / / / / / / /   |          /-/\\       |");
    slide("  |      |-|-|-|-|-|-|-|-|-|-|  / |         / ///       |");
    slide("  |      | | | | | | | | | | | // |        / ///        |");
    slide("  |      | | | | | | | | | | | /  |       / ///         |");
    slide("  |      | | | | | | | | | | |    |      / /_/          |");
    slide("  |      |A|B|C|D|E|F|G|H|I|X|    |     / /        _|_  |");
    slide("  |      | | | | | | | | | | |  //     / /          |   |");
    slide("  |      | | | | | | | | | | | //     / /               |");
    slide("  |      | | | | | | | | | | | /     /_/                |");
    slide("  |      |_|_|_|_|_|_|_|_|_|_|/      |/                 |");
    slide("  |                               ___/                  |");
    slide("  |                               \\_______UMT POS SYSTEM|");
    slide("   ----------------------------------------------------- ");
    typing("   Welcome to UMT Programming Bookstore");
    typing("   Kindly choose one of the options below to begin");
    typing("   Enjoy");
    box(1);
}

void outro()
{
    // OUTPUT
    typing("Shutting down...\n");
    for (int i = 3; i > 0; i--)
    {
        printf("%d\n", i);
        delay(300);
    }

    printf("Shut down successfully!!\n");
    footer();

    // EXIT
    exit(0);
}

void header()
{
    printf("+-----------------------------------------------------+\n");
    box(1);
    printf("|         ....  ....  ...       ...   .........       |\n");
    printf("|        $$$!: $$$!: $$!:      $$!: $$$$$$$$$!:       |\n");
    printf("|        $$$!: $$$!: $$$!:    $$$!: $$$$$$$$$!        |\n");
    printf("|        $$$!: $$$!: $$$$!:  $$$$!:    $$$!:          |\n");
    printf("|        $$$!: $$$!: $$$$$$$$$$$$!:    $$$!:          |\n");
    printf("|        $$$!: $$$!: $$$!$$$$!$$$!:    $$$!:          |\n");
    printf("|        $$$$$$$$$!: $$$!:$$! $$$!:    $$$!:          |\n");
    printf("|         $$$$$$$!:  $$$:     $$$!     $$$!           |\n");
    printf("|                                                     |\n");
    box(1);
}

void footer()
{
    box(2);
    printf("| Time: %s                                      |\n", __TIME__);
    printf("| Date: %s                     UMT POS SYSTEM |\n", __DATE__);
    printf("+-----------------------------------------------------+\n");
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
        printf("|                                                     |\n");
    }
}

void cursorMove(int move)
{
    for (int i = 0; i < move; i++)
    {
        printf("\b");
    }
}

void delay(int lateRate)
{
    clock_t timeProcessed = clock();

    while (clock() < timeProcessed + lateRate);
}

void typing(char text[])
{
    int strSize = strlen(text);
    int lateRate = strSize * 15;

    for (int i = 0; i < strSize; i++)
    {
        printf("%c", text[i]);
        delay(lateRate / 30);
    }

    delay(390);
    printf(" ");

    for (int i = 0; i < strSize; i++)
    {
        printf("\b\b ");
        delay(lateRate / 60);
    }

    printf("\b");
}

void slide(char text[])
{
    int strSize = strlen(text);

    for (int i = 0; i <= strSize + 1; i++)
    {
        for (int j = 0; j <= strSize + 1 - i; j++)
        {
            if (j < strSize - i)
            {
                printf("%c", text[strSize - 1 - i]);
                if (text[strSize - 1 - i] != ' ')
                    delay(1);
                printf("\b ");
            }
            else
            {
                printf("%c\r", text[strSize - 1 - i]);
            }
        }
    }

    printf("\n");
}

void error()
{
    srand(time(NULL));
    int randNum = rand() % 20 + 1;

    printf("\a");
    box(1);

    switch (randNum)
    {
    case 1:
        typing("              Ouch!!");
        typing("   Don't enter that keyword again");
        typing("             It hurts");
        break;
    case 2:
        typing("               Hey!");
        typing("      Don't play the keyboard");
        break;
    case 3:
        typing("You wanna test my validation, huh?");
        typing("   My validation is impeccable");
        typing("              Hehe");
        break;
    case 4:
        typing("       &6%)'>E`@#*&v,/|s(}-!?");
        typing("       Error, please try again");
        break;
    case 5:
        typing("Error input detected, shutting down...");
        typing("                ...");
        typing("                ...");
        typing("                ...");
        typing("           Just kidding");
        break;
    case 6:
        typing("         Once upon a time...");
        typing("         There was a man...");
        typing("He kept entering invalid input...");
        typing("              Then...");
        typing("            He gone...");
        typing("           Story ends");
    }

    printf("| Invalid input, please try it again                  |\n");
    box(1);
}
