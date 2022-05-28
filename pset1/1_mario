#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Usuário define a altura da escada
    int altura;
    
    // Loop tipo while do para validação
    do
    {
        altura = get_int("Altura: ");
    }
    
    // Condição de validação da altura
    while (altura < 1 || altura > 8);

    // Construção da escada
    for (int linha = 0; linha < altura; linha++)
    {
        // Imprime os espaços em brancos para alinhamento à esquerda
        for (int coluna = 0; coluna + linha < altura - 1; coluna++)
        {
            printf(" ");
        }

        // Insere os blocos da escada
        for (int coluna = 0; coluna < linha + 1; coluna++)
        {
            printf("#");
        }
        printf("\n");
    }
}
