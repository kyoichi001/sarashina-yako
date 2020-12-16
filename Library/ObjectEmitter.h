
#pragma once

#include <functional>

class Emitter {
protected:
	std::function<void(void)> mEmit;
	int mTime;
	int mInterval, mMakeTime;
	int mCount;
	bool mLiveFlag;
public:
	Emitter(const std::function<void(void)>&& Emit, int Interval, int MakeTime)noexcept;
	~Emitter()noexcept;
	bool Update(float t)noexcept;
	void Draw()const noexcept {}
	bool IsLive()const noexcept { return mLiveFlag; }
	void Kill()noexcept { mLiveFlag = false; }
#ifdef _DEBUG
	void DrawDebug();
#endif
};