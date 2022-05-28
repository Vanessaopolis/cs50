def main():
    # Declara as moedas para troco
    coins = [25, 10, 5, 1]
    
    # Define a quantidade de centavos a ser trocada
    c = cents()
    
    # Conta quantas moedas foram usadas
    counter = 0;
    
    # Itera para cada moeda atualizando a quantidade de moedas usadas e atualizando quanto sobrou do valor c
    for coin in coins:
        amount, c = divmod(c, coin)
        
        counter += amount
    
    # Imprime a quantidade de moedas
    print(counter)

# Pede ao usuario uma entrada float positiva
def cents():
    while True:
        cents = input("Change owed: ")

        if ispositivefloat(cents):
            break

    return int(float(cents) * 100)

# Checa se um texto pode ser convertido para float positivo
def ispositivefloat(num):
    try:
        float(num) and float(num) > 0
        if float(num) > 0:
            return True
        
        else:
            return False
    
    except ValueError:
        return False

main()
