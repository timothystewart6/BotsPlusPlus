-- Reference class to add some missing spells you get from quest and some others.
SET @Deathknight :=90001;
SET @Druid :=90001; -- Adding missing spell you get from quest.
SET @Hunter :=90001; -- Adding missing spell you get from quest.
SET @Mage :=90001; -- Adding missing spell you get from quest.
SET @Paladin :=90001; -- Adding missing spell you get from quest.
SET @Rogue :=90001; -- Adding missing spell you get from quest.
SET @Shaman :=90001; -- Adding missing spell you get from quest.
SET @Hunter :=90001; -- Adding missing spell you get from quest.
SET @Warlock :=90001; -- Adding missing spell you get from quest.
SET @Warrior :=90001; -- Adding missing spell you get from quest.
SET @Skills :=90001;
SET @Trainer :=90001;
SET @NAME := "Ulf";
SET @SUBNAME := "Trainer Master";
SET @COMMENT := 'Trainer Master';
SET @MODEL := 30790;

-- Clean Trainer before inserting new NPC,spells & skills.
DELETE FROM creature WHERE id = @Trainer;
DELETE FROM creature_template WHERE entry = @Trainer;
DELETE FROM npc_trainer WHERE id = @Trainer;

-- Create Trainer NPC
INSERT INTO creature_template (entry,modelid1,name,subname,minlevel,maxlevel,faction,npcflag,scale,unit_class,trainer_type,type,inhabittype) VALUES
(@Trainer,@MODEL,@NAME,@SUBNAME,80,80,35,51,1,2,2,7,3);

-- Insert spells to trainer
INSERT INTO npc_trainer (id,spellid) VALUES
(@Trainer,-200001), -- Warrior-Lowlevel
(@Trainer,-200002), -- Warrior-Highlevel
(@Trainer,-200003), -- Paladin-Lowlevel
(@Trainer,-200004), -- Paladin-Highlevel
(@Trainer,-200005), -- Druid-Lowlevel
(@Trainer,-200006), -- Druid-Highlevel
(@Trainer,-200007), -- Mage-Lowlevel
(@Trainer,-200008), -- Mage-Highlevel
(@Trainer,-200009), -- Warlock-Lowlevel
(@Trainer,-200010), -- Warlock-Highlevel
(@Trainer,-200011), -- Priest-Lowlevel
(@Trainer,-200012), -- Priest-Highlevel
(@Trainer,-200013), -- Hunter-Lowlevel
(@Trainer,-200014), -- Hunter-Highlevel
(@Trainer,-200015), -- Rogue-Lowlevel
(@Trainer,-200016), -- Rogue-Highlevel
(@Trainer,-200017), -- Shaman-Lowlevel
(@Trainer,-200018); -- Shaman-Highlevel
-- (@Trainer,-200019); -- Death Knights-Alllevel (Disable because alot of frost spell available to any class. Remade the DK spells and will remove the one trainable by any class)

-- DeathKnight Spells
INSERT INTO npc_trainer (`id`,`spellid`,`moneycost`,`reqskillline`,`reqskillrank`,`reqlevel`) VALUES 
(@Deathknight,50977,0,0,0,55), -- Death Gate
(@Deathknight,53428,0,0,0,55), -- Runeforging
(@Deathknight,49998,5600,0,0,56), -- Death Strike Rank 1
(@Deathknight,50842,5600,0,0,56), -- Pestilence
(@Deathknight,46584,5600,0,0,56), -- Raise Dead
(@Deathknight,48263,5700,0,0,57), -- Frost Presence
(@Deathknight,47528,5700,0,0,57), -- Mind Freeze
(@Deathknight,48721,5800,0,0,58), -- Blood Boil Rank 1
(@Deathknight,45524,5800,0,0,58), -- Chains of Ice
(@Deathknight,49926,5900,0,0,59), -- Blood Strike Rank 2
(@Deathknight,55258,5900,0,0,59), -- Heart Strike Rank 2
(@Deathknight,47476,5900,0,0,59), -- Strangulate
(@Deathknight,51325,300,0,0,60), -- Corpse Explosion Rank 2
(@Deathknight,43265,6000,0,0,60), -- Death and Decay Rank 1
-- (@Deathknight,51416,6200,0,0,60), -- Frost Strike Rank 2
(@Deathknight,49917,5800,0,0,60), -- Plague Strike Rank 2
(@Deathknight,49896,61000,0,0,61), -- Icy Touch Rank 2
-- (@Deathknight,49020,61000,0,0,61), -- Obliterate Rank 1
-- (@Deathknight,3714,61000,0,0,61), -- Path of Frost
(@Deathknight,49892,59000,0,0,62), -- Death Coil Rank 2
(@Deathknight,48792,62000,0,0,62), -- Icebound Fortitude
(@Deathknight,49999,65000,0,0,63), -- Death Strike Rank 2
(@Deathknight,49927,64000,0,0,64), -- Blood Strike Rank3
(@Deathknight,45529,64000,0,0,64), -- Blood Tap
(@Deathknight,55259,3200,0,0,64), -- Heart Strike Rank 3
(@Deathknight,56222,65000,0,0,65), -- Dark Command
-- (@Deathknight,51417,3250,0,0,65), -- Frost Strike Rank 3
-- (@Deathknight,57330,65000,0,0,65), -- Horn of Winter Rank 1
(@Deathknight,49918,65000,0,0,65), -- Plague Strike Rank 3
(@Deathknight,49939,66000,0,0,66), -- Blood Boil Rank 2
(@Deathknight,48743,66000,0,0,66), -- Death Pact
(@Deathknight,49936,68000,0,0,67), -- Death and Decay Rank 2
(@Deathknight,49903,67000,0,0,67), -- Icy Touch Rank 3
-- (@Deathknight,51423,67000,0,0,67), -- Obliterate Rank 2
-- (@Deathknight,56815,67000,0,0,67), -- Rune Strike
(@Deathknight,55265,18000,0,0,67), -- Scourge Strike Rank 2
(@Deathknight,48707,68000,0,0,68), -- Anti-Magic Shell
(@Deathknight,49893,68000,0,0,68), -- Death Coil Rank 3
(@Deathknight,49928,69000,0,0,69), -- Blood Strike Rank 4
(@Deathknight,55260,3450,0,0,69), -- Heart Strike Rank 4
(@Deathknight,51326,18000,0,0,70), -- Corpse Explosion Rank 3
(@Deathknight,45463,63000,0,0,70), -- Death Strike Rank 3
-- (@Deathknight,51418,18000,0,0,70), -- Frost Strike Rank 4
-- (@Deathknight,51409,3350,0,0,70), -- Howling Blast Rank 2
(@Deathknight,49919,360000,0,0,70), -- Plague strike Rank 4
(@Deathknight,48265,360000,0,0,70), -- Unholy Presence
(@Deathknight,49940,360000,0,0,72), -- Blood Boil Rank 3
(@Deathknight,61999,360000,0,0,72), -- Raise Ally
(@Deathknight,49937,360000,0,0,73), -- Death and Decay Rank 3
(@Deathknight,49904,360000,0,0,73), -- Icy Touch Rank 4
-- (@Deathknight,51424,360000,0,0,73), -- Obliterate Rank 3
(@Deathknight,55270,18000,0,0,73), -- Scourge Strike Rank 3
(@Deathknight,49929,360000,0,0,74), -- Blood Strike Rank 5
(@Deathknight,55261,18000,0,0,74), -- Heart Strike Rank 5
(@Deathknight,51327,18000,0,0,75), -- Corpse Explosion Rank 4
(@Deathknight,49923,360000,0,0,75), -- Death Strike Rank 4
(@Deathknight,47568,360000,0,0,75), -- Empower Rune Weapon
-- (@Deathknight,51419,18000,0,0,75), -- Frost Strike Rank 5
-- (@Deathknight,57623,360000,0,0,75), -- Horn of Winter Rank 2
-- (@Deathknight,51410,18000,0,0,75), -- Howling Blast Rank 3
(@Deathknight,49920,360000,0,0,75), -- Plague Strike Rank 5
(@Deathknight,49894,360000,0,0,76), -- Death Coil Rank 4
(@Deathknight,49941,360000,0,0,78), -- Blood Boil Rank 4
(@Deathknight,49909,360000,0,0,78), -- Icy Touch Rank 5
-- (@Deathknight,51425,360000,0,0,79), -- Obliterate Rank 4
(@Deathknight,55271,18000,0,0,79), -- Scourge Strike Rank 4
(@Deathknight,42650,360000,0,0,80), -- Army of the Dead
(@Deathknight,49930,360000,0,0,80), -- Blood Strike Rank 6
(@Deathknight,51328,18000,0,0,80), -- Corpse Explosion Rank 5
(@Deathknight,49895,360000,0,0,80), -- Death Coil Rank 5
(@Deathknight,49924,360000,0,0,80), -- Death Strike Rank 5
(@Deathknight,49938,360000,0,0,80), -- Death and Decay Rank 4
-- (@Deathknight,55268,18000,0,0,80), -- Frost Strike Rank 6
(@Deathknight,55262,18000,0,0,80), -- Heart Strike Rank 6
-- (@Deathknight,51411,18000,0,0,80), -- Howling Blast Rank 4
(@Deathknight,49921,360000,0,0,80), -- Plague Strike Rank 6
-- Rune Forging
(@Deathknight,54447,5700,0,0,57), -- Rune of Spellbreaking
(@Deathknight,53342,5700,0,0,57), -- Rune of Spellshattering
(@Deathknight,53331,6000,0,0,60), -- Rune of Lichbane
(@Deathknight,54446,68000,0,0,63), -- Rune of Swordbreaking
(@Deathknight,53323,63000,0,0,63), -- Rune of Swordshattering
(@Deathknight,53344,360000,0,0,70), -- Rune of the Fallen Crusader
(@Deathknight,62158,360000,0,0,72); -- Rune of the Stoneskin Gargoyle

-- Missing spells you get from quest.
INSERT INTO `npc_trainer` (`id`,`spellid`,`moneycost`,`reqskillline`,`reqskillrank`,`reqlevel`) VALUES 
(@Druid,5487,0,0,0,10), -- Bear Form
(@Druid,1446,0,0,0,10), -- Aquatic Form
(@Druid,8947,0,0,0,10), -- Cure Poison
(@Druid,6807,0,0,0,10), -- Maul
(@Druid,6795,0,0,0,10), -- Growl
(@Paladin,7328,0,0,0,10), -- Redemption Rank 1
(@Shaman,8071,0,0,0,4), -- Stoneskin Totem Rank 1
(@Shaman,3599,0,0,0,10), -- Searing Totem Rank 1
(@Shaman,5394,0,0,0,20), -- Healing Stream Totem Rank 1
(@Hunter,883,0,0,0,10), -- Call Pet
(@Hunter,2641,0,0,0,10), -- Dismiss Pet
(@Hunter,6991,0,0,0,10), -- Feed Pet
(@Hunter,982,0,0,0,10), -- Revive Pet
(@Hunter,1515,0,0,0,10), -- Tame Beast
(@Mage,61305,0,0,0,60), -- Polymorph (Black Cat)
(@Mage,28272,0,0,0,60), -- Polymorph (Pig)
(@Mage,61721,0,0,0,60), -- Polymorph (Rabbit)
(@Mage,61780,0,0,0,60), -- Polymorph (Turkey)
(@Mage,28271,0,0,0,60), -- Polymorph (Turtle)
(@Mage,61316,0,0,0,80), -- Dalaran Brillance
(@Mage,61024,0,0,0,80), -- Dalaran Intellect
(@Warlock,688,0,0,0,10), -- Summon Imp
(@Warlock,697,0,0,0,10), -- Summon Voidwalker
(@Warlock,712,0,0,0,20), -- Summon Succubus
(@Warlock,691,0,0,0,30), -- Summon Felhunter
(@Warlock,1122,0,0,0,50), -- Inferno
(@Warlock,18540,0,0,0,60), -- Ritual of Doom
(@Warrior,71,0,0,0,10), -- Defensive Stance
(@Warrior,7386,0,0,0,10), -- Sunder Armor
(@Warrior,355,0,0,0,10), -- Taunt
(@Warrior,2458,0,0,0,30); -- Berserker Stance

-- Skills
INSERT INTO `npc_trainer` (`id`,`spellid`,`moneycost`,`reqskillline`,`reqskillrank`,`reqlevel`) VALUES 
(@Skills,33388,40000,0,0,20), -- Apprentice Riding
(@Skills,33391,500000,33388,0,40), -- Journeyman Riding
(@Skills,34090,2500000,33391,0,60), -- Expert Riding
(@Skills,34091,50000000,34090,0,70), -- Artisan Riding
(@Skills,54197,10000000,34090,0,77), -- Cold Weather Flying
(@Skills,196,10000,0,0,1), -- One-Handed Axes
(@Skills,197,10000,0,0,1), -- Two-Handed Axes
(@Skills,198,10000,0,0,1), -- One-Handed Maces
(@Skills,199,10000,0,0,1), -- Two-Handed Maces
(@Skills,200,10000,0,0,1), -- Polearms
(@Skills,201,10000,0,0,1), -- One-Handed Swords
(@Skills,202,10000,0,0,1), -- Two-Handed Swords
(@Skills,227,10000,0,0,1), -- Staves
(@Skills,264,10000,0,0,1), -- Bows
(@Skills,266,10000,0,0,1), -- Guns
(@Skills,1180,10000,0,0,1), -- Daggers
(@Skills,2567,10000,0,0,1), -- Throwns
(@Skills,5011,10000,0,0,1), -- Crossbows
(@Skills,15590,10000,0,0,1), -- Fists
(@Skills,8737,10000,0,0,40), -- Mail Armor
(@Skills,750,10000,0,0,40); -- Plate Armor

REPLACE INTO creature (guid, id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, dynamicflags) VALUE
('210069', @Trainer, '1', '1', '1', '0', '0', '1577.506714', '-4399.330078', '6.729856', '5.329268', '300', '0', '0', '4274', '3994', '0', '0', '134217728', '0'),
('210070', @Trainer, '0', '1', '1', '0', '0', '-8847.464844', '628.872864', '94.809029', '0.543854', '300', '0', '0', '4274', '3994', '0', '0', '134217728', '0');

DELETE FROM `spell_required` WHERE (`spell_id`=5784);
DELETE FROM `spell_required` WHERE (`req_spell`=686);
INSERT INTO `spell_required` (`spell_id`, `req_spell`) VALUES ('5784', '686')