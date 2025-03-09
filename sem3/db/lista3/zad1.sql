CREATE DATABASE Praca;
USE Praca;

CREATE TABLE Ludzie (
    id INT AUTO_INCREMENT PRIMARY KEY, 
    PESEL CHAR(11) UNIQUE NOT NULL, 
    imie VARCHAR(30) NOT NULL, 
    nazwisko VARCHAR(30) NOT NULL,
    data_urodzenia DATE NOT NULL,
    plec ENUM('K', 'M') NOT NULL,
    CHECK (PESEL REGEXP '^[0-9]{11}$'), 
    CHECK ( 
        YEAR(data_urodzenia) = 
            CASE 
                WHEN CAST(SUBSTRING(PESEL, 3, 2) AS UNSIGNED) > 20 
                THEN  CONCAT('20', SUBSTRING(PESEL, 1, 2))
                ELSE 
                        CONCAT('19', SUBSTRING(PESEL, 1, 2))
                END
        ),
    CHECK ( 
        CAST(MONTH(data_urodzenia) AS CHAR(2)) = 
            LPAD(CASE 
                WHEN CAST(SUBSTRING(PESEL, 3, 2) AS UNSIGNED) > 20 THEN CAST(SUBSTRING(PESEL, 3, 2) AS UNSIGNED) - 20
                ELSE
                     CAST(SUBSTRING(PESEL, 3, 2) AS UNSIGNED)
                END, 2, '0')
        ),
    CHECK (
        CAST(DAY(data_urodzenia) AS CHAR(2)) = 
            LPAD(CASE 
                 WHEN CAST(SUBSTRING(PESEL, 5, 2) AS UNSIGNED) < 32 THEN 
                    CAST(SUBSTRING(PESEL, 5, 2) AS UNSIGNED)
                ELSE 
                    NULL  
                END, 2, '0')
        ),
    CHECK (plec = IF(SUBSTRING(PESEL, 7, 1) % 2 = 0, 'K', 'M')));



CREATE TABLE Zawody (
    zawod_id INT AUTO_INCREMENT PRIMARY KEY,
    nazwa VARCHAR(50) NOT NULL,
    pensja_min FLOAT NOT NULL CHECK (pensja_min > 0),
    pensja_max FLOAT NOT NULL CHECK (pensja_max > pensja_min)
);

CREATE TABLE Pracownicy (
    id INT AUTO_INCREMENT PRIMARY KEY,
    PESEL CHAR(11) NOT NULL,
    zawod_id INT NOT NULL,
    pensja FLOAT NOT NULL CHECK (pensja > 0),
    FOREIGN KEY (PESEL) REFERENCES Ludzie(PESEL),
    FOREIGN KEY (zawod_id) REFERENCES Zawody(zawod_id)
);

