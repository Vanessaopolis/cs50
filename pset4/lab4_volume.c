// Modifica o volume de um arquivo de audio

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef int16_t SAMPLE;

// Numero de bytes no cabeçalho de um arquivo .wav
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Verifica os argumentos
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abre os arquivos e determina o fator de mudança de volume
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copia o cabeçalho do arquivo de entrada e para o arquivo de saida
    BYTE header[HEADER_SIZE];

    fread(header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output);

    // Lê cada sample do arquivo de entrada, atualiza de acordo com o fator e então escreve no arquivo de saída
    SAMPLE buffer;

    while(fread(&buffer, sizeof(SAMPLE), 1, input))
    {
        buffer *= factor;

        fwrite(&buffer, sizeof(SAMPLE), 1, output);
    }

    // Fecha arquivos abertos
    fclose(input);
    fclose(output);
}
