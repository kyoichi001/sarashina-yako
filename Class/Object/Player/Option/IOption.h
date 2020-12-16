#pragma once


#include "../../../../Library/Primitive/Primitive.h"

class ObjectAdaptor;

class IOption :public Point {
protected:
	int mTime;
	Vec2 mOfs;
	Point* mParent;
	bool mLiveFlag;
	static ObjectAdaptor* mCList;
public:
	IOption(Point* XY, const Vec2& ofs)noexcept;
	~IOption()noexcept;
	bool virtual Update(float t)noexcept;
	void virtual Draw()const noexcept {}
	void virtual Shoot()noexcept {}
	void Kill()noexcept { mLiveFlag = false; }
	bool IsLive()const noexcept { return mLiveFlag; }
	void static SetClassList(ObjectAdaptor* ClassListPtr)noexcept;
};
