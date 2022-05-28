# Simula um torneio esportiva

import csv
import sys
import random

# Numero de simulações
N = 1000


def main():

    # Verifica uso e argumentos
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    
    # Lê o arquivo de entrada e carrega para a memoria as informações dos times e suas pontuações
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        
        for row in reader:
            team = row["team"]
            rating = int(row["rating"])
            teams.append({"team" : team, "rating" : rating})
    
    counts = {}
    
    # Simula N torneios e atualiza o dicionario counts para contar quantas vezes cada país foi ganhador
    for i in range(N):
        champion = simulate_tournament(teams)
        
        if champion in counts:
            counts[champion] += 1
        
        else:
            counts[champion] = 1
    
    
    # Imprime a chance de cada pais de ganhar, de acordo com as N simulações
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

# Simula um jogo, entre dois times. Retorna true se o time 1 for vencedor, e false se o time 2 for vencedor
def simulate_game(team1, team2):
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

# Simula uma etapa. Retorna uma lista com o time ganhador de cada dupla
def simulate_round(teams):
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners

# Simula um torneio, retorna apenas um time vencedor
def simulate_tournament(teams):
    # Continua a chamar simulate_round() até que não haja mais duplas
    while len(teams) > 1:
        teams = simulate_round(teams)
    
    # Retorna o nome do time vencedor
    winner = teams[0]["team"]
    return winner

if __name__ == "__main__":
    main()
