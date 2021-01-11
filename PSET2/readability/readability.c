#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);
void grader(float index);

int main(void)
{
    string text = get_string("Text: "); // get the text
    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);

    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text
    // index = 0.0588 * L - 0.296 * S - 15.8

    // Coleman liau index
    float L = (float) letters / ((float) words / 100); // Error on calculation of int and float values!
    float S = sentences / ((float) words / 100);
    float index = 0.0588 * L - 0.296 * S - 15.8;

    grader(index);

    return 0;
}

int letter_count(string text)
{
    int tmp = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // Read Alphabet only
        //printf("%i\n", text[i]);
        if (isalpha(text[i]))
        {
            tmp++;
        }
    }

    return tmp;
}

int word_count(string text)
{
    int tmp = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // Read whitespaces and last letter of the array
        if (isspace(text[i]) || i + 1 == strlen(text))
        {
            tmp++;
        }
    }

    return tmp;
}

int sentence_count(string text)
{
    int tmp = 0;
    string item = ".!?";

    for (int i = 0; i < strlen(text); i++)
    {
        int c = (int) text[i];

        // . or a ! or a ?
        if (c == (int) item[0] || c == (int) item[1] || c == (int) item[2])
        {
            tmp++;
        }
    }

    return tmp;
}

void grader(float index)
{
    index = round(index); // round to the nearest integer

    printf("%f \n", index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index); // whole number
    }

}