#include "WorldSession.h"
#include "World.h"
#include "Chat.h"
#include <string>
#include<chrono>
#include<thread>


using namespace std;

/*
    Script made by Dustin (Sinistah) if you want to contact me or want to see more things I make go to Http://wowmodding.com
*/

// ToDo/Ideas:
//   - Might be a good idea to add support for world config settings so you dont need to recompile to change things.
class welcome_message : public PlayerScript {

public:
	welcome_message() : PlayerScript("welcome_message") { }

    // True = New Character Only / False = Everyone
    static constexpr bool newCharactersOnly = true;

    /* Message Type:
       0 = Individual chatbox message
       1 = Red individual center screen notification
       2 = Yellow individual center screen notification
       3 = World chatbox message.
       All messages are affected by colors. */
    static constexpr int messageType = 0;

    // Server name along with its own color.
    const string serverName = "|cffFFFFFF[ServerName]|r ";

    // This is the color for the rest of the message.
    const string messageColor = "|cff70f98e";

    void SendMsg(Player* player) const {
        // Edit the following line if you want to customize the message itself.
        string msg = serverName + messageColor + "Welcome, " + player->GetName() + "!|r " +
        "Be sure to visit the Heirloom vendor for gear and a mount that you can use immediately. " +
        "Be sure to make your way to Stormwind or Orgrimmar, there's plenty to see and do there including a level 70 boost. ";
        // Calls the message handler function which sends our message.

        std::this_thread::sleep_for(std::chrono::nanoseconds(10));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(10));
        MessageHandler(player, messageType, msg);
    }

    // If your a novice in c++ stay away from the lines below it is mostly functionality rather than customization.
    // This function is what decides which message type to send based on the messageType variable.
    void MessageHandler(Player* player, int type, string message) const {
        switch (type) {
            case 0:
                ChatHandler(player->GetSession()).SendSysMessage(message.c_str());
                break;
            case 1:
                player->GetSession()->SendNotification(message.c_str());
                break;
            case 2:
                player->GetSession()->SendAreaTriggerMessage(message.c_str());
                break;
            case 3:
                sWorld->SendGlobalText(message.c_str(), nullptr);
                break;
            default:
                ChatHandler(player->GetSession()).SendSysMessage(message.c_str());
                break;
        }
    }

    // This is the OnLogin player hook that is called everytime a player logs in. It then calls our other functions.
    void OnLogin(Player* player, bool firstLogin) {
        if (newCharactersOnly) {
            if (firstLogin) SendMsg(player);
        } else SendMsg(player);
    }
};

void AddSC_welcome_message() {
    new welcome_message();
}
