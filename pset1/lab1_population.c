#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Pede ao usuario um valor inicial e continua a pedir se o valor for menor que 9
    int inicial;
    do
    {
        inicial = get_int("Tamanho inicial da população: ");
    }
    while (inicial < 9);

    // Solicita, então, o valor final da populacao e continua caso seja menor que o valor inicial
    int final;
    do
    {
        final = get_int("Tamanho final da população: ");
    }
    while (final < inicial);

    // Acompanha os anos
    int anos = 0;
    
    // Loop enquanto a populacao inicial for menor que a final
    while (inicial < final)
    {
        // Atualiza o valor inicial e a quantidade de anos
        inicial += ((inicial / 3) - (inicial / 4));
        anos++;
    }

    // Imprime quantos anos seriam para que a populacao cresca até o valor final
    printf("Years: %i\n", anos);
}
