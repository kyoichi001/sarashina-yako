
#include "DxLib.h"
#include "Fps.h"

Fps::Fps()noexcept :mStartTime(0), mCount(0), mFps(0){}
Fps::~Fps()noexcept{}

void Fps::Update()noexcept {
	if (mCount == 0){//1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N){//60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	++mCount;
}

float Fps::GetFps()const noexcept {
	return mFps;
}
