
#include "Ibom.h"
#include "../../../../Library/Math/Collision.h"
#include "../../../../Data/DATA.h"

ObjectAdaptor* IBom::mCList = nullptr;

IBom::IBom(const Point& rXY) noexcept:Circle(rXY, 30), mLiveFlag(true), mTime(0), mAttack(10) {}
IBom::~IBom()noexcept {}

void IBom::Kill()noexcept {
	Finalize();
}
bool IBom::IsOver()const noexcept {
	return !IsHit(GameWindow, *this);
}
