#pragma once

#ifdef _DEBUG

#include "BaseMenu.h"
#include "../../../../Library/GUI/GUI.h"

class Debug :public BaseMenu {
	GUI mGUI;
public:
	Debug();

	void Initialize()noexcept override;
	void Finalize()noexcept override;

	void Update(float t = 1.0f)noexcept override;
	void Draw()const noexcept override;

};

#endif