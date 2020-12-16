
#include "UPrimitive.h"
#include "../Math/Random.h"
#include "../Math/Geometory.h"

void UPrimitive::setPoint(const Point& Obj) { mPrim.p = Obj; mValidPrim = 0; }
void UPrimitive::setCircle(const Circle& Obj) { mPrim.cir = Obj; mValidPrim = 1; }
void UPrimitive::setCapsule(const Capsule& Obj) { mPrim.cap = Obj; mValidPrim = 2; }
void UPrimitive::setRect(const Rect& Obj) { mPrim.rec = Obj; mValidPrim = 3; }
void UPrimitive::setSegment(const Segment& Obj) { mPrim.seg = Obj; mValidPrim = 4; }

Point UPrimitive::getRegion()const {
	switch (mValidPrim) {
	case 0:return Rand(mPrim.p);
	case 1:return Rand(mPrim.cir);
	case 2:return Rand(mPrim.cap);
	case 3:return Rand(mPrim.rec);
	case 4:return Rand(mPrim.seg);
	}
}

bool UPrimitive::isCollided(const UPrimitive& obj)const {
	switch(obj.mValidPrim) {
	case 0:return isCollided(obj.mPrim.p);
	case 1:return isCollided(obj.mPrim.cir);
	case 2:return isCollided(obj.mPrim.cap);
	case 3:return isCollided(obj.mPrim.rec);
	case 4:return isCollided(obj.mPrim.seg);
	}
}