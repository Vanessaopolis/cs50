#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de eleitores e de candidatos
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] é j-esima preferencia para o eleitor i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidatos tem nome, votos e status de eliminação
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array de candidatos
candidate candidates[MAX_CANDIDATES];

// Numero de eleitores e de candidatos
int voter_count;
int candidate_count;

// Prototipos de funções
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Verifica por uso incorreto
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Alimenta array de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Iteração para cada eleitor
    for (int i = 0; i < voter_count; i++)
    {

        // Iteração para cada posição de voto
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Registra voto, a não ser que seja invalido
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Continua a verificar os votos, até que haja vencedor
    while (true)
    {
        // Calcula votos de candidatos restantes
        tabulate();

        // Verifica se a eleição tem vencedor
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Registra o menor número de votos e caso de empate
        int min = find_min();
        bool tie = is_tie(min);

        // Se tiver empate, todos os candidatos restantes ganham
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Elimina todo candidato com o menor número de votos, em caso de não empate
        eliminate(min);

        // Reseta a quantidade de votos para 0 para todos os candidatos restantes
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Valida o voto
bool vote(int voter, int rank, string name)
{
    // Itera, para cada eleitor, comparando se o voto de cada posição é válido
    for (int i = 0; i < candidate_count; i++)
    {
        // Caso seja válido, alimenta o array 2D preferences[i][j] com o indice o candidato
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;

            return true;
        }
    }

    return false;
}

// Tabula o voto de cada candidato
void tabulate(void)
{
    // Itera todo o arrau 2D de preferencias de voto, a procura do candidato em maior posição que não tenha sido eliminado, escolhido por cada eleitor
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // Assim que o candidato não eliminado é encontrado, seu voto aumento em 1
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;

                break;
            }
        }
    }
    return;
}

// Se houver, informa o ganhador da eleição
bool print_winner(void)
{
    // Compara a quantidade de votos de cada candidato restante com a metade de eleitores, caso seja suficiente, é declarado o candidato vencedor
    int half = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > half)
        {
            printf("%s\n", candidates[i].name);

            return true;
        }
    }
    return false;
}

// Retorna a menor quantidade de votos que um candidato tenha
int find_min(void)
{
    // Entre todos os candidatos restante, varre um por um, comparando a quantidade de votos
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Verifica se a eleição está empatada, ou não, entre todos os candidatos restantes
bool is_tie(int min)
{
    // TODO
    int tied = 0;
    int eliminated = 0;


    for (int i = 0; i < candidate_count; i++)
    {
        // A cada candidato já eliminado a variavel eliminated aumenta em 1
        if (candidates[i].eliminated)
        {
            eliminated++;
        }
        // A cada candidato restante que possua votos iguais ao menor valor min a variavel tied aumenta em 1
        else
        {
            if (candidates[i].votes == min)
            {
                tied++;
            }
        }
    }

    // Caso a soma do numero de empatados e de eliminados seja igual a quantidade total de candidatos, significa que os restantes estão, todos, empatados
    if (tied + eliminated == candidate_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Elimina todos os candidatos que possuam a menor quantidade de votos
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
