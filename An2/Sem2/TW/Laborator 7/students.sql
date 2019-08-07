-- Baza de data `stud` folosita in exemple
-- (SQL generat de PHPMyAdmin)

USE stud;

-- 
-- Tabela `students`
-- 

DROP TABLE IF EXISTS `students`;
CREATE TABLE IF NOT EXISTS `students` (
  `name` varchar(50) NOT NULL default '',
  `year` enum('1','2','3') NOT NULL default '1',
  `id` int(11) NOT NULL auto_increment,
  `age` smallint(2) unsigned zerofill NOT NULL default '00',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;

-- 
-- O serie de date
-- 

INSERT INTO `students` VALUES ('George Rosca', '2', 1, 20);
INSERT INTO `students` VALUES ('Loredana Vamanu', '2', 2, 19);
INSERT INTO `students` VALUES ('Sonia Mihaela-Bogos', '3', 3, 21);
