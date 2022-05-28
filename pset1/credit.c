#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Pede e armazena o possivel numero do cartao de credito
    long numero = get_long("Número: ");
    
    // Cria cópia
    long cartao = numero;

    // Descarta os números fora do intervalo aceito (diferentes de tamanho 16 15 ou 13)
    if (cartao < 1000000000000 || cartao > 9999999999999999 || (cartao >= 10000000000000 && cartao <= 99999999999999))
    {
        printf("INVALID\n");
    }
    else
    {
        // Começa a soma dos digitos do número do cartão
        int soma = 0;

        // Guarda a posição dos digitos, para fazer a operação adequada
        int posicao = 0;

        while (cartao > 0)
        {
            // Guarda o último digito do cartão
            int digito = cartao % 10;
            
            // Começa a somar os valores que estao na ultima posicao e a cada 2 casas
            if (posicao % 2 == 0)
            {
                soma += digito;
            }
            
            // Atualiza a soma para os valores que estao na penultima posicao e a cada 2 casas
            else
            {
                // Multiplica o valor por 2 e entao soma cada digito do resultado
                digito *= 2;

                if (digito >= 10)
                {
                    soma += digito % 10;
                    soma++;
                }
                else
                {
                    soma += digito;
                }
            }

            // Retira o ultimo digito do número do cartão e sobe uma posição
            cartao = cartao / 10;
            posicao++;
        }

        // Testa o Algoritmo de Luhn
        if (soma % 10 == 0)
        {
            // Testa o primeiro numero caso o cartão tenha 13 digitos, VISA
            if (posicao == 13)
            {
                numero = numero / 1000000000000;

                if (numero == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }

            // Testa os dois primeiros digitos caso o cartao tenha 15 digitos, AMERICAN EXPRESS
            else if (posicao == 15)
            {
                numero = numero / 10000000000000;

                if (numero == 34 || numero == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }

            // E caso o cartao tenha 16 digitos, testa os dois primeiros, VISA ou MASTERCARD
            else
            {
                numero = numero / 100000000000000;

                if (numero >= 40 && numero < 50)
                {
                    printf("VISA\n");
                }
                else if (numero > 50 && numero <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        
        // Caso nao pertença a nenhuma bandeira, o numero é invalido
        else
        {
            printf("INVALID\n");
        }
    }
}
