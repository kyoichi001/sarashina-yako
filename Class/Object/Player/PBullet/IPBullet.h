#pragma once

#include "../../../../Library/Primitive/Primitive.h"

class ObjectAdaptor;
class IGhost;
class IBoss;

class IPBullet :public Circle {
protected:
	bool mLiveFlag;
	int mTime;
	static ObjectAdaptor* mCList;
	int mAttack;
public:
	IPBullet(const Point& XY)noexcept;
	~IPBullet()noexcept;
	bool virtual Update(float t)noexcept = 0;
	void virtual Draw()const noexcept {}
	void virtual Finalize()noexcept { mLiveFlag = false; };

	bool IsLive()const noexcept { return mLiveFlag; }
	bool IsOver()const noexcept;
	void Erace() noexcept { mLiveFlag = false; }
	void Kill()noexcept;

	void virtual Collided(IGhost& obj){}
	void virtual Collided(IBoss& obj){}

	static void SetClassList(ObjectAdaptor* ClassListPtr)noexcept { mCList = ClassListPtr; }
	int GetAttack()const noexcept { return mAttack; }
};