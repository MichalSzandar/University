
CREATE PROCEDURE AssignJobs()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE person_PESEL CHAR(11);
    DECLARE person_gender ENUM('K', 'M');
    DECLARE person_age INT;
    DECLARE cur CURSOR FOR SELECT PESEL, plec, YEAR(CURDATE()) - YEAR(data_urodzenia) AS age FROM Ludzie WHERE YEAR(CURDATE()) - YEAR(data_urodzenia) >= 18;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO person_PESEL, person_gender, person_age;
        IF done THEN
            LEAVE read_loop;
        END IF;

        IF person_gender = 'M' AND person_age <= 65 THEN
            INSERT INTO Pracownicy (PESEL, zawod_id, pensja) VALUES (person_PESEL, 4, 8000);
        ELSEIF person_gender = 'K' AND person_age <= 60 THEN
            INSERT INTO Pracownicy (PESEL, zawod_id, pensja) VALUES (person_PESEL, 3, 8000);
        END IF;
    END LOOP;

    CLOSE cur;
END;

CALL AssignJobs();
