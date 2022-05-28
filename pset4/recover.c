#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checa uso indevido
    if (argc != 2)
    {
        printf("Uso: ./recover file_name");

        return 1;
    }

    // Pointer para o arquivo fonte
    FILE *file = fopen(argv[1], "r");

    // Checa se o arquivo é valido
    if (file == NULL)
    {
        printf("O arquivo não pode ser aberto\n");

        return 1;
    }

    // Determina blocos de 512 bytes
    BYTE buffer[512];

    // Conta as imagens recuperadas
    int counter = 0;

    // Poiter para os arquivos de saída
    FILE *jpeg = NULL;

    // Pointer para o nome dos arquivos de saída
    char *filename = malloc(8 * sizeof(char));

    // Itera e lê o arquivo em blocos de 512 bytes
    while (fread(buffer, sizeof(BYTE), 512, file))
    {
        // Checa os 3 primeiros bytes, para ver se é o começo de um arquivo jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // Checa o 4 byte, para confirmar se é o começo de um jpeg
            if (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5
                || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb
                || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
            {
                // Gera os nomes dos aquivos jpeg
                sprintf(filename, "%03i.jpg", counter);

                // Escreve e recupera as imagens jpeg
                jpeg = fopen(filename, "w");

                // Atualiza a contagem de imagens recuperadas
                counter++;
            }
        }

        // Checa se o arquivo de saída foi usado
        if (jpeg != NULL)
        {
            fwrite(buffer, sizeof(char), 512, jpeg);
        }
    }

    // Fecha os arquivos que foram abertos
    fclose(file);
    fclose(jpeg);

    // Libera o espaço alocado por malloc
    free(filename);

    return 0;
}
