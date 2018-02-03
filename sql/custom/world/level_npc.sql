
SET
@ENTRY = 601000,
@NAME = "Maiden of the Stars",
@SUBNAME = "Level Master";

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType,ScriptName,AIName,iconname) VALUES
(@ENTRY,28777,@NAME,@SUBNAME,80,80,35,.15,35,3,"Level_NPC","SmartAI","Directions");


REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
-- Orgimmar
('15200100', @ENTRY, '1', '1', '1', '0', '0', '1570.647095', '-4407.840332', '7.654320', '5.810328', '300', '0', '0', '1', '0', '0', '0', '0', '0'),
-- Stormwind
('15200101', @ENTRY, '0', '1', '1', '0', '0', '-8839.855469', '648.560791', '96.271896', '3.892737', '300', '0', '0', '1', '0', '0', '0', '0', '0');
