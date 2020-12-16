
#include "IEffect.h"

IEffect::IEffect(const Point& XY, int LifeTime)noexcept : Point(XY), mLifeTime(LifeTime), mTime(0), mLiveFlag(true) {}
IEffect::~IEffect()noexcept {}