
#include "Timer.h"

Timer::Timer()noexcept: mStart(0), mEnd(0), mDuration(0){}
void Timer::restart()noexcept {
	mStart = clock();
}
int Timer::elapsed()noexcept {
	mEnd = clock();
	return mDuration = int(mEnd - mStart);
}