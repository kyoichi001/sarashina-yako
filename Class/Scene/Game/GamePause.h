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
	int mState;//-1: ������� 0: �|�[�Y�� 1: �|�[�Y���Ă�Œ� 2: �|�[�Y���I���Œ� 3:�|�[�Y���I�����
	int mMessage;
public:
	GamePause(Game* GamePtr)noexcept;
	bool Update(float t)noexcept;
	void Draw()const noexcept;
	void Init()noexcept;
	void Open()noexcept { mState = 1; }
	int sendMessage()noexcept;//0:�ُ�Ȃ��@1:�Q�[������蒼�� 2:�Q�[�����I������
};