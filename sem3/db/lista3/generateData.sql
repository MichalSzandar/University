USE Praca;

INSERT INTO Ludzie (PESEL, imie, nazwisko, data_urodzenia, plec) VALUES
-- 5 osób niepełnoletnich
('10210112345', 'Jan', 'Kowalski', '2010-01-01', 'M'),
('12221554321', 'Anna', 'Nowak', '2012-02-15', 'K'),
('09272098765', 'Piotr', 'Wiśniewski', '2009-07-20', 'M'),
('15363045678', 'Maria', 'Zielińska', '2015-06-30', 'K'),
('08112267890', 'Adam', 'Woźniak', '2008-11-22', 'M'),
-- 45 osób pełnoletnich, ale mniej niż 60 lat
('85031212345', 'Tomasz', 'Mazur', '1985-03-12', 'M'),
('90090954321', 'Katarzyna', 'Lewandowska', '1990-09-09', 'K'),
('75101098765', 'Marek', 'Krawczyk', '1975-10-10', 'M'),
('80051545678', 'Andrzej', 'Duda', '1980-05-15', 'M'),
('88112267890', 'Barbara', 'Jasińska', '1988-11-22', 'K'),
('82011112345', 'Marcin', 'Kowalczyk', '1982-01-11', 'M'),
('79063054321', 'Karolina', 'Wiśniewska', '1979-06-30', 'K'),
('91041798765', 'Zbigniew', 'Kamiński', '1991-04-17', 'M'),
('87122545678', 'Monika', 'Kowal', '1987-12-25', 'K'),
('84090967890', 'Paweł', 'Adamski', '1984-09-09', 'M'),
('92030712345', 'Agnieszka', 'Górska', '1992-03-07', 'K'),
('81071454321', 'Tadeusz', 'Nowicki', '1981-07-14', 'M'),
('83020598765', 'Joanna', 'Zawadzka', '1983-02-05', 'K'),
('86102945678', 'Piotr', 'Sikora', '1986-10-29', 'M'),
('90081267890', 'Magdalena', 'Baran', '1990-08-12', 'K'),
('89031812345', 'Michał', 'Sadowski', '1989-03-18', 'M'),
('85060954321', 'Anna', 'Chmielewska', '1985-06-09', 'K'),
('93010398765', 'Rafał', 'Piotrowski', '1993-01-03', 'M'),
('82042245678', 'Ewelina', 'Czarnecka', '1982-04-22', 'K'),
('77083067890', 'Grzegorz', 'Głowacki', '1977-08-30', 'M'),
('80121512345', 'Dominika', 'Kaczmarek', '1980-12-15', 'K'),
('91021154321', 'Sebastian', 'Król', '1991-02-11', 'M'),
('86050498765', 'Natalia', 'Laskowska', '1986-05-04', 'K'),
('84101045678', 'Dariusz', 'Borkowski', '1984-10-10', 'M'),
('88090767890', 'Aleksandra', 'Błaszczyk', '1988-09-07', 'K'),
('90011912345', 'Krzysztof', 'Sobczak', '1990-01-19', 'M'),
('83110154321', 'Ewa', 'Stankiewicz', '1983-11-01', 'K'),
('87072598765', 'Łukasz', 'Mazurek', '1987-07-25', 'M'),
('92061345678', 'Beata', 'Woźniak', '1992-06-13', 'K'),
('81081867890', 'Maciej', 'Jakubowski', '1981-08-18', 'M'),
('79032212345', 'Dorota', 'Michalska', '1979-03-22', 'K'),
('85121154321', 'Artur', 'Wilk', '1985-12-11', 'M'),
('90042898765', 'Izabela', 'Kubiak', '1990-04-28', 'K'),
('83051745678', 'Jan', 'Marciniak', '1983-05-17', 'M'),
('76070467890', 'Renata', 'Pawlak', '1976-07-04', 'K'),
('84102712345', 'Adrian', 'Jankowski', '1984-10-27', 'M'),
('89022054321', 'Sylwia', 'Urbaniak', '1989-02-20', 'K'),
('78091598765', 'Robert', 'Wojciechowski', '1978-09-15', 'M'),
('91083145678', 'Jolanta', 'Kowalewska', '1991-08-31', 'K'),
('87110967890', 'Mateusz', 'Bialek', '1987-11-09', 'M'),
('87110967891', 'Tymon', 'Ostrowski', '2004-11-09', 'M'),
('87110967892', 'Kasia', 'Zyla', '2000-01-26', 'K'),
('87110967893', 'Krystian', 'Bach', '2001-02-23', 'M'),
('87110967894', 'Mateusz', 'Wielki', '1999-12-09', 'M'),
('87110967895', 'Malgorzata', 'Widzgowska', '2004-11-09', 'K'),
-- 5 osób co najmniej 60 lat
('50030512345', 'Zofia', 'Stępień', '1950-03-05', 'K'),
('45080854321', 'Janina', 'Sikorska', '1945-08-08', 'K'),
('40121598765', 'Władysław', 'Baran', '1940-12-15', 'M'),
('35052045678', 'Kazimierz', 'Nowacki', '1935-05-20', 'M'),
('47070767890', 'Helena', 'Adamska', '1947-07-07', 'K');


-- Dodanie zawodów do tabeli Zawody
INSERT INTO Zawody (nazwa, pensja_min, pensja_max)
VALUES
('Polityk', 5000, 20000),
('Nauczyciel', 3000, 8000),
('Lekarz', 7000, 15000),
('Informatyk', 6000, 25000);
