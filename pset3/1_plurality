#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos
#define MAX 9

// Candidatos têm nome e contagem dos votos
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array dos candidatos
candidate candidates[MAX];

// Número de candidatos
int candidate_count;

// Protótipos das funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifica uso incorreto
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Alimenta array dos candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Iteração para cada um dos eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verifica voto inválido
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Informa o ganhador da eleição
    print_winner();
}

// Atualiza a contagem de votos
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Compara o nome votado com os nomes dos candidatos, se forem iguais, a função soma +1 voto e retorna verdadeiro
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;

            return true;
        }
    }

    return false;
}

// Informa o ganhador, ou ganhadores, da eleição
void print_winner(void)
{
    // Começa a contagem da maior quantidade de votos
    int x = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        // Verifica se a quantidade de votos em determinado candidato é maior que a quantidade já guardada x
        if (candidates[i].votes > x)
        {
            x = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        // Imprime todo candidato que possua o número de votos igual à maior quantidade de votos x
        if (candidates[i].votes == x)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
