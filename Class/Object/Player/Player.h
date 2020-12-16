#pragma once

#include "IPlayer.h"

void InitPlayerResource()noexcept;

class Hirochi1 :public IPlayer {
public:
	Hirochi1()noexcept;
	void drawPlane()const noexcept override;
};

class Hirochi2 :public IPlayer {
public:
	Hirochi2()noexcept;
	void drawPlane()const noexcept override;
};