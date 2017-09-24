SET
@Entry = 190011,
@Name = "Thaumaturge Vashreen";
@Subname = "Arcane Reforger";
DELETE FROM `creature_template` WHERE `entry` = @Entry ;

INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(@Entry, 20988, 0, @Name, @Subname, NULL, 0, 80, 80, 2, 35, 1, 1, 0, 0, 2000, 0, 1, 0, 7, 138936390, 0, 0, 0, '', 0, 3, 1, 0, 0, 1, 0, 0, 'REFORGER_NPC');

REPLACE INTO `creature` VALUES ('15122157', '190011', '0', '0', '0', '1', '1', '0', '0', '-8826.56', '647.301', '94.5076', '4.69467', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
REPLACE INTO `creature` VALUES ('15122177', '190011', '1', '0', '0', '1', '1', '0', '0', '1588.45', '-4407.94', '7.18797', '2.05219', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
