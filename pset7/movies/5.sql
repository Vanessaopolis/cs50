-- lista os títulos e anos de lançamento de todos os filmes de Harry Potter, em ordem cronológica.

SELECT title, year
FROM movies
WHERE title LIKE "Harry Potter%"
ORDER BY year;