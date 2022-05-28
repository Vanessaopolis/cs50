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

// Detecta contornos
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copia a imagem
    RGBTRIPLE img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = image [i][j];
        }
    }

    // Varre toda linha e coluna de pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Faz os calculos para os pixels na primeira linha, separando em primeiro coluna, ultima coluna e demais colunas respectivamente
            if (i == 0)
            {
                if (j == 0)
                {
                    int redx = 2 * img[i][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int redy = 2 * img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = 2 * img[i][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int greeny = 2 * img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = 2 * img[i][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int bluey = 2 * img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else if (j == width - 1)
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed;
                    int redy = 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen;
                    int greeny = 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue;
                    int bluey = 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed + 2 * img[i][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int redy = 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen + 2 * img[i][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int greeny = 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue + 2 * img[i][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int bluey = 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

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

            // Pixels que estão na ultima linha, separando-os em primeira coluna, ultima coluna e demais colunas, respectivamente
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    int redx = 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed;
                    int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen;
                    int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue;
                    int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else if (j == width - 1)
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed;
                    int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen;
                    int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue;
                    int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                    if (blue <= 255)
                    {
                        image[i][j].rgbtBlue = blue;
                    }
                    else
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }

                else
                {
                    int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed + 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed;
                    int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i - 1][j + 1].rgbtRed;
                    int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                    if (red <= 255)
                    {
                        image[i][j].rgbtRed = red;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 255;
                    }

                    int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen + 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen;
                    int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i - 1][j + 1].rgbtGreen;
                    int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                    if (green <= 255)
                    {
                        image[i][j].rgbtGreen = green;
                    }
                    else
                    {
                        image[i][j].rgbtGreen = 255;
                    }

                    int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue + 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue;
                    int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i - 1][j + 1].rgbtBlue;
                    int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

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

            // Primeira coluna
            else if (j == 0)
            {
                int redx = 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j + 1].rgbtRed + 2 * img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                if (red <= 255)
                {
                    image[i][j].rgbtRed = red;
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                int greenx = 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j + 1].rgbtGreen + 2 * img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                if (green <= 255)
                {
                    image[i][j].rgbtGreen = green;
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                int bluex = 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j + 1].rgbtBlue + 2 * img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                if (blue <= 255)
                {
                    image[i][j].rgbtBlue = blue;
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }

            // Ultima coluna
            else if (j == width - 1)
            {
                int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed;
                int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed + 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed;
                int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                if (red <= 255)
                {
                    image[i][j].rgbtRed = red;
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen;
                int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen + 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen;
                int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                if (green <= 255)
                {
                    image[i][j].rgbtGreen = green;
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue;
                int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j - 1].rgbtBlue + 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue;
                int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

                if (blue <= 255)
                {
                    image[i][j].rgbtBlue = blue;
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }

            // Pixels fora da borda
            else
            {
                int redx = -2 * img[i][j - 1].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i + 1][j - 1].rgbtRed + 2 * img[i][j + 1].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int redy = -2 * img[i - 1][j].rgbtRed - img[i - 1][j - 1].rgbtRed - img[i - 1][j + 1].rgbtRed + 2 * img[i + 1][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j + 1].rgbtRed;
                int red = round(sqrt(pow(redx, 2) + pow(redy, 2)));

                if (red <= 255)
                {
                    image[i][j].rgbtRed = red;
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                int greenx = -2 * img[i][j - 1].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i + 1][j - 1].rgbtGreen + 2 * img[i][j + 1].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int greeny = -2 * img[i - 1][j].rgbtGreen - img[i - 1][j - 1].rgbtGreen - img[i - 1][j + 1].rgbtGreen + 2 * img[i + 1][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j + 1].rgbtGreen;
                int green = round(sqrt(pow(greenx, 2) + pow(greeny, 2)));

                if (green <= 255)
                {
                    image[i][j].rgbtGreen = green;
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                int bluex = -2 * img[i][j - 1].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i + 1][j - 1].rgbtBlue + 2 * img[i][j + 1].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int bluey = -2 * img[i - 1][j].rgbtBlue - img[i - 1][j - 1].rgbtBlue - img[i - 1][j + 1].rgbtBlue + 2 * img[i + 1][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j + 1].rgbtBlue;
                int blue = round(sqrt(pow(bluex, 2) + pow(bluey, 2)));

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
    }
    return;
}
