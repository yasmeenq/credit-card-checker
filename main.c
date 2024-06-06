#include <stdio.h>
#include <cs50.h>

long cc;
int counter;
int x;

void types();

int main(void) {
    cc = get_long("Insert your credit card number:");
    while (cc < 0) {
        cc = get_long("Insert your credit card number:");
    }
    counter = 0;
    int sum_all = 0;
    int temp = cc;
    while (temp > 0) {
        //Check Odd numbers
        sum_all += (temp % 10);
        temp /= 10;
        // Check even numbers alone
        if (temp > 0) {
            int curr_even = (temp % 10) * 2;
            temp /= 10;
            if (curr_even > 9) {
                sum_all += (curr_even % 10) + 1;
            } else {
                sum_all += curr_even;
            }
        }
    }
    if (sum_all >= 0) {
        x = sum_all % 10;
        if (x == 0) {
            // if valid go to the function that'll determine the card type
            types();
        } else {
            printf("INVALID\n");
        }
    }
}

void types() {
    // American express use 15 digits
    // and start with 34 || 37
    if (counter == 15) {
        long a = cc;
        if (a > 0) {
            int a1;
            int i;
            for (i = 0; i < 14; i++) {
                a1 = a % 100;
                a = a / 10;
            }
            if (a1 == 34 || a1 == 37) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");

            }
        }

    }
        // visa use 13 digits
        // and start with 4
    else if (counter == 13) {
        long a = cc;
        if (a > 0) {
            int a1;
            int i;
            for (i = 0; i < 13; i++) {
                a1 = a % 10;
                a = a / 10;
            }
            if (a1 == 4) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        }
    }

        // visa also use 16 digits and start with 4
        // mastercard use 16 digits and start with 51, 52, 53,54, 55
    else if (counter == 16) {
        long a = cc;
        if (a > 0) {
            int a1;
            int i;
            for (i = 0; i < 15; i++) {
                a1 = a % 100;
                a = a / 10;
            }
            int y = (a1 % 100 - a1 % 10) / 10;

            if (a1 >= 51 && a1 <= 55) {
                printf("MASTERCARD\n");
            } else if (y == 4) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        }

    }

        //if none of the above it's invalid
    else {
        printf("INVALID\n");
    }

}
