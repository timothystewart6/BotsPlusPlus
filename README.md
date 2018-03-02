# BotsPlusPlus

|  Circle CI    |  Travis Build|  Auth Server |  World Server  |  Build Tools  |
|  ------------ |  ----------- | ------------- | ------------- | ------------- |
| [![CircleCI](https://circleci.com/gh/timothystewart6/BotsPlusPlus/tree/master.svg?style=shield)](https://circleci.com/gh/timothystewart6/BotsPlusPlus/tree/master)| [![Build Status](https://travis-ci.org/timothystewart6/BotsPlusPlus.svg?branch=master)](https://travis-ci.org/timothystewart6/BotsPlusPlus)| [![Docker Pulls](https://img.shields.io/docker/pulls/timothystewart6/botsplusplus-authserver.svg)](https://hub.docker.com/r/timothystewart6/botsplusplus-authserver/)| [![Docker Pulls](https://img.shields.io/docker/pulls/timothystewart6/botsplusplus-worldserver.svg)](https://hub.docker.com/r/timothystewart6/botsplusplus-worldserver/)| [![Docker Pulls](https://img.shields.io/docker/pulls/timothystewart6/trinitycore-docker.svg)](https://hub.docker.com/r/timothystewart6/trinitycore-docker/)

Trinity Core 3.3.5a with NPC Bots and Extras. Great for learning, single player, or playing with friends.

## Trinity Core

This source is based on [TrinityCore Revision 330e5b0](https://github.com/TrinityCore/TrinityCore/commit/330e5b0ebcc6753a355afc3824121c5eba1bf5bc)

## New NPC Bots Source from martin26

* NPC Bots
* AH Bot

With [NewNPC Bots f7936eb9](https://github.com/martin26/NewNPCBots/commit/f7936eb9ea332c45146c59810f7d0d6bd3313308)

## New NPC Bots Source by thanosdk

For more information on how to use NPC Bots please see: [thesawolf New NPC Bots Readme](https://github.com/thesawolf/TrinityCore/blob/TrinityCoreLegacy/README_Bots.md)

## Lord Psyan Patches

With [Lord Psyan Patches](https://bitbucket.org/technotim/lordpsyan-patches)

* Start Guild
* Auto Learn New Spells
* Announce Login
* Account Mounts
* Login BoA (with enchants)
* Start Guild
* Beastmaster

## SQL Scripts

### world_db

You will need to use [TDB 335.61](https://github.com/TrinityCore/TrinityCore/releases/tag/TDB335.61)

Not sure this is necessary but here is the order in which to apply database scripts:

* create
* base
* world (see above)
* updates
* custom

### Custom

Included in `sql/custom`

* Portal Master by [rochet2](http://rochet2.github.io/Portal-Master.html)
* Heirloom Vendor by [Fullhouser](http://sqlmegapack.weebly.com/)
* Buff Master by [Fullhouser](http://sqlmegapack.weebly.com/) and [SingleCore](https://github.com/conan513/SingleCore_TC)
* Aura Master by [Fullhouser](http://sqlmegapack.weebly.com/) and fixes by [timothystewart6](https://github.com/timothystewart6)
* Trainer Master by [Fullhouser](http://sqlmegapack.weebly.com/) and fixes by [timothystewart6](https://github.com/timothystewart6)
* Profession Teleporter by [Fullhouser](http://sqlmegapack.weebly.com/) and fixes by [timothystewart6](https://github.com/timothystewart6)
* Profession Material Vendor by [Fullhouser](http://sqlmegapack.weebly.com/) and fixes by [timothystewart6](https://github.com/timothystewart6)
* Class Material Vendor by [Fullhouser](http://sqlmegapack.weebly.com/) and fixes by [timothystewart6](https://github.com/timothystewart6)
* Level Rewards by [thesawolf](https://github.com/thesawolf/TrinityCore/tree/TrinityCoreLegacy/sql/TrinityCore-Patches/LegacyTrinityCore) and fixes by [timothystewart6](https://github.com/timothystewart6)
* Spawned NPC Bots by [timothystewart6](https://github.com/timothystewart6)
* Gear Master by [timothystewart6](https://github.com/timothystewart6)
* Level Master by [timothystewart6](https://github.com/timothystewart6)
* Jewel Crafting trainers in Stormwind and Orgrimmar by [timothystewart6](https://github.com/timothystewart6)
* Title Master by [timothystewart6](https://github.com/timothystewart6)
* Reputation Master by [timothystewart6](https://github.com/timothystewart6)

`C++` scripts applied:

* Item Enchant Visuals [rochet2](http://rochet2.github.io/Item-Enchant-Visuals.html)
* Fireworks on Level up (All) [SingleCore](https://github.com/conan513/SingleCore_TC)
* Boss Announcer [SingleCore](https://github.com/conan513/SingleCore_TC)
* Account Achievements [SingleCore](https://github.com/conan513/SingleCore_TC)
* Congrats on Level [SingleCore](https://github.com/conan513/SingleCore_TC)
* Arcane Reforger [rochet2](http://rochet2.github.io/Reforging.html) from [fd44b6d9](https://github.com/Rochet2/TrinityCore/commit/fd44b6d998818ffaa70b605a58c63318598e3f9a)
* Transmogrification NPC [rochet2](http://rochet2.github.io/Transmogrification.html)
* Enchanter NPC [SingleCore](https://github.com/conan513/SingleCore_TC)
* Played Time Rewards [SingleCore](https://github.com/conan513/SingleCore_TC)
* Level NPC [rochet2](http://rochet2.github.io/Item-Enchant-Visuals.html) (forum post)
* Double XP Weekend [SingleCore](https://github.com/conan513/SingleCore_TC)
* Title NPC [JunkyBulgaria/BattleArenas-2](https://github.com/JunkyBulgaria/BattleArenas-2)
* Account Companions [timothystewart6](https://github.com/timothystewart6)
* Lord Psyan patches mentioned above

## NPC List

| Name | Utility  |
|-------------| -----|
| LordPsyan | Beastmaster |
| Simon Magus | Enchanter |
| Major Oak | Heirlooms |
| Prospero | Portal Master |
| Thaumaturge Vashreen | Arcane Reforger |
| Warphoof | Transmogrifier |
| Gwydion | Buff Master |
| Faegan | Aura Master |
| Ulf | Trainer Master |
| Wu | Profession Teleporter|
| Sartie Sweettoe | Profession Material Vendor |
| Ja'Nanji | Class Materials |
| Acantha | Gear Master |
| Maiden of the Stars| Level Master |
| NPC Bots| Stormwind |
| NPC Bots| Orgrimmar |
| Grunty | Title Master |
| Wal'rufus | Reputation Master |

## Config

We have included better defaults that are tailored for customizations this server supports.  They are ready to use, all you need to do is update the database info. Both auth and world configs can be found at:

`src/server/authserver/authserver.conf`

`src/server/worldserver/worldserver.conf`

## Docker

* Docker images use a modified version of [neechbear/trinitycore](https://github.com/neechbear/trinitycore)
* All credit goes to [neechbear](https://github.com/neechbear) for creating a great set of Docker images to boostrap the ones used in this repo.

### Docker commands

#### Starting the auth server

```bash
docker run -d \
-p 3724:3724 \
-e DB_HOST=192.168.0.100 \
-e DB_PORT=3306 \
-v /path/to/your/authserver:/opt/trinitycore/etc/ \
-v /path/to/your/logs:/opt/trinitycore/logs/ \
timothystewart6/botsplusplus-authserver:latest
```

#### Starting the world server

```bash
docker run -d \
-p 8085:8085 \
-e DB_HOST=192.168.0.100 \
-e DB_PORT=3306 \
-v path/to/your/worldserverconf:/opt/trinitycore/etc/ \
-v path/to/your/cameras:/opt/trinitycore/bin/cameras \
-v path/to/your/dbc:/opt/trinitycore/bin/dbc \
-v path/to/your/maps:/opt/trinitycore/bin/maps \
-v path/to/your/mmaps:/opt/trinitycore/bin/mmaps \
-v path/to/your/vmaps:/opt/trinitycore/bin/vmaps \
-v path/to/your/logs:/opt/trinitycore/logs/ \
timothystewart6/botsplusplus-worldserver:latest
```

## Build

[Windows Requirements](https://trinitycore.atlassian.net/wiki/spaces/tc/pages/10977296/Windows+Requirements)

* Visual Studio 2017 (x64)
* Boost 1.63.0 (x64)
* MySQL 5.6.39.0 (x64)
* CMake 3.9.1 (x64)
* OpenSSL 1.0.2L (x64)

[Linux Requirements](https://trinitycore.atlassian.net/wiki/spaces/tc/pages/10977288/Linux+Requirements)

* Built on Debian 9.x
* Tested on Debian 9.x
