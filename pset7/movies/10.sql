-- lista os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0

SELECT name
FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE rating >= 9.0
GROUP BY name, person_id;