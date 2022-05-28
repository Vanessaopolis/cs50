import sys
import csv

def main():
    # Verifica uso incorreto
    if len(sys.argv) != 3:
        print("Usage: python dna.py file_data.csv file_sequence.txt")
        sys.exit(1)

    # Dicionario vazio para os dados do arquivo csv
    person = {}

    # Lista vazia para os STRs presentes no arquivo csv
    STRs = []

    STRrepetitions = []

    # Abre, lê e então fecha o arquivo csv
    with open(sys.argv[1], "r") as datafile:
        # Pega as informações da tabela
        reader = csv.reader(datafile)

        # Armazena os STRs analisados
        for row in reader:
            STRs = row[1 : ]
            break

        # Para cada linha, ou seja, cada pessoa, adiciona os dados ("nomes" : [repeticoes]) ao dicionario
        for row in reader:
            person[row[0]] = [int(x) for x in row[1 : ]]

    # Abre, lê e fecha o arquivo txt
    with open(sys.argv[2], "r") as sequencefile:
        # Armazena a sequencia na memoria
        sequence = sequencefile.read().strip()

    # Calcula e armazena a maxima repeticao de cada STR
    for STR in STRs:
        STR_maxrepetition = max_repetition(sequence, STR)

        STRrepetitions.append(STR_maxrepetition)
    
    find_dna(person, STRrepetitions)

def max_repetition(txt, key):
    # Declara variaveis
    i = 0
    j = i + len(key)
    maxi = 0

    # Iteracao para cada caractere em txt
    for c in range(len(txt)):
        # Reseta o valor de maximo de cada linha
        maxi_temp = 0

        if txt[i : j] == key:
            while txt[i : j] == key:
                maxi_temp += 1
                i += len(key)
                j += len(key)

                if maxi_temp > maxi:
                    maxi = maxi_temp
        else:
            i += 1
            j += 1
    return maxi

def find_dna(dictionary, array):
    # Procura, se houver, o array de repetições na lista de valores do dicionario
    values = dictionary.values()
    
    # Imprime caso nao haja correspondencia
    if array not in values:
        print("No match")
    
    # Caso contrario, encontra o nome da pessoa com a repeticao correspondente
    else:
        for key, value in dictionary.items():
            if value == array:
                print(key)

main()
