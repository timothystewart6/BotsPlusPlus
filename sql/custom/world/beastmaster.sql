-- -----------------

-- BeastMasterNPC ---

-- -----------------

SET @BEASTMASTER := 26307 ; -- TTR Beastmaster

-- Clean before inserting data

DELETE FROM `creature_template` WHERE `entry` = @BEASTMASTER ;

DELETE FROM `npc_vendor` WHERE `entry` = @BEASTMASTER ;

DELETE FROM `creature` WHERE `id` = @BEASTMASTER ;

-- Create Beast Master

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES

(@BEASTMASTER, 0, 0, 0, 0, 0, 24028, 0, 0, 0, 'Beastmaster', '', '', 0, 80, 80, 0, 35, 35, 4194433, 1, 1.14286, 1, 0, 1755, 1755, 0, 1504, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'beastmaster_creaturescript', 0);

-- Random Food
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(@BEASTMASTER, 0, 3771, 0, 0, 0), -- Wild Hog Shank
(@BEASTMASTER, 0, 3927, 0, 0, 0), -- Fine Aged Cheddar
(@BEASTMASTER, 0, 4541, 0, 0, 0), -- Freshly Baked Bread
(@BEASTMASTER, 0, 4607, 0, 0, 0), -- Delicious Cave Mold
(@BEASTMASTER, 0, 4536, 0, 0, 0), -- Shiny Red Apple
(@BEASTMASTER, 0, 33451, 0, 0, 0); -- Fillet of Icefin