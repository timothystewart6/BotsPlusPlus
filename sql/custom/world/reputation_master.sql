SET
@ENTRY = 190020,
@NAME = "Svipul",
@SUBNAME = "Reputation Master";

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType) VALUES
(@ENTRY,29240,@NAME,@SUBNAME,80,80,35,0.4,128,3);

REPLACE INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`extendedcost`) VALUES
 (@ENTRY, '0', '43950', '0', '0', '1000'),
 (@ENTRY, '0', '44710', '0', '0', '0'),
 (@ENTRY, '0', '44711', '0', '0', '0'),
 (@ENTRY, '0', '44713', '0', '0', '0'),
 (@ENTRY, '0', '45714', '0', '0', '0'),
 (@ENTRY, '0', '45715', '0', '0', '0'),
 (@ENTRY, '0', '45716', '0', '0', '0'),
 (@ENTRY, '0', '45717', '0', '0', '0'),
 (@ENTRY, '0', '45718', '0', '0', '0'),
 (@ENTRY, '0', '45719', '0', '0', '0'),
 (@ENTRY, '0', '45720', '0', '0', '0'),
 (@ENTRY, '0', '45721', '0', '0', '0'),
 (@ENTRY, '0', '45722', '0', '0', '0'),
 (@ENTRY, '0', '45723', '0', '0', '0'),
 (@ENTRY, '0', '49702', '0', '0', '0');

REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
 ('15130000', @ENTRY, '1', '1', '1', '0', '0', '1597.131348', '-4403.859375', '7.566588', '2.012756', '300', '0', '0', '1', '0', '0', '0', '0', '0'),
 ('15130001', @ENTRY, '0', '1', '1', '0', '0', '-8841.624023', '651.309509', '96.679054', '3.869612', '300', '0', '0', '1', '0', '0', '0', '0', '0');
