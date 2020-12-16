#pragma once

#include "../../../../Library/Scene/Task.h"
#include "StageChapter.h"

class BaseStage:public Task {
protected:
	int mTime;
	StageChapter mChapter;
	int mBackHdl;
public:

	BaseStage(int)noexcept;
	BaseStage(StageFunc& initFunc,std::vector<StageFunc>& Func)noexcept;
	BaseStage(StageFunc& initFunc, StageFunc Func)noexcept;
	~BaseStage()noexcept;

	void Initialize()noexcept override;
	void Finalize()noexcept override;
	void Update(float t)noexcept override;
	void Draw()const noexcept override;

	void setBack(int Hdl) { mBackHdl = Hdl; }

	int GetTime()const noexcept { return mTime; }
StageChapter& GetChapter()noexcept { return mChapter; }
#ifdef _DEBUG
	void DrawDebug(int X, int Y)noexcept;
#endif
};