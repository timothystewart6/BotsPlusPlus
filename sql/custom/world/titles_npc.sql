SET
@ENTRY = 601001,
@NAME = "McBotface",
@SUBNAME = "Title Master";

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType,ScriptName,AIName,iconname) VALUES
(@ENTRY,28777,@NAME,@SUBNAME,80,80,35,.15,35,3,"TitleNpc","SmartAI","Directions");


REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
-- Orgimmar
-- ('15200100', @ENTRY, '1', '1', '1', '0', '0', '1570.647095', '-4407.840332', '7.654320', '5.810328', '300', '0', '0', '1', '0', '0', '0', '0', '0'),
-- Stormwind
('15200101', @ENTRY, '0', '1', '1', '0', '0', '-8852.091797', '640.012329', '96.422478', '1.030003', '300', '0', '0', '1', '0', '0', '0', '0', '0');
