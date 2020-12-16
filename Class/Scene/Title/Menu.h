#pragma once

#include "../../../Library/Scene/Task.h"
#include "../../../Library/Scene/SceneMgr.h"

//メニュー画面クラス
class Menu : public Task {
	CSceneMgr mMenumgr;
	int backShadowHdl;
	int mBackAlpha;
	bool mChangeFlag;
	int mTime;
public:
	Menu(int Value)noexcept;
	~Menu()noexcept {}
	void Initialize()noexcept override;
	void Finalize()noexcept override;
	void Update(float t = 1.0f)noexcept override;
	void Draw()const noexcept override;

};
