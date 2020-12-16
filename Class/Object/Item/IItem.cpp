
#include "IItem.h"
#include "../Player/IPlayer.h"
#include <cmath>

IPlayer* IItem::mPlayerPtr = nullptr;

IItem::IItem(const Point& P)noexcept :
Circle(P, 48),mState(0){//, mSpeed(0.0f, -0.8f), mAccel(0.0f, 0.01f), mItemID(ItemID), mState(0) {
}
IItem::~IItem()noexcept{}

bool IItem::Update(float t)noexcept {
	const float a = p.Angle(mPlayerPtr->p);
	switch (mState) {
	case 0:
		mState = 1;
	case 1:
		p += mSpeed;
		//mSpeed += mAccel;
		break;
	case 2:
		p.x += 10.0f * cosf(a);
		p.y += 10.0f * sinf(a);
		break;
	case 3:
		return false;
		break;
	}
	if (p.y > 712) {
		mState = 3;
		return false;
	}
	UpdateObj(t);
	return true;
}
void IItem::Gather() noexcept { mState = 2; }
void IItem::Kill() noexcept { mState = 3; }
void IItem::Execute() noexcept {
	//ItemFunc[mItemID](*mPlayerPtr);
}