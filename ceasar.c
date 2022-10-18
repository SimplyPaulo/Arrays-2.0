#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Confere se foram usados dois argumentos
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    // Pega chave, texto e tamanho do texto
    int key = atoi(argv[1]);
    string texto = get_string("Texto: ");
    string cifra = texto;
    int tamanho = strlen(texto);

    // loop de encripção
    for (int i = 0; i < tamanho; i++)
    {
        // Se não for alfabético, ignora
        if (isalpha(texto[i]))
        {
            cifra[i] = texto[i];
        }
        // se for minúsculo subrtai 'a', aplica a fórmula, e adiciona 'a' no final
        else if (islower(texto[i]))
        {
            cifra[i] -= 'a';
            cifra[i] = (cifra[i] + key) % 26;
            cifra[i] += 'a';
        }
        // senão, é maiúsculo. subtrai 'A', aplica a fórmula, e adiciona 'A' no final
        else
        {
            cifra[i] -= 'A';
            cifra[i] = (cifra[i] + key) % 26;
            cifra[i] += 'A';
        }

    }
    printf("ciphertext: %s\n", cifra);
}