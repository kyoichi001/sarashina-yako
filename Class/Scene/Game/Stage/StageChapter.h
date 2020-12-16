
#pragma once

#include <vector>

class ObjectAdaptor;
class StageChapter;
class BaseStage;
using StageFunc = void(*)(ObjectAdaptor&, StageChapter*, int);

class StageChapter{
	std::vector<StageFunc> mFunc;
	float mTime;
	char mChapter;
	bool mLiveFlag;
	static ObjectAdaptor* mObj;
	BaseStage* mStage;
public:
	StageChapter(BaseStage* stage)noexcept;
	StageChapter(BaseStage* stage,StageFunc& initFunc,std::vector<StageFunc>& Func)noexcept;
	StageChapter(BaseStage* stage,StageFunc& initFunc, StageFunc& Func)noexcept;
	~StageChapter()noexcept;
	void Update(float t)noexcept;
	void Next()noexcept;
	void Push(StageFunc& Func)noexcept;
	void Push(std::vector<StageFunc>& Func)noexcept;
	bool IsFinished()const noexcept { return mChapter >= mFunc.size(); }//全てのチャプターを実行し終わったか
	float GetTime()const noexcept { return mTime; }
	void setBack(int Hdl);
	static void SetAdaptor(ObjectAdaptor* Adaptor)noexcept { mObj = Adaptor; }
#ifdef _DEBUG
	int GetNowChapter()const noexcept { return mChapter; }
#endif
};