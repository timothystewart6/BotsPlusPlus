SET
@Entry = 190010,
@Name = "Warphoof",
@Subname = "Transmogrifier";

REPLACE INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(@Entry, 29825, 0, @Name, @Subname, NULL, 0, 80, 80, 2, 35, 129, 1, 0, 0, 2000, 0, 1, 0, 7, 138936390, 0, 0, 0, '', 0, 3, 1, 0, 0, 1, 0, 0, 'NPC_TransmogDisplayVendor');

REPLACE INTO `creature` VALUES ('15122156', '190010', '0', '0', '0', '1', '1', '0', '0', '-8829.8', '645.669', '94.5523', '5.32139', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
REPLACE INTO `creature` VALUES ('15122178', '190010', '1', '0', '0', '1', '1', '0', '0', '1591.65', '-4406.32', '6.92044', '2.03883', '300', '0', '0', '12600', '0', '0', '0', '0', '0', '0');
