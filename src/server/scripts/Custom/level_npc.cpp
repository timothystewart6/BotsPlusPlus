// Original script by Ghostcrawler336

#include "ScriptPCH.h"

class Level_NPC : public CreatureScript
{
public:
    Level_NPC() : CreatureScript("Level_NPC") {}

    bool OnGossipHello(Player* pPlayer, Creature* _creature)
    {
        pPlayer->ADD_GOSSIP_ITEM(7, "I can use my powers to grant you levels.  Choose wisely, there's no turning back...", GOSSIP_SENDER_MAIN, 0);
        pPlayer->ADD_GOSSIP_ITEM(10, "Add 10 levels please!", GOSSIP_SENDER_MAIN, 1);
        pPlayer->ADD_GOSSIP_ITEM(10, "Boost me to 70 please!", GOSSIP_SENDER_MAIN, 8);
        pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* _creature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if(uiAction != 0)
                if(pPlayer->getLevel() >= 70)
                {
                    pPlayer->GetSession()->SendNotification("Sorry! I've used all of my powers to get you to 70.");
                }
                else
                {
                    uint8 newlevel = pPlayer->getLevel()+uiAction*10;
                    if(newlevel > 70)
                        newlevel = 70;
                    pPlayer->GiveLevel(newlevel);
                    pPlayer->InitTalentForLevel();
                    pPlayer->SetUInt32Value(PLAYER_XP, 0);
                    pPlayer->GetSession()->SendAreaTriggerMessage("Aw yeah! You are now Level %u!", uint32(pPlayer->getLevel()));
                    pPlayer->PlayerTalkClass->SendCloseGossip();
                    return true;
                }
        OnGossipHello(pPlayer, _creature);
        return true;
    }
};
void AddSC_Level_NPC()
{
    new Level_NPC();
}