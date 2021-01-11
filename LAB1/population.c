#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);


    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (start > end);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    if (start != end)
    {
        do
        {
            float increase = start / 3;
            float decrease = start / 4;
            start = start + increase - decrease;

            years++;
        }
        while (start < end);
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);

    return 0;
}