
#include "ILeazer.h"
#include "../../../Data/DATA.h"
#include "../../../Library/Func.h"
#include "../../../Library/Renderer.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Math/intersectAt.h"
#include "../../../Library/Math/Geometory.h"
#include "../../../Library/Math/Collision.h"
#include "../Effect/Effects.h"

#include "../../MediatorClass/ObjectAdaptor.h"

ObjectAdaptor* ILeazer::mList=nullptr;

ILeazer::ILeazer(uchar ID, uchar renewID, const Point& ofs,float angle, Point* Parent, BulletColor Color, LeazerData* Data, int till)noexcept 
:mID(ID),mRenewID(renewID),mOfs(ofs),mParent(Parent),mColor(Color),mAngle(angle),mData(Data),mTill(till),
mTime(0),mState(0){
}

ILeazer::~ILeazer()noexcept {}

bool ILeazer::Update(float t)noexcept {
	std::vector<Point> list = IntersectAt(HalfLine{ *mParent + mOfs,mAngle }, GameWindow);
	if (!list.empty()) {
		mEnd = list[0];
	}
	if (!mParent) {
		mState = 4;
		return false;
	}
	//mList->ObjBRen().Renew(mRenewID, *this, mTime, *mList);
	++mTime;
	mList->ObjLRen().Renew(mRenewID, *this, mTime, *mList);
	switch (mState) {
	case 0:
		if (mTime >= 30) {
			mState = 1;
			mTime = 0;
		}
		break;
	case 1:
		if (mTime >= 15) {
			mState = 2;
			mTime = 0;
		}
		break;
	case 2:
		if (mTime >= mTill) {
			mState = 3;
			mTime = 0;
		}
		break;
	case 3:
		if (mTime >= 15) {
			mState = 4;
			mTime = 0;
		}
		break;
	default:
		return false;
		break;
	}
	return IsLive();
}

void ILeazer::Draw()const noexcept {
#ifdef _DEBUG
	DxWrp::DrawCircle(*mParent + mOfs, 5, 0xFF0000);
	DxWrp::DrawCircle(mEnd, 5, 0x00FF00);
#endif
	switch (mState) {
	case 0:
		DxWrp::DrawLine(*mParent + mOfs, mEnd, 0xFFFFFF, 3);
		break;
	case 1:
		mData->Draw(*mParent + mOfs, mEnd, float(mTime)/15.0f, mColor, mTime);
		break;
	case 2:
		mData->Draw(*mParent + mOfs, mEnd, 1.0f, mColor, mTime);
		break;
	case 3:
		mData->Draw(*mParent + mOfs, mEnd, 1.0f - float(mTime)/15.0f, mColor, mTime);
		break;
	}
}
void ILeazer::splitBullet(uchar ID, uchar renewID, float position, uchar FanMany, float Angle, float Speed, float open ){

}

ObjectAdaptor* ILeazer2::mList = nullptr;

ILeazer2::ILeazer2(uchar ID, uchar renewID, const Point& p,const Vec2& speed, float length, BulletColor Color, LeazerData* Data, int till )noexcept
:Segment(p,p),mID(ID), mRenewID(renewID),mSpeed(speed), mColor(Color), mLength(length), mData(Data), mTill(till),
mTime(0), mLiveFlag(true) 
{

}

ILeazer2::ILeazer2()noexcept: Segment(Point::Zero, Point::Zero){}
ILeazer2::~ILeazer2()noexcept {}

bool ILeazer2::Update(float t)noexcept {
	if (mTime > mLength * mLength / mSpeed.lengthSqu()) {
		end += mSpeed;
	}
	if (!IsHit(GameWindow, end)) {
		mLiveFlag = false;
		return false;
	}
	begin += mSpeed;
	mList->ObjLRen().Renew2(mRenewID, *this, mTime, *mList);
	++mTime;
	return mLiveFlag;
}
void ILeazer2::Draw()const noexcept{
	mData->Draw(begin, end, 1.0f, mColor, mTime);
}

