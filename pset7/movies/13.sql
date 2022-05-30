-- lista os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou

SELECT DISTINCT name
FROM stars
JOIN people ON stars.person_id = people.id
WHERE movie_id IN
(SELECT movie_id
FROM stars
JOIN people ON stars.person_id = people.id
WHERE name = "Kevin Bacon" AND birth = 1958)
AND name != "Kevin Bacon";