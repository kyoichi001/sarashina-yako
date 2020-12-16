
#pragma once

#include "../../../Library/Typedef.h"

class IBullet;
class ObjectAdaptor;

class BulletRenewManager{
	using func = void(*)(IBullet&, int, ObjectAdaptor&);
	func mFunc[256];
public:
	BulletRenewManager()noexcept;
	~BulletRenewManager()noexcept;
	void Push(uchar ID, func Func)noexcept;
	void Renew(uchar ID, IBullet& Obj, int t, ObjectAdaptor& List) noexcept {
		mFunc[ID](Obj, t,List);
	}
};
