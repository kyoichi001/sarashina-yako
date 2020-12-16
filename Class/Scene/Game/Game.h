#pragma once

#include "../../../Library/Scene/Task.h"
#include "../../../Library/Scene/SceneMgr.h"
#include "GamePause.h"
#include "GameScore.h"

//�Q�[����ʃN���X
class Game : public Task {
	CSceneMgr StageMgr;
	bool StagePracticeFlag;
	GamePause mPause;
	GameScore mScore;
	int mStageID;
public:
	//Value 0 �ʂ��Ńv���C 1~6 �v���N�e�B�X 7: �f�o�b�O���[�h
	Game(int stageID )noexcept;
	~Game()noexcept;
	void Initialize()noexcept override;
	void Finalize()noexcept override;
	void Update(float t = 1.0f)noexcept override;
	void Draw()const noexcept override;
	void Reset();
#ifdef _DEBUG
private:
	void DrawDebugWindow(int X,int Y)const noexcept;
#endif

};