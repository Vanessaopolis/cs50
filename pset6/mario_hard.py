def main():
    # Define a altura
    h = height()

    # Itera cada degrau da escada
    for row in range(h):

        # Alinha os degraus da primeira escada à direita
        print(" " * (h - row - 1), end="")

        # Imprime os blocos dos degraus da primeira escada
        print("#" * (row + 1), end="")

        # Imprime a segunda escada
        print(" " * 2 + "#" * (row + 1), end="")

        print()

# Guarda a altura da escada
def height():
    while True:

        # Pede ao usuario para informar a altura
        height = input("Height: ")

        # Checa se a altura é entre 1 e 8
        if "1" <= height <= "8":
            break

    return int(height)

main()
