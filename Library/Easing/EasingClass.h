
#pragma once

#include "InterpolationMethod.h"

using call_back = void(*)();

//éÂÇ…ÉNÉâÉXóp
template<typename T>
class Easing{
	T* mValue;
	T mMax, mMin;
	int mTime, mLimit;
	EasingFunc mEasing;
	call_back mCallBack;
	bool mStartFlag;
public:
	Easing()noexcept :mStartFlag(false){}

	Easing(T* Value, const T& min, const T& max, int Time, EasingFunc Easing = Ease<Liner>::In, call_back CallBack = [](){}) noexcept :
		mValue(Value), mMax(max), mMin(min), mLimit(Time), mEasing(Easing), mTime(0), mCallBack(CallBack), mStartFlag(true){}
	~Easing()noexcept{}
	void Init(T* Value, const T& min, const T& max, int Time, EasingFunc Easing = Ease<Liner>::In, call_back CallBack = [](){})noexcept {
		mValue = Value;
		mMin = min;
		mMax = max;
		mLimit = Time;
		mEasing = Easing;
		mTime = 0;
		mCallBack = CallBack;
		mStartFlag = true;
	}
	void InitReverce()noexcept {
		T a = mMin;
		mMin = mMax;
		mMax = a;
		mTime = 0;
		mStartFlag = true;
	}
	void Update(float t=1.0f)noexcept {
		if (mStartFlag){
			if (mTime<mLimit ){
				float s = float(mTime) / float(mLimit);// éûä‘Çî}âÓïœêîÇ…
				*mValue = mMin * (1.0f - mEasing(s)) + mMax * mEasing(s);
				mTime+=t;
			}
			else if (mTime >= mLimit){
				mCallBack();
				mStartFlag = false;
			}
		}
	}
	bool IsFinished()const noexcept { return !mStartFlag; }//Ç‡Ç§èIÇÌÇ¡ÇƒÇ¢ÇÈÇ©Ç«Ç§Ç©
	bool IsFinish()const noexcept { return mTime==mLimit; }//èIÇÌÇÈèuä‘Ç©Ç«Ç§Ç©
	void Stop()noexcept { mStartFlag = false; }
	void Restart()noexcept { mStartFlag = true; }
	void Redo()noexcept {
		mStartFlag = true;
		mTime = 0;
	}
};

template<typename T>
class D_Easing {
	T* mValue;
	T mMax;
	int mTime, mLimit;
	EasingFunc mEasing;
	call_back mCallBack;
	bool mStartFlag;
public:
	D_Easing()noexcept : mStartFlag(false) {}

	D_Easing(T* Value,const T& max, int Time, EasingFunc Easing = Ease<Liner>::In, call_back CallBack = []() {}) noexcept :
		mValue(Value), mMax(max), mLimit(Time), mEasing(Easing), mTime(0), mCallBack(CallBack), mStartFlag(true) {}
	~D_Easing()noexcept {}
	void Init(T* Value, const T& max, int Time, EasingFunc Easing = Ease<Liner>::In, call_back CallBack = []() {})noexcept {
		mValue = Value;
		mMax = max;
		mLimit = Time;
		mEasing = Easing;
		mTime = 0;
		mCallBack = CallBack;
		mStartFlag = true;
	}
	void Update(float t = 1.0f)noexcept {
		if (mStartFlag) {
			if (mTime < mLimit) {
				float s = float(mTime) / float(mLimit);// éûä‘Çî}âÓïœêîÇ…
				*mValue += (mMax / mLimit)*mEasing(s);
				mTime += t;
			}
			else if (mTime >= mLimit) {
				mCallBack();
				mStartFlag = false;
			}
		}
	}
	bool IsFinished()const noexcept { return !mStartFlag; }
	bool IsFinish()const noexcept { return mTime == mLimit; }
	void Stop()noexcept { mStartFlag = false; }
	void Restart()noexcept { mStartFlag = true; }
	void Redo()noexcept {
		mStartFlag = true;
		mTime = 0;
	}
};