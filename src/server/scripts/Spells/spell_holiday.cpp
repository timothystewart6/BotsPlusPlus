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

/*
 * Spells used in holidays/game events that do not fit any other category.
 * Ordered alphabetically using scriptname.
 * Scriptnames in this file should be prefixed with "spell_#holidayname_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "Vehicle.h"

// 45102 Romantic Picnic
enum SpellsPicnic
{
    SPELL_BASKET_CHECK              = 45119, // Holiday - Valentine - Romantic Picnic Near Basket Check
    SPELL_MEAL_PERIODIC             = 45103, // Holiday - Valentine - Romantic Picnic Meal Periodic - effect dummy
    SPELL_MEAL_EAT_VISUAL           = 45120, // Holiday - Valentine - Romantic Picnic Meal Eat Visual
    //SPELL_MEAL_PARTICLE             = 45114, // Holiday - Valentine - Romantic Picnic Meal Particle - unused
    SPELL_DRINK_VISUAL              = 45121, // Holiday - Valentine - Romantic Picnic Drink Visual
    SPELL_ROMANTIC_PICNIC_ACHIEV    = 45123, // Romantic Picnic periodic = 5000
};

class spell_love_is_in_the_air_romantic_picnic : public SpellScriptLoader
{
    public:
        spell_love_is_in_the_air_romantic_picnic() : SpellScriptLoader("spell_love_is_in_the_air_romantic_picnic") { }

        class spell_love_is_in_the_air_romantic_picnic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_love_is_in_the_air_romantic_picnic_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->SetStandState(UNIT_STAND_STATE_SIT);
                target->CastSpell(target, SPELL_MEAL_PERIODIC, false);
            }

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                // Every 5 seconds
                Unit* target = GetTarget();
                Unit* caster = GetCaster();

                // If our player is no longer sit, remove all auras
                if (target->GetStandState() != UNIT_STAND_STATE_SIT)
                {
                    target->RemoveAura(SPELL_ROMANTIC_PICNIC_ACHIEV);
                    target->RemoveAura(GetAura());
                    return;
                }

                target->CastSpell(target, SPELL_BASKET_CHECK, false); // unknown use, it targets Romantic Basket
                target->CastSpell(target, RAND(SPELL_MEAL_EAT_VISUAL, SPELL_DRINK_VISUAL), false);

                bool foundSomeone = false;
                // For nearby players, check if they have the same aura. If so, cast Romantic Picnic (45123)
                // required by achievement and "hearts" visual
                std::list<Player*> playerList;
                Trinity::AnyPlayerInObjectRangeCheck checker(target, INTERACTION_DISTANCE*2);
                Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(target, playerList, checker);
                target->VisitNearbyWorldObject(INTERACTION_DISTANCE*2, searcher);
                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if ((*itr) != target && (*itr)->HasAura(GetId())) // && (*itr)->GetStandState() == UNIT_STAND_STATE_SIT)
                    {
                        if (caster)
                        {
                            caster->CastSpell(*itr, SPELL_ROMANTIC_PICNIC_ACHIEV, true);
                            caster->CastSpell(target, SPELL_ROMANTIC_PICNIC_ACHIEV, true);
                        }
                        foundSomeone = true;
                        // break;
                    }
                }

                if (!foundSomeone && target->HasAura(SPELL_ROMANTIC_PICNIC_ACHIEV))
                    target->RemoveAura(SPELL_ROMANTIC_PICNIC_ACHIEV);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_love_is_in_the_air_romantic_picnic_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_love_is_in_the_air_romantic_picnic_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_love_is_in_the_air_romantic_picnic_AuraScript();
        }
};

enum HallowEndCandysSpells
{
    SPELL_HALLOWS_END_CANDY_ORANGE_GIANT          = 24924, // Effect 1: Apply Aura: Mod Size, Value: 30%
    SPELL_HALLOWS_END_CANDY_SKELETON              = 24925, // Effect 1: Apply Aura: Change Model (Skeleton). Effect 2: Apply Aura: Underwater Breathing
    SPELL_HALLOWS_END_CANDY_PIRATE                = 24926, // Effect 1: Apply Aura: Increase Swim Speed, Value: 50%
    SPELL_HALLOWS_END_CANDY_GHOST                 = 24927, // Effect 1: Apply Aura: Levitate / Hover. Effect 2: Apply Aura: Slow Fall, Effect 3: Apply Aura: Water Walking
    SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE  = 44742, // Effect 1: Apply Aura: Change Model (Defias Pirate, Female). Effect 2: Increase Swim Speed, Value: 50%
    SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE    = 44743  // Effect 1: Apply Aura: Change Model (Defias Pirate, Male).   Effect 2: Increase Swim Speed, Value: 50%
};

// 24930 - Hallow's End Candy
class spell_hallow_end_candy : public SpellScriptLoader
{
    public:
        spell_hallow_end_candy() : SpellScriptLoader("spell_hallow_end_candy") { }

        class spell_hallow_end_candy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_candy_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                for (uint32 spellId : spells)
                    if (!sSpellMgr->GetSpellInfo(spellId))
                        return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), spells[urand(0, 3)], true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_hallow_end_candy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        private:
            static uint32 const spells[4];
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_candy_SpellScript();
        }
};

uint32 const spell_hallow_end_candy::spell_hallow_end_candy_SpellScript::spells[4] =
{
    SPELL_HALLOWS_END_CANDY_ORANGE_GIANT,
    SPELL_HALLOWS_END_CANDY_SKELETON,
    SPELL_HALLOWS_END_CANDY_PIRATE,
    SPELL_HALLOWS_END_CANDY_GHOST
};

// 24926 - Hallow's End Candy
class spell_hallow_end_candy_pirate : public SpellScriptLoader
{
    public:
        spell_hallow_end_candy_pirate() : SpellScriptLoader("spell_hallow_end_candy_pirate") { }

        class spell_hallow_end_candy_pirate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hallow_end_candy_pirate_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE)
                    || !sSpellMgr->GetSpellInfo(SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE))
                    return false;
                return true;
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                uint32 spell = GetTarget()->getGender() == GENDER_FEMALE ? SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE : SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE;
                GetTarget()->CastSpell(GetTarget(), spell, true);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                uint32 spell = GetTarget()->getGender() == GENDER_FEMALE ? SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE : SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE;
                GetTarget()->RemoveAurasDueToSpell(spell);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_hallow_end_candy_pirate_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_INCREASE_SWIM_SPEED, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_hallow_end_candy_pirate_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_INCREASE_SWIM_SPEED, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hallow_end_candy_pirate_AuraScript();
        }
};

// 24750 Trick
enum TrickSpells
{
    SPELL_PIRATE_COSTUME_MALE           = 24708,
    SPELL_PIRATE_COSTUME_FEMALE         = 24709,
    SPELL_NINJA_COSTUME_MALE            = 24710,
    SPELL_NINJA_COSTUME_FEMALE          = 24711,
    SPELL_LEPER_GNOME_COSTUME_MALE      = 24712,
    SPELL_LEPER_GNOME_COSTUME_FEMALE    = 24713,
    SPELL_SKELETON_COSTUME              = 24723,
    SPELL_GHOST_COSTUME_MALE            = 24735,
    SPELL_GHOST_COSTUME_FEMALE          = 24736,
    SPELL_TRICK_BUFF                    = 24753,
};

class spell_hallow_end_trick : public SpellScriptLoader
{
    public:
        spell_hallow_end_trick() : SpellScriptLoader("spell_hallow_end_trick") { }

        class spell_hallow_end_trick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_trick_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PIRATE_COSTUME_MALE) || !sSpellMgr->GetSpellInfo(SPELL_PIRATE_COSTUME_FEMALE) || !sSpellMgr->GetSpellInfo(SPELL_NINJA_COSTUME_MALE)
                    || !sSpellMgr->GetSpellInfo(SPELL_NINJA_COSTUME_FEMALE) || !sSpellMgr->GetSpellInfo(SPELL_LEPER_GNOME_COSTUME_MALE) || !sSpellMgr->GetSpellInfo(SPELL_LEPER_GNOME_COSTUME_FEMALE)
                    || !sSpellMgr->GetSpellInfo(SPELL_SKELETON_COSTUME) || !sSpellMgr->GetSpellInfo(SPELL_GHOST_COSTUME_MALE) || !sSpellMgr->GetSpellInfo(SPELL_GHOST_COSTUME_FEMALE) || !sSpellMgr->GetSpellInfo(SPELL_TRICK_BUFF))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Player* target = GetHitPlayer())
                {
                    uint8 gender = target->getGender();
                    uint32 spellId = SPELL_TRICK_BUFF;
                    switch (urand(0, 5))
                    {
                        case 1:
                            spellId = gender ? SPELL_LEPER_GNOME_COSTUME_FEMALE : SPELL_LEPER_GNOME_COSTUME_MALE;
                            break;
                        case 2:
                            spellId = gender ? SPELL_PIRATE_COSTUME_FEMALE : SPELL_PIRATE_COSTUME_MALE;
                            break;
                        case 3:
                            spellId = gender ? SPELL_GHOST_COSTUME_FEMALE : SPELL_GHOST_COSTUME_MALE;
                            break;
                        case 4:
                            spellId = gender ? SPELL_NINJA_COSTUME_FEMALE : SPELL_NINJA_COSTUME_MALE;
                            break;
                        case 5:
                            spellId = SPELL_SKELETON_COSTUME;
                            break;
                        default:
                            break;
                    }

                    caster->CastSpell(target, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hallow_end_trick_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_trick_SpellScript();
        }
};

// 24751 Trick or Treat
enum TrickOrTreatSpells
{
    SPELL_TRICK                 = 24714,
    SPELL_TREAT                 = 24715,
    SPELL_TRICKED_OR_TREATED    = 24755,
    SPELL_TRICKY_TREAT_SPEED    = 42919,
    SPELL_TRICKY_TREAT_TRIGGER  = 42965,
    SPELL_UPSET_TUMMY           = 42966
};

class spell_hallow_end_trick_or_treat : public SpellScriptLoader
{
    public:
        spell_hallow_end_trick_or_treat() : SpellScriptLoader("spell_hallow_end_trick_or_treat") { }

        class spell_hallow_end_trick_or_treat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_trick_or_treat_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TRICK) || !sSpellMgr->GetSpellInfo(SPELL_TREAT) || !sSpellMgr->GetSpellInfo(SPELL_TRICKED_OR_TREATED))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Player* target = GetHitPlayer())
                {
                    caster->CastSpell(target, roll_chance_i(50) ? SPELL_TRICK : SPELL_TREAT, true);
                    caster->CastSpell(target, SPELL_TRICKED_OR_TREATED, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hallow_end_trick_or_treat_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_trick_or_treat_SpellScript();
        }
};

class spell_hallow_end_tricky_treat : public SpellScriptLoader
{
    public:
        spell_hallow_end_tricky_treat() : SpellScriptLoader("spell_hallow_end_tricky_treat") { }

        class spell_hallow_end_tricky_treat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_tricky_treat_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TRICKY_TREAT_SPEED))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_TRICKY_TREAT_TRIGGER))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_UPSET_TUMMY))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (caster->HasAura(SPELL_TRICKY_TREAT_TRIGGER) && caster->GetAuraCount(SPELL_TRICKY_TREAT_SPEED) > 3 && roll_chance_i(33))
                    caster->CastSpell(caster, SPELL_UPSET_TUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hallow_end_tricky_treat_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_tricky_treat_SpellScript();
        }
};

// Hallowed wands
enum HallowendData
{
    //wand spells
    SPELL_HALLOWED_WAND_PIRATE             = 24717,
    SPELL_HALLOWED_WAND_NINJA              = 24718,
    SPELL_HALLOWED_WAND_LEPER_GNOME        = 24719,
    SPELL_HALLOWED_WAND_RANDOM             = 24720,
    SPELL_HALLOWED_WAND_SKELETON           = 24724,
    SPELL_HALLOWED_WAND_WISP               = 24733,
    SPELL_HALLOWED_WAND_GHOST              = 24737,
    SPELL_HALLOWED_WAND_BAT                = 24741
};

class spell_hallow_end_wand : public SpellScriptLoader
{
public:
    spell_hallow_end_wand() : SpellScriptLoader("spell_hallow_end_wand") {}

    class spell_hallow_end_wand_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hallow_end_wand_SpellScript);

        bool Validate(SpellInfo const* /*spellEntry*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PIRATE_COSTUME_MALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_PIRATE_COSTUME_FEMALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_NINJA_COSTUME_MALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_NINJA_COSTUME_FEMALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_LEPER_GNOME_COSTUME_MALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_LEPER_GNOME_COSTUME_FEMALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_GHOST_COSTUME_MALE) ||
                !sSpellMgr->GetSpellInfo(SPELL_GHOST_COSTUME_FEMALE))
                return false;
            return true;
        }

        void HandleScriptEffect()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            uint32 spellId = 0;
            uint8 gender = target->getGender();

            switch (GetSpellInfo()->Id)
            {
                case SPELL_HALLOWED_WAND_LEPER_GNOME:
                    spellId = gender ? SPELL_LEPER_GNOME_COSTUME_FEMALE : SPELL_LEPER_GNOME_COSTUME_MALE;
                    break;
                case SPELL_HALLOWED_WAND_PIRATE:
                    spellId = gender ? SPELL_PIRATE_COSTUME_FEMALE : SPELL_PIRATE_COSTUME_MALE;
                    break;
                case SPELL_HALLOWED_WAND_GHOST:
                    spellId = gender ? SPELL_GHOST_COSTUME_FEMALE : SPELL_GHOST_COSTUME_MALE;
                    break;
                case SPELL_HALLOWED_WAND_NINJA:
                    spellId = gender ? SPELL_NINJA_COSTUME_FEMALE : SPELL_NINJA_COSTUME_MALE;
                    break;
                case SPELL_HALLOWED_WAND_RANDOM:
                    spellId = RAND(SPELL_HALLOWED_WAND_PIRATE, SPELL_HALLOWED_WAND_NINJA, SPELL_HALLOWED_WAND_LEPER_GNOME, SPELL_HALLOWED_WAND_SKELETON, SPELL_HALLOWED_WAND_WISP, SPELL_HALLOWED_WAND_GHOST, SPELL_HALLOWED_WAND_BAT);
                    break;
                default:
                    return;
            }
            caster->CastSpell(target, spellId, true);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_hallow_end_wand_SpellScript::HandleScriptEffect);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hallow_end_wand_SpellScript();
    }
};

enum PilgrimsBountyBuffFood
{
    // Pilgrims Bounty Buff Food
    SPELL_WELL_FED_AP_TRIGGER       = 65414,
    SPELL_WELL_FED_ZM_TRIGGER       = 65412,
    SPELL_WELL_FED_HIT_TRIGGER      = 65416,
    SPELL_WELL_FED_HASTE_TRIGGER    = 65410,
    SPELL_WELL_FED_SPIRIT_TRIGGER   = 65415
};

class spell_pilgrims_bounty_buff_food : public SpellScriptLoader
{
    private:
        uint32 const _triggeredSpellId;
    public:
        spell_pilgrims_bounty_buff_food(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_pilgrims_bounty_buff_food_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pilgrims_bounty_buff_food_AuraScript);
        private:
            uint32 const _triggeredSpellId;

        public:
            spell_pilgrims_bounty_buff_food_AuraScript(uint32 triggeredSpellId) : AuraScript(), _triggeredSpellId(triggeredSpellId)
            {
                _handled = false;
            }

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (_handled)
                    return;

                _handled = true;
                GetTarget()->CastSpell(GetTarget(), _triggeredSpellId, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_pilgrims_bounty_buff_food_AuraScript::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

            bool _handled;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pilgrims_bounty_buff_food_AuraScript(_triggeredSpellId);
        }
};

enum FeastOnSpells
{
    FEAST_ON_TURKEY                     = 61784,
    FEAST_ON_CRANBERRIES                = 61785,
    FEAST_ON_SWEET_POTATOES             = 61786,
    FEAST_ON_PIE                        = 61787,
    FEAST_ON_STUFFING                   = 61788,
    SPELL_CRANBERRY_HELPINS             = 61841,
    SPELL_TURKEY_HELPINS                = 61842,
    SPELL_STUFFING_HELPINS              = 61843,
    SPELL_SWEET_POTATO_HELPINS          = 61844,
    SPELL_PIE_HELPINS                   = 61845,
    SPELL_ON_PLATE_EAT_VISUAL           = 61826
};

class spell_pilgrims_bounty_feast_on : public SpellScriptLoader
{
    public:
        spell_pilgrims_bounty_feast_on() : SpellScriptLoader("spell_pilgrims_bounty_feast_on") { }

        class spell_pilgrims_bounty_feast_on_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_feast_on_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                uint32 _spellId = 0;
                switch (GetSpellInfo()->Id)
                {
                    case FEAST_ON_TURKEY:
                        _spellId = SPELL_TURKEY_HELPINS;
                        break;
                    case FEAST_ON_CRANBERRIES:
                        _spellId = SPELL_CRANBERRY_HELPINS;
                        break;
                    case FEAST_ON_SWEET_POTATOES:
                        _spellId = SPELL_SWEET_POTATO_HELPINS;
                        break;
                    case FEAST_ON_PIE:
                        _spellId = SPELL_PIE_HELPINS;
                        break;
                    case FEAST_ON_STUFFING:
                        _spellId = SPELL_STUFFING_HELPINS;
                        break;
                    default:
                        return;
                }

                if (Vehicle* vehicle = caster->GetVehicleKit())
                    if (Unit* target = vehicle->GetPassenger(0))
                        if (Player* player = target->ToPlayer())
                        {
                            player->CastSpell(player, SPELL_ON_PLATE_EAT_VISUAL, true);
                            caster->CastSpell(player, _spellId, true, NULL, NULL, player->GetGUID());
                        }

                if (Aura* aura = caster->GetAura(GetEffectValue()))
                {
                    if (aura->GetStackAmount() == 1)
                        caster->RemoveAurasDueToSpell(aura->GetSpellInfo()->Effects[EFFECT_0].CalcValue());
                    aura->ModStackAmount(-1);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_feast_on_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_feast_on_SpellScript();
        }
};

enum TheTurkinator
{
    SPELL_KILL_COUNTER_VISUAL       = 62015,
    SPELL_KILL_COUNTER_VISUAL_MAX   = 62021,
    EMOTE_TURKEY_HUNTER             = 0,
    EMOTE_TURKEY_DOMINATION         = 1,
    EMOTE_TURKEY_SLAUGHTER          = 2,
    EMOTE_TURKEY_TRIUMPH            = 3
};

class spell_pilgrims_bounty_turkey_tracker : public SpellScriptLoader
{
    public:
        spell_pilgrims_bounty_turkey_tracker() : SpellScriptLoader("spell_pilgrims_bounty_turkey_tracker") { }

        class spell_pilgrims_bounty_turkey_tracker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_turkey_tracker_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_KILL_COUNTER_VISUAL) || !sSpellMgr->GetSpellInfo(SPELL_KILL_COUNTER_VISUAL_MAX))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                Unit* target = GetHitUnit();

                if (!target || !caster)
                    return;

                if (target->HasAura(SPELL_KILL_COUNTER_VISUAL_MAX))
                    return;

                if (Aura const* aura = target->GetAura(GetSpellInfo()->Id))
                {
                    switch (aura->GetStackAmount())
                    {
                        case 10:
                            caster->AI()->Talk(EMOTE_TURKEY_HUNTER, target);
                            break;
                        case 20:
                            caster->AI()->Talk(EMOTE_TURKEY_DOMINATION, target);
                            break;
                        case 30:
                            caster->AI()->Talk(EMOTE_TURKEY_SLAUGHTER, target);
                            break;
                        case 40:
                            caster->AI()->Talk(EMOTE_TURKEY_TRIUMPH, target);
                            target->CastSpell(target, SPELL_KILL_COUNTER_VISUAL_MAX, true);
                            target->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                            break;
                        default:
                            return;
                    }
                    target->CastSpell(target, SPELL_KILL_COUNTER_VISUAL, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_turkey_tracker_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_turkey_tracker_SpellScript();
        }
};

enum SpiritOfSharing
{
    SPELL_THE_SPIRIT_OF_SHARING    = 61849
};

class spell_pilgrims_bounty_well_fed : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId;

    public:
        spell_pilgrims_bounty_well_fed(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_pilgrims_bounty_well_fed_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_well_fed_SpellScript);
        private:
            uint32 _triggeredSpellId;

        public:
            spell_pilgrims_bounty_well_fed_SpellScript(uint32 triggeredSpellId) : SpellScript(), _triggeredSpellId(triggeredSpellId) { }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_triggeredSpellId))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Player* target = GetHitPlayer();
                if (!target)
                    return;

                if (Aura const* aura = target->GetAura(GetSpellInfo()->Id))
                {
                    if (aura->GetStackAmount() == 5)
                        target->CastSpell(target, _triggeredSpellId, true);
                }

                Aura const* turkey = target->GetAura(SPELL_TURKEY_HELPINS);
                Aura const* cranberies = target->GetAura(SPELL_CRANBERRY_HELPINS);
                Aura const* stuffing = target->GetAura(SPELL_STUFFING_HELPINS);
                Aura const* sweetPotatoes = target->GetAura(SPELL_SWEET_POTATO_HELPINS);
                Aura const* pie = target->GetAura(SPELL_PIE_HELPINS);

                if ((turkey && turkey->GetStackAmount() == 5) && (cranberies && cranberies->GetStackAmount() == 5) && (stuffing && stuffing->GetStackAmount() == 5)
                    && (sweetPotatoes && sweetPotatoes->GetStackAmount() == 5) && (pie && pie->GetStackAmount() == 5))
                {
                    target->CastSpell(target, SPELL_THE_SPIRIT_OF_SHARING, true);
                    target->RemoveAurasDueToSpell(SPELL_TURKEY_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_CRANBERRY_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_STUFFING_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_SWEET_POTATO_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_PIE_HELPINS);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_well_fed_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_well_fed_SpellScript(_triggeredSpellId);
        }
};

enum Mistletoe
{
    SPELL_CREATE_MISTLETOE          = 26206,
    SPELL_CREATE_HOLLY              = 26207,
    SPELL_CREATE_SNOWFLAKES         = 45036
};

class spell_winter_veil_mistletoe : public SpellScriptLoader
{
    public:
        spell_winter_veil_mistletoe() : SpellScriptLoader("spell_winter_veil_mistletoe") { }

        class spell_winter_veil_mistletoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_winter_veil_mistletoe_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CREATE_MISTLETOE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_CREATE_HOLLY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_CREATE_SNOWFLAKES))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Player* target = GetHitPlayer())
                {
                    uint32 spellId = RAND(SPELL_CREATE_HOLLY, SPELL_CREATE_MISTLETOE, SPELL_CREATE_SNOWFLAKES);
                    GetCaster()->CastSpell(target, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_winter_veil_mistletoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_winter_veil_mistletoe_SpellScript();
        }
};

// 26275 - PX-238 Winter Wondervolt TRAP
enum PX238WinterWondervolt
{
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1  = 26157,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2  = 26272,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3  = 26273,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4  = 26274
};

class spell_winter_veil_px_238_winter_wondervolt : public SpellScriptLoader
{
    public:
        spell_winter_veil_px_238_winter_wondervolt() : SpellScriptLoader("spell_winter_veil_px_238_winter_wondervolt") { }

        class spell_winter_veil_px_238_winter_wondervolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_winter_veil_px_238_winter_wondervolt_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                uint32 const spells[4] =
                {
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1,
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2,
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3,
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4
                };

                if (Unit* target = GetHitUnit())
                {
                    for (uint8 i = 0; i < 4; ++i)
                        if (target->HasAura(spells[i]))
                            return;

                    target->CastSpell(target, spells[urand(0, 3)], true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_winter_veil_px_238_winter_wondervolt_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_winter_veil_px_238_winter_wondervolt_SpellScript();
        }
};

enum RamBlaBla
{
    SPELL_GIDDYUP                           = 42924,
    SPELL_RENTAL_RACING_RAM                 = 43883,
    SPELL_RENTAL_RACING_RAM_AURA            = 42146,
    SPELL_RAM_LEVEL_NEUTRAL                 = 43310,
    SPELL_RAM_TROT                          = 42992,
    SPELL_RAM_CANTER                        = 42993,
    SPELL_RAM_GALLOP                        = 42994,
    SPELL_RAM_FATIGUE                       = 43052,
    SPELL_EXHAUSTED_RAM                     = 43332,

    // Quest
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_GREEN  = 43345,
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_YELLOW = 43346,
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_RED    = 43347
};

// 42924 - Giddyup!
class spell_brewfest_giddyup : public SpellScriptLoader
{
    public:
        spell_brewfest_giddyup() : SpellScriptLoader("spell_brewfest_giddyup") { }

        class spell_brewfest_giddyup_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_giddyup_AuraScript);

            void OnChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (!target->HasAura(SPELL_RENTAL_RACING_RAM))
                {
                    target->RemoveAura(GetId());
                    return;
                }

                if (target->HasAura(SPELL_EXHAUSTED_RAM))
                    return;

                switch (GetStackAmount())
                {
                    case 1: // green
                        target->RemoveAura(SPELL_RAM_LEVEL_NEUTRAL);
                        target->RemoveAura(SPELL_RAM_CANTER);
                        target->CastSpell(target, SPELL_RAM_TROT, true);
                        break;
                    case 6: // yellow
                        target->RemoveAura(SPELL_RAM_TROT);
                        target->RemoveAura(SPELL_RAM_GALLOP);
                        target->CastSpell(target, SPELL_RAM_CANTER, true);
                        break;
                    case 11: // red
                        target->RemoveAura(SPELL_RAM_CANTER);
                        target->CastSpell(target, SPELL_RAM_GALLOP, true);
                        break;
                    default:
                        break;
                }

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEFAULT)
                {
                    target->RemoveAura(SPELL_RAM_TROT);
                    target->CastSpell(target, SPELL_RAM_LEVEL_NEUTRAL, true);
                }
            }

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->RemoveAuraFromStack(GetId());
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_brewfest_giddyup_AuraScript::OnChange, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                OnEffectRemove += AuraEffectRemoveFn(spell_brewfest_giddyup_AuraScript::OnChange, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_giddyup_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_giddyup_AuraScript();
        }
};

// 43310 - Ram Level - Neutral
// 42992 - Ram - Trot
// 42993 - Ram - Canter
// 42994 - Ram - Gallop
class spell_brewfest_ram : public SpellScriptLoader
{
    public:
        spell_brewfest_ram() : SpellScriptLoader("spell_brewfest_ram") { }

        class spell_brewfest_ram_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_ram_AuraScript);

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* target = GetTarget();
                if (target->HasAura(SPELL_EXHAUSTED_RAM))
                    return;

                switch (GetId())
                {
                    case SPELL_RAM_LEVEL_NEUTRAL:
                        if (Aura* aura = target->GetAura(SPELL_RAM_FATIGUE))
                            aura->ModStackAmount(-4);
                        break;
                    case SPELL_RAM_TROT: // green
                        if (Aura* aura = target->GetAura(SPELL_RAM_FATIGUE))
                            aura->ModStackAmount(-2);
                        if (aurEff->GetTickNumber() == 4)
                            target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_GREEN, true);
                        break;
                    case SPELL_RAM_CANTER:
                        target->CastCustomSpell(SPELL_RAM_FATIGUE, SPELLVALUE_AURA_STACK, 1, target, TRIGGERED_FULL_MASK);
                        if (aurEff->GetTickNumber() == 8)
                            target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_YELLOW, true);
                        break;
                    case SPELL_RAM_GALLOP:
                        target->CastCustomSpell(SPELL_RAM_FATIGUE, SPELLVALUE_AURA_STACK, target->HasAura(SPELL_RAM_FATIGUE) ? 4 : 5 /*Hack*/, target, TRIGGERED_FULL_MASK);
                        if (aurEff->GetTickNumber() == 8)
                            target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_RED, true);
                        break;
                    default:
                        break;
                }

            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_ram_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_ram_AuraScript();
        }
};

// 43052 - Ram Fatigue
class spell_brewfest_ram_fatigue : public SpellScriptLoader
{
    public:
        spell_brewfest_ram_fatigue() : SpellScriptLoader("spell_brewfest_ram_fatigue") { }

        class spell_brewfest_ram_fatigue_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_ram_fatigue_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetStackAmount() == 101)
                {
                    target->RemoveAura(SPELL_RAM_LEVEL_NEUTRAL);
                    target->RemoveAura(SPELL_RAM_TROT);
                    target->RemoveAura(SPELL_RAM_CANTER);
                    target->RemoveAura(SPELL_RAM_GALLOP);
                    target->RemoveAura(SPELL_GIDDYUP);

                    target->CastSpell(target, SPELL_EXHAUSTED_RAM, true);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_brewfest_ram_fatigue_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_ram_fatigue_AuraScript();
        }
};

// 43450 - Brewfest - apple trap - friendly DND
class spell_brewfest_apple_trap : public SpellScriptLoader
{
    public:
        spell_brewfest_apple_trap() : SpellScriptLoader("spell_brewfest_apple_trap") { }

        class spell_brewfest_apple_trap_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_apple_trap_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAura(SPELL_RAM_FATIGUE);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_brewfest_apple_trap_AuraScript::OnApply, EFFECT_0, SPELL_AURA_FORCE_REACTION, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_apple_trap_AuraScript();
        }
};

// 43332 - Exhausted Ram
class spell_brewfest_exhausted_ram : public SpellScriptLoader
{
    public:
        spell_brewfest_exhausted_ram() : SpellScriptLoader("spell_brewfest_exhausted_ram") { }

        class spell_brewfest_exhausted_ram_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_exhausted_ram_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->CastSpell(target, SPELL_RAM_LEVEL_NEUTRAL, true);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectApplyFn(spell_brewfest_exhausted_ram_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_exhausted_ram_AuraScript();
        }
};

// 43714 - Brewfest - Relay Race - Intro - Force - Player to throw- DND
class spell_brewfest_relay_race_intro_force_player_to_throw : public SpellScriptLoader
{
    public:
        spell_brewfest_relay_race_intro_force_player_to_throw() : SpellScriptLoader("spell_brewfest_relay_race_intro_force_player_to_throw") { }

        class spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript);

            void HandleForceCast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                // All this spells trigger a spell that requires reagents; if the
                // triggered spell is cast as "triggered", reagents are not consumed
                GetHitUnit()->CastSpell((Unit*)NULL, GetSpellInfo()->Effects[effIndex].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript();
        }
};

// 43876 - Dismount Ram
class spell_brewfest_dismount_ram : public SpellScriptLoader
{
    public:
        spell_brewfest_dismount_ram() : SpellScriptLoader("spell_brewfest_dismount_ram") { }

        class spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->RemoveAura(SPELL_RENTAL_RACING_RAM);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript();
        }
};

enum RamBlub
{
    // Horde
    QUEST_BARK_FOR_DROHNS_DISTILLERY        = 11407,
    QUEST_BARK_FOR_TCHALIS_VOODOO_BREWERY   = 11408,

    // Alliance
    QUEST_BARK_BARLEYBREW                   = 11293,
    QUEST_BARK_FOR_THUNDERBREWS             = 11294,

    // Bark for Drohn's Distillery!
    SAY_DROHN_DISTILLERY_1                  = 23520,
    SAY_DROHN_DISTILLERY_2                  = 23521,
    SAY_DROHN_DISTILLERY_3                  = 23522,
    SAY_DROHN_DISTILLERY_4                  = 23523,

    // Bark for T'chali's Voodoo Brewery!
    SAY_TCHALIS_VOODOO_1                    = 23524,
    SAY_TCHALIS_VOODOO_2                    = 23525,
    SAY_TCHALIS_VOODOO_3                    = 23526,
    SAY_TCHALIS_VOODOO_4                    = 23527,

    // Bark for the Barleybrews!
    SAY_BARLEYBREW_1                        = 23464,
    SAY_BARLEYBREW_2                        = 23465,
    SAY_BARLEYBREW_3                        = 23466,
    SAY_BARLEYBREW_4                        = 22941,

    // Bark for the Thunderbrews!
    SAY_THUNDERBREWS_1                      = 23467,
    SAY_THUNDERBREWS_2                      = 23468,
    SAY_THUNDERBREWS_3                      = 23469,
    SAY_THUNDERBREWS_4                      = 22942
};

// 43259 Brewfest  - Barker Bunny 1
// 43260 Brewfest  - Barker Bunny 2
// 43261 Brewfest  - Barker Bunny 3
// 43262 Brewfest  - Barker Bunny 4
class spell_brewfest_barker_bunny : public SpellScriptLoader
{
    public:
        spell_brewfest_barker_bunny() : SpellScriptLoader("spell_brewfest_barker_bunny") { }

        class spell_brewfest_barker_bunny_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_barker_bunny_AuraScript);

            bool Load() override
            {
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Player* target = GetTarget()->ToPlayer();

                uint32 BroadcastTextId = 0;

                if (target->GetQuestStatus(QUEST_BARK_FOR_DROHNS_DISTILLERY) == QUEST_STATUS_INCOMPLETE ||
                    target->GetQuestStatus(QUEST_BARK_FOR_DROHNS_DISTILLERY) == QUEST_STATUS_COMPLETE)
                    BroadcastTextId = RAND(SAY_DROHN_DISTILLERY_1, SAY_DROHN_DISTILLERY_2, SAY_DROHN_DISTILLERY_3, SAY_DROHN_DISTILLERY_4);

                if (target->GetQuestStatus(QUEST_BARK_FOR_TCHALIS_VOODOO_BREWERY) == QUEST_STATUS_INCOMPLETE ||
                    target->GetQuestStatus(QUEST_BARK_FOR_TCHALIS_VOODOO_BREWERY) == QUEST_STATUS_COMPLETE)
                    BroadcastTextId = RAND(SAY_TCHALIS_VOODOO_1, SAY_TCHALIS_VOODOO_2, SAY_TCHALIS_VOODOO_3, SAY_TCHALIS_VOODOO_4);

                if (target->GetQuestStatus(QUEST_BARK_BARLEYBREW) == QUEST_STATUS_INCOMPLETE ||
                    target->GetQuestStatus(QUEST_BARK_BARLEYBREW) == QUEST_STATUS_COMPLETE)
                    BroadcastTextId = RAND(SAY_BARLEYBREW_1, SAY_BARLEYBREW_2, SAY_BARLEYBREW_3, SAY_BARLEYBREW_4);

                if (target->GetQuestStatus(QUEST_BARK_FOR_THUNDERBREWS) == QUEST_STATUS_INCOMPLETE ||
                    target->GetQuestStatus(QUEST_BARK_FOR_THUNDERBREWS) == QUEST_STATUS_COMPLETE)
                    BroadcastTextId = RAND(SAY_THUNDERBREWS_1, SAY_THUNDERBREWS_2, SAY_THUNDERBREWS_3, SAY_THUNDERBREWS_4);

                if (BroadcastTextId)
                    target->Talk(BroadcastTextId, CHAT_MSG_SAY, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), target);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_brewfest_barker_bunny_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_barker_bunny_AuraScript();
        }
};

enum TorchSpells
{
    SPELL_TORCH_TOSSING_TRAINING                    = 45716,
    SPELL_TORCH_TOSSING_PRACTICE                    = 46630,
    SPELL_TORCH_TOSSING_TRAINING_SUCCESS_ALLIANCE   = 45719,
    SPELL_TORCH_TOSSING_TRAINING_SUCCESS_HORDE      = 46651,
    SPELL_BRAZIERS_HIT                              = 45724
};

// 45724 - Braziers Hit!
class spell_midsummer_braziers_hit : public SpellScriptLoader
{
    public:
        spell_midsummer_braziers_hit() : SpellScriptLoader("spell_midsummer_braziers_hit") { }

        class spell_midsummer_braziers_hit_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_midsummer_braziers_hit_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TORCH_TOSSING_TRAINING) || !sSpellMgr->GetSpellInfo(SPELL_TORCH_TOSSING_PRACTICE))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Player* player = GetTarget()->ToPlayer();
                if (!player)
                    return;

                if ((player->HasAura(SPELL_TORCH_TOSSING_TRAINING) && GetStackAmount() == 8) || (player->HasAura(SPELL_TORCH_TOSSING_PRACTICE) && GetStackAmount() == 20))
                {
                    if (player->GetTeam() == ALLIANCE)
                        player->CastSpell(player, SPELL_TORCH_TOSSING_TRAINING_SUCCESS_ALLIANCE, true);
                    else if (player->GetTeam() == HORDE)
                        player->CastSpell(player, SPELL_TORCH_TOSSING_TRAINING_SUCCESS_HORDE, true);
                    Remove();
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_midsummer_braziers_hit_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AuraEffectHandleModes(AURA_EFFECT_HANDLE_REAPPLY));
            }
        };

        AuraScript* GetAuraScript() const override
        {
           return new spell_midsummer_braziers_hit_AuraScript();
        }
};

enum RibbonPoleData
{
    SPELL_HAS_FULL_MIDSUMMER_SET        = 58933,
    SPELL_BURNING_HOT_POLE_DANCE        = 58934,
    SPELL_RIBBON_DANCE_COSMETIC         = 29726,
    SPELL_RIBBON_DANCE                  = 29175,
    GO_RIBBON_POLE                      = 181605,
};

class spell_gen_ribbon_pole_dancer_check : public SpellScriptLoader
{
    public:
        spell_gen_ribbon_pole_dancer_check() : SpellScriptLoader("spell_gen_ribbon_pole_dancer_check") { }

        class spell_gen_ribbon_pole_dancer_check_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_ribbon_pole_dancer_check_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_HAS_FULL_MIDSUMMER_SET)
                    || !sSpellMgr->GetSpellInfo(SPELL_RIBBON_DANCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_BURNING_HOT_POLE_DANCE))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();

                // check if aura needs to be removed
                if (!target->FindNearestGameObject(GO_RIBBON_POLE, 8.0f) || !target->HasUnitState(UNIT_STATE_CASTING))
                {
                    target->InterruptNonMeleeSpells(false);
                    target->RemoveAurasDueToSpell(GetId());
                    target->RemoveAura(SPELL_RIBBON_DANCE_COSMETIC);
                    return;
                }

                // set xp buff duration
                if (Aura* aur = target->GetAura(SPELL_RIBBON_DANCE))
                {
                    aur->SetMaxDuration(std::min(3600000, aur->GetMaxDuration() + 180000));
                    aur->RefreshDuration();

                    // reward achievement criteria
                    if (aur->GetMaxDuration() == 3600000 && target->HasAura(SPELL_HAS_FULL_MIDSUMMER_SET))
                        target->CastSpell(target, SPELL_BURNING_HOT_POLE_DANCE, true);
                }
                else
                    target->AddAura(SPELL_RIBBON_DANCE, target);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_ribbon_pole_dancer_check_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gen_ribbon_pole_dancer_check_AuraScript();
        }
};

void AddSC_holiday_spell_scripts()
{
    // Love is in the Air
    new spell_love_is_in_the_air_romantic_picnic();
    // Hallow's End
    new spell_hallow_end_candy();
    new spell_hallow_end_candy_pirate();
    new spell_hallow_end_trick();
    new spell_hallow_end_trick_or_treat();
    new spell_hallow_end_tricky_treat();
    new spell_hallow_end_wand();
    // Pilgrims Bounty
    new spell_pilgrims_bounty_buff_food("spell_gen_slow_roasted_turkey", SPELL_WELL_FED_AP_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_cranberry_chutney", SPELL_WELL_FED_ZM_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_spice_bread_stuffing", SPELL_WELL_FED_HIT_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_pumpkin_pie", SPELL_WELL_FED_SPIRIT_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_candied_sweet_potato", SPELL_WELL_FED_HASTE_TRIGGER);
    new spell_pilgrims_bounty_feast_on();
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_turkey", SPELL_WELL_FED_AP_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_cranberry", SPELL_WELL_FED_ZM_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_stuffing", SPELL_WELL_FED_HIT_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_sweet_potatoes", SPELL_WELL_FED_HASTE_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_pie", SPELL_WELL_FED_SPIRIT_TRIGGER);
    new spell_pilgrims_bounty_turkey_tracker();
    // Winter Veil
    new spell_winter_veil_mistletoe();
    new spell_winter_veil_px_238_winter_wondervolt();
    // Brewfest
    new spell_brewfest_giddyup();
    new spell_brewfest_ram();
    new spell_brewfest_ram_fatigue();
    new spell_brewfest_apple_trap();
    new spell_brewfest_exhausted_ram();
    new spell_brewfest_relay_race_intro_force_player_to_throw();
    new spell_brewfest_dismount_ram();
    new spell_brewfest_barker_bunny();
    // Midsummer Fire Festival
    new spell_midsummer_braziers_hit();
    new spell_gen_ribbon_pole_dancer_check();
}
