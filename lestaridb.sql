-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 23, 2020 at 04:07 PM
-- Server version: 10.4.10-MariaDB
-- PHP Version: 7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `lestaridb`
--

-- --------------------------------------------------------

--
-- Table structure for table `employee_db`
--

CREATE TABLE `employee_db` (
  `Emp_Id` varchar(255) NOT NULL,
  `Emp_Pass` varchar(255) NOT NULL,
  `Emp_Name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `employee_db`
--

INSERT INTO `employee_db` (`Emp_Id`, `Emp_Pass`, `Emp_Name`) VALUES
('firdaus', 'firdaus', 'firdaus');

-- --------------------------------------------------------

--
-- Table structure for table `manager_db`
--

CREATE TABLE `manager_db` (
  `Manager_Id` varchar(255) NOT NULL,
  `Manager_Pass` varchar(255) NOT NULL,
  `Manager_Name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `manager_db`
--

INSERT INTO `manager_db` (`Manager_Id`, `Manager_Pass`, `Manager_Name`) VALUES
('firdaus', 'firdaus', 'firdaus'),
('mfar', 'mfar', 'mfar');

-- --------------------------------------------------------

--
-- Table structure for table `menu_db`
--

CREATE TABLE `menu_db` (
  `menu_id` int(11) NOT NULL,
  `menu_name` varchar(255) NOT NULL,
  `menu_cat` varchar(255) NOT NULL,
  `menu_price` varchar(100) CHARACTER SET latin1 NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `menu_db`
--

INSERT INTO `menu_db` (`menu_id`, `menu_name`, `menu_cat`, `menu_price`) VALUES
(1, 'Mee Goreng', 'Mee', '5'),
(3, 'Nasi Goreng Pattaya', 'Nasi', '6'),
(5, 'Nasi Goreng Kampung', 'Nasi', '5.5'),
(6, 'Teh Ais', 'Air', '1.6'),
(7, 'Nasi Goreng Ayam', 'Nasi', '5.6'),
(9, 'Kueh Tiaw Kungfu', 'Mee', '6'),
(10, 'Roti Canai', 'Special', '1'),
(11, 'Nasi Goreng Cili Padi', 'Nasi', '5'),
(14, 'Burger Oblong', 'Special', '5.5'),
(15, 'Burger Daging', 'Special', '5');

-- --------------------------------------------------------

--
-- Table structure for table `orders_db`
--

CREATE TABLE `orders_db` (
  `order_id` int(11) NOT NULL,
  `order_name` varchar(255) NOT NULL,
  `order_month` varchar(255) NOT NULL,
  `order_year` varchar(255) NOT NULL,
  `order_price` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `orders_db`
--

INSERT INTO `orders_db` (`order_id`, `order_name`, `order_month`, `order_year`, `order_price`) VALUES
(1, 'Nasi Goreng Ayam', '6', '2020', '5.6'),
(2, 'Nasi Goreng Pattaya', '3', '2019', '6'),
(3, 'Nasi Goreng Kampung', '4', '2019', '5.5'),
(4, 'Roti Canai', '6', '2020', '1'),
(5, 'Teh Ais', '9', '2018', '1.6'),
(6, 'Teh Ais', '6', '2020', '1.6'),
(7, 'Nasi Goreng Ayam', '6', '2020', '5.6'),
(8, 'Teh Ais', '6', '2020', '1.6'),
(9, 'Roti Canai', '6', '2020', '1'),
(11, 'Nasi Goreng Ayam', '6', '2020', '5.6'),
(12, 'Nasi Goreng Cili Padi', '6', '2020', '5'),
(13, 'Burger Oblong', '6', '2020', '5.5'),
(14, 'Burger Oblong', '6', '2020', '5.5'),
(15, 'Burger Oblong', '6', '2020', '5.5');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `employee_db`
--
ALTER TABLE `employee_db`
  ADD UNIQUE KEY `Emp_Id` (`Emp_Id`);

--
-- Indexes for table `manager_db`
--
ALTER TABLE `manager_db`
  ADD UNIQUE KEY `Manager_Id` (`Manager_Id`);

--
-- Indexes for table `menu_db`
--
ALTER TABLE `menu_db`
  ADD PRIMARY KEY (`menu_id`);

--
-- Indexes for table `orders_db`
--
ALTER TABLE `orders_db`
  ADD PRIMARY KEY (`order_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `menu_db`
--
ALTER TABLE `menu_db`
  MODIFY `menu_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `orders_db`
--
ALTER TABLE `orders_db`
  MODIFY `order_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
