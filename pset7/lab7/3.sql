-- lista os nomes de todas as músicas em ordem crescente de ritmo

SELECT name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;