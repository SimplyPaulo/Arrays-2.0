#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main (void)

{
    string texto = get_string("Texto: ");
    int qtdletters = 0;
    int qtdwords = 1;
    int qtdsentences = 0;

    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto [i] >= 'A' && texto[i] <= 'Z'))
        {
            qtdletters++;
        }

        else if (texto[i] == ' ')
        {
            qtdwords++;
        }

        else if (texto[i] == '!' || texto[i] == '?' || texto[i] == '.' || texto[i] == ',')
        {
            qtdsentences++;
        }
    }

    float L = 100 * qtdletters / (float) qtdwords;
    float S = 100 * qtdsentences / (float) qtdwords;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before grade 1\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }

}