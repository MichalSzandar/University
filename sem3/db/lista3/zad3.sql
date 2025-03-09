

CREATE PROCEDURE give_raise(IN nazwa_zawodu VARCHAR(50))
BEGIN

    DECLARE max_pensja FLOAT;
    
    DECLARE exceeds_max BOOLEAN DEFAULT FALSE;
    
    DECLARE zawod_id_number INT;
    
    START TRANSACTION;
    
    SELECT zawod_id, pensja_max INTO zawod_id_number, max_pensja
    FROM Zawody
    WHERE nazwa = nazwa_zawodu;
    
    IF zawod_id_number IS NULL THEN
        -- Zgłoszenie błędu, jeśli zawód nie istnieje
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Nie ma takiego zawodu';
        
        -- Wycofanie transakcji
        ROLLBACK;
    ELSE
        -- Sprawdzenie, czy maksymalna pensja po podwyżce nie przekracza limitu
        SELECT MAX(pensja * 1.05) > max_pensja INTO exceeds_max
        FROM Pracownicy
        WHERE zawod_id = zawod_id_number;
        
        -- Sprawdzenie, czy podwyżka przekracza dozwoloną maksymalną pensję
        IF exceeds_max THEN
            SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'exceeds max';
            
            -- Wycofanie transakcji
            ROLLBACK;
        ELSE
            UPDATE Pracownicy
            SET pensja = pensja * 1.05
            WHERE zawod_id = zawod_id_number;
            
            COMMIT;
        END IF;
    END IF;
END;

call give_raise('Lekarz');