#pragma once

#include "../../../Library/GUI/GUI.h"
#include "../../../Library/Easing/EasingClass.h"

class Game;

class GamePause {
	GUI mMenu;
	int PauseAlpha;
	Easing<int> mPauseEasing;
	Easing<Point> mMenuEasing;
	Game* mGamePtr;
	int mState;//-1: 初期状態 0: ポーズ中 1: ポーズしてる最中 2: ポーズが終わる最中 3:ポーズが終わった
	int mMessage;
public:
	GamePause(Game* GamePtr)noexcept;
	bool Update(float t)noexcept;
	void Draw()const noexcept;
	void Init()noexcept;
	void Open()noexcept { mState = 1; }
	int sendMessage()noexcept;//0:異常なし　1:ゲームをやり直せ 2:ゲームを終了せよ
};