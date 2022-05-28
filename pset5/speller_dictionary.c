// Implementa a funcionalidade do dicionario

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Define o nó de uma tabela hah
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Contador para quantidade de palavras do dicionario
int counter = 0;

// Numero de ramificações da tabela hash
const unsigned int N = 26;

// Gera a tabela hash
node *table[N];

// Retorna true se a palavra estiver no dicionario, caso contrario, retorna false
bool check(const char *word)
{
    // Retorna o valor hash da palavra
    int index = hash(word);
    
    // Varre todo a lista de palavras com valor hash iguais, a procura da palavra word
    for (node *aux = table[index]; aux != NULL; aux = aux->next)
    {
        if (strcasecmp(aux->word, word) == 0)
        {
            return true;
        }
    }
    
    return false;
}

// Converte a palavra em um numero correspondente, para adiciona-la na tabela hash
unsigned int hash(const char *word)
{
    // Variavel para soma, apenas positivo
    unsigned long sum = 0;
    
    // Itera todas as letras da palvra, somando o valor ASCII de cada caractere
    for (int i = 0; i < strlen(word); i++)
    {
        sum += toupper(word[i]);
    }
    
    return sum % N;
}

// Carrega o dicionario para a memoria, retorna true se sucesso, caso contrario, retorna false
bool load(const char *dictionary)
{
    // Abre o arquivo dicionário no modo reading "r"
    FILE *file = fopen(dictionary, "r");
    
    // Checa se foi possivel abrir o arquivo ou não
    if (file == NULL)
    {
        printf("Could not open dictionary\n");
        
        return false;
    }
    // Determina a variavel word dentro da função
    char word[LENGTH + 1];
    
    // Itera todas as palavras no dicionario
    while (fscanf(file, "%s", word) != EOF)
    {
        // Aloca memoria para um novo nó e checa se a memoria foi alocada adequamente
        node *head = malloc(sizeof(node));
        if (head != NULL)
        {
            // Copia determinada palavra para o nó
            strcpy(head->word, word);
            
            // Retorna a posição da palavra na tabela hash
            int index = hash(word);
            
            // Definimos o ponteiro para a "cabeça"
            head->next = table[index];
                
            // E então toma o seu lugar
            table[index] = head;
            
            // Atualiza a contagem de palavras
            counter++;
        }
        
        // Retorna falso caso nao seja possivel alocar a memoria
        else
        {
            return false;
        }
    }
    // Fecha o arquivo aberto
    fclose(file);
    
    return true;
}

// Retorna o numero de palavras no dicionario
unsigned int size(void)
{
    // Retorna a variavel counter que é atualizada a cada nova palavra carregada
    return counter;
}

// Descarrega o dicionario da memoria, liberando o espaço alocado
bool unload(void)
{
    // Repete e limpa todas as listas de cada linha da tabela hash
    for (int i = 0; i < N; i++)
    {
        // Libera cada nó da linha
        while (table[i] != NULL)
        {
            // Definimos um nó auxiliar para apontar para o segundo nó
            node *aux = table[i]->next;
            
            // Liberamos a memória usada pro primeiro nó
            free(table[i]);
            
            // Fazemos, então, a lista apontar para o próximo nó
            table[i] = aux;
        }
    }
    
    return true;
}
