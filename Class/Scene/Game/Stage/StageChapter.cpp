
#include "StageChapter.h"
#include "BaseStage.h"

ObjectAdaptor* StageChapter::mObj=nullptr;

StageChapter::StageChapter(BaseStage* stage) noexcept:mStage(stage),mTime(0.0f), mChapter(0){}
StageChapter::StageChapter(BaseStage* stage,StageFunc& initFunc, std::vector<StageFunc>& Func) noexcept
	:mStage(stage), mTime(0.0f), mChapter(0), mFunc(Func) {
	mFunc.insert(mFunc.begin(),initFunc);
}
StageChapter::StageChapter(BaseStage* stage,StageFunc& initFunc, StageFunc& Func) noexcept 
	: mStage(stage),mTime(0.0f), mChapter(0){
	mFunc.push_back(initFunc);
	Push(Func);
}
StageChapter::~StageChapter()noexcept{}

void StageChapter::Update(float t) noexcept {
	mFunc[mChapter](*mObj, this, mTime);
	mTime += t;
}
void StageChapter::Next()noexcept {
	if (!IsFinished()) {
		++mChapter;
		mTime = 0;
	}
}
void  StageChapter::setBack(int Hdl) {
	mStage->setBack(Hdl);
}

void StageChapter::Push(StageFunc& Func)noexcept {
	mFunc.push_back(Func);
}
void  StageChapter::Push(std::vector<StageFunc>& Func)noexcept {
	for (int i = 0; i < Func.size(); ++i) {
		mFunc.push_back(Func[i]);
	}
}

