#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Usuário define a altura da escada
    int altura;
    
    do
    {
        altura = get_int("Altura: ");
    }
    // Validação da altura (entre 1 e 8)
    while (altura < 1 || altura > 8);

    // Construção da escada
    for (int linha = 0; linha < altura; linha++)
    {
        // Escada alinhada à direita
        for (int coluna = 0; coluna < altura; coluna++)
        {
            if (coluna + linha < altura - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");

        // Escada alinha à esquerda
        for (int coluna = 0; coluna < linha + 1; coluna++)
        {
            printf("#");
        }
        printf("\n");
    }
}
