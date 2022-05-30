-- lista os nomes das músicas que apresentam “feat.” (participação) de outros artistas

SELECT name
FROM songs
WHERE name LIKE "%feat.%";