SET
@ENTRY  := 190004,
@ID     := 190010;
REPLACE INTO `creature_template` (entry,modelid1,name,subname,minlevel,maxlevel,faction,npcflag,scale,AIName,InhabitType) VALUES
(@ENTRY,31011,"Commencer","Welcome Master",80,80,35,2,.75,"SmartAI",3);

REPLACE INTO quest_template (Id, QuestType, LogTitle, RewardMoney, RewardNextQuest) VALUES
   (@ID, 0,"|cff58FAF4Welcome",10000,@ID);
 REPLACE INTO `creature_queststarter` VALUES
 (@ENTRY, @ID);
REPLACE INTO `creature_questender` VALUES
 (@ENTRY, @ID);


 REPLACE INTO `quest_offer_reward` (`ID`, `RewardText`)
VALUES
	(@ID, "Welcome $N... Thank you for deciding to play on our realm. This is the first of many quests to do while here, however this may be the easiest. There is much work to be done. $B$BBefore continuing on your journey, be sure to talk to Major Oak.  He offers heirloom gear that levels with you and a mount you can start riding now. $B$BIf you want to boost to level 70 and pick up some raiding gear, be sure to make your way to Stormwind or Orgrimmar. While there, be sure to check the fully stocked Auction House.  You too can make some coin. $B$BGood luck, safe travels, and do not lose faith...");

REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
   (15121656, 190004, 1, 1, 1, 0, 0, -611.809, -4244.23, 38.9562, 3.05946, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121657, 190004, 1, 1, 1, 0, 0, -2914.23, -261.105, 53.2086, 3.34024, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121658, 190004, 1, 1, 1, 0, 0, 10335.8, 828.057, 1326.29, 2.38637, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121659, 190004, 530, 1, 1, 0, 0, -3973.83, -13917.4, 99.4282, 0.44767, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121660, 190004, 530, 1, 1, 0, 0, 10354, -6363.58, 34.9047, 3.15741, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121661, 190004, 0, 1, 1, 0, 0, 1660.83, 1665.7, 120.719, 1.65421, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121662, 190004, 0, 1, 1, 0, 0, -8916.02, -120.186, 82.0557, 3.97086, 300, 0, 0, 5342, 0, 0, 0, 0, 0),
   (15121663, 190004, 0, 1, 1, 0, 0, -6217.81, 334.406, 383.246, 3.31351, 300, 0, 0, 5342, 0, 0, 0, 0, 0);