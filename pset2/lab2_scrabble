#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Pontos atribuídos a cada letra do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Recebe as palavras de cada jogador
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Computador a pontuação de cada palavra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Imprime o vencedor de acordo com a pontuação ou informa empate
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Acompanha a pontuação, inicia em 0
    int score = 0;
    
    // Pra cada caractere da palavra, verifica se é alfabetico, determine o indice e soma a pontuação
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            int pi = (int) toupper(word[i]) - 65;
            
            score += POINTS[pi];
        }
    }
    
    return score;
}
