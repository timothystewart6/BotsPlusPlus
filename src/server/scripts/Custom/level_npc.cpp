// Original script by Ghostcrawler336

#include "ScriptPCH.h"
#define TOKEN_ID   60007   // Replace 60007 to YOUR_TOKEN_ID

class Level_NPC : public CreatureScript
{
public:
    Level_NPC() : CreatureScript("Level_NPC") {}

    bool OnGossipHello(Player* pPlayer, Creature* _creature)
    {
        pPlayer->ADD_GOSSIP_ITEM(7, "Welcome to the level NPC!", GOSSIP_SENDER_MAIN, 0);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 10(10 Token)", GOSSIP_SENDER_MAIN, 1);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 20(20 Tokens)", GOSSIP_SENDER_MAIN, 2);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 30(30 Tokens)", GOSSIP_SENDER_MAIN, 3);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 40(40 Tokens)", GOSSIP_SENDER_MAIN, 4);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 50(50 Tokens)", GOSSIP_SENDER_MAIN, 5);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 60(60 Tokens)", GOSSIP_SENDER_MAIN, 6);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 70(70 Tokens)", GOSSIP_SENDER_MAIN, 7);
        pPlayer->ADD_GOSSIP_ITEM(10, "Level 80(80 Tokens)", GOSSIP_SENDER_MAIN, 8);

        pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* _creature, uint32 uiSender, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if(uiAction != 0)
            if (pPlayer->HasItemCount(TOKEN_ID, uiAction*10, false))
            {
                if(pPlayer->getLevel() >= 80)
                {
                    pPlayer->GetSession()->SendNotification("You are already level 80!");
                }
                else
                {
                    uint8 newlevel = pPlayer->getLevel()+uiAction*10;
                    if(newlevel > 80)
                        newlevel = 80;
                    pPlayer->GiveLevel(newlevel);
                    pPlayer->InitTalentForLevel();
                    pPlayer->SetUInt32Value(PLAYER_XP, 0);
                    pPlayer->DestroyItemCount(TOKEN_ID, uiAction*10, true);
                    pPlayer->GetSession()->SendAreaTriggerMessage("You are now Level %u!", uint32(pPlayer->getLevel()));
                    pPlayer->PlayerTalkClass->SendCloseGossip();
                    return true;
                }
            }
            else
                pPlayer->GetSession()->SendNotification("You don't have the required token");
        OnGossipHello(pPlayer, _creature);
        return true;
    }
};
void AddSC_Level_NPC()
{
    new Level_NPC();
}