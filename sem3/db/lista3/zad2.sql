
CREATE INDEX idx_plec_imie ON Ludzie (plec, imie);
CREATE INDEX idx_pensja ON Pracownicy (pensja);

-- Kobiety, których imię zaczyna się na 'A'
SELECT * FROM Ludzie WHERE plec = 'K' AND imie LIKE 'A%';



-- Wszystkie kobiety
SELECT * FROM Ludzie WHERE plec = 'K';

-- Osoby, których imię zaczyna się na 'K'
SELECT * FROM Ludzie WHERE imie LIKE 'K%';

-- Osoby zarabiające poniżej 2000
SELECT * FROM Pracownicy WHERE pensja < 2000;
-- Informatycy płci męskiej zarabiający powyżej 10000

EXPLAIN SELECT * FROM Pracownicy P
JOIN Zawody Z ON P.zawod_id = Z.zawod_id
WHERE Z.nazwa = 'Informatyk' AND pensja > 10000 AND P.PESEL IN (SELECT PESEL FROM Ludzie WHERE plec = 'M');


--SELECT * FROM Ludzie WHERE plec = 'K' AND imie LIKE '%a';

--EXPLAIN SELECT imie FROM Ludzie WHERE plec = 'M' AND imie LIKE '%n';
