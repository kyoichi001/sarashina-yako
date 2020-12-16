
#include "IPBullet.h"
#include "../../../../Library/Math/Collision.h"
#include "../../../../Data/DATA.h"

ObjectAdaptor* IPBullet::mCList = nullptr;

IPBullet::IPBullet(const Point& rXY) noexcept:Circle(rXY, 30), mLiveFlag(true),  mTime(0), mAttack(10) {}
IPBullet::~IPBullet()noexcept {}

void IPBullet::Kill()noexcept {
	Finalize();
}
bool IPBullet::IsOver()const noexcept {
	return !IsHit(GameWindow, *this);
}
