-- lista os nomes de todas as pessoas que estrelaram um filme lançado em 2004, ordenado por ano de nascimento

SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE year = 2004
GROUP BY name, person_id
ORDER BY birth;