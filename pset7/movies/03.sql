-- lista os títulos de todos os filmes com data de lançamento igual ou posterior a 2018, em ordem alfabética

SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title;
