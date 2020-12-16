
#include "ObjectEmitter.h"

Emitter::Emitter(const std::function<void(void)>&& Emit, int Interval, int MakeTime)noexcept : mEmit(Emit), mInterval(Interval), mMakeTime(MakeTime), mTime(0), mLiveFlag(true), mCount(0) {}

Emitter::~Emitter()noexcept{}

bool Emitter::Update(float t)noexcept {
	if (mInterval == 0) {
		for (int i = 0; i < mMakeTime; ++i)mEmit();
		mLiveFlag = false;
		return false;
	}
	else if (mTime == (mCount * mInterval)) {
		mEmit();
		if (mCount >= mMakeTime) {
			mLiveFlag = false;
			return false;
		}
		++mCount;
	}
	mTime += t;
	return mLiveFlag;
}

#ifdef _DEBUG
#include "DxLib.h"
void Emitter::DrawDebug() {

}
#endif