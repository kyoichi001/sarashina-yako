#pragma once

#include "Primitive.h"
#include "../Math/Collision.h"

union Primitive {
	Point p;
	Circle cir;
	Capsule cap;
	Rect rec;
	Segment seg;
	Primitive() {}
	~Primitive() {}
};

class UPrimitive {
	Primitive mPrim;
	char mValidPrim;
public:
	UPrimitive(const Point& Obj) :mValidPrim(0) { mPrim.p = Obj; }
	UPrimitive(const Circle& Obj) :mValidPrim(1) { mPrim.cir = Obj; }
	UPrimitive(const Capsule& Obj) :mValidPrim(2) { mPrim.cap = Obj; }
	UPrimitive(const Rect& Obj) :mValidPrim(3) { mPrim.rec = Obj; }
	UPrimitive(const Segment& Obj) :mValidPrim(4) { mPrim.seg = Obj; }
	~UPrimitive() {}
	void setPoint(const Point& Obj);
	void setCircle(const Circle& Obj);
	void setCapsule(const Capsule& Obj);
	void setRect(const Rect& Obj);
	void setSegment(const Segment& Obj);
	Point getRegion()const;
	template<class P>
	bool isCollided(const P& obj)const {
		switch (mValidPrim) {
		case 0:return IsHit(mPrim.p, obj);
		case 1:return IsHit(mPrim.cir, obj);
		case 2:return IsHit(mPrim.cap, obj);
		case 3:return IsHit(mPrim.rec, obj);
		case 4:return IsHit(mPrim.seg, obj);
		}
	}
	bool isCollided(const UPrimitive& obj)const;
};