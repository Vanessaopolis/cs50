#include <math.h>
#include "helpers.h"

// Converte a imagem para tons de cinza
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Percorre toda linha e coluna de pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Recolhe as informações de cada pixel, do canal de cada cor
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calcula e substitui todo canal de cor pela média dos valores calculados antes
            int average = round((red + green + blue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Converte imagem para escala sépia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Cria copia da imagem
    RGBTRIPLE img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = image[i][j];
        }
    }

    // Calcula para cada pixel os novos valores dos canais vermelho, verde e azul
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round(0.393 * img[i][j].rgbtRed + 0.769 * img[i][j].rgbtGreen + 0.189 * img[i][j].rgbtBlue);
            int green = round(0.349 * img[i][j].rgbtRed + 0.686 * img[i][j].rgbtGreen + 0.168 * img[i][j].rgbtBlue);
            int blue = round(0.272 * img[i][j].rgbtRed + 0.534 * img[i][j].rgbtGreen + 0.131 * img[i][j].rgbtBlue);

            if (red <= 255)
            {
                image[i][j].rgbtRed = red;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (green <= 255)
            {
                image[i][j].rgbtGreen = green;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (blue <= 255)
            {
                image[i][j].rgbtBlue = blue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflete a imagem horizontalmente
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Percorre todas as linhas de pixel
    for (int i = 0; i < height; i++)
    {
        // Define uma variavel auxiliar aux
        RGBTRIPLE aux;

        // Define os limites iniciais para fazer a troca de posicao dos pixels em cada linha
        int start = 0;
        int end = width - 1;

        while (start < end)
        {
            // A variavel auxiliar copia o pixel inicial
            // O pixel inicial então copia o pixel final
            // Finalizando a troca, o pixel final copia o pixel auxiliar
            aux = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = aux;

            // Os valores de start e end sao atualizados após cada troca
            start++;
            end--;
        }
    }
    return;
}

// Desfoca imagem
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Gera uma copia da imagem para que os calculos fiquem corretos
    RGBTRIPLE img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = image[i][j];
        }
    }

    // Itera cada linha e coluna de pixel, fazendo a média dos valores dos canais de cores com uma margem de 1 pixel para cada lado
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Analisa os pixels que estao na primeira linha
            if (i == 0)
            {
                // E na primeira coluna
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 4.0);
                }

                // E na ultima coluna
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue) / 4.0);
                }

                // No "meio" da linha
                else
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 6.0);
                }
            }

            // Pixels que estao na ultima linha
            else if (i == height - 1)
            {
                // E primeira coluna
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue) / 4.0);
                }

                // E ultima coluna
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue) / 4.0);
                }

                // Meio da linha
                else
                {
                    image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i][j + 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j - 1].rgbtRed + img[i - 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j + 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j + 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue) / 6.0);
                }
            }

            // Pixels que estão na primeira coluna, sem incluir os que estao na primeira e ultima linha
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            // Pixels que estão na ultima coluna, sem incluir os que estao na primeira e ultima linha
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue) / 6.0);
            }

            // Os pixels do meio, ou seja, os que não estão na borda da imagem
            else
            {
                image[i][j].rgbtRed = round((img[i][j].rgbtRed + img[i - 1][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i][j - 1].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = round((img[i][j].rgbtGreen + img[i - 1][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = round((img[i][j].rgbtBlue + img[i - 1][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }
    return;
}
