#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    // Recebe o texto do usuário
    string t = get_string("Texto: ");
    
    // Começa a contagem de letras, frases e palavras
    int letras = 0;
    int frases = 0;
    int palavras = 1;
    
    // Itera cada caractere no texto, classificando se são letras, finais de frases ou de palavras
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        // Aumenta quantidade de letras se o caractere for entre A e Z ou entre a e z
        if ((t[i] >= 'A' && t[i] <= 'Z') || (t[i] >= 'a' && t[i] <= 'z'))
        {
            letras++;
        }
        
        // Aumenta quantidade de frases de acordo com a quantidade de . ! e de ?
        else if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            frases++;
        }
        
        Aumenta a quantidade de palavras pela quantidade de espaços em branco
        else if (t[i] == ' ')
        {
            palavras++;
        }
    }
    
    // Calcula a média de letras e de frases em 100 palavras
    float L = (float) letras / palavras * 100;
    float S = (float) frases / palavras * 100;
    
    // Calcula o indice Coleman-Liau
    int indice = round(0.0588 * L - 0.296 * S - 15.8);
    
    // De acordo com o indice, informa o nível escolar necessário
    if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (indice < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", indice);
    }
    
    return 0;
}
