-- lista os nomes de quaisquer músicas que tenham dançabilidade, energia e valência maior que 0.75

SELECT name
FROM songs
WHERE danceability > 0.75
AND energy > 0.75
AND valence > 0.75;