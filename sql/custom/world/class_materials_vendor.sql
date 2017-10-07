SET
@ENTRY = 600800,
@NAME = "Ja'Nanji",
@SUBNAME = "Class Materials";

DELETE FROM creature_template WHERE entry = @ENTRY;
DELETE FROM creature WHERE id = @ENTRY;

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType) VALUES
(600800,27500,@NAME,@SUBNAME,80,80,35,1,128,3);

REPLACE INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`extendedcost`,`verifiedbuild`) VALUES
  (@ENTRY, '0', '13335', '0', '0', '0', '0'),
  (@ENTRY, '0', '5178', '0', '0', '0', '0'),
  (@ENTRY, '0', '5175', '0', '0', '0', '0'),
  (@ENTRY, '0', '5176', '0', '0', '0', '0'),
  (@ENTRY, '0', '5177', '0', '0', '0', '0'),
  (@ENTRY, '0', '17028', '0', '0', '0', '0'),
  (@ENTRY, '0', '17029', '0', '0', '0', '0'),
  (@ENTRY, '0', '17030', '0', '0', '0', '0'),
  (@ENTRY, '0', '17031', '0', '0', '0', '0'),
  (@ENTRY, '0', '17032', '0', '0', '0', '0'),
  (@ENTRY, '0', '17033', '0', '0', '0', '0'),
  (@ENTRY, '0', '17034', '0', '0', '0', '0'),
  (@ENTRY, '0', '17035', '0', '0', '0', '0'),
  (@ENTRY, '0', '17036', '0', '0', '0', '0'),
  (@ENTRY, '0', '17037', '0', '0', '0', '0'),
  (@ENTRY, '0', '17038', '0', '0', '0', '0'),
  (@ENTRY, '0', '17026', '0', '0', '0', '0'),
  (@ENTRY, '0', '17020', '0', '0', '0', '0'),
  (@ENTRY, '0', '17021', '0', '0', '0', '0'),
  (@ENTRY, '0', '37201', '0', '0', '0', '0'),
  (@ENTRY, '0', '16583', '0', '0', '0', '0'),
  (@ENTRY, '0', '44615', '0', '0', '0', '0'),
  (@ENTRY, '0', '22147', '0', '0', '0', '0'),
  (@ENTRY, '0', '5565', '0', '0', '0', '0'),
  (@ENTRY, '0', '44614', '0', '0', '0', '0'),
  (@ENTRY, '0', '21177', '0', '0', '0', '0'),
  (@ENTRY, '0', '44605', '0', '0', '0', '0'),
  (@ENTRY, '0', '22148', '0', '0', '0', '0'),
  (@ENTRY, '0', '6265', '0', '0', '0', '0');

REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
 ('15115101', @ENTRY, '1', '1', '1', '0', '0', '1586.680420', '-4394.539062', '6.399858', '5.040626', '300', '0', '0', '1', '0', '0', '0', '0', '0'),
 ('15115102', @ENTRY, '0', '1', '1', '0', '0', '-8849.227539', '637.660278', '95.974136', '0.549357', '300', '0', '0', '1', '0', '0', '0', '0', '0');
