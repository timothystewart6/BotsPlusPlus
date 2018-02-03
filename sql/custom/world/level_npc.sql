
SET
@ENTRY = 601000,
@NAME = "Level",
@SUBNAME = "Level Vendor";

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType,ScriptName,AIName,iconname) VALUES
(@ENTRY,28970,@NAME,@SUBNAME,80,80,35,1,35,3,"Level_NPC","SmartAI","Directions");


-- INSERT INTO `creature_template` VALUES ('14', '0', '0', '0', '0', '0', '21572', '0', '0', '0', 'Level Npc', '', 'Directions', '0', '71', '71', '0', '35', '35', '1', '1', '1.14286', '1.25', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '7', '138936390', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'SmartAI', '0', '3', '1', '1.56', '1.56', '1.56', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '2', 'vote_NPC', '1');



REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
-- Orgimmar
('15200100', @ENTRY, '1', '1', '1', '0', '0', '1574.658569', '-4401.979492', '7.172108', '5.661114', '300', '0', '0', '1', '0', '0', '0', '0', '0'),
-- Stormwind
('15200101', @ENTRY, '0', '1', '1', '0', '0', '-8839.585938', '648.703979', '95.914322', '3.888847', '300', '0', '0', '1', '0', '0', '0', '0', '0');
