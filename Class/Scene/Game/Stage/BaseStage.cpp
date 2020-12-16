
#include "BaseStage.h"
#include"../../../../Library/Renderer.h"

BaseStage::BaseStage(int)noexcept: mTime(0),mChapter(this){}
BaseStage::BaseStage(StageFunc& initFunc, std::vector<StageFunc>& Func)noexcept :mChapter(this,initFunc,Func), mTime(0){}
BaseStage::BaseStage(StageFunc& initFunc, StageFunc Func)noexcept : mChapter(this,initFunc,Func), mTime(0) {}
BaseStage::~BaseStage()noexcept{}

void BaseStage::Initialize()noexcept  {}
void BaseStage::Finalize()noexcept  {}
void BaseStage::Update(float t) noexcept {
	if (mChapter.IsFinished()) {
		mLiveFlag = false;
		return;
	}
	mChapter.Update(t);
	//mTime += t;
}
void BaseStage::Draw()const noexcept {
	DxWrp::DrawGraph(0,0,mBackHdl);
}

#ifdef _DEBUG
#include"../../../../Library/Color/ColorData.h"
#include "DxLib.h"
void BaseStage::DrawDebug(int X, int Y) noexcept {
	DxLib::SetDrawBlendMode(BLEND_ALPHA, 150);
	{
		DxLib::DrawBox(X, Y, X + 300, Y + 80, GREY, TRUE);
		DxLib::DrawBox(X, Y, X + 300, Y + 80, WHITE, FALSE);
	}
	DxLib::SetDrawBlendMode(0, 0);
	DxLib::DrawFormatString(X + 5, Y + 5, WHITE, "Stage Scene Debug");
	DxLib::DrawFormatString(X + 5, Y + 25, WHITE, "Time %d", mTime);
	DxLib::DrawFormatString(X + 5, Y + 45, WHITE, "Stage Time %d", int(mChapter.GetTime()));
	DxLib::DrawFormatString(X + 5, Y + 65, WHITE, "Stage Chapter Num %d", mChapter.GetNowChapter());
}
#endif