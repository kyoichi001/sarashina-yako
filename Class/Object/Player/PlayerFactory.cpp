
#include "PlayerFactory.h"

#include "Player.h"

PlayerFactory::PlayerFactory(){
	InitPlayerResource();
}

IPlayer* PlayerFactory::getPlayer(char weapon) {
	switch (weapon) {
	case 0:return new Hirochi1();
	case 1:return new Hirochi2();
	case 2:return new Hirochi1();
	}
	return new Hirochi1();
}