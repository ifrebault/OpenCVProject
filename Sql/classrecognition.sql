-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Mar 15 Décembre 2015 à 11:06
-- Version du serveur :  5.6.17
-- Version de PHP :  5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `classrecognition`
--

-- --------------------------------------------------------

--
-- Structure de la table `disease`
--

CREATE TABLE IF NOT EXISTS `disease` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idPatient` int(11) NOT NULL,
  `disease` text NOT NULL,
  `treatment` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Contenu de la table `disease`
--

INSERT INTO `disease` (`id`, `idPatient`, `disease`, `treatment`) VALUES
(1, 1, 'Nothing', 'Nothing'),
(2, 2, 'Nothing', 'Nothing'),
(3, 3, 'Nothing', 'Nothing'),
(4, 4, 'Nothing', 'Nothing');

-- --------------------------------------------------------

--
-- Structure de la table `insertdata`
--

CREATE TABLE IF NOT EXISTS `insertdata` (
  `id` varchar(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `insertdata`
--

INSERT INTO `insertdata` (`id`) VALUES
('''img0''');

-- --------------------------------------------------------

--
-- Structure de la table `patient`
--

CREATE TABLE IF NOT EXISTS `patient` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `firstName` varchar(255) NOT NULL,
  `gender` char(255) NOT NULL,
  `birthDate` date NOT NULL,
  `SSN` varchar(255) NOT NULL,
  `address` text NOT NULL,
  `telephoneNumber` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Contenu de la table `patient`
--

INSERT INTO `patient` (`id`, `name`, `firstName`, `gender`, `birthDate`, `SSN`, `address`, `telephoneNumber`, `email`) VALUES
(1, 'Frébault', 'Inès', 'Female', '2015-12-01', 'X XX XX XX XXX XXX XX', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit.', '0671800578', 'inesfrebault@gmail.com'),
(2, 'Mimouni', 'Karim', 'Male', '2015-12-02', 'X XX XX XX XXX XXX XX', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit.', '0662810443', 'kmimouni10@gmail.com'),
(3, 'Laurent', 'Guillaume', 'Male', '2015-12-03', 'X XX XX XX XXX XXX XX', 'Lorem ipsum dolor sit amet, consectetur adipiscing elit.', '0658900543', 'gui.laurent91@gmail.com'),
(4, 'Couturier', 'Jonathan', 'Male', '2015-12-04', 'X XX XX XX XXX XXX XX', '13 Place de la République \r\n77760 La Chapelle La Reine', '0677274135', 'couturier.jonathan.kun@gmail.com');

-- --------------------------------------------------------

--
-- Structure de la table `picture`
--

CREATE TABLE IF NOT EXISTS `picture` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idPatient` int(11) NOT NULL,
  `fileName` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Contenu de la table `picture`
--

INSERT INTO `picture` (`id`, `idPatient`, `fileName`) VALUES
(1, 1, 'img0'),
(2, 1, 'img2'),
(3, 1, 'img3'),
(4, 2, 'img11'),
(5, 2, 'img12'),
(6, 2, 'img13'),
(7, 2, 'img14'),
(8, 2, 'img15'),
(9, 3, 'img6'),
(10, 4, 'img5');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
