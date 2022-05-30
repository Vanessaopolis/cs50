-- lista todos os filmes lançados em 2010 e suas classificações,em ordem decrescente por classificação. Para filmes com a mesma classificação,
-- ordena-os em ordem alfabética por título.

SELECT title, rating
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE year = 2010
ORDER BY rating DESC, title ASC;