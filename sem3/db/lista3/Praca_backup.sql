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
(1,'97558627088','Ewa','Kowalska','2021-10-01','M'),
(2,'72225081055','Adam','Kowalska','2012-09-30','K'),
(3,'25251959101','Piotr','Mazur','2019-07-30','K'),
(4,'95948761324','Piotr','Mazur','2019-09-28','K'),
(5,'88200676429','Ewa','Kowalska','2007-02-23','K'),
(6,'80452515817','Alicja','Zalewska','2000-05-30','M'),
(7,'34700243206','Magdalena','Górski','1964-08-10','K'),
(8,'32901170228','Jakub','Kowalski','1969-02-01','K'),
(9,'97070770986','Tomasz','Zalewska','1984-01-04','K'),
(10,'84406624160','Jakub','Wiśniewska','1993-06-02','M'),
(11,'11577070980','Alicja','Wiśniewska','1998-12-26','K'),
(12,'65373808950','Tomasz','Wiśniewska','1975-08-23','K'),
(13,'13143738371','Tomasz','Nowicka','1984-10-01','M'),
(14,'01182306000','Jakub','Wiśniewska','1985-07-05','M'),
(15,'49976709344','Alicja','Wiśniewska','2001-01-22','K'),
(16,'28349709630','Jakub','Zalewska','1996-07-30','K'),
(17,'71485117143','Jakub','Górski','1980-09-22','M'),
(18,'51572131133','Magdalena','Kowalski','1989-11-18','M'),
(19,'98013740123','Karol','Nowicka','2004-01-26','K'),
(20,'38242600893','Alicja','Górski','1971-05-16','K'),
(21,'90501251527','Tomasz','Górski','1993-02-09','M'),
(22,'96397770657','Magdalena','Nowicka','1986-01-20','M'),
(23,'94911383179','Tomasz','Kowalski','2002-05-03','K'),
(24,'69635704968','Tomasz','Nowicka','1985-11-01','K'),
(25,'49202500608','Jakub','Górski','1978-08-17','K'),
(26,'52215873870','Magdalena','Wiśniewska','1996-03-12','M'),
(27,'62210095358','Alicja','Wiśniewska','1988-03-24','M'),
(28,'71437087441','Karol','Zalewska','1998-03-09','K'),
(29,'52654588271','Karol','Górski','1974-05-16','M'),
(30,'06309235381','Tomasz','Nowicka','1986-04-01','M'),
(31,'11061020671','Alicja','Zalewska','2003-04-16','K'),
(32,'81865076051','Alicja','Nowicka','1989-04-20','K'),
(33,'63162936700','Magdalena','Górski','1981-07-22','M'),
(34,'72121937546','Magdalena','Nowicka','1990-03-10','M'),
(35,'31268046638','Alicja','Kowalski','1967-05-31','M'),
(36,'94741752179','Magdalena','Zalewska','1988-08-29','K'),
(37,'45952915535','Karol','Zalewska','2003-10-13','M'),
(38,'58308419452','Magdalena','Zalewska','1966-12-03','K'),
(39,'38364001585','Jakub','Wiśniewska','1978-09-16','M'),
(40,'17960194794','Magdalena','Kowalski','2000-03-23','M'),
(41,'68838719807','Jakub','Kowalski','1968-11-27','K'),
(42,'72788165576','Jakub','Wiśniewska','1996-11-13','M'),
(43,'34739096680','Karol','Zalewska','1983-03-12','K'),
(44,'52647152964','Tomasz','Wiśniewska','1993-10-06','K'),
(45,'12953912571','Jakub','Nowicka','1965-12-15','K'),
(46,'13766656549','Magdalena','Kowalski','2003-10-31','K'),
(47,'58021438734','Tomasz','Zalewska','1979-12-21','K'),
(48,'36328375372','Karol','Zalewska','1984-02-16','K'),
(49,'85147846475','Karol','Wiśniewska','1980-11-14','M'),
(50,'65282120150','Jakub','Wiśniewska','1992-11-20','K'),
(51,'00204311963','Barbara','Wolska','1931-09-06','K'),
(52,'37808732630','Zbigniew','Wolska','1938-03-09','M'),
(53,'18236606212','Jan','Wolska','1926-07-30','M'),
(54,'11475917614','Zbigniew','Szulc','1922-12-16','M'),
(55,'95486955060','Krystyna','Kowal','1957-03-18','M');
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
(1,'80452515817',3,8000),
(2,'34700243206',3,8000),
(3,'32901170228',3,8000),
(4,'97070770986',3,8000),
(5,'84406624160',3,8000),
(6,'11577070980',3,8000),
(7,'65373808950',3,8000),
(8,'13143738371',3,8000),
(9,'01182306000',3,8000),
(10,'49976709344',3,8000),
(11,'28349709630',3,8000),
(12,'71485117143',3,8000),
(13,'51572131133',3,8000),
(14,'98013740123',3,8000),
(15,'38242600893',3,8000),
(16,'90501251527',3,8000),
(17,'96397770657',3,8000),
(18,'94911383179',3,8000),
(19,'69635704968',3,8000),
(20,'49202500608',3,8000),
(21,'52215873870',3,8000),
(22,'62210095358',3,8000),
(23,'71437087441',3,8000),
(24,'52654588271',3,8000),
(25,'06309235381',3,8000),
(26,'11061020671',3,8000),
(27,'81865076051',3,8000),
(28,'63162936700',3,8000),
(29,'72121937546',3,8000),
(30,'31268046638',3,8000),
(31,'94741752179',3,8000),
(32,'45952915535',3,8000),
(33,'58308419452',3,8000),
(34,'38364001585',3,8000),
(35,'17960194794',3,8000),
(36,'68838719807',3,8000),
(37,'72788165576',3,8000),
(38,'34739096680',3,8000),
(39,'52647152964',3,8000),
(40,'12953912571',3,8000),
(41,'13766656549',3,8000),
(42,'58021438734',3,8000),
(43,'36328375372',3,8000),
(44,'85147846475',3,8000),
(45,'65282120150',3,8000);
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

-- Dump completed on 2024-12-02 19:32:09
