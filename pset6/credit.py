def main():
    # Pede numero de cartao ao usuario
    number = card()

    # Se nao se adequar aos criterios, invalida o numero
    if number == 1:
        print("INVALID")

    else:
        # Verifica se o numero é aceito pelo algoritimo de Luhn
        if luhn(number):
            digits = len(number)
            # Verifica se é um cartao VISA
            if int(number[0]) == 4 and (digits == 13 or digits == 16):
                print("VISA")

            # Verifica se é um cartao MASTERCARD
            elif 51 <= int(number[0 : 2]) <= 55 and digits == 16:
                print("MASTERCARD")

            # Verifica se é um cartao AMEX
            elif (int(number[0 : 2]) == 34 or int(number[0 : 2]) == 37) and digits == 15:
                print("AMEX")

        # Caso nao passe pelo algoritimo de Luhn, o numero é invalidado
        else:
            print("INVALID")

# Prompt usuario até que digite uma entrada numerica
def card():
    while True:
        card = input("Number: ")

        # Checa se a entrada confere com um possivel cartao de credito
        if card.isdigit() and int(card) > 0:
            if 15 <= len(card) <= 16 or len(card) == 13:
                return card

                break

            else:
                return 1

# Passa o numero de cartao pelo algoritimo de Luhn para validaçao
def luhn(num):
    # Guarda o tamanho do numero
    digits = len(num)

    # Prepara para a soma de verificaçao
    total = 0

    # Itera do penultimo ate o ultimo elemento, em passo de 2
    for i in range(digits - 2, -1, -2):

        T = str(int(num[i]) * 2)

        # Adiciona à total cada digito do resultado da multiplicacao de cada elemento por 2
        for t in T:
            total += int(t)

    # Itera do último ate o ultimo elemento, em passo de 2
    for i in range(digits - 1, -1, -2):
        # Adiciona cada elemento à total
        total += int(num[i])

    # Verifica se o ultimo difito de total é 0
    if total % 10 == 0:
        return True

    else:
        return False

main()
