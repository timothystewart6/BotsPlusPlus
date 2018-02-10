SET
@ENTRY = 601001,
@NAME = "Grunty",
@SUBNAME = "Title Master";

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType,ScriptName,AIName,iconname) VALUES
(@ENTRY,29348,@NAME,@SUBNAME,80,80,35,2.5,35,3,"TitleNpc","SmartAI","Directions");


REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
-- Orgimmar
('15200300', @ENTRY, '1', '1', '1', '0', '0', '1589.864990', '-4393.636719', '6.980998', '4.773604', '300', '0', '0', '1', '0', '0', '0', '0', '0'),

-- Stormwind
('15200301', @ENTRY, '0', '1', '1', '0', '0', '-8852.091797', '640.012329', '96.422478', '1.030003', '300', '0', '0', '1', '0', '0', '0', '0', '0');
