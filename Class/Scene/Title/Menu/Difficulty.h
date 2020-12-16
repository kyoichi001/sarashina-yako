#pragma once

#include "BaseMenu.h"
#include "../../../../Library/GUI/GUI.h"

class Difficulty :public BaseMenu {
	GUI mGUI;
public:
	Difficulty();

	void Initialize()noexcept override;
	void Finalize()noexcept override;

	void Update(float t = 1.0f)noexcept override;
	void Draw()const noexcept override;

};

