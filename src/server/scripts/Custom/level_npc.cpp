// Original script by Ghostcrawler336

#include "ScriptPCH.h"
class Level_NPC : public CreatureScript
{
public:
	Level_NPC() : CreatureScript("Level_NPC") {}

	bool OnGossipHello(Player* pPlayer, Creature* _creature)
	{
		pPlayer->ADD_GOSSIP_ITEM(7, "Welcome to the level NPC!", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 10", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 20", GOSSIP_SENDER_MAIN, 2);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 30", GOSSIP_SENDER_MAIN, 3);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 40", GOSSIP_SENDER_MAIN, 4);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 50", GOSSIP_SENDER_MAIN, 5);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 60", GOSSIP_SENDER_MAIN, 6);
		pPlayer->ADD_GOSSIP_ITEM(10, "Level 70", GOSSIP_SENDER_MAIN, 7);

		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* _creature, uint32 uiSender, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus();
				pPlayer->SetLevel(uiAction*10); // changed to setlevel, give level gives X amount of levels I think.
				pPlayer->GetSession()->SendAreaTriggerMessage("You are now Level %u!", uiAction*10);
				pPlayer->PlayerTalkClass->SendCloseGossip();
				return true;

		OnGossipHello(pPlayer, _creature);
	}
};
void AddSC_Level_NPC()
{
	new Level_NPC();
}