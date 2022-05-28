#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Protótipo da função
int isnumber(char c[]);

int main(int argc, string argv[])
{
    // Verifica se o usuário usou corretamente o comando
    if (argc != 2 || isnumber(argv[1]) != 0)
    {
        printf("Uso: ./caesar key\n");
        
        return 1;
    }
    
    else
    {
        // Solicita o texto a ser cifrado
        string t = get_string("plaintext: ");
        
        printf("ciphertext: ");
        
        // Converte a chave do tipo 'char' para o tipo 'int'
        int key = atoi(argv[1]);
        
        // Itera cada caractere do texto a ser cifrado
        for (int i = 0, n = strlen(t); i < n; i++)
        {
            // Verifica se o caractere é alfabético
            if (isalpha(t[i]))
            {
                // Guarda o valor ASCII do caractere
                int ascii = (int) t[i];
                
                // Verifica se o caractere é maiúsculo
                if (isupper(t[i]))
                {
                    // Redesigna os valos das letras como A-0, B-1, C-2, D-3, sucessivamente
                    int pi = ascii - 65;
                    
                    // Faz a rotação
                    int ci = ((pi + key) % 26) + 65;
                    
                    printf("%c", ci);
                }
                // Caso o caractere seja minusculo
                else
                {
                    // Redesigna os valos das letras como a-0, b-1, c-2, d-3, sucessivamente
                    int pi = ascii - 97;
                    
                    // Faz a rotação
                    int ci = ((pi + key) % 26) + 97;
                    
                    printf("%c", ci);
                }
            }
            // Caso não seja uma letra
            else
            {
                printf("%c", t[i]);
            }
        }
        
        printf("\n");
        
        return 0;
    }
}

// Verifica se uma string é numérica ou não
int isnumber(char c[])
{
    // Itera cada char de uma string, verificando se o char é um numero ou nao
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (!isdigit(c[i]))
        {
            // Caso algum dos chars na string não seja numerica, retorna como falso
            return 1;
            exit(1);
        }
    }
    
    return 0;
}
