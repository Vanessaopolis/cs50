// Simula herança genetica do tipo de sangue

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a estrutura de person, com 2 pais e 1 par de alelos
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

// Define a quantidade de gerações presentes na simulação
const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Gera numero aleatorio
    srand(time(0));

    // Cria uma nova familia com GENERATIONS gerações
    person *p = create_family(GENERATIONS);

    // Informa a arvore genetica da familia
    print_family(p, 0);

    // Libera memoria alocada
    free_family(p);
}

// Cria um novo individeo da familia até ter GENERATIONS gerações
person *create_family(int generations)
{
    // Aloca memoria para pessoa p
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        exit(1);
    }

    // Lida com individuos com informaçoes sobre os pais
    if (generations > 1)
    {
        // Chama a função create_family de novo, para os pais da pessoa p
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);
        
        // Determina aleatoriamente os alelos de acordo com o alelos dos pais da pessoa p
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }

    // E então com o individuo sem informaçoes dos pais
    else
    {
        // Determina os pais como NULL
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        
        // Gera alelos aleatorios
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    // Retorna pessoa p
    return p;
}

// Libera memoria de todo individuo da familia
void free_family(person *p)
{
    // Caso a pessoa p esteja vazia, a funcao retorna vazia 
    if (p == NULL)
    {
        return;
    }
    // A função é chamada pra liberar cada um dos pais
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    
    // Libera, por fim, a propria pessoa
    free(p);
}

// Imprime cada individuo e seu tipo sanguineo
void print_family(person *p, int generation)
{
    // Lida com base nula
    if (p == NULL)
    {
        return;
    }

    // Imprime identação
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Imprime individuo
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Escolhe, aleatoriamente, o alelo
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
