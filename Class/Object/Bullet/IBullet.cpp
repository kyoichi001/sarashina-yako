
#include "IBullet.h"
#include "RenewManager.h"
#include "../Effect/Effects.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../../../Library/Math/Collision.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Geometory.h"
#include "../../../Data/Resource.h"

float IBullet::TurnAngle = 0.0f;

ObjectAdaptor* IBullet::mCList = nullptr;
DammakuData* IBullet::mBul=nullptr;

void  IBullet::SetClassList(ObjectAdaptor* ClassListPtr)noexcept { mCList = ClassListPtr; mBul = ClassListPtr->FacBul().getData().mBullet; }

IBullet::IBullet()noexcept {}

IBullet::IBullet(uchar ID, uchar renewID,const Point& XY, const Vec2& Speed, BulletColor Color, Point* Parent, BulletData* Data)noexcept:
	Circle(XY,Data->radius), mLiveFlag(true),mTime(0.0f), mData(Data),mID(ID),mRenewID(renewID),mSpeed(Speed),mColor(Color),mParent(Parent){
	mCList->ObjEff().SetObject(new BulletEffect(p, Color));
}

void IBullet::Init(uchar ID, uchar renewID, const Point& XY,const Vec2& Speed, BulletColor Color, Point* Parent, BulletData* Data)noexcept {
	mData = Data;
	r = mData->radius;
	mLiveFlag = true;
	p = XY; mID = ID; mRenewID=renewID,mSpeed = Speed; mColor = Color;mParent = Parent;
	mTime = 0.0f;
	mCList->ObjEff().SetObject(new BulletEffect(p, Color));
}

bool IBullet::Update(float t)noexcept {
	p += mSpeed*t;
	//if (mParent != nullptr)	p += *mParent;
	mCList->ObjBRen().Renew(mRenewID, *this, mTime, *mCList);
	mTime+=t;
	return IsLive();
}

void IBullet::Draw()const noexcept {
	DxWrp::SetDrawBlendMode(mBul[mID].mDrawBlend, 255);
	mData->Draw(p, mSpeed, mColor, mTime);
	DxWrp::SetDrawBlendMode(0, 255);
}

void IBullet::Kill()noexcept {
	if (mTime > mBul[mID].mTill) {
		mCList->ObjEff().SetObject(new BulletBreak(p, 1.0f, 10, mColor));
		mLiveFlag = false;
	}
}
bool IBullet::IsOver()const noexcept { return !IsHit(BulletRect, *this) && mTime > mBul[mID].mTill; }

void IBullet::Remake( BulletColor rColor, BulletShape obj) noexcept {
	if (rColor != BulletColor::NoColor) mColor = rColor;
	if (obj != BulletShape::NoShape) {
		Kill();
		//mCList->GetBul()->Bullet(mID, &p, Angle, Speed, mAccel, obj, mColor);
	}
	//PLAY_SE(4);
}
void IBullet::Accel( float Speed)noexcept {
	// v *(|v| + delta) =v *(1+ delta)
	//|v|                         |v|
	mSpeed *= (1 + Speed / mSpeed.length());
}
void IBullet::Split(uchar ID, uchar renewID, uchar FanMany, float Angle, float Speed, float open, bool LiveFlag) noexcept {
	DammakuData& data = mCList->FacBul().getData().mBullet[ID];
	BulletColor color = data.mColor == BulletColor::NoColor ? mColor : data.mColor;
	BulletShape shape = data.mShape;
	//if (data.mShape == BulletShape::NoShape)shape = mShape;
	if (data.mAngleState == BulletState::Sequence)Angle += mSpeed.Angle();
	mCList->FacBul().Bullet(ID, renewID, p, FanMany, Angle, Speed, open);
	if (!LiveFlag)Kill();
	//PLAY_SE(4);
}

void IBullet::SetSpeed(const Vec2& Speed)noexcept { mSpeed = Speed; }
void IBullet::Turn( float Angle)noexcept { mSpeed.Rotate(Angle); }
void IBullet::Force(const Vec2&& Accel)noexcept { mSpeed += Accel; }
void IBullet::Rotate(const Point& P, float Angle)noexcept {
	p = Rotation(p,P,Angle);
}
void IBullet::Renew(float Angle, float Speed, BulletState AngleState, BulletState SpeedState)noexcept {
	switch (AngleState) {
	case Absolute:
		if (SpeedState == Absolute) {
			mSpeed = { Angle,Speed,0 };
		}
		else {
			mSpeed = { Angle,Speed + mSpeed.length(),0 };
		}
		break;
	case Sequence:
		if (SpeedState == Absolute) {
			mSpeed = { mSpeed.Angle() + Angle,Speed,0 };
		}
		else {
			mSpeed = { mSpeed.Angle() + Angle,Speed + mSpeed.length(),0 };
		}
		break;
	case Aiming:
		if (SpeedState == Absolute) {
			mSpeed = { mCList->FacBul().GetBullettoPlayerAngle(p) + Angle,Speed,0 };
		}
		else {
			mSpeed = { mCList->FacBul().GetBullettoPlayerAngle(p) + Angle,Speed + mSpeed.length(),0 };
		}
		break;
	}
}
#include "../../../Library/Func.h"
bool IBullet::isReflected(uchar reflectflag, Point& Cood, Vec2& Speed)noexcept {
	if ((GetDigit(reflectflag, 2) && int(p.x) <= WALL_X1) ||
		(GetDigit(reflectflag, 3) && int(p.x) >= WALL_X2)) {
		Speed = { -mSpeed.x, mSpeed.y };
		Cood = p;
		return true;
	}
	if ((GetDigit(reflectflag, 0) && int(p.y) <= WALL_Y1) ||
		(GetDigit(reflectflag, 1) && int(p.y) >= WALL_Y2)) {
		Speed = { mSpeed.x, -mSpeed.y };
		Cood = p;
		return true;
	}
	return false;
}
#ifdef _DEBUG
#include "../../../Library/Color/ColorData.h"
#include "../../../Library/Renderer.h"
#include "DxLib.h"
void IBullet::DrawHit()noexcept { Circle::draw(CYAN); }
void IBullet::DrawGraze()noexcept { DxWrp::DrawCircle(p, mData->graze, ORANGE,false); }
void IBullet::DrawSpeed()noexcept { DxWrp::DrawLine(p, p + mSpeed*20.0f, WHITE); }
void IBullet::DrawValue()noexcept {
	DrawBox(p.x, p.y, p.x + 140.0f, p.y + 120.0f,GREY,true);
	DxLib::DrawFormatString(p.x + 20.0f, p.y + 20.0f, WHITE, "Time  : %f", mTime);
	DxLib::DrawFormatString(p.x + 20.0f, p.y + 40.0f, WHITE, "Id    : %d", mID);
	DxLib::DrawFormatString(p.x + 20.0f, p.y + 60.0f, WHITE, mLiveFlag ? "true":"false");
	DxLib::DrawFormatString(p.x + 20.0f, p.y + 80.0f, WHITE, "Speed : x = %f y = %f", mSpeed.x, mSpeed.y);
	//DxLib::DrawFormatString(p.x + 20.0f, p.y + 100.0f, WHITE, "Till  : %f", mTill);
}
#endif
