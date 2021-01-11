#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_key(string key);
void tocipher(string plain, string key);

int main(int argc, string argv[])
{
    //printf("%i\n%s\n", argc, argv[1]);

    // Only accept 2 arguments!
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Don't accept duplicate letters
    if (!check_key(argv[1]))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    tocipher(plaintext, argv[1]);

    return 0;
}

void tocipher(string plain, string key)
{
    // convert to special key
    for (int i = 0; i < strlen(plain); i++)
    {
        char c = plain[i];

        if (islower(c))
        {
            printf("%c", tolower(key[c - 'a'])); // tolower to preserve case // c - 'a' (View it as ascii)
        }
        else if (isupper(c))
        {
            printf("%c", toupper(key[c - 'A'])); // to preserve case
        }
        else
        {
            printf("%c", c); // for non alphabet just print it.
        }
    }
    printf("\n");
}

bool check_key(string key)
{
    // Only accepts 26 characters!
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Check for duplicate letters in the key!
    for (int i = 0; i < strlen(key); i++)
    {
        for (int x = i + 1; x < strlen(key); x++)
        {
            if (tolower(key[i]) == tolower(key[x]))
            {
                printf("Key must contain 26 characters.\n");
                return false;
            }
        }

        // Don't accept non alphabet character!
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters.\n");
            return false;
        }
    }

    return true;
}