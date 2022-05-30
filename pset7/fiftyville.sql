-- Mantem um registro de todas as consultas SQL executadas

-- Consulta os relatórios da tabela crime_scene_reports
-- Lista a descrição da cena do crime do dia do roubo da rua Chamberlin Street
SELECT description
FROM crime_scene_reports
WHERE year = 2020
AND month = 7
AND day = 28
AND street = "Chamberlin Street";
    -- Descrição: Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
    -- Interviews were conducted today with three witnesses who were present at the time
    -- each of their interview transcripts mentions the courthouse.

-- Consulta as entrevistas da tabela interviews
-- Levanta os testemunhos do dia do roubo que citaram a palavra "courthouse"
SELECT name, transcript
FROM interviews
WHERE year = 2020
AND month = 7
AND day = 28
AND transcript LIKE "%courthouse%";
    -- Testemunho 1: I don't know the thief's name, but it was someone I recognized. Earlier this morning,
    -- before I arrived at the courthouse, I was walking by the ATM on Fifer Street
    -- and saw the thief there withdrawing some money.

    -- Testemunho 2: As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
    -- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    -- The thief then asked the person on the other end of the phone to purchase the flight ticket.

    -- Testemunho 3: Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
    -- If you have security footage from the courthouse parking lot,
    -- you might want to look for cars that left the parking lot in that time frame.


-- Consulta as pessoas da tabela people e as movimentações da tabela courthouse_security_logs
-- Enumera o nome do dono das contas bancárias que tiraram dinheiro no caixa da rua Fifer Street no dia do roubo
-- Informações tiradas do testemunho 1
SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2020
AND month = 7
AND day = 28
AND atm_location = "Fifer Street"
AND transaction_type = "withdraw"
ORDER BY name;
    -- Suspeitos: Bobby, Danielle, Elizabeth, Ernest, Madison, Roy, Russell, Victoria

-- Consulta as pessoas da tabela people e as ligacoes da tabela phone_calls
-- Lista todas as pessoas que fizeram ligações de menos de 1min no dia do crime
-- Informações tiradas do testemunho 2
SELECT name
FROM people
WHERE phone_number IN (SELECT caller
FROM phone_calls
WHERE year = 2020
AND month = 7
AND day = 28
AND duration < 60)
ORDER BY name;
    -- Suspeitos: Bobby, Ernest, Evelyn, Kimberly, Madison, Roger, Russell, Victoria

-- Retorna o horário do primeiro voo que saiu de Fiftyville no dia após o roubo
SELECT hour, minute
FROM flights
WHERE year = 2020
AND month = 7
AND day = 29
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1;
    -- Horario: 8:20

-- Consulta as pessoas da tabela people, os passageiros da tabela passengers e os voos da tabela flights
-- Enumera os passageiros do primeiro voo que saiu de Fiftyville no dia após o roubo
-- Informações tiradas do testemunho 2
SELECT name
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE year = 2020
AND month = 7
AND day = 29
AND hour = 8
AND minute = 20
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY name;
    -- Suspeitos: Bobby, Danielle, Doris, Edward, Ernest, Evelyn, Madison, Roger

-- Consulta as pessoas da tabela people e os registros da tabela courthouse_security_logs
-- Enumera o nome do dono das placas que deixaram o tribunal dentro do tempo de 10min após o roubo
-- Informações tiradas do testemunho 3
SELECT name
FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020
AND month = 7
AND day = 28
AND hour = 10
AND minute > 15
AND minute <= 25
AND activity = "exit"
ORDER BY name;
    -- Suspeitos: Amber, Danielle, Elizabeth, Ernest, Evelyn, Patrick, Roger, Russell

-- Por meio de intersect, podemos saber que o único nome comum em todas as procuras é Ernest

-- Consulta as pessoas da tabela people e as ligacoes da tabela phone_calls
-- Encontra a pessoa para quem Ernest ligou no dia do roubo
SELECT name
FROM people
WHERE phone_number IN (SELECT receiver
FROM phone_calls
WHERE year = 2020
AND month = 7
AND day = 28
AND duration < 60
AND caller IN(SELECT phone_number
FROM people
WHERE name = "Ernest"));
    -- Cumplice: Berthold

-- Consulta as cidades da tabela airports e voos da tabela flights
-- Retorna o destino do voo em que o ladrão saiu de Fiftyville
SELECT city
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE year = 2020
AND month = 7
AND day = 29
AND hour = 8
AND minute = 20
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville");
    -- Destino: London
