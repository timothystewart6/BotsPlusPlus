SET
@ENTRY = 900086,
@NAME = "Wal'rufus",
@SUBNAME = "Reputation Master";

REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,scale,npcflag,InhabitType) VALUES
(@ENTRY,28218,@NAME,@SUBNAME,80,80,35,1,128,3);

REPLACE INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`extendedcost`) VALUES
 (@ENTRY, '0', '100000', '0', '0', '0'),
 (@ENTRY, '0', '100001', '0', '0', '0'),
 (@ENTRY, '0', '100002', '0', '0', '0'),
 (@ENTRY, '0', '100003', '0', '0', '0'),
 (@ENTRY, '0', '100004', '0', '0', '0'),
 (@ENTRY, '0', '100005', '0', '0', '0'),
 (@ENTRY, '0', '100006', '0', '0', '0'),
 (@ENTRY, '0', '100007', '0', '0', '0'),
 (@ENTRY, '0', '100008', '0', '0', '0'),
 (@ENTRY, '0', '100009', '0', '0', '0'),
 (@ENTRY, '0', '100010', '0', '0', '0'),
 (@ENTRY, '0', '100011', '0', '0', '0'),
 (@ENTRY, '0', '100012', '0', '0', '0'),
 (@ENTRY, '0', '100013', '0', '0', '0'),
 (@ENTRY, '0', '100014', '0', '0', '0'),
 (@ENTRY, '0', '100015', '0', '0', '0');

REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
 ('15130000', @ENTRY, '1', '1', '1', '0', '0', '1597.131348', '-4403.859375', '7.566588', '2.012756', '300', '0', '0', '1', '0', '0', '0', '0', '0'),
 ('15130001', @ENTRY, '0', '1', '1', '0', '0', '-8841.624023', '651.309509', '96.679054', '3.869612', '300', '0', '0', '1', '0', '0', '0', '0', '0');
