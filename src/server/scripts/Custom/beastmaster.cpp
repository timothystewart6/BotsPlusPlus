/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2009-2014 DSS Mortos <dss_mortos@outlook.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 #include "Config.h"
 #include "Pet.h"
 
 enum GOSSIPS {
     GOSSIP_OPTION_MAINMENU                  = 20,        //Main Menu entry
     GOSSIP_OPTION_NEWPET_EXOTIC             = 21,        //Exotic pet menu entry
     GOSSIP_OPTION_NEWPET                    = 22,        //Normal pet menu entry
     GOSSIP_OPTION_CHIMERA                   = 23,        //Cast Pet Chimera
     GOSSIP_OPTION_CORE_HOUND                = 24,        //Cast Pet Core Hound
     GOSSIP_OPTION_DEVILSAUR                 = 25,        //Cast Pet Devilsaur
     GOSSIP_OPTION_RHINO                     = 26,        //Cast Pet Rhino
     GOSSIP_OPTION_SILITHID                  = 27,        //Cast Pet Silithid
     GOSSIP_OPTION_WORM                      = 28,        //Cast Pet Worm
     GOSSIP_OPTION_SPIRIT_BEAST              = 29,        //Cast Pet SpiritBeast
     GOSSIP_OPTION_BAT                       = 30,        //Cast Pet Bat
     GOSSIP_OPTION_BOAR                      = 31,        //Cast Pet Boar
     GOSSIP_OPTION_BEAR                      = 32,        //Cast Pet Bear
     GOSSIP_OPTION_CAT                       = 33,        //Cast Pet Cat
     GOSSIP_OPTION_CARRION_BIRD              = 34,        //Cast Pet Carrion Bird
     GOSSIP_OPTION_CROCOLISK                 = 35,        //Cast Pet Crocolisk
     GOSSIP_OPTION_CRAB                      = 36,        //Cast Pet Crab
     GOSSIP_OPTION_DRAGONHAWK                = 37,        //Cast Pet Dragonhawk
     GOSSIP_OPTION_GORILLA                   = 38,        //Cast Pet Gorilla
     GOSSIP_OPTION_HOUND                     = 39,        //Cast Pet Hound
     GOSSIP_OPTION_HYENA                     = 40,        //Cast Pet Hyena
     GOSSIP_OPTION_MOTH                      = 41,        //Cast Pet Moth
     GOSSIP_OPTION_NETHER_RAY                = 42,        //Cast Pet Nether Ray
     GOSSIP_OPTION_OWL                       = 43,        //Cast Pet Bird of Prey
     GOSSIP_OPTION_RAPTOR                    = 44,        //Cast Pet Raptor
     GOSSIP_OPTION_RAVAGER                   = 45,        //Cast Pet Ravager
     GOSSIP_OPTION_SCORPID                   = 46,        //Cast Pet Scorpid
     GOSSIP_OPTION_SERPENT                   = 47,        //Cast Pet Serpent
     GOSSIP_OPTION_SPIDER                    = 48,        //Cast Pet Spider
     GOSSIP_OPTION_TURTLE                    = 49,        //Cast Pet Turtle
     GOSSIP_OPTION_WASP                      = 50,        //Cast Pet Wasp
     GOSSIP_OPTION_WARP_STALKER              = 51,        //Cast Pet Warp Stalker
     GOSSIP_OPTION_WIND_SERPENT              = 52,        //Cast Pet Wind Serpent
     GOSSIP_OPTION_WOLF                      = 53,        //Cast Pet Wolf
     GOSSIP_OPTION_SPOREBAT                  = 55,        //Cast Pet Sporebat
     GOSSIP_OPTION_TALLSTRIDER               = 56,        //Cast Pet Tallstriker
 };
 
 enum NormalPetEntry {
     SPELL_PET_BAT                       = 46717,          //Add Tamable Bat (26017)
     SPELL_PET_BOAR                      = 46718,          //Add Tamable Boar (26020)
     SPELL_PET_BEAR                      = 64330,          //Add Tamable Bear (34025)
     SPELL_PET_CAT                       = 46720,          //Add Tamable Cat (26021)
     SPELL_PET_CARRION_BIRD              = 46719,          //Add Tamable Carrion Bird (26019)
     SPELL_PET_CROCOLISK                 = 64332,          //Add Tamable Crocolisk (34027)
     SPELL_PET_CRAB                      = 64331,          //Add Tamable Crab (34026)
     SPELL_PET_DRAGONHAWK                = 46721,          //Add Tamable Dragonhawk (26024)
     SPELL_PET_HOUND                     = 96234,          //Add Tamable Dog (52010)
     SPELL_PET_GORILLA                   = 64333,          //Add Tamable Gorilla (34028)
     SPELL_PET_HYENA                     = 64335,          //Add Tamable Hyena (34019)
     SPELL_PET_MOTH                      = 64334,          //Add Tamable Moth (34021)
     SPELL_PET_NETHER_RAY                = 46722,          //Add Tamable Nether Ray (26027)
     SPELL_PET_BIRD_OF_PREY              = 46723,          //Add Tamable Bird of Prey (26028)
     SPELL_PET_RAPTOR                    = 46724,          //Add Tamable Raptor (26029)
     SPELL_PET_RAVAGER                   = 46725,          //Add Tamable Ravager (26030)
     SPELL_PET_SCORPID                   = 46726,          //Add Tamable Scorpid (26031)
     SPELL_PET_SERPENT                   = 46727,          //Add Tamable Serpent (26032)
     SPELL_PET_SPIDER                    = 46728,          //Add Tamable Spider (26033)
     SPELL_PET_SPOREBAT                  = 64336,          //Add Tameable Sporebat (34018)
     SPELL_PET_TALLSTRIDER               = 64337,          //Add Tameable Tallstrider (34022)
     SPELL_PET_TURTLE                    = 64339,          //Add Tamable Turtle (34029)
     SPELL_PET_WASP                      = 64338,          //Add Tamable Wasp (34024)
     SPELL_PET_WARP_STALKER              = 46716,          //Add Tamable Warp Stalker (26037)
     SPELL_PET_WIND_SERPENT              = 46729,          //Add Tamable Wind Serpent (26038)
     SPELL_PET_WOLF                      = 46730,          //Add Tamable Wolf (26016)
 };
 
 enum ExoticPetEntry {
     SPELL_PET_CHIMAERA           = 63177,        //Add Tamable Chimaera (33504)
     SPELL_PET_CORE_HOUND         = 63178,        //Add Tamable Core Hound (33502)
     SPELL_PET_DEVILSAUR          = 63179,        //Add Tamable Devilsaur (33505)
     SPELL_PET_RHINO              = 63180,        //Add Tamable Rhino (33506)
     SPELL_PET_SILITHID           = 63183,        //Add Tamable Silithid (33508)
     SPELL_PET_WORM               = 63185,        //Add Tamable Worm (33511)
     SPELL_PET_SPIRIT_BEAST       = 63184,        //Add Tamable Spirit Beast (33510)
 };
 
 class beastmaster_creaturescript : public CreatureScript {
 public:
    
     beastmaster_creaturescript() : CreatureScript("beastmaster_creaturescript") { }
 
     void CreateNewPet(Player* player, Creature* npc, uint32 entry) {
         //check for existing pets
         if (player->GetPet()) {
             ChatHandler(player->GetSession()).PSendSysMessage("You already have a pet.");
             player->PlayerTalkClass->SendCloseGossip();
             return;
         }
         //add the new pet
         npc->CastSpell(player, entry);
         if (Pet* newpet = player->GetPet())
             //because feed your pet is boring
             newpet->SetPower(POWER_HAPPINESS, 1048000);
         //we're done!
         player->PlayerTalkClass->SendCloseGossip();
     }
 
     void DisplayMainMenu(Player* player, Creature* npc) {
         if (player->CanTameExoticPets()) 
             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "What exotic pets do you have?", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_NEWPET_EXOTIC);
         
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "I need a new pet.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_NEWPET);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, "Sell me some food for my pet.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_VENDOR);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Take me to the stable.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_STABLEPET);
         player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
     }
 
     void DisplayExoticPetMenu(Player* player, Creature* npc) {
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Main Menu.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_MAINMENU);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Chimaera.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_CHIMERA);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Core Hound.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_CORE_HOUND);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Devilsaur.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_DEVILSAUR);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Rhino.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_RHINO);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Silithid.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_SILITHID);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Worm.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_WORM);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Spirit Beast", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_SPIRIT_BEAST);
         player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
     }
 
     void DisplayNormalPetMenu(Player* player, Creature* npc) {
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Main Menu.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_MAINMENU);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Bat.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_BAT);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Boar.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_BOAR);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Bear.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_BEAR);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Cat.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_CAT);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Carrion Bird.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_CARRION_BIRD);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Crocolisk.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_CROCOLISK);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Crab.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_CRAB);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Dragonhawk.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_DRAGONHAWK);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Gorilla.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GORILLA);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Hound.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_HOUND);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Hyena.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_HYENA);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Moth.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_MOTH);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Nether Ray.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_NETHER_RAY);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Owl.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_OWL);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Raptor.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_RAPTOR);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Ravager.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_RAVAGER);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Scorpid.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_SCORPID);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Serpent.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_SERPENT);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Spider.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_SPIDER);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Sporebat.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_SPIDER);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Tallstrider.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_TALLSTRIDER);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Turtle.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_TURTLE);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Warp Stalker.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_WARP_STALKER);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Wasp.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_WASP);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Wind Serpent.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_WIND_SERPENT);
         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Wolf.",  GOSSIP_SENDER_MAIN, GOSSIP_OPTION_WOLF);
         player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
     }
 
     bool OnGossipHello(Player* player, Creature* npc) {
         if (player->getClass() != CLASS_HUNTER) {
             player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
             return true;
         }
 
         DisplayMainMenu(player, npc);
         return true;
     }
 
     bool OnGossipSelect(Player* player, Creature* npc, uint32 sender, uint32 action) {
         if (!player)
             return false;
 
         player->PlayerTalkClass->ClearMenus();
         switch (action) {
             //Display Main Menu
             case GOSSIP_OPTION_MAINMENU:
                 DisplayMainMenu(player, npc);
                 break;
             //Exotic Pets
             case GOSSIP_OPTION_NEWPET_EXOTIC:
                 DisplayExoticPetMenu(player, npc);
                 break;
             case GOSSIP_OPTION_CHIMERA:
                 CreateNewPet(player, npc, SPELL_PET_CHIMAERA);
                 break;
             case GOSSIP_OPTION_CORE_HOUND:
                 CreateNewPet(player, npc, SPELL_PET_CORE_HOUND);
                 break;
             case GOSSIP_OPTION_DEVILSAUR:
                 CreateNewPet(player, npc, SPELL_PET_DEVILSAUR);
                 break;
             case GOSSIP_OPTION_RHINO:
                 CreateNewPet(player, npc, SPELL_PET_RHINO);
                 break;
             case GOSSIP_OPTION_SILITHID:
                 CreateNewPet(player, npc, SPELL_PET_SILITHID);
                 break;
             case GOSSIP_OPTION_WORM:
                 CreateNewPet(player, npc, SPELL_PET_WORM);
                 break;
             case GOSSIP_OPTION_SPIRIT_BEAST:
                 CreateNewPet(player, npc, SPELL_PET_SPIRIT_BEAST);
                 break;
             //Normal pets
             case GOSSIP_OPTION_NEWPET:
                 DisplayNormalPetMenu(player, npc);
                 break;
             case GOSSIP_OPTION_BAT:
                 CreateNewPet(player, npc, SPELL_PET_BAT);
                 break;
             case GOSSIP_OPTION_BOAR:
                 CreateNewPet(player, npc, SPELL_PET_BOAR);
                 break;
             case GOSSIP_OPTION_BEAR:
                 CreateNewPet(player, npc, SPELL_PET_BEAR);
                 break;
             case GOSSIP_OPTION_CAT:
                 CreateNewPet(player, npc, SPELL_PET_CAT);
                 break;
             case GOSSIP_OPTION_CARRION_BIRD:
                 CreateNewPet(player, npc, SPELL_PET_CARRION_BIRD);
                 break;
             case GOSSIP_OPTION_CROCOLISK:
                 CreateNewPet(player, npc, SPELL_PET_CARRION_BIRD);
                 break;
             case GOSSIP_OPTION_CRAB:
                 CreateNewPet(player, npc, SPELL_PET_CRAB);
                 break;
             case GOSSIP_OPTION_DRAGONHAWK:
                 CreateNewPet(player, npc, SPELL_PET_DRAGONHAWK);
                 break;
             case GOSSIP_OPTION_GORILLA:
                 CreateNewPet(player, npc, SPELL_PET_GORILLA);
                 break;
             case GOSSIP_OPTION_HOUND:
                 CreateNewPet(player, npc, SPELL_PET_HOUND);
                 break;
             case GOSSIP_OPTION_HYENA:
                 CreateNewPet(player, npc, SPELL_PET_HYENA);
                 break;
             case GOSSIP_OPTION_MOTH:
                 CreateNewPet(player, npc, SPELL_PET_MOTH);
                 break;
             case GOSSIP_OPTION_NETHER_RAY:
                 CreateNewPet(player, npc, SPELL_PET_NETHER_RAY);
                 break;
             case GOSSIP_OPTION_OWL:
                 CreateNewPet(player, npc, SPELL_PET_BIRD_OF_PREY);
                 break;
             case GOSSIP_OPTION_RAPTOR:
                 CreateNewPet(player, npc, SPELL_PET_RAPTOR);
                 break;
             case GOSSIP_OPTION_RAVAGER:
                 CreateNewPet(player, npc, SPELL_PET_RAVAGER);
                 break;
             case GOSSIP_OPTION_SCORPID:
                 CreateNewPet(player, npc, SPELL_PET_SCORPID);
                 break;
             case GOSSIP_OPTION_SERPENT:
                 CreateNewPet(player, npc, SPELL_PET_SERPENT);
                 break;
             case GOSSIP_OPTION_SPIDER:
                 CreateNewPet(player, npc, SPELL_PET_SPIDER);
                 break;
             case GOSSIP_OPTION_TURTLE:
                 CreateNewPet(player, npc, SPELL_PET_TURTLE);
                 break;
             case GOSSIP_OPTION_WASP:
                 CreateNewPet(player, npc, SPELL_PET_WASP);
                 break;
             case GOSSIP_OPTION_WIND_SERPENT:
                 CreateNewPet(player, npc, SPELL_PET_WIND_SERPENT);
                 break;
             case GOSSIP_OPTION_WOLF:
                 CreateNewPet(player, npc, SPELL_PET_WOLF);
                 break;
             case GOSSIP_OPTION_SPOREBAT:
                 CreateNewPet(player, npc, SPELL_PET_SPOREBAT);
                 break;
             case GOSSIP_OPTION_TALLSTRIDER:
                 CreateNewPet(player, npc, SPELL_PET_TALLSTRIDER);
                 break;
             //Stable
             case GOSSIP_OPTION_STABLEPET:
                 player->GetSession()->SendStablePet(npc->GetGUID());
                 break;
             //Food vendor
             case GOSSIP_OPTION_VENDOR:
                 player->GetSession()->SendListInventory(npc->GetGUID());
                 break;
         }
         return true;
     }
 };
 
 void AddSC_beastmaster_npc() {
     new beastmaster_creaturescript;
 }