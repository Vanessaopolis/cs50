--  lista os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos

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