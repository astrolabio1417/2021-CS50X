#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;

    // Accept 1-8 only
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height >= 9);

    for (int i = 0; i < height; i++)
    {
        //Print Spaces
        for (int y = 1; y < height - i; y++)
        {
            printf(" ");
        }

        //Left side hash
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf("  ");

        //Right side hash
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}