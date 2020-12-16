#pragma once

class IPlayer;

class PlayerFactory {
public:
	PlayerFactory();
	IPlayer* getPlayer(char weapon);
};