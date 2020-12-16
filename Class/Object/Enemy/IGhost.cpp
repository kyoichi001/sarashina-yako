
#include "IGhost.h"
//#include "../Item/ItemData.h"
#include "../../MediatorClass/ObjectAdaptor.h"
#include "../../../Library/Func.h"
#include "../../../Library/Math/Collision.h"
#include "../../../Library/Math/Constant.h"
#include "../../../Library/Sprite/Animation.h"
#include "GhostData.h"

ObjectAdaptor* IGhost::mCList = nullptr;

IGhost::IGhost(const Point& P, GhostData* data, float Value)noexcept:
	Circle(P,40),mValue(Value),mFirst(P),mData(data),mState(1), mTime(0), mHP(data->HP),mSpeed(Vec2::Zero) {
	r = data->r;
}
void IGhost::Init(const Point& P, GhostData* data, float Value )noexcept {
	p=P; r = data->r;mValue=Value;mFirst = P;mData=data;mState = 1;mTime = 0;
	mHP = data->HP;
}
void IGhost::Damage(int damage)noexcept {
	mHP -= damage;
	mState = mHP <= 0 ? 3 : 2;
}
bool IGhost::Update(float t) noexcept {
	if (mState == 3) {
		Finalize();
		return false;
	}
	if(mState==2)mState = 1;//”í’eó‘Ô‚ð‚à‚Æ‚É–ß‚·
	mData->func(this, *mCList, mTime);
	p += mSpeed;
	++mTime;
	return mState != 4;
}
void IGhost::Draw()const noexcept {
	mData->animation->Draw(p, mTime);
}

void IGhost::Finalize()noexcept {
	mData->endfunc(this, *mCList);
	mState = 4;
}

bool IGhost::IsOver()const noexcept {
	return !IsHit(GameWindow, *this);
}
