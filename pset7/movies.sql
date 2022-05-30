-- 1.sql: lista os títulos de todos os filmes lançados em 2008
SELECT title
FROM movies
WHERE year = 2008;

-- 2.sql: determina o ano de nascimento de Emma Stone
SELECT birth
FROM people
WHERE name = "Emma Stone";

-- 3.sql: lista os títulos de todos os filmes com data de lançamento igual ou posterior a 2018, em ordem alfabética
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title;

-- 4.sql: determina o número de filmes com uma classificação IMDb de 10,0
SELECT COUNT (rating)
FROM ratings
WHERE rating = 10.0;

-- 5.sql: lista os títulos e anos de lançamento de todos os filmes de Harry Potter, em ordem cronológica.
SELECT title, year
FROM movies
WHERE title LIKE "Harry Potter%"
ORDER BY year;

-- 6.sql: determina a avaliação média de todos os filmes lançados em 2012
SELECT AVG (rating)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;

-- 7.sql: lista todos os filmes lançados em 2010 e suas classificações,em ordem decrescente por classificação.
-- Para filmes com a mesma classificação, ordena-os em ordem alfabética por título.
SELECT title, rating
FROM movies
JOIN ratings ON ratings.movie_id = movies.id
WHERE year = 2010
ORDER BY rating DESC, title ASC;

--  8.sql: lista os nomes de todas as pessoas que estrelaram Toy Story
SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE title = "Toy Story";

-- 9.sql: lista os nomes de todas as pessoas que estrelaram um filme lançado em 2004, ordenado por ano de nascimento
SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE year = 2004
GROUP BY name, person_id
ORDER BY birth;

-- 10.sql: lista os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0
SELECT name
FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE rating >= 9.0
GROUP BY name, person_id;

-- 11.sql: lista os títulos dos cinco filmes com melhor classificação (em ordem) que Chadwick Boseman estrelou, começando com os de maior classificação
SELECT title
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON ratings.movie_id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;

--  12.sql: lista os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos
SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Johnny Depp"
INTERSECT 
SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name ="Helena Bonham Carter";

-- 13.sql: lista os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou
SELECT DISTINCT name
FROM stars
JOIN people ON stars.person_id = people.id
WHERE movie_id IN
(SELECT movie_id
FROM stars
JOIN people ON stars.person_id = people.id
WHERE name = "Kevin Bacon" AND birth = 1958)
AND name != "Kevin Bacon";
