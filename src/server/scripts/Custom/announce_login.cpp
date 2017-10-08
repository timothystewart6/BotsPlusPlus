class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {
        std::ostringstream ss;
            ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online.";
        sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
    }
};

void AddSC_announce_login()
{
    new announce_login;
}