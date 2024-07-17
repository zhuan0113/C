/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Function to compute the Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute GCD of three numbers
int gcd_of_three(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

// Function to open the shop
void open_shop(int *is_open) {
    if (*is_open) {
        printf("Your Kirby shop has already opened :(\n\n");
    } else {
        *is_open = 1;
        printf("Your shop is openning!\n\n");
    }
    printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
}

// Function to list the current sale conditions
void list_sale_conditions(int kirby_A, int kirby_B, int kirby_C) {
    printf("Options: List\n");
    printf("===================================\n");
    printf("Kirby-A: %d\n", kirby_A);
    printf("Kirby-B: %d\n", kirby_B);
    printf("Kirby-C: %d\n", kirby_C);
    int total_money = kirby_A + kirby_B + kirby_C;
    printf("Kirby: %d, Money: %d\n\n", total_money, total_money);
    printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
}

// Function to add Kirby purchases
void add_kirby(int is_open) {
    if (!is_open) {
        printf("Your Kirby shop has not opened\n\n");
        printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
        return;
    }

    int x, y, z;
    while (1) {
        printf("Please enter three numbers: ");
        if (scanf("%d %d %d", &x, &y, &z) != 3) {
            printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (x == -1 && y == -1 && z == -1) {
            break;
        }
        if (x < 0 || y < 0 || z < 0) {
            printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
            continue;
        }

        int boxes = gcd_of_three(x, y, z);
        int price = (x + y + z) - (2 * boxes);
        printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\n\n", boxes, x / boxes, y / boxes, z / boxes);
        printf("Price: %d\n\n", price);
        break;
    }
    printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
}

int main() {
    int is_open = 0;
    int kirby_A = 0, kirby_B = 0, kirby_C = 0;

    printf("//////////Welcome to NCKU-PD1-Kirby-Shop\\\\\\\\\\\n\n");
    printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");

    int option;
    while (1) {
        if (scanf("%d", &option) != 1) {
            printf("Error: Please try again!\n\n");
            printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (option) {
            case 1:
                open_shop(&is_open);
                break;
            case 2:
                list_sale_conditions(kirby_A, kirby_B, kirby_C);
                break;
            case 3:
                add_kirby(is_open);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Please try again!\n\n");
                printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
                break;
        }
    }

    return 0;
}

