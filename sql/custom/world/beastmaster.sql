SET 
@BEASTMASTER = 99990,
@Name = "LordPsyan",
@Subname = "Beastmaster";

-- Clean before inserting data

DELETE FROM `creature_template` WHERE `entry` = @BEASTMASTER ;

DELETE FROM `npc_vendor` WHERE `entry` = @BEASTMASTER ;

DELETE FROM `creature` WHERE `id` = @BEASTMASTER ;

-- Beastmaster NPC

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
(@BEASTMASTER,'0','0','0','0','0','26789','0','0','0',@Name,@Subname,'','0','80','80','0','35','129','1','1.14286','0.75','1','0','1500','0','1','1','1','0','0','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','1','1','1','0','0','1','0','0','beastmaster_creaturescript','0');

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(@BEASTMASTER, 0, 3771, 0, 0, 0), -- Wild Hog Shank
(@BEASTMASTER, 0, 3927, 0, 0, 0), -- Fine Aged Cheddar
(@BEASTMASTER, 0, 4541, 0, 0, 0), -- Freshly Baked Bread
(@BEASTMASTER, 0, 4607, 0, 0, 0), -- Delicious Cave Mold
(@BEASTMASTER, 0, 4536, 0, 0, 0), -- Shiny Red Apple
(@BEASTMASTER, 0, 33451, 0, 0, 0); -- Fillet of Icefin


REPLACE INTO `creature` VALUES ('15122174', '99990', '0', '0', '0', '1', '1', '0', '0', '-8837.74', '605.145', '94.2286', '2.45629', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');
REPLACE INTO `creature` VALUES ('15122175', '99990', '1', '0', '0', '1', '1', '0', '0', '1582.41', '-4412.54', '7.87135', '2.39777', '300', '0', '0', '5342', '0', '0', '0', '0', '0', '0');