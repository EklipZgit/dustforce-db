SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `dustforce-db` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `dustforce-db` ;

-- -----------------------------------------------------
-- Table `dustforce-db`.`Player`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`Player` (
  `pID` INT NOT NULL ,
  `player_name` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`pID`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`MapsStock`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`MapsStock` (
  `mapID` INT NOT NULL ,
  `map_name` VARCHAR(30) NOT NULL ,
  PRIMARY KEY (`mapID`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`Character`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`Character` (
  `charID` INT NOT NULL COMMENT 'Dustman    = 0\nDustgirl      = 1\nDustkid      = 2\nDustworth = 3' ,
  `char_name` VARCHAR(9) NOT NULL COMMENT 'Dustman  \nDustgirl\nDustkid  \nDustworth' ,
  PRIMARY KEY (`charID`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`LeaderboardStockScore`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`LeaderboardStockScore` (
  `pID` INT NOT NULL ,
  `mapID` INT NOT NULL ,
  `rank` INT NOT NULL ,
  `charID` INT NOT NULL ,
  `score` INT NOT NULL ,
  `score_finesse` CHAR(1) NOT NULL ,
  `score_thoroughness` CHAR(1) NOT NULL ,
  `time` INT NOT NULL ,
  `timestamp` DATETIME NOT NULL ,
  PRIMARY KEY (`pID`, `mapID`) ,
  INDEX `fk_ScoreStockLB_MapsStock1_idx` (`mapID` ASC) ,
  INDEX `fk_ScoreStockLB_Character1_idx` (`charID` ASC) ,
  CONSTRAINT `fk_ScoreStockLB_Player`
    FOREIGN KEY (`pID` )
    REFERENCES `dustforce-db`.`Player` (`pID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ScoreStockLB_MapsStock1`
    FOREIGN KEY (`mapID` )
    REFERENCES `dustforce-db`.`MapsStock` (`mapID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ScoreStockLB_Character1`
    FOREIGN KEY (`charID` )
    REFERENCES `dustforce-db`.`Character` (`charID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`MapsCustom`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`MapsCustom` (
  `mapNo` INT NOT NULL ,
  `map_name` VARCHAR(45) NOT NULL ,
  `map_date` DATETIME NOT NULL ,
  `map_author` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`mapNo`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`LeaderboardStockTime`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`LeaderboardStockTime` (
  `pID` INT NOT NULL ,
  `mapID` INT NOT NULL ,
  `rank` INT NOT NULL ,
  `char` INT NOT NULL ,
  `score` INT NOT NULL ,
  `score_finesse` CHAR(1) NOT NULL ,
  `score_thoroughness` CHAR(1) NOT NULL ,
  `time` INT NOT NULL ,
  `timestamp` DATETIME NOT NULL ,
  PRIMARY KEY (`pID`, `mapID`) ,
  INDEX `fk_ScoreStockLB_MapsStock1_idx` (`mapID` ASC) ,
  INDEX `fk_ScoreStockLB_Character1_idx` (`char` ASC) ,
  CONSTRAINT `fk_ScoreStockLB_Player0`
    FOREIGN KEY (`pID` )
    REFERENCES `dustforce-db`.`Player` (`pID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ScoreStockLB_MapsStock10`
    FOREIGN KEY (`mapID` )
    REFERENCES `dustforce-db`.`MapsStock` (`mapID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ScoreStockLB_Character10`
    FOREIGN KEY (`char` )
    REFERENCES `dustforce-db`.`Character` (`charID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`LeaderboardCustomTime`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`LeaderboardCustomTime` (
  `pID` INT NOT NULL ,
  `mapID` INT NOT NULL ,
  `rank` INT NOT NULL ,
  `char` INT NOT NULL ,
  `score` INT NOT NULL ,
  `score_finesse` CHAR(1) NOT NULL ,
  `score_thoroughness` CHAR(1) NOT NULL ,
  `time` INT NOT NULL ,
  `timestamp` DATETIME NOT NULL ,
  PRIMARY KEY (`pID`, `mapID`) ,
  INDEX `fk_ScoreStockLB_Character1_idx` (`char` ASC) ,
  INDEX `fk_LeaderboardCustomTime_MapsCustom1_idx` (`mapID` ASC) ,
  CONSTRAINT `fk_ScoreStockLB_Player00`
    FOREIGN KEY (`pID` )
    REFERENCES `dustforce-db`.`Player` (`pID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ScoreStockLB_Character100`
    FOREIGN KEY (`char` )
    REFERENCES `dustforce-db`.`Character` (`charID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_LeaderboardCustomTime_MapsCustom1`
    FOREIGN KEY (`mapID` )
    REFERENCES `dustforce-db`.`MapsCustom` (`mapNo` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`LeaderboardCustomScore`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`LeaderboardCustomScore` (
  `pID` INT NOT NULL ,
  `mapID` INT NOT NULL ,
  `rank` INT NOT NULL ,
  `charID` INT NOT NULL ,
  `score` INT NOT NULL ,
  `score_finesse` CHAR(1) NOT NULL ,
  `score_thoroughness` CHAR(1) NOT NULL ,
  `time` INT NOT NULL ,
  `timestamp` DATETIME NOT NULL ,
  PRIMARY KEY (`pID`, `mapID`) ,
  INDEX `fk_ScoreStockLB_Character1_idx` (`charID` ASC) ,
  INDEX `fk_LeaderboardCustomScore_MapsCustom1_idx` (`mapID` ASC) ,
  CONSTRAINT `fk_ScoreStockLB_Player1`
    FOREIGN KEY (`pID` )
    REFERENCES `dustforce-db`.`Player` (`pID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ScoreStockLB_Character11`
    FOREIGN KEY (`charID` )
    REFERENCES `dustforce-db`.`Character` (`charID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_LeaderboardCustomScore_MapsCustom1`
    FOREIGN KEY (`mapID` )
    REFERENCES `dustforce-db`.`MapsCustom` (`mapNo` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`StatsStock`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`StatsStock` (
  `pID` INT NOT NULL ,
  `pointsT10` INT NULL ,
  `pointsT100` INT NULL ,
  `countT100` INT NULL ,
  `countT20` INT NULL ,
  `countT10` INT NULL ,
  `countT5` INT NULL ,
  `countT3` INT NULL ,
  `countWR` INT NULL ,
  `rank_avg` DECIMAL NULL ,
  `rank_avg_of_T10` DECIMAL NULL ,
  PRIMARY KEY (`pID`) ,
  CONSTRAINT `fk_StatsStock_Player1`
    FOREIGN KEY (`pID` )
    REFERENCES `dustforce-db`.`Player` (`pID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `dustforce-db`.`StatsCustom`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `dustforce-db`.`StatsCustom` (
  `pID` INT NOT NULL ,
  `pointsT10` INT NULL ,
  `pointsT100` INT NULL ,
  `countT100` INT NULL ,
  `countT20` INT NULL ,
  `countT10` INT NULL ,
  `countT5` INT NULL ,
  `countT3` INT NULL ,
  `countWR` INT NULL ,
  `rank_avg` DECIMAL NULL ,
  `rank_avg_of_T10` DECIMAL NULL ,
  PRIMARY KEY (`pID`) ,
  CONSTRAINT `fk_StatsStock_Player10`
    FOREIGN KEY (`pID` )
    REFERENCES `dustforce-db`.`Player` (`pID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

USE `dustforce-db` ;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
