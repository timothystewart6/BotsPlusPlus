/*https://github.com/thesawolf/TrinityCore/blob/TrinityCoreLegacy/sql/TrinityCore-Patches/LegacyTrinityCore/QOL-world-achievement_reward.sql*/
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

REPLACE INTO `achievement_reward` (`entry`, `title_A`, `title_H`, `item`, `sender`, `subject`, `text`, `mailTemplate`) VALUES
(6, 0, 0, 60001, 190001, 'Congrats on level 10!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(7, 0, 0, 60002, 190001, 'Congrats on level 20!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(8, 0, 0, 60003, 190001, 'Congrats on level 30!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(9, 0, 0, 60004, 190001, 'Congrats on level 40!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(10, 0, 0, 60005, 190001, 'Congrats on level 50!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(11, 0, 0, 60006, 190001, 'Congrats on level 60!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(12, 0, 0, 60007, 190001, 'Congrats on level 70!', 'Dear $N,$B$BCongratulations on reaching another level milestone! For your hard work and dedication, please accept this gift. $B$BYour GM,$BGameMaster Oz', 0),
(1558, 0, 0, 33223, 190001, 'We heard you like fishing...', '... so you might as well do it in style, $N!$B$BEnjoy!$BGameMaster Oz', 0),
(1795, 0, 0, 32566, 190001, 'We heard you like cooking...', '... so take some time out to enjoy the fruits of your labor, $N!$B$BEnjoy!$BGameMaster Oz', 0);
