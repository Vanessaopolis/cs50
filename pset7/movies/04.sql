-- determina o número de filmes com uma classificação IMDb de 10,0

SELECT COUNT (rating)
FROM ratings
WHERE rating = 10.0;
