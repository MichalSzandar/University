
PREPARE liczba_kobiet FROM 'SELECT COUNT(*)
                            FROM Ludzie
                            JOIN Pracownicy ON Ludzie.pesel = Pracownicy.pesel
                            JOIN Zawody ON Pracownicy.zawod_id = Zawody.zawod_id
                            WHERE Ludzie.plec = "K" AND Zawody.nazwa = ?';

SET @nazwa = 'Lekarz';
EXECUTE liczba_kobiet USING @nazwa;