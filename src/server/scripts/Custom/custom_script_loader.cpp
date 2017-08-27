/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

// This is where scripts' loading functions should be declared:
void AddSC_gon_playerscripts();
void AddSC_accontmounts();
void AddSC_announce_login();
void AddSC_LearnSpellsOnLevelUp();
void AddSC_FireWorksOnLevelUp();
void AddSC_item_enchant_visuals();
void AddSC_Player_Boa();

// Bots
void AddSC_death_knight_bot();
void AddSC_druid_bot();
void AddSC_hunter_bot();
void AddSC_mage_bot();
void AddSC_paladin_bot();
void AddSC_priest_bot();
void AddSC_rogue_bot();
void AddSC_shaman_bot();
void AddSC_warlock_bot();
void AddSC_warrior_bot();
void AddSC_blademaster_bot();
void AddSC_script_bot_commands();

void AddCustomScripts()
{
    AddSC_gon_playerscripts();
    AddSC_accontmounts();
    AddSC_announce_login();
    AddSC_LearnSpellsOnLevelUp();
    AddSC_FireWorksOnLevelUp();
    AddSC_item_enchant_visuals();    
    AddSC_Player_Boa();  
    //Bots
    AddSC_death_knight_bot();
    AddSC_druid_bot();
    AddSC_hunter_bot();
    AddSC_mage_bot();
    AddSC_paladin_bot();
    AddSC_priest_bot();
    AddSC_rogue_bot();
    AddSC_shaman_bot();
    AddSC_warlock_bot();
    AddSC_warrior_bot();
    AddSC_blademaster_bot();
    AddSC_script_bot_commands();
}
