-- determina a avaliação média de todos os filmes lançados em 2012

SELECT AVG (rating)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;