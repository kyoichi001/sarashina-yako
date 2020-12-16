#pragma once

#include "../../../Library/Scene/Task.h"
#include "../../../Library/Scene/SceneMgr.h"
#include "GamePause.h"
#include "GameScore.h"

//ゲーム画面クラス
class Game : public Task {
	CSceneMgr StageMgr;
	bool StagePracticeFlag;
	GamePause mPause;
	GameScore mScore;
	int mStageID;
public:
	//Value 0 通しでプレイ 1~6 プラクティス 7: デバッグモード
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