
#include "OptionData.h"
#include "../PBullet/PlayerBullet.h"
#include "../Bom/Bom.h"
#include "../../../MediatorClass/ObjectAdaptor.h"
#include "../../../../Library/Renderer.h"
#include "../../../../Library/Math/Constant.h"
#include "../../../../Library/Math/Random.h"

int Option1Hdl, Option2Hdl;
void InitOptionResource()noexcept{
	Option1Hdl = DxWrp::LoadGraph("Picture/Chara/Player/PlayerOption.png");
	Option2Hdl = DxWrp::LoadGraph("Picture/Chara/Player/PlayerOption2.png");
	InitBomResource();
}

OptionInvisible::OptionInvisible(Point* XY, const Vec2& dif)noexcept:IOption(XY,dif){}
void OptionInvisible::Shoot()noexcept{
	mCList->ObjPBl().SetObject(new BulletNormal(*this, 10.0f));
}

OptionHorming::OptionHorming(Point* XY, const Vec2& dif)noexcept : IOption(XY, dif) {}
void OptionHorming::Shoot()noexcept {
	mCList->ObjPBl().SetObject(new BulletHorming(*this, 10.0f));
}
void OptionHorming::Draw()const noexcept {
	DxWrp::DrawRotaGraph(*this, 0.7f, float(mTime)/10.0f, Option1Hdl);
}

OptionWind::OptionWind(Point* XY, char typeNum)noexcept : IOption(XY, Vec2::Zero), mLength(50), mMoveSign(false) {
	switch (typeNum) {
	case 0:
		mAngle = -HALF_PI + PI / 5;
		mMoveSign = false;
		break;
	case 1:
		mAngle = -HALF_PI - PI / 5;
		mMoveSign = true;
		break;
	case 2:
		mAngle = -HALF_PI + PI / 6;
		mMoveSign = false;
		mLength = 80;
		break;
	case 3:
		mAngle = -HALF_PI - PI / 6;
		mLength = 80;
		mMoveSign = true;
		break;
	}
}
bool OptionWind::Update(float t)noexcept {
	if (!mParent) {
		mLiveFlag = false;
		return mLiveFlag;
	}
	if (mMoveSign) {
		mAngle += 0.05f;
		if (mAngle >= -HALF_PI + PI / 3)mMoveSign = false;
	}
	else {
		mAngle -= 0.05f;
		if (mAngle <= -HALF_PI - PI / 3)mMoveSign = true;
	}
	mOfs = Vec2{ mAngle,mLength,0 };
	++mTime;
	return mLiveFlag;
}
void OptionWind::Shoot()noexcept {
	mCList->ObjPBl().SetObject(new BulletWind(*mParent + mOfs, 10.0f, mAngle));
}
void OptionWind::Draw()const noexcept {
	DxWrp::DrawRotaGraph(*mParent+mOfs, 1.0f, 0.0f, Option2Hdl);
}

OptionBom::OptionBom(Point* XY, const Vec2& dif)noexcept : IOption(XY, dif) {}
void OptionBom::Shoot()noexcept {
	mCList->ObjBom().SetObject(new PlayerBom(*this));
}

OptionBom2::OptionBom2(Point* XY, const Vec2& dif)noexcept : IOption(XY, dif) ,mShootFlag(false), mShotCount(0){}
bool  OptionBom2::Update(float t)noexcept {
	if (mShootFlag) {
		if (mTime % 10 == 0) {
			mCList->ObjBom().SetObject(new PlayerBom2(Rand(GameWindow)));
			if (mShotCount >= 30) {
				mShotCount = 0;
				mShootFlag = false;
			}
			else {
				mShotCount++;
			}
		}
	}
	++mTime;
	return mLiveFlag;
}
void OptionBom2::Shoot()noexcept {
	mShootFlag = true;
}