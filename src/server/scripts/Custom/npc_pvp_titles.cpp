#include "ScriptMgr.h"
#include "Chat.h"
#include "AccountMgr.h"
#include "ObjectMgr.h"
#include "PlayerDump.h"
#include "ScriptedGossip.h"

class npc_pvp_titles : CreatureScript
{
public:
    npc_pvp_titles() : CreatureScript("npc_pvp_titles") {}

    char* fixText(const char* Text, ...)
    {
        va_list ap;
        char szStr[1024];
        szStr[0] = '\0';

        va_start(ap, Text);
        vsnprintf(szStr, 1024, Text, ap);
        va_end(ap);

        uint32 length = strlen(szStr) + 1;
        return szStr;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->PlayerTalkClass->ClearMenus();

        uint32 count = 0;
        for (uint32 i = 0; i < sCharTitlesStore.GetNumRows(); ++i)
        {
            CharTitlesEntry const* entry = sCharTitlesStore.LookupEntry(i);
            if (entry)
            {
                count++;
                std::string findS = std::string(entry->name);
                if(findS.find("%s") != std::string::npos)
                {
                    char* text = fixText(entry->name, player->GetName());
                    player->ADD_GOSSIP_ITEM(0, text, 0, entry->ID);
                }
                else
                {
                    player->ADD_GOSSIP_ITEM(0, entry->name, 0, entry->ID);
                }
                if (count >= 15)
                {
                    player->ADD_GOSSIP_ITEM(0, "--------->", 0, 200015);
                    break;
                }

            }
        }
        player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
        return true;
    }

    void showMore(Player* player, Creature* creature, uint32 action)
    {
        if (action >= 200000)//lol
        {
            uint32 count = 0;
            for (uint32 i = (action - 200000); i < sCharTitlesStore.GetNumRows(); ++i)
            {
                CharTitlesEntry const* entry = sCharTitlesStore.LookupEntry(i);
                if (entry)
                {
                    count++;
                    char* text = fixText(entry->name, player->GetName());
                    player->ADD_GOSSIP_ITEM(0, text, 0, entry->ID);
                    if (count >= 15)
                    {
                        player->ADD_GOSSIP_ITEM(0, "--------->", 0, action + 15);
                        break;
                    }
                }
            }
            if (action >= 200015)
                player->ADD_GOSSIP_ITEM(0, "<---------", 0, action - 15);
        }
        else
        {
            action = 200000 + action;
            uint32 count = 0;
            for (uint32 i = (action - 200000); i < sCharTitlesStore.GetNumRows(); ++i)
            {
                CharTitlesEntry const* entry = sCharTitlesStore.LookupEntry(i);
                if (entry)
                {
                    count++;
                    char* text = fixText(entry->name, player->GetName());
                    player->ADD_GOSSIP_ITEM(0, text, 0, entry->ID);
                    if (count >= 15)
                    {
                        player->ADD_GOSSIP_ITEM(0, "--------->", 0, action + 15);
                        break;
                    }
                }
            }
            if (action >= 200000+15)
                player->ADD_GOSSIP_ITEM(0, "<---------", 0, action - 15);
        }
        player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        CharTitlesEntry const* entry = sCharTitlesStore.LookupEntry(action);
        if (entry)
            if (!player->HasTitle(entry))
                player->SetTitle(entry);


        showMore(player, creature, action);

        return true;
    }
};

void AddSC_npc_pvp_titles()
{
    new npc_pvp_titles();
}