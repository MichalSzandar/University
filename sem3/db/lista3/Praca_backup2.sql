/*!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19  Distrib 10.11.8-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: Praca
-- ------------------------------------------------------
-- Server version	10.11.8-MariaDB-0ubuntu0.24.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Ludzie`
--

DROP TABLE IF EXISTS `Ludzie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Ludzie` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `PESEL` char(11) NOT NULL,
  `imie` varchar(30) NOT NULL,
  `nazwisko` varchar(30) NOT NULL,
  `data_urodzenia` date NOT NULL,
  `plec` enum('K','M') NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `PESEL` (`PESEL`),
  KEY `idx_plec_imie` (`plec`,`imie`)
) ENGINE=InnoDB AUTO_INCREMENT=56 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Ludzie`
--

LOCK TABLES `Ludzie` WRITE;
/*!40000 ALTER TABLE `Ludzie` DISABLE KEYS */;
INSERT INTO `Ludzie` VALUES
(1,'10210112345','Jan','Kowalski','2010-01-01','M'),
(2,'12221554321','Anna','Nowak','2012-02-15','K'),
(3,'09272098765','Piotr','Wiśniewski','2009-07-20','M'),
(4,'15363045678','Maria','Zielińska','2015-06-30','K'),
(5,'08112267890','Adam','Woźniak','2008-11-22','M'),
(6,'85031212345','Tomasz','Mazur','1985-03-12','M'),
(7,'90090954321','Katarzyna','Lewandowska','1990-09-09','K'),
(8,'75101098765','Marek','Krawczyk','1975-10-10','M'),
(9,'80051545678','Andrzej','Duda','1980-05-15','M'),
(10,'88112267890','Barbara','Jasińska','1988-11-22','K'),
(11,'82011112345','Marcin','Kowalczyk','1982-01-11','M'),
(12,'79063054321','Karolina','Wiśniewska','1979-06-30','K'),
(13,'91041798765','Zbigniew','Kamiński','1991-04-17','M'),
(14,'87122545678','Monika','Kowal','1987-12-25','K'),
(15,'84090967890','Paweł','Adamski','1984-09-09','M'),
(16,'92030712345','Agnieszka','Górska','1992-03-07','K'),
(17,'81071454321','Tadeusz','Nowicki','1981-07-14','M'),
(18,'83020598765','Joanna','Zawadzka','1983-02-05','K'),
(19,'86102945678','Piotr','Sikora','1986-10-29','M'),
(20,'90081267890','Magdalena','Baran','1990-08-12','K'),
(21,'89031812345','Michał','Sadowski','1989-03-18','M'),
(22,'85060954321','Anna','Chmielewska','1985-06-09','K'),
(23,'93010398765','Rafał','Piotrowski','1993-01-03','M'),
(24,'82042245678','Ewelina','Czarnecka','1982-04-22','K'),
(25,'77083067890','Grzegorz','Głowacki','1977-08-30','M'),
(26,'80121512345','Dominika','Kaczmarek','1980-12-15','K'),
(27,'91021154321','Sebastian','Król','1991-02-11','M'),
(28,'86050498765','Natalia','Laskowska','1986-05-04','K'),
(29,'84101045678','Dariusz','Borkowski','1984-10-10','M'),
(30,'88090767890','Aleksandra','Błaszczyk','1988-09-07','K'),
(31,'90011912345','Krzysztof','Sobczak','1990-01-19','M'),
(32,'83110154321','Ewa','Stankiewicz','1983-11-01','K'),
(33,'87072598765','Łukasz','Mazurek','1987-07-25','M'),
(34,'92061345678','Beata','Woźniak','1992-06-13','K'),
(35,'81081867890','Maciej','Jakubowski','1981-08-18','M'),
(36,'79032212345','Dorota','Michalska','1979-03-22','K'),
(37,'85121154321','Artur','Wilk','1985-12-11','M'),
(38,'90042898765','Izabela','Kubiak','1990-04-28','K'),
(39,'83051745678','Jan','Marciniak','1983-05-17','M'),
(40,'76070467890','Renata','Pawlak','1976-07-04','K'),
(41,'84102712345','Adrian','Jankowski','1984-10-27','M'),
(42,'89022054321','Sylwia','Urbaniak','1989-02-20','K'),
(43,'78091598765','Robert','Wojciechowski','1978-09-15','M'),
(44,'91083145678','Jolanta','Kowalewska','1991-08-31','K'),
(45,'87110967890','Mateusz','Bialek','1987-11-09','M'),
(46,'87110967891','Tymon','Ostrowski','2004-11-09','M'),
(47,'87110967892','Kasia','Zyla','2000-01-26','K'),
(48,'87110967893','Krystian','Bach','2001-02-23','M'),
(49,'87110967894','Mateusz','Wielki','1999-12-09','M'),
(50,'87110967895','Malgorzata','Widzgowska','2004-11-09','K'),
(51,'50030512345','Zofia','Stępień','1950-03-05','K'),
(52,'45080854321','Janina','Sikorska','1945-08-08','K'),
(53,'40121598765','Władysław','Baran','1940-12-15','M'),
(54,'35052045678','Kazimierz','Nowacki','1935-05-20','M'),
(55,'47070767890','Helena','Adamska','1947-07-07','K');
/*!40000 ALTER TABLE `Ludzie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Pracownicy`
--

DROP TABLE IF EXISTS `Pracownicy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Pracownicy` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `PESEL` char(11) NOT NULL,
  `zawod_id` int(11) NOT NULL,
  `pensja` float NOT NULL CHECK (`pensja` > 0),
  PRIMARY KEY (`id`),
  KEY `PESEL` (`PESEL`),
  KEY `zawod_id` (`zawod_id`),
  KEY `idx_pensja` (`pensja`),
  CONSTRAINT `Pracownicy_ibfk_1` FOREIGN KEY (`PESEL`) REFERENCES `Ludzie` (`PESEL`),
  CONSTRAINT `Pracownicy_ibfk_2` FOREIGN KEY (`zawod_id`) REFERENCES `Zawody` (`zawod_id`)
) ENGINE=InnoDB AUTO_INCREMENT=46 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Pracownicy`
--

LOCK TABLES `Pracownicy` WRITE;
/*!40000 ALTER TABLE `Pracownicy` DISABLE KEYS */;
INSERT INTO `Pracownicy` VALUES
(1,'85031212345',3,8000),
(2,'90090954321',3,8000),
(3,'75101098765',3,8000),
(4,'80051545678',3,8000),
(5,'88112267890',3,8000),
(6,'82011112345',3,8000),
(7,'79063054321',3,8000),
(8,'91041798765',3,8000),
(9,'87122545678',3,8000),
(10,'84090967890',3,8000),
(11,'92030712345',3,8000),
(12,'81071454321',3,8000),
(13,'83020598765',3,8000),
(14,'86102945678',3,8000),
(15,'90081267890',3,8000),
(16,'89031812345',3,8000),
(17,'85060954321',3,8000),
(18,'93010398765',3,8000),
(19,'82042245678',3,8000),
(20,'77083067890',3,8000),
(21,'80121512345',3,8000),
(22,'91021154321',3,8000),
(23,'86050498765',3,8000),
(24,'84101045678',3,8000),
(25,'88090767890',3,8000),
(26,'90011912345',3,8000),
(27,'83110154321',3,8000),
(28,'87072598765',3,8000),
(29,'92061345678',3,8000),
(30,'81081867890',3,8000),
(31,'79032212345',3,8000),
(32,'85121154321',3,8000),
(33,'90042898765',3,8000),
(34,'83051745678',3,8000),
(35,'76070467890',3,8000),
(36,'84102712345',3,8000),
(37,'89022054321',3,8000),
(38,'78091598765',3,8000),
(39,'91083145678',3,8000),
(40,'87110967890',3,8000),
(41,'87110967891',3,8000),
(42,'87110967892',3,8000),
(43,'87110967893',3,8000),
(44,'87110967894',3,8000),
(45,'87110967895',3,8000);
/*!40000 ALTER TABLE `Pracownicy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Zawody`
--

DROP TABLE IF EXISTS `Zawody`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Zawody` (
  `zawod_id` int(11) NOT NULL AUTO_INCREMENT,
  `nazwa` varchar(50) NOT NULL,
  `pensja_min` float NOT NULL CHECK (`pensja_min` > 0),
  `pensja_max` float NOT NULL CHECK (`pensja_max` > `pensja_min`),
  PRIMARY KEY (`zawod_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Zawody`
--

LOCK TABLES `Zawody` WRITE;
/*!40000 ALTER TABLE `Zawody` DISABLE KEYS */;
INSERT INTO `Zawody` VALUES
(1,'Polityk',5000,20000),
(2,'Nauczyciel',3000,8000),
(3,'Lekarz',7000,15000),
(4,'Informatyk',6000,25000);
/*!40000 ALTER TABLE `Zawody` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-12 17:41:23
