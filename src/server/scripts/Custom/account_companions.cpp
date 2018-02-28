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

		std::vector<uint32> CompanionSpells;

        for (auto& i : Spells)
		{
			QueryResult result3 = WorldDatabase.PQuery("SELECT DISTINCT spellid_2 FROM item_template WHERE spellid_2 = %u AND class = 15 AND subclass = 2", i);
			if (!result3)
				continue;

			do
			{
				CompanionSpells.push_back(result3->Fetch()[0].GetUInt32());
			} while (result3->NextRow());
		}

		for (auto& i : CompanionSpells)
		{
			auto sSpell = sSpellStore.LookupEntry(i);
            pPlayer->LearnSpell(sSpell->Id, false);
		}
	}
};

void AddSC_AccountCompanions()
{
	new AccountCompanions();
}