
#include "BulletEmitter.h"
#include "BulletFactory.h"

BulletFactory* BEmitter::mBsList = nullptr;

BEmitter& BEmitter::SetDelta(int DFanMany, float DAngle, float DSpeed, float Dopen, short DRadius)noexcept {
	mDFanMany = DFanMany;
	mDSpeed = DSpeed;
	mDAngle = DAngle;
	mDOpen =Dopen;
	mDRadius = DRadius;
	return *this;
}
void BEmitter::Emit(uchar ID, uchar renewID, const Point& XY, uchar fanMany, float Angle, float Speed, float open, short radius) {
	mBsList->Bullet(ID, renewID, XY, fanMany, Angle, Speed, open, radius);
}
