#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Protótipo das funções
int istext(char c[]);
int repetition(char c[]);

int main(int argc, string argv[])
{
    // Verifica se o usuário digitou a quantidade certa de chaves
    if (argc != 2)
    {
        printf("Uso: ./substitution key\n");
        
        return 1;
    }
    
    // Verifica se a chave tem 26 letras
    else if (strlen(argv[1]) != 26 || istext(argv[1]) != 0)
    {
        printf("The substitution key must have 26 letters\n");
        
        return 1;
    }
    
    // Verifica se todas as letras são diferentes umas das outras
    else if (repetition(argv[1]) != 0)
    {
        printf("All the letters must be different from each other\n");
        
        return 1;
    }
    
    // Caso a chave seja adequada
    else
    {
        // Recebe o texto a ser cifrado
        string t = get_string("plaintext: ");
        
        printf("ciphertext: ");
        
        // Itera todos os caracteres do texto, rotacionando os alfabéticos de acordo com a chave dada
        for (int i = 0, n = strlen(t); i < n; i++)
        {
            // Verifica se o caractere é alfabético
            if (isalpha(t[i]))
            {
                // Usa um valor referência como A,a - 0; B,b - 1; C,c - 2; D,d - 3, sucessivamente
                int aux = (int) toupper(t[i]) - 65;
                
                // Se o caractere for maiusculo, imprime, de acordo com a chave, a letra de saída tambem maiuscula
                if (isupper(t[i]))
                {
                    printf("%c", toupper(argv[1][aux]));
                }
                
                // Caso o caractere for minusculo, a saida será minuscula
                else
                {
                    printf("%c", tolower(argv[1][aux]));
                }
            }
            
            // Caso o caractere não seja alfabético, apenas o repete
            else
            {
                printf("%c", t[i]);
            }
        }
        printf("\n");
        
        return 0;
    }
}

// Verifica se uma string é alfabética ou não
int istext(char c[])
{
    // Itera cada char de uma string, verificando se o char é uma letra ou nao
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (!isalpha(c[i]))
        {
            // Caso algum dos chars na string não seja uma letra, retorna como falso
            return 1;
            exit(1);
        }
    }
    
    return 0;
}

// Verifica se há repetições em um texto apenas com letras
int repetition(char c[])
{
    // Gera um vetor com 26 posições iguais a 0, para auxiliar na contagem das aparições das letras
    int quantidade[26] = {0};
    
    // Itera cada um dos caracteres da chave, somando 1 quantidade na posição da letra, a cada aparição
    for (int i = 0; i < 26; i++)
    {
        int pi = (int) toupper(c[i]) - 65;
        
        quantidade[pi]++;
    }
    
    // Checa o array quantidade se alguma posição é diferente de 1, sendo assim, uma letra foi repetida
    for (int i = 0; i < 26; i++)
    {
        if (quantidade[i] != 1)
        {
            return 1;
            exit(1);
        }
    }
    
    return 0;
}
