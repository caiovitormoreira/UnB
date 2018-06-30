-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 29-Jun-2018 às 08:26
-- Versão do servidor: 10.1.30-MariaDB
-- PHP Version: 7.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `api_forecast`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `current`
--

CREATE TABLE `current` (
  `id_weather` int(5) NOT NULL,
  `temperature` float NOT NULL,
  `temp_min` float NOT NULL,
  `temp_max` float NOT NULL,
  `humidity` int(10) NOT NULL,
  `description` text NOT NULL,
  `name` varchar(50) NOT NULL,
  `country` varchar(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `current`
--

INSERT INTO `current` (`id_weather`, `temperature`, `temp_min`, `temp_max`, `humidity`, `description`, `name`, `country`) VALUES
(42, 17.4, 16, 19, 82, 'clear sky', 'Brno', 'CZ'),
(43, 25, 25, 25, 78, 'few clouds', 'Brasilia', 'BR'),
(44, 23.63, 22, 26, 88, 'clear sky', 'New York', 'US'),
(45, -273.15, -273.15, -273.15, 0, '', '', ''),
(46, -273.15, -273.15, -273.15, 0, '', '', ''),
(47, 20.781, 20.781, 20.781, 53, 'clear sky', 'Caldas Novas', 'BR'),
(48, 16.99, 15, 18, 68, 'clear sky', 'Paris', 'FR'),
(49, 25, 25, 25, 78, 'few clouds', 'Brasilia', 'BR'),
(50, -273.15, -273.15, -273.15, 0, '', '', ''),
(51, -273.15, -273.15, -273.15, 0, '', '', ''),
(52, 12.88, 11, 14, 87, 'mist', 'London', 'GB'),
(53, 28.41, 27, 30, 74, 'clear sky', 'New Orleans', 'US'),
(54, 13.68, 13, 14, 87, 'broken clouds', 'Buenos Aires', 'AR'),
(55, 18.348, 18.348, 18.348, 60, 'few clouds', 'Caldas Novas', 'BR'),
(56, 12.89, 11, 14, 87, 'mist', 'London', 'GB'),
(57, 28.41, 27, 30, 74, 'clear sky', 'New Orleans', 'US'),
(58, 23.24, 20, 26, 88, 'mist', 'New York', 'US'),
(59, 13.68, 13, 14, 87, 'broken clouds', 'Buenos Aires', 'AR'),
(60, 27.49, 27, 28, 78, 'clear sky', 'Texas', 'US'),
(61, 16.99, 15, 18, 68, 'clear sky', 'Paris', 'FR'),
(62, 21.5, 21, 22, 56, 'clear sky', 'Moscow', 'RU'),
(63, 27.5, 26, 29, 69, 'few clouds', 'Barcelona', 'ES');

-- --------------------------------------------------------

--
-- Estrutura da tabela `forecast`
--

CREATE TABLE `forecast` (
  `id_forecast` int(2) NOT NULL,
  `country` varchar(50) NOT NULL,
  `city` text NOT NULL,
  `temp_1` float NOT NULL,
  `max_1` float NOT NULL,
  `min_1` float NOT NULL,
  `date_1` date NOT NULL,
  `temp_2` float NOT NULL,
  `max_2` float NOT NULL,
  `min_2` float NOT NULL,
  `date_2` date NOT NULL,
  `temp_3` float NOT NULL,
  `max_3` float NOT NULL,
  `min_3` float NOT NULL,
  `date_3` date NOT NULL,
  `temp_4` float NOT NULL,
  `max_4` float NOT NULL,
  `min_4` float NOT NULL,
  `date_4` date NOT NULL,
  `temp_5` float NOT NULL,
  `max_5` float NOT NULL,
  `min_5` float NOT NULL,
  `date_5` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `forecast`
--

INSERT INTO `forecast` (`id_forecast`, `country`, `city`, `temp_1`, `max_1`, `min_1`, `date_1`, `temp_2`, `max_2`, `min_2`, `date_2`, `temp_3`, `max_3`, `min_3`, `date_3`, `temp_4`, `max_4`, `min_4`, `date_4`, `temp_5`, `max_5`, `min_5`, `date_5`) VALUES
(1, 'BR', 'Brasilia', 297.18, 297.18, 291.648, '0000-00-00', 291.495, 291.495, 291.495, '0000-00-00', 292.92, 292.92, 292.92, '0000-00-00', 290.817, 290.817, 290.817, '0000-00-00', 292.517, 292.517, 292.517, '0000-00-00'),
(2, 'US', 'New York', 295.91, 295.91, 294.348, '0000-00-00', 294.145, 294.145, 294.145, '0000-00-00', 300.32, 300.32, 300.32, '0000-00-00', 298.267, 298.267, 298.267, '0000-00-00', 300.017, 300.017, 300.017, '0000-00-00'),
(3, 'BR', 'Brasilia', 297.18, 297.18, 291.648, '0000-00-00', 291.495, 291.495, 291.495, '0000-00-00', 292.92, 292.92, 292.92, '0000-00-00', 290.817, 290.817, 290.817, '0000-00-00', 292.517, 292.517, 292.517, '0000-00-00'),
(4, 'US', 'New York', 295.91, 295.91, 294.348, '0000-00-00', 294.145, 294.145, 294.145, '0000-00-00', 300.32, 300.32, 300.32, '0000-00-00', 298.267, 298.267, 298.267, '0000-00-00', 300.017, 300.017, 300.017, '0000-00-00'),
(5, 'BR', 'Caldas Novas', 291.5, 291.5, 291.498, '2018-06-29', 286.395, 286.395, 286.395, '2018-06-30', 287.17, 287.17, 287.17, '2018-07-01', 289.867, 289.867, 289.867, '2018-07-02', 287.067, 287.067, 287.067, '2018-07-03'),
(6, 'BR', 'Brasilia', 297.18, 297.18, 291.648, '2018-06-29', 291.495, 291.495, 291.495, '2018-06-30', 292.92, 292.92, 292.92, '2018-07-01', 290.817, 290.817, 290.817, '2018-07-02', 292.517, 292.517, 292.517, '2018-07-03'),
(7, 'FR', 'Paris', 291.91, 294.298, 291.91, '2018-06-29', 295.795, 295.795, 295.795, '2018-06-30', 296.67, 296.67, 296.67, '2018-07-01', 295.267, 295.267, 295.267, '2018-07-02', 294.617, 294.617, 294.617, '2018-07-03'),
(8, 'BR', 'Brasilia', 297.18, 297.18, 291.648, '2018-06-29', 291.495, 291.495, 291.495, '2018-06-30', 292.92, 292.92, 292.92, '2018-07-01', 290.817, 290.817, 290.817, '2018-07-02', 292.517, 292.517, 292.517, '2018-07-03'),
(9, '', '', 0, 0, 0, '0000-00-00', 0, 0, 0, '0000-00-00', 0, 0, 0, '0000-00-00', 0, 0, 0, '0000-00-00', 0, 0, 0, '0000-00-00'),
(10, 'GB', 'London', 287.04, 287.998, 287.04, '2018-06-29', 287.195, 287.195, 287.195, '2018-06-30', 292.92, 292.92, 292.92, '2018-07-01', 293.417, 293.417, 293.417, '2018-07-02', 286.217, 286.217, 286.217, '2018-07-03'),
(11, 'US', 'New Orleans', 300.56, 301.298, 300.56, '2018-06-29', 301.745, 301.745, 301.745, '2018-06-30', 301.67, 301.67, 301.67, '2018-07-01', 302.167, 302.167, 302.167, '2018-07-02', 301.917, 301.917, 301.917, '2018-07-03'),
(12, 'AR', 'Buenos Aires', 286.76, 286.76, 284.998, '2018-06-29', 280.545, 280.545, 280.545, '2018-06-30', 283.57, 283.57, 283.57, '2018-07-01', 288.067, 288.067, 288.067, '2018-07-02', 279.467, 279.467, 279.467, '2018-07-03'),
(13, 'BR', 'Caldas Novas', 289.55, 291.498, 289.55, '2018-06-29', 286.395, 286.395, 286.395, '2018-06-30', 287.17, 287.17, 287.17, '2018-07-01', 289.867, 289.867, 289.867, '2018-07-02', 287.067, 287.067, 287.067, '2018-07-03'),
(14, 'GB', 'London', 13.9, 14.848, 13.9, '2018-06-29', 287.195, 287.195, 287.195, '2018-06-30', 292.92, 292.92, 292.92, '2018-07-01', 293.417, 293.417, 293.417, '2018-07-02', 286.217, 286.217, 286.217, '2018-07-03'),
(15, 'US', 'New Orleans', 27.41, 28.148, 27.41, '2018-06-29', 28.595, 28.595, 28.595, '2018-06-30', 28.52, 28.52, 28.52, '2018-07-01', 29.017, 29.017, 29.017, '2018-07-02', 28.767, 28.767, 28.767, '2018-07-03'),
(16, 'US', 'New York', 22.45, 22.45, 21.198, '2018-06-29', 20.995, 20.995, 20.995, '2018-06-30', 27.17, 27.17, 27.17, '2018-07-01', 25.117, 25.117, 25.117, '2018-07-02', 26.867, 26.867, 26.867, '2018-07-03'),
(17, 'AR', 'Buenos Aires', 13.61, 13.61, 11.848, '2018-06-29', 7.395, 7.395, 7.395, '2018-06-30', 10.42, 10.42, 10.42, '2018-07-01', 14.917, 14.917, 14.917, '2018-07-02', 6.317, 6.317, 6.317, '2018-07-03'),
(18, 'US', 'Texas', 26.14, 26.14, 25.848, '2018-06-29', 25.995, 25.995, 25.995, '2018-06-30', 26.72, 26.72, 26.72, '2018-07-01', 26.667, 26.667, 26.667, '2018-07-02', 25.967, 25.967, 25.967, '2018-07-03'),
(19, 'FR', 'Paris', 18.76, 21.148, 18.76, '2018-06-29', 22.645, 22.645, 22.645, '2018-06-30', 23.52, 23.52, 23.52, '2018-07-01', 22.117, 22.117, 22.117, '2018-07-02', 21.467, 21.467, 21.467, '2018-07-03'),
(20, 'RU', 'Moscow', 27.4, 27.4, 25.148, '2018-06-29', 22.645, 22.645, 22.645, '2018-06-30', 20.52, 20.52, 20.52, '2018-07-01', 17.767, 17.767, 17.767, '2018-07-02', 18.017, 18.017, 18.017, '2018-07-03'),
(21, 'ES', 'Barcelona', 27.02, 27.02, 24.219, '2018-06-29', 24.34, 24.34, 24.34, '2018-06-30', 24.365, 24.365, 24.365, '2018-07-01', 24.352, 24.352, 24.352, '2018-07-02', 25.703, 25.703, 25.703, '2018-07-03');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `current`
--
ALTER TABLE `current`
  ADD UNIQUE KEY `id_weather` (`id_weather`);

--
-- Indexes for table `forecast`
--
ALTER TABLE `forecast`
  ADD KEY `id_forecast` (`id_forecast`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `current`
--
ALTER TABLE `current`
  MODIFY `id_weather` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=64;

--
-- AUTO_INCREMENT for table `forecast`
--
ALTER TABLE `forecast`
  MODIFY `id_forecast` int(2) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
