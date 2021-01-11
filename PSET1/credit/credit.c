#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool check(int n);
int length(long n);
void validator(long n);

int main(void)
{
    long number = get_long("Number: ");

    // Check if valid card
    if (check(length(number)))
    {
        // Check if valid card and print the card name
        validator(number);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool check(int n)
{
    if (n == 16 || n == 13 || n == 15)
    {
        return true;
    }

    return false;
}

void validator(long n)
{
    int cardLength = length(n);
    char number[cardLength];
    int total = 0;

    sprintf(number, "%ld", n);

    /*
        Set the starting point
        0 odd
        1 even
    */
    int start = 0;
    if (cardLength % 2 == 0)
    {
        start = 1;
    }

    /*
        After checking if the length is even or not.
        We will start at 1st line if the total length is even
        and start at 2nd line if the total length is odd
    */
    for (int i = 1; i <= cardLength; i++)
    {
        int digit = number[i - 1] - '0'; // Convert ascii to normal number
        int tmp = 0;

        if (i % 2 == start)
        {
            // starting with the number’s second-to-last digit.
            tmp = digit * 2;

            if (tmp >= 10)
            {
                tmp = 1 + tmp % 10;
            }
        }
        else
        {
            // Add only
            tmp = digit;
        }

        total = total + tmp;
    }

    if (total % 10 == 0)
    {
        // Card name
        // American Express numbers 34 or 37 | 15-digit numbers
        // MasterCard numbers start with 51, 52, 53, 54, or 55 | 16-digit numbers
        // all Visa numbers start with 4  | 13- and 16-digit numbers
        int fnum = number[0] - '0';
        int snum = number[1] - '0';

        if (cardLength == 15 && fnum == 3 && (snum == 3 || snum == 7))
        {
            printf("AMEX\n");
        }
        else if (cardLength == 16 && fnum == 5 && (snum > 0 && snum < 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((cardLength == 16 || cardLength == 13) && fnum == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}

int length(long n)
{
    int i = floor(log10(labs(n))) + 1;

    return i;
}