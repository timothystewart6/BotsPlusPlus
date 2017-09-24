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
* Annouce Login
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

* Portal Master [rochet2](http://rochet2.github.io/Portal-Master.html)

`C++` scripts applied:

* Item Enchant Visuals [rochet2](http://rochet2.github.io/Item-Enchant-Visuals.html)
* Fireworks on Level up (All) [SingleCore](https://github.com/conan513/SingleCore_TC)
* Boss Announcer [SingleCore](https://github.com/conan513/SingleCore_TC)
* Account Achievements [SingleCore](https://github.com/conan513/SingleCore_TC)
* Congrats on Level [SingleCore](https://github.com/conan513/SingleCore_TC)
* Arcane Reforger [rochet2](http://rochet2.github.io/Reforging.html) from [fd44b6d9](https://github.com/Rochet2/TrinityCore/commit/fd44b6d998818ffaa70b605a58c63318598e3f9a)
* Transmogrification NPC [rochet2](http://rochet2.github.io/Transmogrification.html)
* Enchanter NPC [SingleCore](https://github.com/conan513/SingleCore_TC)
* Lord Psyan patches mentioned above
* Heirloom Vendor [Fullhouser](http://sqlmegapack.weebly.com/)

## Docker

* Docker images use a modified version of [neechbear/trinitycore](https://github.com/neechbear/trinitycore)
* All credit goes to [neechbear](https://github.com/neechbear) for creating a great set of Docker images to boostrap the ones used in this repo.

## Build

[Windows Requirements](https://trinitycore.atlassian.net/wiki/spaces/tc/pages/10977296/Windows+Requirements)

* Visual Studio 2017 (x64)
* Boost 1.63.0 (x64)
* MySQL 5.6.37.0 (x64)
* CMake 3.9.1 (x64)
* OpenSSL 1.0.2L (x64)

[Linux Requirements](https://trinitycore.atlassian.net/wiki/spaces/tc/pages/10977288/Linux+Requirements)

* Tested on Debian 9.x
