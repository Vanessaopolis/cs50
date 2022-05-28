#include <cs50.h>
#include <stdio.h>
#include <math.h>

int min_moedas(int n);

int main(void)
{
    // Recebe a quantia do troco
    float valor;
    do
    {
        valor = get_float("Valor de troca: ");
    }
    // Condição do troco ser positivo
    while (valor < 0);

    // Quantidade de centavos
    int centavos = round(valor * 100);
    
    // Calcula a quantidade minima de moedas usada para o troco
    int minimo = min_moedas(centavos);
    
    // Informa a quantidade
    printf("%i\n", minimo);
}


int min_moedas(int n)
{
    // Contador para quantidade de moedas usadas
    int moedas = 0;
    
    // Array com os valores em centavos das moedas usadas para troca
    int valores[] = {25, 10, 5, 1};
    
    // Itera por cada um dos valores somando a variavel moedas a maior quantidade possivel daquele valor especifico
    for (int i = 0; i < 4; i++)
    {
        moedas += n / valores[i];
        
        // Atualiza o valor do argumento n
        n -= n / valores[i] * valores[i];
    }
    
    // Retorna a quantidade de moedas
    return moedas;
}
