SET @AURANPC := 99950;
SET @GOPTION := 58055;
SET @NAME := "Faegan";
SET @SUBNAME := "Aura Master";
SET @CONFIRM := 'Are you sure?';
SET @COMMENT := 'Aura Master';
SET @MODEL := '17704';

DELETE FROM gossip_menu_option WHERE menu_id = @GOPTION;
DELETE FROM smart_scripts WHERE entryorguid = @AURANPC;
DELETE FROM creature_template WHERE entry = @AURANPC;
DELETE FROM creature WHERE id = @AURANPC;

INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, HealthModifier, ManaModifier, ArmorModifier, faction, npcflag, speed_walk, speed_run, scale, rank, DamageModifier, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, AiName) VALUES
(@AURANPC, @MODEL, @NAME, @SUBNAME, 'Directions', '50000', 71, 71, 1.56, 1.56, 1.56, 35, 3, 1, 1.14286, 1, 1, 1, 1, 2, 7, 138936390, 3, 1, 2, 'SmartAI');

SET @GID := IFNULL((SELECT id FROM gossip_menu_option WHERE menu_id = @GOPTION ORDER BY id DESC LIMIT 1), 0)+1;
INSERT INTO gossip_menu_option (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(@GOPTION, @GID, 2, 'Duraks Shield', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+1, 2, 'Shadowmourne', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+2, 2, 'Blood Orb', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+3, 2, 'Purple Banish', 1, 1, @GOPTION, 0, 0, 0, NULL),
(@GOPTION, @GID+4, 2, 'Gas Mask Pump', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+5, 2, 'Red Aura', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+6, 2, 'Burning', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+7, 2, 'Hearts', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+8, 2, 'Sleep', 1, 1, @GOPTION, 0, 0, 0, NULL),
(@GOPTION, @GID+9, 2, 'Bijou Red', 1, 1, @GOPTION, 0, 0, 0, NULL),
(@GOPTION, @GID+10, 2, 'Shadowform', 1, 1, @GOPTION, 0, 0, 0, NULL),
(@GOPTION, @GID+11, 2, 'Remove Duraks Shield', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+12, 2, 'Remove Shadowmourne', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+13, 2, 'Remove Blood Orb', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+14, 2, 'Remove Purple Banish', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+15, 2, 'Remove Gas Mask Pump', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+16, 2, 'Remove Red Aura', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM), 
(@GOPTION, @GID+17, 2, 'Remove Burning', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM), 
(@GOPTION, @GID+18, 2, 'Remove Hearts', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM), 
(@GOPTION, @GID+19, 2, 'Remove Sleep', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+20, 2, 'Remove Bijou Red', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+21, 2, 'Remove Shadowform', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM),
(@GOPTION, @GID+22, 2, 'Remove all Visuals', 1, 1, @GOPTION, 0, 0, 0, @CONFIRM);


SET @SID := IFNULL((SELECT id FROM smart_scripts WHERE entryorguid = @AURANPC ORDER BY id DESC LIMIT 1), 0)+1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@AURANPC, 0, @SID, 0, 62, 0, 100, 0, @GOPTION, @GID, 0, 0, 75, 74621, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+1, 0, 62, 0, 100, 0, @GOPTION, @GID+1, 0, 0, 75, 72521, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+2, 0, 62, 0, 100, 0, @GOPTION, @GID+2, 0, 0, 75, 68862, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+3, 0, 62, 0, 100, 0, @GOPTION, @GID+3, 0, 0, 75, 72100, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+4, 0, 62, 0, 100, 0, @GOPTION, @GID+4, 0, 0, 75, 71947, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+5, 0, 62, 0, 100, 0, @GOPTION, @GID+5, 0, 0, 75, 48044, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+6, 0, 62, 0, 100, 0, @GOPTION, @GID+6, 0, 0, 75, 43184, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+7, 0, 62, 0, 100, 0, @GOPTION, @GID+7, 0, 0, 75, 20372, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+8, 0, 62, 0, 100, 0, @GOPTION, @GID+9, 0, 0, 75, 47760, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+9, 0, 62, 0, 100, 0, @GOPTION, @GID+8, 0, 0, 75, 20373, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+10, 0, 62, 0, 100, 0, @GOPTION, @GID+10, 0, 0, 75, 55086, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),

(@AURANPC, 0, @SID+11, 0, 62, 0, 100, 0, @GOPTION, @GID+11, 0, 0, 28, 74621, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+12, 0, 62, 0, 100, 0, @GOPTION, @GID+12, 0, 0, 28, 72521, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+13, 0, 62, 0, 100, 0, @GOPTION, @GID+13, 0, 0, 28, 68862, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+14, 0, 62, 0, 100, 0, @GOPTION, @GID+14, 0, 0, 28, 72100, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+15, 0, 62, 0, 100, 0, @GOPTION, @GID+15, 0, 0, 28, 71947, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+16, 0, 62, 0, 100, 0, @GOPTION, @GID+16, 0, 0, 28, 48044, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+17, 0, 62, 0, 100, 0, @GOPTION, @GID+17, 0, 0, 28, 43184, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+18, 0, 62, 0, 100, 0, @GOPTION, @GID+18, 0, 0, 28, 20372, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+19, 0, 62, 0, 100, 0, @GOPTION, @GID+19, 0, 0, 28, 20373, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+20, 0, 62, 0, 100, 0, @GOPTION, @GID+20, 0, 0, 28, 47760, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+21, 0, 62, 0, 100, 0, @GOPTION, @GID+21, 0, 0, 28, 55086, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),

(@AURANPC, 0, @SID+22, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 74621, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+23, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 72521, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+24, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 68862, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+25, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 72100, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+26, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 71947, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+27, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 48044, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+28, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 43184, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+29, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 20372, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+30, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 20373, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+31, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 47760, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT),
(@AURANPC, 0, @SID+32, 0, 62, 0, 100, 0, @GOPTION, @GID+22, 0, 0, 28, 55086, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, @COMMENT);

UPDATE creature_template SET gossip_menu_id = @GOPTION, npcflag = npcflag|1, AIName = 'SmartAI' WHERE Entry = @AURANPC;

REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
('15129989', @AURANPC, '1', '1', '1', '0', '0', '1590.71', '-4444.57', '7.03082', '2.01403', '300', '0', '0', '6495', '0', '0', '0', '0', '0'),
('15129999', @AURANPC, '0', '1', '1', '0', '0', '-8820.324219', '649.191772', '94.519020', '5.159598', '300', '0', '0', '6495', '0', '0', '0', '0', '0');