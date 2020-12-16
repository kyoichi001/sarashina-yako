
#pragma once

#include "../../../Library/Typedef.h"
#include "../../../Library//Math/Random.h"
#include "../../../Library/ObjectEmitter.h"
#include "../../../Data/Data.h"


class BulletFactory;

class BEmitter :public Emitter {
	uchar mDFanMany ;
	float mDSpeed, mDAngle;
	float mDOpen;
	short mDRadius;
	static BulletFactory* mBsList;
	void Emit(uchar ID, uchar renewID, const Point& XY, uchar fanMany, float Angle, float Speed, float open , short radius);
public:
	friend BulletFactory;
	template<typename T>
	BEmitter(uchar ID, uchar renewID,T* Cood, uchar FanMany, uchar Interval, unsigned ShotTime, float Angle, float Speed, float open = 0.0f, short Radius = 0)noexcept
		:Emitter([this, Cood, ID, renewID, FanMany, Angle, Speed, open, Radius]()mutable {
		if (!Cood) {
			mLiveFlag = false;
			return;
		}
		Emit(ID, renewID, Rand(*Cood), FanMany, Angle, Speed, open, Radius);

		Speed += mDSpeed;
		Angle += mDAngle;
		FanMany += mDFanMany;
		open += mDOpen;
		Radius += mDRadius;
	},
		Interval, ShotTime),
		mDFanMany(0), mDSpeed(0.0f), mDAngle(0.0f), mDOpen(0.0f), mDRadius(0){
	}
	~BEmitter()noexcept{}
	BEmitter& SetDelta(int DFanMany , float DAngle = 0.0f, float DSpeed = 0.0f, float Dopen = 0.0f, short DRadius=0)noexcept;
	void static SetSplitBList(BulletFactory* BulletListPointer)noexcept { mBsList = BulletListPointer; }

};