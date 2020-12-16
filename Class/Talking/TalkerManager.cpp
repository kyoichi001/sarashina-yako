
#include "TalkerManager.h"
#include "../../Library/Renderer.h"

TalkerManager::TalkerManager()
	:mActiveFlag(false), mCurrentTalk(nullptr), mTalker(nullptr), mChanges(true), mTime(0), mCood({100.0f,100.0f}) {}

void TalkerManager::update(float t) {
	if (mChanges) {
		++mTime;
		if (mTime >= 3) {
			mTime = 0;
			mChanges = false;
		}
		mCood += mActiveFlag?Vec2{ 10.0f,10.0f }: -Vec2{ 10.0f,10.0f };
	}
}
void TalkerManager::draw()const {
	if (!mTalker)return;
	DxWrp::SetBlendModeAlpha(mActiveFlag ? 255 : 150);
	DxWrp::DrawRotaGraph(mCood, 0.75f, 0.0f, mTalker->Hdl);
	DxWrp::ResetBlendMode();
}
void TalkerManager::setTalker(Talker* talker, bool activeFlag, const Point& cood) {
	mTalker = talker;
	mActiveFlag = activeFlag;
	mCood = cood;
}
void  TalkerManager::activate() {
	if (!mActiveFlag) {
		mActiveFlag = true;
		mChanges = true;
	}
}
void  TalkerManager::inactivate() {
	if (mActiveFlag) {
		mActiveFlag = false;
		mChanges = true;
	}
}