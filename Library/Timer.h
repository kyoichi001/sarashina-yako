
#pragma once

#include<time.h>

class Timer {
	clock_t mStart, mEnd;
	int mDuration;
public:
	Timer()noexcept;
	void restart()noexcept;
	int elapsed()noexcept;
	int getDuration()const noexcept { return mDuration; }
};