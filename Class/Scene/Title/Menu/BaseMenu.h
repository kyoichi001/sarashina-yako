#pragma once

#include "../../../../Library/Scene/Task.h"

class Menu;

//シーンの基底クラス。
class BaseMenu :public Task {
protected:
	static Menu* mMenuptr;
public:
	BaseMenu()noexcept;
	virtual ~BaseMenu()noexcept;
	virtual void Initialize()noexcept override{}
	virtual void Finalize()noexcept override {}
	virtual void Update(float t = 1.0f)noexcept override{}
	virtual void Draw()const noexcept override{}
	Menu* getParent()noexcept { return mMenuptr; }
	void static SetMenuptr(Menu* menuptr)noexcept { mMenuptr = menuptr; }
};