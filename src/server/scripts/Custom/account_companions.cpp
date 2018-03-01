#include "Player.h"

class AccountCompanions : public PlayerScript
{
    static const bool limitrace = false; // This set to true will only learn mounts from chars on the same team, do what you want.
public:
	AccountCompanions() : PlayerScript("AccountCompanions") { }

    void OnLogin(Player* pPlayer, bool first_login)
	{
        std::vector<uint32> Guids;
        QueryResult result1 = CharacterDatabase.PQuery("SELECT guid, race FROM characters WHERE account = %u", pPlayer->GetSession()->GetAccountId());
        if (!result1)
            return;

        do
        {
            Field* fields = result1->Fetch();

            uint32 guid = fields[0].GetUInt32();
            uint32 race = fields[1].GetUInt8();

            if ((Player::TeamForRace(race) == Player::TeamForRace(pPlayer->getRace())) || !limitrace)
                Guids.push_back(result1->Fetch()[0].GetUInt32());

        } while (result1->NextRow());

          std::vector<uint32> Spells;

           for (auto& i : Guids)
           {
               QueryResult result2 = CharacterDatabase.PQuery("SELECT DISTINCT spell FROM character_spell WHERE guid = %u", i);
               if (!result2)
                   continue;

               do
               {
                   Spells.push_back(result2->Fetch()[0].GetUInt32());
               } while (result2->NextRow());
           }

		for (auto& i : Spells)
		{
			auto sSpell = sSpellStore.LookupEntry(i);
			 if (sSpell->Effect[0] == SPELL_EFFECT_CREATE_TAMED_PET)
                            pPlayer->LearnSpell(sSpell->Id, false);
		}
	}
};

void AddSC_AccountCompanions()
{
	new AccountCompanions();
}